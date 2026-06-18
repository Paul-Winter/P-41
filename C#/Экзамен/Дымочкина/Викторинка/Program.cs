using System;
using System.Collections.Generic;

namespace Викторинка
{
    class Program
    {
        static QuizService quizService = new QuizService();
        static User? currentUser = null;
        static bool isAdmin = false;

        static void Main(string[] args)
        {
            while (true)
            {
                if (currentUser == null && !isAdmin)
                    ShowAuthMenu();
                else if (isAdmin)
                    ShowAdminMenu();
                else
                    ShowMainMenu();
            }
        }

        static void ShowAuthMenu()
        {
            Console.Clear();
            Console.WriteLine("Добро пожаловать в Викторину!");
            Console.WriteLine("\n1 - Вход");
            Console.WriteLine("2 - Регистрация");
            Console.WriteLine("3 - Выход");
            Console.Write("Выберите действие: ");
            var choice = Console.ReadLine();

            switch (choice)
            {
                case "1": Login(); break;
                case "2": Register(); break;
                case "3": Environment.Exit(0); break;
                default: Console.WriteLine("Неверный выбор."); Console.ReadKey(); break;
            }
        }

        static string ReadPassword()
        {
            string pass = "";
            ConsoleKeyInfo key;
            do
            {
                key = Console.ReadKey(true);
                if (key.Key != ConsoleKey.Backspace && key.Key != ConsoleKey.Enter)
                {
                    pass += key.KeyChar;
                    Console.Write("*");
                }
                else if (key.Key == ConsoleKey.Backspace && pass.Length > 0)
                {
                    pass = pass.Substring(0, pass.Length - 1);
                    Console.Write("\b \b");
                }
            } while (key.Key != ConsoleKey.Enter);
            Console.WriteLine();
            return pass;
        }

        static void Login()
        {
            Console.Write("Логин: ");
            var login = Console.ReadLine() ?? "";

            if (login == "admin")
            {
                Console.Write("Пароль: ");
                var pass = ReadPassword();
                if (pass == "admin")
                {
                    isAdmin = true;
                    Console.WriteLine("Вы вошли как администратор.");
                    Console.ReadKey();
                    return;
                }
                Console.WriteLine("Неверный пароль администратора.");
                Console.ReadKey();
                return;
            }

            Console.Write("Пароль: ");
            var password = ReadPassword();
            currentUser = quizService.Login(login, password);
            if (currentUser == null)
            {
                Console.WriteLine("Неверный логин или пароль.");
                Console.ReadKey();
            }
            else
            {
                Console.WriteLine($"Добро пожаловать, {currentUser.Login}!");
                Console.ReadKey();
            }
        }

        static void Register()
        {
            Console.Write("Придумайте логин: ");
            var login = Console.ReadLine() ?? "";
            Console.Write("Придумайте пароль: ");
            var password = ReadPassword();

            if (quizService.Register(login, password))
            {
                Console.WriteLine("Регистрация успешна! Теперь войдите.");
            }
            else
            {
                Console.WriteLine("Пользователь с таким логином уже существует.");
            }
            Console.ReadKey();
        }

        static void ShowMainMenu()
        {
            Console.Clear();
            Console.WriteLine("Главное меню:");
            Console.WriteLine("1 - Посмотреть прогресс");
            Console.WriteLine("2 - Пройти викторину");
            Console.WriteLine("3 - Выйти из аккаунта");
            Console.Write("Ваш выбор: ");
            var choice = Console.ReadLine();

            switch (choice)
            {
                case "1": ShowProgress(); break;
                case "2": StartQuiz(); break;
                case "3":
                    currentUser = null;
                    Console.WriteLine("Вы вышли из аккаунта.");
                    Console.ReadKey();
                    break;
                default: Console.WriteLine("Неверный выбор."); Console.ReadKey(); break;
            }
        }

        static void ShowProgress()
        {
            Console.Clear();
            Console.WriteLine("Ваш прогресс:\n");
            Console.WriteLine("{0,-30} {1,10} {2,15}", "Тема", "Прогресс", "Лучший результат");
            Console.WriteLine(new string('-', 60));
            foreach (var quiz in quizService.Quizzes)
            {
                var (percent, best) = quizService.GetProgress(currentUser!, quiz.Topic);
                string progressStr = $"{percent}%";
                string bestStr = $"{best}/{quiz.Questions.Count}";
                Console.WriteLine("{0,-30} {1,10} {2,15}", quiz.Topic, progressStr, bestStr);
            }
            Console.WriteLine("\nНажмите любую клавишу для продолжения...");
            Console.ReadKey();
        }

