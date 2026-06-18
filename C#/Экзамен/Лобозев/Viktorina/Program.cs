using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.Json;

namespace QuizApp
{
    public class Question
    {
        public string Text { get; set; }
        public List<string> Options { get; set; }
        public int CorrectAnswerIndex { get; set; }
        public Question() { }
        public Question(string text, List<string> options, int correctIndex)
        {
            Text = text;
            Options = options;
            CorrectAnswerIndex = correctIndex;
        }
        public bool CheckAnswer(int userChoice) => (userChoice - 1) == CorrectAnswerIndex;
        public override string ToString() => $"{Text}\n" + string.Join("\n", Options.Select((opt, i) => $"{i + 1}. {opt}"));
    }
    public class Topic
    {
        public string Name { get; set; }
        public List<Question> Questions { get; set; }
        public Topic() { }
        public Topic(string name) { Name = name; Questions = new List<Question>(); }
        public override string ToString() => Name;
    }
    public class User
    {
        public string Login { get; set; }
        public string Password { get; set; }
        public string Role { get; set; }
        public int TotalQuizzes { get; set; }
        public int TotalCorrect { get; set; }
        public int TotalQuestions { get; set; }
        public User() { }
        public User(string login, string password, string role = "User")
        {
            Login = login;
            Password = password;
            Role = role;
            TotalQuizzes = 0;
            TotalCorrect = 0;
            TotalQuestions = 0;
        }
        public void UpdateStats(int correct, int total)
        {
            TotalQuizzes++;
            TotalCorrect += correct;
            TotalQuestions += total;
        }
        public double SuccessRate => TotalQuestions > 0 ? (double)TotalCorrect / TotalQuestions * 100 : 0;
    }
    public static class UserStorage
    {
        private const string FileName = "users.json";
        public static List<User> Load()
        {
            if (!File.Exists(FileName))
                return new List<User> { new User("admin", "admin", "Admin") };
            try
            {
                string json = File.ReadAllText(FileName);
                var users = JsonSerializer.Deserialize<List<User>>(json);
                return users ?? new List<User>();
            }
            catch { return new List<User>(); }
        }
        public static void Save(List<User> users)
        {
            var options = new JsonSerializerOptions { WriteIndented = true };
            string json = JsonSerializer.Serialize(users, options);
            File.WriteAllText(FileName, json);
        }
        public static User FindUser(List<User> users, string login) =>
            users.FirstOrDefault(u => u.Login.Equals(login, StringComparison.OrdinalIgnoreCase));
        public static User Authenticate(List<User> users, string login, string password)
        {
            var user = FindUser(users, login);
            return (user != null && user.Password == password) ? user : null;
        }
    }
    public class QuizManager
    {
        private const string FileName = "topics.json";
        public List<Topic> Topics { get; set; } = new List<Topic>();

