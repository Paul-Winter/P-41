using System;

namespace Викторинка
{
    class Program
    {
        static QuizService quizService = new QuizService();
        static User? currentUser = null;

        static void Main(string[] args)
        {
            Console.WriteLine("Добро пожаловать в Викторину!");
            while (true)
            {
                if (currentUser == null)
                    ShowAuthMenu();
                else
                    ShowMainMenu();
            }
        }

        static void ShowAuthMenu()
        {
            Console.WriteLine("\n1 - Вход");
            Console.WriteLine("2 - Регистрация");
            Console.WriteLine("3 - Выход");
            Console.Write("Выберите действие: ");
            var choice = Console.ReadLine();

            switch (choice)
            {
                case "1":
                    Login();
                    break;
                case "2":
                    Register();
                    break;
                case "3":
                    Environment.Exit(0);
                    break;
                default:
                    Console.WriteLine("Неверный выбор.");
                    break;
            }
        }

        static void Login()
        {
            Console.Write("Логин: ");
            var login = Console.ReadLine();
            Console.Write("Пароль: ");
            var password = Console.ReadLine();

            currentUser = quizService.Login(login ?? string.Empty, password ?? string.Empty);
            if (currentUser == null)
                Console.WriteLine("Неверный логин или пароль.");
            else
                Console.WriteLine($"Добро пожаловать, {currentUser.Login}!");
        }

        static void Register()
        {
            Console.Write("Придумайте логин: ");
            var login = Console.ReadLine();
            Console.Write("Придумайте пароль: ");
            var password = Console.ReadLine();

            if (quizService.Register(login ?? string.Empty, password ?? string.Empty))
            {
                Console.WriteLine("Регистрация успешна! Теперь войдите.");
            }
            else
            {
                Console.WriteLine("Пользователь с таким логином уже существует.");
            }
        }

        static void ShowMainMenu()
        {
            Console.WriteLine("\nГлавное меню:");
            Console.WriteLine("1 - Посмотреть прогресс");
            Console.WriteLine("2 - Пройти викторину");
            Console.WriteLine("3 - Выйти из аккаунта");
            Console.Write("Ваш выбор: ");
            var choice = Console.ReadLine();

            switch (choice)
            {
                case "1":
                    ShowProgress();
                    break;
                case "2":
                    StartQuiz();
                    break;
                case "3":
                    currentUser = null;
                    Console.WriteLine("Вы вышли из аккаунта.");
                    break;
                default:
                    Console.WriteLine("Неверный выбор.");
                    break;
            }
        }

        static void ShowProgress()
        {
            Console.WriteLine("\nВаш прогресс:");
            foreach (var quiz in quizService.Quizzes)
            {
                var (percent, best) = quizService.GetProgress(currentUser!, quiz.Topic);
                Console.WriteLine($"{quiz.Topic}: выполнено на {percent}% | Лучший результат: {best}/{quiz.Questions.Count}");
            }
        }

        static void StartQuiz()
        {
            Console.WriteLine("\nДоступные темы:");
            for (int i = 0; i < quizService.Quizzes.Count; i++)
            {
                Console.WriteLine($"{i + 1}. {quizService.Quizzes[i].Topic}");
            }
            Console.Write("Выберите номер темы (0 - назад): ");
            if (!int.TryParse(Console.ReadLine(), out int index) || index < 1 || index > quizService.Quizzes.Count)
                return;

            var quiz = quizService.Quizzes[index - 1];
            Console.WriteLine($"\nТема: {quiz.Topic}. Ответьте на {quiz.Questions.Count} вопросов.");
            int score = 0;

            for (int i = 0; i < quiz.Questions.Count; i++)
            {
                var q = quiz.Questions[i];
                Console.WriteLine($"\nВопрос {i + 1}: {q.Text}");
                char letter = 'A';
                for (int j = 0; j < q.Options.Length; j++)
                {
                    Console.WriteLine($"{letter}) {q.Options[j]}");
                    letter++;
                }

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
                {
                    Console.WriteLine($"Неправильно. Правильный ответ: {(char)('A' + q.CorrectIndex)}");
                }
            }

            Console.WriteLine($"\nВикторина завершена! Ваш результат: {score}/{quiz.Questions.Count}");
            quizService.UpdateResult(currentUser!, quiz.Topic, score, quiz.Questions.Count);

            var (percent, best) = quizService.GetProgress(currentUser!, quiz.Topic);
            Console.WriteLine($"Лучший результат по теме: {best}/{quiz.Questions.Count}. Прогресс: {percent}%");
        }
    }
}