        static void StartQuiz()
        {
            Console.Clear();
            Console.WriteLine("Доступные темы:");
            for (int i = 0; i < quizService.Quizzes.Count; i++)
                Console.WriteLine($"{i + 1}. {quizService.Quizzes[i].Topic}");
            Console.Write("\nВыберите номер темы (0 - назад): ");
            if (!int.TryParse(Console.ReadLine(), out int index) || index < 1 || index > quizService.Quizzes.Count)
                return;

            var quiz = quizService.Quizzes[index - 1];
            Console.Clear();
            Console.WriteLine($"Тема: {quiz.Topic}. Ответьте на {quiz.Questions.Count} вопросов.");
            int score = 0;

            for (int i = 0; i < quiz.Questions.Count; i++)
            {
                var q = quiz.Questions[i];
                Console.WriteLine($"\nВопрос {i + 1}: {q.Text}");
                char letter = 'A';
                for (int j = 0; j < q.Options.Length; j++)
                    Console.WriteLine($"{letter++}) {q.Options[j]}");

                Console.Write("Ваш ответ (A/B/C/D): ");
                var answer = Console.ReadLine()?.Trim().ToUpper();
                int answerIndex = answer switch
                {
                    "A" => 0,
                    "B" => 1,
                    "C" => 2,
                    "D" => 3,
                    _ => -1
                };

                if (answerIndex == q.CorrectIndex)
                {
                    Console.WriteLine("Правильно!");
                    score++;
                }
                else
                    Console.WriteLine($"Неправильно. Правильный ответ: {(char)('A' + q.CorrectIndex)}");
                Console.WriteLine("Нажмите любую клавишу для продолжения...");
                Console.ReadKey();
            }

            Console.Clear();
            Console.WriteLine($"Викторина завершена! Ваш результат: {score}/{quiz.Questions.Count}");
            quizService.UpdateResult(currentUser!, quiz.Topic, score, quiz.Questions.Count);
            var (percent, best) = quizService.GetProgress(currentUser!, quiz.Topic);
            Console.WriteLine($"Лучший результат: {best}/{quiz.Questions.Count}. Прогресс: {percent}%");
            Console.ReadKey();
        }
        static void ShowAdminMenu()
        {
            Console.Clear();
            Console.WriteLine("Меню администратора");
            Console.WriteLine("1 - Управление викторинами");
            Console.WriteLine("2 - Управление пользователями");
            Console.WriteLine("3 - Выход из аккаунта");
            Console.Write("Ваш выбор: ");
            var choice = Console.ReadLine();

            switch (choice)
            {
                case "1": AdminQuizzesMenu(); break;
                case "2": AdminUsersMenu(); break;
                case "3":
                    isAdmin = false;
                    Console.WriteLine("Вы вышли из аккаунта администратора.");
                    Console.ReadKey();
                    break;
                default: Console.WriteLine("Неверный выбор."); Console.ReadKey(); break;
            }
        }

        static void AdminQuizzesMenu()
        {
            while (true)
            {
                Console.Clear();
                Console.WriteLine("Управление викторинами");
                Console.WriteLine("1 - Просмотр всех тем");
                Console.WriteLine("2 - Добавить новую тему");
                Console.WriteLine("3 - Редактировать тему (выбрать)");
                Console.WriteLine("4 - Удалить тему");
                Console.WriteLine("0 - Назад");
                Console.Write("Ваш выбор: ");
                var choice = Console.ReadLine();

                switch (choice)
                {
                    case "1":
                        Console.Clear();
                        foreach (var quiz in quizService.Quizzes)
                            Console.WriteLine($"- {quiz.Topic} ({quiz.Questions.Count} вопросов)");
                        Console.ReadKey();
                        break;
                    case "2":
                        AddNewTopic();
                        break;
                    case "3":
                        EditTopic();
                        break;
                    case "4":
                        DeleteTopic();
                        break;
                    case "0": return;
                    default: Console.WriteLine("Неверный выбор."); Console.ReadKey(); break;
                }
            }
        }