        public void Load()
        {
            if (!File.Exists(FileName)) { Save(); return; }
            try
            {
                string json = File.ReadAllText(FileName);
                Topics = JsonSerializer.Deserialize<List<Topic>>(json) ?? new List<Topic>();
            }
            catch { Topics = new List<Topic>(); }
        }
        public void Save()
        {
            try
            {
                var options = new JsonSerializerOptions { WriteIndented = true };
                string json = JsonSerializer.Serialize(Topics, options);
                File.WriteAllText(FileName, json);
            }
            catch (Exception ex) { Console.WriteLine($"Ошибка сохранения: {ex.Message}"); }
        }
        // ----- Управление темами -----
        public void AddTopic()
        {
            Console.Clear();
            Console.WriteLine("=== Создание новой темы ===");
            Console.Write("Введите название темы: ");
            string name = Console.ReadLine()?.Trim();
            if (string.IsNullOrEmpty(name)) { Console.WriteLine("Название не может быть пустым."); return; }
            if (Topics.Any(t => t.Name.Equals(name, StringComparison.OrdinalIgnoreCase)))
            { Console.WriteLine("Тема с таким названием уже существует."); return; }
            Topics.Add(new Topic(name));
            Save();
            Console.WriteLine($"Тема '{name}' создана.");
        }
        public void EditTopic()
        {
            if (Topics.Count == 0) { Console.WriteLine("Нет тем для редактирования."); return; }
            Console.Clear();
            Console.WriteLine("=== Редактирование темы ===");
            ShowTopics();
            Console.Write("Введите номер темы для редактирования: ");
            if (!int.TryParse(Console.ReadLine(), out int index) || index < 1 || index > Topics.Count)
            { Console.WriteLine("Неверный номер."); return; }
            var topic = Topics[index - 1];
            Console.Write($"Текущее название: {topic.Name}. Новое название: ");
            string newName = Console.ReadLine()?.Trim();
            if (string.IsNullOrEmpty(newName)) { Console.WriteLine("Название не может быть пустым."); return; }
            if (Topics.Any(t => t != topic && t.Name.Equals(newName, StringComparison.OrdinalIgnoreCase)))
            { Console.WriteLine("Тема с таким названием уже существует."); return; }
            topic.Name = newName;
            Save();
            Console.WriteLine("Тема переименована.");
        }
        public void DeleteTopic()
        {
            if (Topics.Count == 0) { Console.WriteLine("Нет тем для удаления."); return; }
            Console.Clear();
            Console.WriteLine("=== Удаление темы ===");
            ShowTopics();
            Console.Write("Введите номер темы для удаления: ");
            if (!int.TryParse(Console.ReadLine(), out int index) || index < 1 || index > Topics.Count)
            { Console.WriteLine("Неверный номер."); return; }
            var topic = Topics[index - 1];
            Console.Write($"Вы уверены, что хотите удалить тему '{topic.Name}' вместе со всеми вопросами? (y/n): ");
            if (Console.ReadLine()?.Trim().ToLower() == "y")
            {
                Topics.RemoveAt(index - 1);
                Save();
                Console.WriteLine("Тема удалена.");
            }
            else Console.WriteLine("Удаление отменено.");
        }
        public void ShowTopics()
        {
            if (Topics.Count == 0) { Console.WriteLine("Список тем пуст."); return; }
            for (int i = 0; i < Topics.Count; i++)
                Console.WriteLine($"{i + 1}. {Topics[i].Name} (вопросов: {Topics[i].Questions.Count})");
        }
        // ----- Управление вопросами внутри темы -----
        private Topic SelectTopic(string action)
        {
            if (Topics.Count == 0) { Console.WriteLine("Нет тем. Сначала создайте тему."); return null; }
            Console.Clear();
            Console.WriteLine($"=== {action} ===");
            ShowTopics();
            Console.Write("Выберите номер темы: ");
            if (!int.TryParse(Console.ReadLine(), out int index) || index < 1 || index > Topics.Count)
            { Console.WriteLine("Неверный номер."); return null; }
            return Topics[index - 1];
        }
        public void AddQuestionToTopic()
        {
            var topic = SelectTopic("Добавление вопроса в тему");
            if (topic == null) return;
            Console.Clear();
            Console.WriteLine($"=== Добавление вопроса в тему '{topic.Name}' ===");
            Console.Write("Введите текст вопроса: ");
            string text = Console.ReadLine()?.Trim();
            if (string.IsNullOrEmpty(text)) { Console.WriteLine("Текст не может быть пустым."); return; }
            var options = new List<string>();
            Console.WriteLine("Введите варианты ответов (по одному, пустая строка для завершения):");
            for (int i = 0; i < 10; i++)
            {
                Console.Write($"Вариант {i + 1}: ");
                string opt = Console.ReadLine()?.Trim();
                if (string.IsNullOrEmpty(opt)) break;
                options.Add(opt);
            }
            if (options.Count < 2) { Console.WriteLine("Нужно минимум 2 варианта."); return; }
            int correctIndex = -1;
            while (true)
            {
                Console.Write($"Введите номер правильного ответа (1-{options.Count}): ");
                if (int.TryParse(Console.ReadLine(), out int choice) && choice >= 1 && choice <= options.Count)
                { correctIndex = choice - 1; break; }
                Console.WriteLine("Некорректный ввод.");
            }
            topic.Questions.Add(new Question(text, options, correctIndex));
            Save();
            Console.WriteLine("Вопрос добавлен!");
        }
        public void EditQuestionInTopic()
        {
            var topic = SelectTopic("Редактирование вопроса");
            if (topic == null) return;
            if (topic.Questions.Count == 0) { Console.WriteLine("В этой теме нет вопросов."); return; }
            Console.Clear();
            Console.WriteLine($"=== Редактирование вопроса в теме '{topic.Name}' ===");
            ShowQuestionsInTopic(topic);
            Console.Write("Введите номер вопроса для редактирования: ");
            if (!int.TryParse(Console.ReadLine(), out int qIndex) || qIndex < 1 || qIndex > topic.Questions.Count)
            { Console.WriteLine("Неверный номер."); return; }
            var q = topic.Questions[qIndex - 1];
            var oldOptions = new List<string>(q.Options);
            int oldCorrect = q.CorrectAnswerIndex;
            Console.WriteLine($"Текущий текст: {q.Text}");
            Console.Write("Новый текст (оставьте пустым, чтобы не менять): ");
            string newText = Console.ReadLine()?.Trim();
            if (!string.IsNullOrEmpty(newText)) q.Text = newText;
            Console.WriteLine("Текущие варианты:");
            for (int i = 0; i < q.Options.Count; i++) Console.WriteLine($"{i + 1}. {q.Options[i]}");
            Console.Write("Хотите изменить варианты? (y/n): ");
            if (Console.ReadLine()?.Trim().ToLower() == "y")
            {
                var newOptions = new List<string>();
                Console.WriteLine("Введите новые варианты (пустая строка – завершить):");
                for (int i = 0; i < 10; i++)
                {
                    Console.Write($"Вариант {i + 1}: ");
                    string opt = Console.ReadLine()?.Trim();
                    if (string.IsNullOrEmpty(opt)) break;
                    newOptions.Add(opt);
                }
                if (newOptions.Count >= 2) q.Options = newOptions;
                else
                {
                    Console.WriteLine("Вариантов должно быть минимум 2. Изменения отменены.");
                    q.Options = oldOptions;
                    q.CorrectAnswerIndex = oldCorrect;
                    return;
                }
            }
            Console.Write($"Новый номер правильного ответа (1-{q.Options.Count}): ");
            if (int.TryParse(Console.ReadLine(), out int newCorrect) && newCorrect >= 1 && newCorrect <= q.Options.Count)
                q.CorrectAnswerIndex = newCorrect - 1;
            else Console.WriteLine("Некорректный ввод, правильный ответ не изменён.");
            Save();
            Console.WriteLine("Вопрос обновлён.");
        }
        public void DeleteQuestionFromTopic()
        {
            var topic = SelectTopic("Удаление вопроса");
            if (topic == null) return;
            if (topic.Questions.Count == 0) { Console.WriteLine("В этой теме нет вопросов."); return; }
            Console.Clear();
            Console.WriteLine($"=== Удаление вопроса из темы '{topic.Name}' ===");
            ShowQuestionsInTopic(topic);
            Console.Write("Введите номер вопроса для удаления: ");
            if (!int.TryParse(Console.ReadLine(), out int qIndex) || qIndex < 1 || qIndex > topic.Questions.Count)
            { Console.WriteLine("Неверный номер."); return; }
            Console.Write($"Вы уверены, что хотите удалить вопрос #{qIndex}? (y/n): ");
            if (Console.ReadLine()?.Trim().ToLower() == "y")
            {
                topic.Questions.RemoveAt(qIndex - 1);
                Save();
                Console.WriteLine("Вопрос удалён.");
            }
            else Console.WriteLine("Удаление отменено.");
        }
        public void ShowQuestionsInTopic(Topic topic = null)
        {
            if (topic == null)
            {
                if (Topics.Count == 0) { Console.WriteLine("Нет тем."); return; }
                foreach (var t in Topics)
                {
                    Console.WriteLine($"\n--- Тема: {t.Name} ---");
                    if (t.Questions.Count == 0) Console.WriteLine("  (нет вопросов)");
                    else for (int i = 0; i < t.Questions.Count; i++)
                            Console.WriteLine($"  {i + 1}. {t.Questions[i].Text}");
                }
                return;
            }
            if (topic.Questions.Count == 0) { Console.WriteLine("В этой теме нет вопросов."); return; }
            for (int i = 0; i < topic.Questions.Count; i++)
            {
                Console.WriteLine($"--- Вопрос {i + 1} ---");
                Console.WriteLine(topic.Questions[i]);
                Console.WriteLine($"Правильный ответ: {topic.Questions[i].CorrectAnswerIndex + 1}\n");
            }
        }
        // ----- Запуск викторины по выбранной теме -----
        public (int correct, int total) RunQuizByTopic(Topic topic)
        {
            if (topic == null || topic.Questions.Count == 0)
            {
                Console.WriteLine("В выбранной теме нет вопросов.");
                return (0, 0);
            }

            int correctCount = 0;
            var random = new Random();
            var shuffled = topic.Questions.OrderBy(q => random.Next()).ToList();

            for (int i = 0; i < shuffled.Count; i++)
            {
                Console.Clear();
                Console.WriteLine($"=== Викторина по теме: {topic.Name} ===\n");
                Console.WriteLine($"Вопрос {i + 1} из {shuffled.Count}:");
                Console.WriteLine(shuffled[i]);
                Console.Write("Ваш ответ (номер варианта): ");
                string input = Console.ReadLine()?.Trim();

                if (int.TryParse(input, out int userAnswer) && userAnswer >= 1 && userAnswer <= shuffled[i].Options.Count)
                {
                    if (shuffled[i].CheckAnswer(userAnswer))
                    {
                        Console.WriteLine("Правильно!");
                        correctCount++;
                    }
                    else
                    {
                        Console.WriteLine($"Неправильно. Правильный ответ: {shuffled[i].CorrectAnswerIndex + 1}");
                    }
                }
                else
                {
                    Console.WriteLine("Некорректный ввод. Ответ засчитан как неправильный.");
                }
                Console.WriteLine("\nНажмите любую клавишу для следующего вопроса...");
                Console.ReadKey(true);
            }

            Console.Clear();
            Console.WriteLine($"=== Викторина по теме '{topic.Name}' завершена ===");
            Console.WriteLine($"Правильных ответов: {correctCount} из {shuffled.Count}");
            Console.WriteLine($"Процент: {(double)correctCount / shuffled.Count * 100:F2}%");
            return (correctCount, shuffled.Count);
        }
        public Topic SelectTopicForUser()
        {
            if (Topics.Count == 0)
            {
                Console.WriteLine("Нет доступных тем. Обратитесь к администратору.");
                return null;
            }
            Console.Clear();
            Console.WriteLine("=== Выбор темы для викторины ===");
            ShowTopics();
            Console.Write("Введите номер темы: ");
            if (!int.TryParse(Console.ReadLine(), out int index) || index < 1 || index > Topics.Count)
            {
                Console.WriteLine("Неверный номер.");
                return null;
            }
            return Topics[index - 1];
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;

            var users = UserStorage.Load();
            var quizManager = new QuizManager();
            quizManager.Load();

            User currentUser = null;

            while (true)
            {
                if (currentUser == null)
                {
                    Console.Clear();
                    Console.WriteLine("\n=== Добро пожаловать в викторину! ===");
                    Console.WriteLine("1. Вход");
                    Console.WriteLine("2. Регистрация");
                    Console.WriteLine("3. Выход");
                    Console.Write("Выберите действие: ");
                    string choice = Console.ReadLine()?.Trim();

                    switch (choice)
                    {
                        case "1": currentUser = Login(users); break;
                        case "2": Register(users); break;
                        case "3": Console.WriteLine("До свидания!"); return;
                        default: Console.WriteLine("Неверный выбор."); break;
                    }
                }
                else
                {
                    bool loggedOut = false;
                    if (currentUser.Role == "Admin")
                        loggedOut = ShowAdminMenu(currentUser, quizManager, users);
                    else
                        loggedOut = ShowUserMenu(currentUser, quizManager, users);

                    if (loggedOut)
                    {
                        currentUser = null;
                        continue;
                    }

                    Console.WriteLine("\nНажмите любую клавишу для продолжения...");
                    Console.ReadKey(true);
                }
            }
        }
        static User Login(List<User> users)
        {
            Console.Clear();
            Console.WriteLine("=== Вход ===");
            Console.Write("Логин: ");
            string login = Console.ReadLine()?.Trim();
            Console.Write("Пароль: ");
            string password = ReadPassword();
            var user = UserStorage.Authenticate(users, login, password);
            if (user != null)
            {
                Console.WriteLine($"Добро пожаловать, {user.Login} ({user.Role})!");
                return user;
            }
            else
            {
                Console.WriteLine("Неверный логин или пароль.");
                return null;
            }
        }
        static void Register(List<User> users)
        {
            Console.Clear();
            Console.WriteLine("=== Регистрация ===");
            Console.Write("Придумайте логин: ");
            string login = Console.ReadLine()?.Trim();
            if (string.IsNullOrEmpty(login)) { Console.WriteLine("Логин не может быть пустым."); return; }
            if (UserStorage.FindUser(users, login) != null) { Console.WriteLine("Пользователь с таким логином уже существует."); return; }
            Console.Write("Придумайте пароль: ");
            string password = ReadPassword();
            if (string.IsNullOrEmpty(password)) { Console.WriteLine("Пароль не может быть пустым."); return; }
            users.Add(new User(login, password, "User"));
            UserStorage.Save(users);
            Console.WriteLine("Регистрация успешна! Теперь войдите.");
        }
        static string ReadPassword()
        {
            string password = "";
            ConsoleKeyInfo key;
            do
            {
                key = Console.ReadKey(true);
                if (key.Key != ConsoleKey.Backspace && key.Key != ConsoleKey.Enter)
                {
                    password += key.KeyChar;
                    Console.Write("*");
                }
                else if (key.Key == ConsoleKey.Backspace && password.Length > 0)
                {
                    password = password.Remove(password.Length - 1);
                    Console.Write("\b \b");
                }
            } while (key.Key != ConsoleKey.Enter);
            Console.WriteLine();
            return password;
        }
        static bool ShowAdminMenu(User admin, QuizManager quizManager, List<User> users)
        {
            Console.Clear();
            Console.WriteLine($"=== Администратор {admin.Login} ===");
            Console.WriteLine("--- Управление темами ---");
            Console.WriteLine("1. Создать тему");
            Console.WriteLine("2. Переименовать тему");
            Console.WriteLine("3. Удалить тему");
            Console.WriteLine("4. Показать все темы");
            Console.WriteLine("--- Управление вопросами ---");
            Console.WriteLine("5. Добавить вопрос в тему");
            Console.WriteLine("6. Редактировать вопрос в теме");
            Console.WriteLine("7. Удалить вопрос из темы");
            Console.WriteLine("8. Показать все вопросы по темам");
            Console.WriteLine("--- Прочее ---");
            Console.WriteLine("9. Просмотреть пользователей");
            Console.WriteLine("10. Выйти из аккаунта");
            Console.Write("Выберите действие: ");

            string choice = Console.ReadLine()?.Trim();
            switch (choice)
            {
                case "1": quizManager.AddTopic(); break;
                case "2": quizManager.EditTopic(); break;
                case "3": quizManager.DeleteTopic(); break;
                case "4": quizManager.ShowTopics(); break;
                case "5": quizManager.AddQuestionToTopic(); break;
                case "6": quizManager.EditQuestionInTopic(); break;
                case "7": quizManager.DeleteQuestionFromTopic(); break;
                case "8": quizManager.ShowQuestionsInTopic(null); break;
                case "9": ShowUsers(users); break;
                case "10": Console.WriteLine("Выход из аккаунта."); return true;
                default: Console.WriteLine("Неверный выбор."); break;
            }
            return false;
        }
        static void ShowUsers(List<User> users)
        {
            Console.Clear();
            Console.WriteLine("=== Список пользователей ===");
            foreach (var u in users)
                Console.WriteLine($"Логин: {u.Login}, Роль: {u.Role}, Викторин пройдено: {u.TotalQuizzes}, " +
                                  $"Правильных: {u.TotalCorrect} из {u.TotalQuestions} ({u.SuccessRate:F2}%)");
        }

