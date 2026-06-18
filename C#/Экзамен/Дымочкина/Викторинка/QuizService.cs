using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Викторинка
{
    public class QuizService
    {
        private const string UsersFile = "users.txt";
        private const string QuestionsFile = "questions.txt";

        public List<User> Users { get; private set; } = new List<User>();
        public List<Quiz> Quizzes { get; private set; } = new List<Quiz>();

        public QuizService()
        {
            LoadUsers();
            LoadQuizzes();
        }

        private void LoadUsers()
        {
            if (File.Exists(UsersFile))
            {
                var lines = File.ReadAllLines(UsersFile);
                foreach (var line in lines)
                {
                    if (string.IsNullOrWhiteSpace(line)) continue;
                    var parts = line.Split('|');
                    if (parts.Length < 2) continue;
                    var user = new User { Login = parts[0], Password = parts[1] };
                    if (parts.Length > 2 && !string.IsNullOrEmpty(parts[2]))
                    {
                        var resultParts = parts[2].Split(';', StringSplitOptions.RemoveEmptyEntries);
                        foreach (var rp in resultParts)
                        {
                            var rd = rp.Split(':');
                            if (rd.Length == 3)
                            {
                                user.Results.Add(new QuizResult
                                {
                                    Topic = rd[0],
                                    BestScore = int.Parse(rd[1]),
                                    Completed = bool.Parse(rd[2])
                                });
                            }
                        }
                    }
                    Users.Add(user);
                }
            }
        }

        public void SaveUsers()
        {
            var lines = Users.Select(u =>
            {
                var resultsStr = string.Join(";", u.Results.Select(r => $"{r.Topic}:{r.BestScore}:{r.Completed}"));
                return $"{u.Login}|{u.Password}|{resultsStr}";
            });
            File.WriteAllLines(UsersFile, lines);
        }

        private void LoadQuizzes()
        {
            if (File.Exists(QuestionsFile))
                Quizzes = ParseQuizzesFromFile(QuestionsFile);
            else
            {
                Quizzes = CreateDefaultQuizzes();
                SaveQuizzes();
            }
        }

        public void SaveQuizzes()
        {
            using (var writer = new StreamWriter(QuestionsFile))
            {
                foreach (var quiz in Quizzes)
                {
                    writer.WriteLine($"[Topic:{quiz.Topic}]");
                    foreach (var q in quiz.Questions)
                    {
                        var options = string.Join("|", q.Options);
                        writer.WriteLine($"{q.Text}|{options}|{q.CorrectIndex}");
                    }
                    writer.WriteLine();
                }
            }
        }

        private List<Quiz> ParseQuizzesFromFile(string path)
        {
            var quizzes = new List<Quiz>();
            var lines = File.ReadAllLines(path);
            Quiz? currentQuiz = null;
            foreach (var line in lines)
            {
                if (line.StartsWith("[Topic:"))
                {
                    var topic = line.Substring(7, line.Length - 8);
                    currentQuiz = new Quiz { Topic = topic, Questions = new List<Question>() };
                    quizzes.Add(currentQuiz);
                }
                else if (!string.IsNullOrWhiteSpace(line) && currentQuiz != null)
                {
                    var parts = line.Split('|');
                    if (parts.Length >= 6)
                    {
                        var question = new Question
                        {
                            Text = parts[0],
                            Options = new[] { parts[1], parts[2], parts[3], parts[4] },
                            CorrectIndex = int.Parse(parts[5])
                        };
                        currentQuiz.Questions.Add(question);
                    }
                }
            }
            return quizzes;
        }

        private List<Quiz> CreateDefaultQuizzes()
        {
            return new List<Quiz>
            {
                new Quiz { Topic = "География", Questions = GeographyQuestions() },
                new Quiz { Topic = "Кино", Questions = CinemaQuestions() },
                new Quiz { Topic = "Животные", Questions = AnimalsQuestions() },
                new Quiz { Topic = "Музыка", Questions = MusicQuestions() },
                new Quiz { Topic = "Спорт", Questions = SportQuestions() },
                new Quiz { Topic = "Компьютерные игры", Questions = GamesQuestions() },
                new Quiz { Topic = "Кулинария", Questions = CookingQuestions() },
                new Quiz { Topic = "Информационные технологии", Questions = ITQuestions() }
            };
        }

        // Фабрики вопросов (оставлены без изменений, только для примера)
        private List<Question> GeographyQuestions() => new List<Question>
        {
            new Question { Text = "Столица Франции?", Options = new[]{"Лондон","Берлин","Париж","Мадрид"}, CorrectIndex = 2 },
            new Question { Text = "Какая самая длинная река в мире?", Options = new[]{"Амазонка","Нил","Миссисипи","Янцзы"}, CorrectIndex = 1 },
            new Question { Text = "На каком материке находится пустыня Сахара?", Options = new[]{"Азия","Африка","Австралия","Южная Америка"}, CorrectIndex = 1 },
            new Question { Text = "Столица Японии?", Options = new[]{"Сеул","Пекин","Токио","Бангкок"}, CorrectIndex = 2 },
            new Question { Text = "Какое море не имеет берегов?", Options = new[]{"Красное","Саргассово","Черное","Карибское"}, CorrectIndex = 1 },
            new Question { Text = "Гора Эверест находится в ...", Options = new[]{"Альпах","Андах","Гималаях","Кордильерах"}, CorrectIndex = 2 },
            new Question { Text = "Страна кленового листа — это", Options = new[]{"США","Канада","Великобритания","Австралия"}, CorrectIndex = 1 },
            new Question { Text = "Какой океан самый большой?", Options = new[]{"Атлантический","Индийский","Тихий","Северный Ледовитый"}, CorrectIndex = 2 },
            new Question { Text = "Где находится озеро Байкал?", Options = new[]{"Россия","Китай","Монголия","Казахстан"}, CorrectIndex = 0 },
            new Question { Text = "Сколько континентов на Земле?", Options = new[]{"5","6","7","8"}, CorrectIndex = 2 }
        };

        private List<Question> CinemaQuestions() => new List<Question>
        {
            new Question { Text = "Кто сыграл Гарри Поттера?", Options = new[]{"Дэниэл Рэдклифф","Руперт Гринт","Том Фелтон","Эдди Редмэйн"}, CorrectIndex = 0 },
            new Question { Text = "Фильм 'Титаник' получил 'Оскар'?", Options = new[]{"Да","Нет"}, CorrectIndex = 0 },
            new Question { Text = "Какого цвета таблетка показывает 'правду' в 'Матрице'?", Options = new[]{"Красная","Синяя","Зелёная","Жёлтая"}, CorrectIndex = 0 },
            new Question { Text = "Кто режиссёр 'Криминального чтива'?", Options = new[]{"Спилберг","Тарантино","Скорсезе","Нолан"}, CorrectIndex = 1 },
            new Question { Text = "Сколько частей в 'Звёздных войнах' (основная сага)?", Options = new[]{"6","7","8","9"}, CorrectIndex = 3 },
            new Question { Text = "Как зовут льва из 'Короля Льва'?", Options = new[]{"Муфаса","Симба","Шрам","Тимон"}, CorrectIndex = 1 },
            new Question { Text = "Какой фильм получил первого 'Оскара' за лучший фильм?", Options = new[]{"Крылья","Бен-Гур","Унесённые ветром","Касабланка"}, CorrectIndex = 0 },
            new Question { Text = "Кто такой Дарт Вейдер?", Options = new[]{"Энакин Скайуокер","Люк Скайуокер","Оби-Ван","Хан Соло"}, CorrectIndex = 0 },
            new Question { Text = "В каком году вышел первый 'Аватар'?", Options = new[]{"2007","2009","2011","2013"}, CorrectIndex = 1 },
            new Question { Text = "Как зовут собаку в 'Маске'?", Options = new[]{"Майло","Рекс","Бетховен","Снупи"}, CorrectIndex = 0 }
        };

        private List<Question> AnimalsQuestions() => new List<Question>
        {
            new Question { Text = "Какое животное самое быстрое на суше?", Options = new[]{"Гепард","Лев","Антилопа","Страус"}, CorrectIndex = 0 },
            new Question { Text = "Сколько ног у паука?", Options = new[]{"6","8","10","12"}, CorrectIndex = 1 },
            new Question { Text = "Кто такой нарвал?", Options = new[]{"Птица","Рыба","Кит","Тюлень"}, CorrectIndex = 2 },
            new Question { Text = "Какое животное может регенерировать утраченные конечности?", Options = new[]{"Ящерица","Аксолотль","Змея","Лягушка"}, CorrectIndex = 1 },
            new Question { Text = "Чем дышат дельфины?", Options = new[]{"Жабрами","Легкими","Кожей","Водой через рот"}, CorrectIndex = 1 },
            new Question { Text = "Какая птица не летает?", Options = new[]{"Орел","Пингвин","Воробей","Голубь"}, CorrectIndex = 1 },
            new Question { Text = "Сколько сердец у осьминога?", Options = new[]{"1","2","3","4"}, CorrectIndex = 2 },
            new Question { Text = "Чем питается панда?", Options = new[]{"Мясом","Рыбой","Бамбуком","Фруктами"}, CorrectIndex = 2 },
            new Question { Text = "Какое млекопитающее умеет летать?", Options = new[]{"Белка-летяга","Летучая мышь","Летучий дракон","Колибри"}, CorrectIndex = 1 },
            new Question { Text = "Самый крупный хищник на суше?", Options = new[]{"Тигр","Бурый медведь","Белый медведь","Лев"}, CorrectIndex = 2 }
        };

        private List<Question> MusicQuestions() => new List<Question>
        {
            new Question { Text = "Сколько нот в октаве?", Options = new[]{"5","6","7","8"}, CorrectIndex = 2 },
            new Question { Text = "Кто написал 'Лунную сонату'?", Options = new[]{"Моцарт","Бетховен","Бах","Чайковский"}, CorrectIndex = 1 },
            new Question { Text = "Какой инструмент называют 'королём'?", Options = new[]{"Скрипка","Орган","Рояль","Гитара"}, CorrectIndex = 1 },
            new Question { Text = "Группа 'Queen' из какой страны?", Options = new[]{"США","Канада","Великобритания","Австралия"}, CorrectIndex = 2 },
            new Question { Text = "Сколько струн у классической гитары?", Options = new[]{"4","5","6","7"}, CorrectIndex = 2 },
            new Question { Text = "Кто исполняет песню 'Thriller'?", Options = new[]{"Prince","Michael Jackson","Madonna","Elvis Presley"}, CorrectIndex = 1 },
            new Question { Text = "Как называется палочка дирижёра?", Options = new[]{"Смычок","Барабанная палочка","Дирижёрская палочка","Плектр"}, CorrectIndex = 2 },
            new Question { Text = "В каком жанре работал И.С. Бах?", Options = new[]{"Романтизм","Классицизм","Барокко","Импрессионизм"}, CorrectIndex = 2 },
            new Question { Text = "Самый низкий мужской голос?", Options = new[]{"Тенор","Баритон","Бас","Контратенор"}, CorrectIndex = 2 },
            new Question { Text = "Какой инструмент входит в состав симфонического оркестра?", Options = new[]{"Гитара","Арфа","Саксофон","Аккордеон"}, CorrectIndex = 1 }
        };

        private List<Question> SportQuestions() => new List<Question>
        {
            new Question { Text = "Сколько игроков в футбольной команде на поле?", Options = new[]{"9","10","11","12"}, CorrectIndex = 2 },
            new Question { Text = "В каком виде спорта используется шайба?", Options = new[]{"Хоккей на траве","Хоккей с шайбой","Кёрлинг","Бейсбол"}, CorrectIndex = 1 },
            new Question { Text = "Через сколько лет проходят Олимпийские игры?", Options = new[]{"2","3","4","5"}, CorrectIndex = 2 },
            new Question { Text = "Какой мяч самый тяжелый?", Options = new[]{"Футбольный","Баскетбольный","Теннисный","Волейбольный"}, CorrectIndex = 1 },
            new Question { Text = "В каком виде спорта есть термин 'смэш'?", Options = new[]{"Футбол","Теннис","Плавание","Бег"}, CorrectIndex = 1 },
            new Question { Text = "Сколько колец в эмблеме Олимпиады?", Options = new[]{"3","4","5","6"}, CorrectIndex = 2 },
            new Question { Text = "Какой спорт называют 'королевой'?", Options = new[]{"Гимнастика","Лёгкая атлетика","Плавание","Фигурное катание"}, CorrectIndex = 1 },
            new Question { Text = "Страна-родоначальница футбола?", Options = new[]{"Бразилия","Англия","Испания","Германия"}, CorrectIndex = 1 },
            new Question { Text = "В баскетболе бросок стоит...", Options = new[]{"1 очко","2 или 3 очка","2 очка","3 очка"}, CorrectIndex = 1 },
            new Question { Text = "Какая дистанция марафона?", Options = new[]{"21 км","30 км","42,195 км","50 км"}, CorrectIndex = 2 }
        };

        private List<Question> GamesQuestions() => new List<Question>
        {
            new Question { Text = "Какой персонаж собирает золотые кольца?", Options = new[]{"Марио","Соник","Пэкмен","Крэш"}, CorrectIndex = 1 },
            new Question { Text = "В какой игре появился блок 'TNT'?", Options = new[]{"Terraria","Minecraft","Fortnite","Roblox"}, CorrectIndex = 1 },
            new Question { Text = "Кто создал игру 'Тетрис'?", Options = new[]{"Алексей Пажитнов","Нолан Бушнелл","Сигэру Миямото","Гейб Ньюэлл"}, CorrectIndex = 0 },
            new Question { Text = "Сколько игроков в команде в 'Counter-Strike' классическом?", Options = new[]{"4","5","6","8"}, CorrectIndex = 1 },
            new Question { Text = "Как зовут главного героя серии 'The Legend of Zelda'?", Options = new[]{"Zelda","Link","Ganon","Impa"}, CorrectIndex = 1 },
            new Question { Text = "В какой игре есть 'Криперы'?", Options = new[]{"Terraria","Minecraft","Stardew Valley","Don't Starve"}, CorrectIndex = 1 },
            new Question { Text = "Какая компания разработала 'World of Warcraft'?", Options = new[]{"Riot Games","Blizzard","Valve","Epic Games"}, CorrectIndex = 1 },
            new Question { Text = "Какой жанр у игры 'Among Us'?", Options = new[]{"Шутер","Симулятор","Социальная дедукция","Гонка"}, CorrectIndex = 2 },
            new Question { Text = "В каком году вышел первый 'Doom'?", Options = new[]{"1990","1993","1996","1999"}, CorrectIndex = 1 },
            new Question { Text = "Что собирают в Pac-Man?", Options = new[]{"Монеты","Точки","Фрукты","Звезды"}, CorrectIndex = 1 }
        };

        private List<Question> CookingQuestions() => new List<Question>
        {
            new Question { Text = "Из чего делают пасту карбонару?", Options = new[]{"Сливки, бекон","Яйца, гуанчиале","Томат, базилик","Сыр, грибы"}, CorrectIndex = 1 },
            new Question { Text = "Что такое 'табаско'?", Options = new[]{"Сыр","Соус","Напиток","Суп"}, CorrectIndex = 1 },
            new Question { Text = "Основной ингредиент гуакамоле?", Options = new[]{"Помидор","Авокадо","Перец","Лук"}, CorrectIndex = 1 },
            new Question { Text = "Что такое 'жульен'?", Options = new[]{"Нарезка","Суп","Салат","Десерт"}, CorrectIndex = 0 },
            new Question { Text = "Как называется японское блюдо из сырой рыбы?", Options = new[]{"Суши","Сашими","Рамен","Темпура"}, CorrectIndex = 1 },
            new Question { Text = "Из какого молока делают моцареллу?", Options = new[]{"Коровьего","Буйволиного","Козьего","Овечьего"}, CorrectIndex = 1 },
            new Question { Text = "Что добавляют в тесто для оладий, чтобы они были пышными?", Options = new[]{"Сахар","Соль","Разрыхлитель","Яйцо"}, CorrectIndex = 2 },
            new Question { Text = "Кулинарный термин 'al dente' означает...", Options = new[]{"Мягкий","Полусырой","Слегка недоваренный","Переваренный"}, CorrectIndex = 2 },
            new Question { Text = "В какую страну обычно относят борщ?", Options = new[]{"Россия","Украина","Польша","Беларусь"}, CorrectIndex = 1 },
            new Question { Text = "Какой напиток делают из ячменя?", Options = new[]{"Квас","Пиво","Компот","Морс"}, CorrectIndex = 1 }
        };

        private List<Question> ITQuestions() => new List<Question>
        {
            new Question { Text = "Что означает аббревиатура CPU?", Options = new[]{"Central Process Unit","Central Processing Unit","Computer Personal Unit","Core Processing Utility"}, CorrectIndex = 1 },
            new Question { Text = "Какая компания создала Windows?", Options = new[]{"Apple","Google","Microsoft","IBM"}, CorrectIndex = 2 },
            new Question { Text = "Сколько бит в одном байте?", Options = new[]{"4","8","16","32"}, CorrectIndex = 1 },
            new Question { Text = "Что такое HTML?", Options = new[]{"Язык программирования","Язык разметки","Протокол","База данных"}, CorrectIndex = 1 },
            new Question { Text = "Какой язык программирования используется для iOS-приложений?", Options = new[]{"Java","C#","Swift","Python"}, CorrectIndex = 2 },
            new Question { Text = "Что такое 'фаервол'?", Options = new[]{"Антивирус","Сетевой экран","Браузер","Плагин"}, CorrectIndex = 1 },
            new Question { Text = "Сколько символов в двоичной системе счисления?", Options = new[]{"8","10","2","16"}, CorrectIndex = 2 },
            new Question { Text = "Кто изобрел World Wide Web?", Options = new[]{"Билл Гейтс","Стив Джобс","Тим Бернерс-Ли","Линус Торвальдс"}, CorrectIndex = 2 },
            new Question { Text = "Что такое 'cookie' в веб-контексте?", Options = new[]{"Вирус","Реклама","Небольшой файл данных","Печенье"}, CorrectIndex = 2 },
            new Question { Text = "Какая операционная система с открытым исходным кодом самая популярная?", Options = new[]{"Windows","macOS","Linux","Android"}, CorrectIndex = 2 }
        };
        public bool Register(string login, string password)
        {
            if (Users.Any(u => u.Login == login))
                return false;
            Users.Add(new User { Login = login, Password = password });
            SaveUsers();
            return true;
        }

        public User? Login(string login, string password)
        {
            return Users.FirstOrDefault(u => u.Login == login && u.Password == password);
        }

        public void UpdateResult(User user, string topic, int score, int totalQuestions)
        {
            var result = user.Results.FirstOrDefault(r => r.Topic == topic);
            if (result == null)
            {
                result = new QuizResult { Topic = topic };
                user.Results.Add(result);
            }
            result.Completed = true;
            if (score > result.BestScore)
                result.BestScore = score;
            SaveUsers();
        }

        public (int percent, int bestScore) GetProgress(User user, string topic)
        {
            var res = user.Results.FirstOrDefault(r => r.Topic == topic);
            var quiz = Quizzes.FirstOrDefault(q => q.Topic == topic);
            int total = quiz?.Questions.Count ?? 10;
            int best = res?.BestScore ?? 0;
            int percent = total > 0 ? (best * 100) / total : 0;
            return (percent, best);
        }
        public void AddQuiz(Quiz quiz)
        {
            Quizzes.Add(quiz);
            SaveQuizzes();
        }

        public void RemoveQuiz(int index)
        {
            if (index >= 0 && index < Quizzes.Count)
            {
                Quizzes.RemoveAt(index);
                SaveQuizzes();
            }
        }

        public void AddQuestion(Quiz quiz, Question question)
        {
            quiz.Questions.Add(question);
            SaveQuizzes();
        }

        public void RemoveQuestion(Quiz quiz, int questionIndex)
        {
            if (questionIndex >= 0 && questionIndex < quiz.Questions.Count)
            {
                quiz.Questions.RemoveAt(questionIndex);
                SaveQuizzes();
            }
        }
        public bool DeleteUser(string login)
        {
            var user = Users.FirstOrDefault(u => u.Login == login);
            if (user != null)
            {
                Users.Remove(user);
                SaveUsers();
                return true;
            }
            return false;
        }

        public bool ChangePassword(string login, string newPassword)
        {
            var user = Users.FirstOrDefault(u => u.Login == login);
            if (user != null)
            {
                user.Password = newPassword;
                SaveUsers();
                return true;
            }
            return false;
        }
    }
}