        static void AddNewTopic()
        {
            Console.Clear();
            Console.Write("Введите название новой темы: ");
            var topic = Console.ReadLine() ?? "";
            var quiz = new Quiz { Topic = topic, Questions = new List<Question>() };

            Console.Write("Сколько вопросов добавить? ");
            if (!int.TryParse(Console.ReadLine(), out int count) || count < 1) return;

            for (int i = 0; i < count; i++)
            {
                Console.Clear();
                Console.WriteLine($"Добавление вопроса {i + 1}/{count}");
                Console.Write("Текст вопроса: ");
                var text = Console.ReadLine() ?? "";
                var options = new string[4];
                for (int j = 0; j < 4; j++)
                {
                    Console.Write($"Вариант {(char)('A' + j)}: ");
                    options[j] = Console.ReadLine() ?? "";
                }
                Console.Write("Номер правильного ответа (1-4): ");
                int correct = 0;
                int.TryParse(Console.ReadLine(), out correct);
                correct = Math.Clamp(correct - 1, 0, 3);
                quiz.Questions.Add(new Question { Text = text, Options = options, CorrectIndex = correct });
            }
            quizService.AddQuiz(quiz);
            Console.WriteLine("Тема успешно добавлена.");
            Console.ReadKey();
        }

        static void EditTopic()
        {
            Console.Clear();
            Console.WriteLine("Выберите тему для редактирования:");
            for (int i = 0; i < quizService.Quizzes.Count; i++)
                Console.WriteLine($"{i + 1}. {quizService.Quizzes[i].Topic}");
            Console.Write("Номер темы (0 - отмена): ");
            if (!int.TryParse(Console.ReadLine(), out int index) || index < 1 || index > quizService.Quizzes.Count)
                return;
            var quiz = quizService.Quizzes[index - 1];

            while (true)
            {
                Console.Clear();
                Console.WriteLine($"Редактирование темы: {quiz.Topic}");
                Console.WriteLine("1 - Просмотреть вопросы");
                Console.WriteLine("2 - Добавить вопрос");
                Console.WriteLine("3 - Редактировать вопрос");
                Console.WriteLine("4 - Удалить вопрос");
                Console.WriteLine("0 - Назад");
                Console.Write("Ваш выбор: ");
                var choice = Console.ReadLine();
                switch (choice)
                {
                    case "1":
                        Console.Clear();
                        for (int i = 0; i < quiz.Questions.Count; i++)
                        {
                            var q = quiz.Questions[i];
                            Console.WriteLine($"{i + 1}. {q.Text}");
                            Console.WriteLine($"   A) {q.Options[0]}  B) {q.Options[1]}  C) {q.Options[2]}  D) {q.Options[3]}");
                            Console.WriteLine($"   Правильный: {(char)('A' + q.CorrectIndex)}");
                        }
                        Console.ReadKey();
                        break;
                    case "2":
                        AddQuestionToQuiz(quiz);
                        break;
                    case "3":
                        EditQuestionInQuiz(quiz);
                        break;
                    case "4":
                        DeleteQuestionFromQuiz(quiz);
                        break;
                    case "0": return;
                    default: Console.WriteLine("Неверный выбор."); Console.ReadKey(); break;
                }
            }
        }

        static void AddQuestionToQuiz(Quiz quiz)
        {
            Console.Clear();
            Console.WriteLine("Добавление вопроса");
            Console.Write("Текст вопроса: ");
            var text = Console.ReadLine() ?? "";
            var options = new string[4];
            for (int i = 0; i < 4; i++)
            {
                Console.Write($"Вариант {(char)('A' + i)}: ");
                options[i] = Console.ReadLine() ?? "";
            }
            Console.Write("Номер правильного ответа (1-4): ");
            int correct = 0;
            int.TryParse(Console.ReadLine(), out correct);
            correct = Math.Clamp(correct - 1, 0, 3);
            quizService.AddQuestion(quiz, new Question { Text = text, Options = options, CorrectIndex = correct });
            Console.WriteLine("Вопрос добавлен.");
            Console.ReadKey();
        }