        static bool ShowUserMenu(User user, QuizManager quizManager, List<User> users)
        {
            Console.Clear();
            Console.WriteLine($"=== Пользователь {user.Login} ===");
            Console.WriteLine("1. Пройти викторину по теме");
            Console.WriteLine("2. Показать мою статистику");
            Console.WriteLine("3. Выйти из аккаунта");
            Console.Write("Выберите действие: ");

            string choice = Console.ReadLine()?.Trim();
            switch (choice)
            {
                case "1":
                    var topic = quizManager.SelectTopicForUser();
                    if (topic != null)
                    {
                        var (correct, total) = quizManager.RunQuizByTopic(topic);
                        if (total > 0)
                        {
                            user.UpdateStats(correct, total);
                            UserStorage.Save(users);
                            Console.WriteLine("Статистика обновлена.");
                        }
                    }
                    break;
                case "2":
                    Console.Clear();
                    Console.WriteLine($"=== Статистика пользователя {user.Login} ===");
                    Console.WriteLine($"Пройдено викторин: {user.TotalQuizzes}");
                    Console.WriteLine($"Всего вопросов: {user.TotalQuestions}");
                    Console.WriteLine($"Правильных ответов: {user.TotalCorrect}");
                    Console.WriteLine($"Процент успеха: {user.SuccessRate:F2}%");
                    break;
                case "3":
                    Console.WriteLine("Выход из аккаунта.");
                    return true;
                default:
                    Console.WriteLine("Неверный выбор.");
                    break;
            }
            return false;
        }
    }
}