        static void EditQuestionInQuiz(Quiz quiz)
        {
            Console.Clear();
            for (int i = 0; i < quiz.Questions.Count; i++)
                Console.WriteLine($"{i + 1}. {quiz.Questions[i].Text}");
            Console.Write("Номер вопроса для редактирования (0 - отмена): ");
            if (!int.TryParse(Console.ReadLine(), out int index) || index < 1 || index > quiz.Questions.Count)
                return;
            var q = quiz.Questions[index - 1];
            Console.Write("Новый текст вопроса (оставьте пустым, чтобы не менять): ");
            var newText = Console.ReadLine();
            if (!string.IsNullOrWhiteSpace(newText)) q.Text = newText;
            for (int i = 0; i < 4; i++)
            {
                Console.Write($"Новый вариант {(char)('A' + i)} (пусто - не менять): ");
                var opt = Console.ReadLine();
                if (!string.IsNullOrWhiteSpace(opt)) q.Options[i] = opt;
            }
            Console.Write("Новый номер правильного ответа (1-4, 0 - не менять): ");
            int newCorrect;
            if (int.TryParse(Console.ReadLine(), out newCorrect) && newCorrect >= 1 && newCorrect <= 4)
                q.CorrectIndex = newCorrect - 1;
            quizService.SaveQuizzes();
            Console.WriteLine("Вопрос обновлён.");
            Console.ReadKey();
        }

        static void DeleteQuestionFromQuiz(Quiz quiz)
        {
            Console.Clear();
            for (int i = 0; i < quiz.Questions.Count; i++)
                Console.WriteLine($"{i + 1}. {quiz.Questions[i].Text}");
            Console.Write("Номер вопроса для удаления (0 - отмена): ");
            if (!int.TryParse(Console.ReadLine(), out int index) || index < 1 || index > quiz.Questions.Count)
                return;
            quizService.RemoveQuestion(quiz, index - 1);
            Console.WriteLine("Вопрос удалён.");
            Console.ReadKey();
        }

        static void DeleteTopic()
        {
            Console.Clear();
            Console.WriteLine("Выберите тему для удаления:");
            for (int i = 0; i < quizService.Quizzes.Count; i++)
                Console.WriteLine($"{i + 1}. {quizService.Quizzes[i].Topic}");
            Console.Write("Номер темы (0 - отмена): ");
            if (!int.TryParse(Console.ReadLine(), out int index) || index < 1 || index > quizService.Quizzes.Count)
                return;
            quizService.RemoveQuiz(index - 1);
            Console.WriteLine("Тема удалена.");
            Console.ReadKey();
        }

        static void AdminUsersMenu()
        {
            while (true)
            {
                Console.Clear();
                Console.WriteLine("Управление пользователями");
                Console.WriteLine("1 - Список пользователей");
                Console.WriteLine("2 - Удалить пользователя");
                Console.WriteLine("3 - Сменить пароль пользователю");
                Console.WriteLine("0 - Назад");
                Console.Write("Ваш выбор: ");
                var choice = Console.ReadLine();
                switch (choice)
                {
                    case "1":
                        Console.Clear();
                        var users = quizService.Users;
                        if (users.Count == 0) Console.WriteLine("Нет зарегистрированных пользователей.");
                        else
                        {
                            Console.WriteLine("{0,-20} {1,-15}", "Логин", "Количество результатов");
                            foreach (var u in users)
                                Console.WriteLine("{0,-20} {1,-15}", u.Login, u.Results.Count);
                        }
                        Console.ReadKey();
                        break;
                    case "2":
                        Console.Write("Введите логин для удаления: ");
                        var delLogin = Console.ReadLine() ?? "";
                        if (quizService.DeleteUser(delLogin))
                            Console.WriteLine("Пользователь удалён.");
                        else
                            Console.WriteLine("Пользователь не найден.");
                        Console.ReadKey();
                        break;
                    case "3":
                        Console.Write("Введите логин пользователя: ");
                        var userLogin = Console.ReadLine() ?? "";
                        Console.Write("Новый пароль: ");
                        var newPass = ReadPassword();
                        if (quizService.ChangePassword(userLogin, newPass))
                            Console.WriteLine("Пароль изменён.");
                        else
                            Console.WriteLine("Пользователь не найден.");
                        Console.ReadKey();
                        break;
                    case "0": return;
                    default: Console.WriteLine("Неверный выбор."); Console.ReadKey(); break;
                }
            }
        }
    }
}