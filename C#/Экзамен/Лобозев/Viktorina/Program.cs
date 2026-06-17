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
        // Проверка ответа пользователя
        public bool CheckAnswer(int userChoice)
        { 
            return (userChoice - 1) == CorrectAnswerIndex;
        }
        public override string ToString()
        {
            return $"{Text}\n" + string.Join("\n", Options.Select((opt, i) => $"{i + 1}. {opt}"));
        }
    }
    // Класс для управления викториной 
    public class Quiz
    {
        private const string FileName = "questions.json";
        public List<Question> Questions { get; set; }
        public Quiz()
        {
            Questions = new List<Question>();
        }
        // Загрузка вопросов из файла
        public void Load()
        {
            if (!File.Exists(FileName))
            {
                Console.WriteLine("Файл с вопросами не найден. Будет создан новый.");
                Save(); 
                return;
            }
            try
            {
                string json = File.ReadAllText(FileName);
                var loaded = JsonSerializer.Deserialize<List<Question>>(json);
                if (loaded != null)
                    Questions = loaded;
                else
                    Questions = new List<Question>();
                Console.WriteLine($"Загружено {Questions.Count} вопросов.");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка загрузки: {ex.Message}");
                Questions = new List<Question>();
            }
        }
        // Сохранение вопросов
        public void Save()
        {
            try
            {
                var options = new JsonSerializerOptions { WriteIndented = true };
                string json = JsonSerializer.Serialize(Questions, options);
                File.WriteAllText(FileName, json);
                Console.WriteLine("Вопросы сохранены.");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка сохранения: {ex.Message}");
            }
        }
        // Добавление нового вопроса
        public void AddQuestion()
        {
            Console.Clear();
            Console.WriteLine("=== Добавление нового вопроса ===");

            Console.Write("Введите текст вопроса: ");
            string text = Console.ReadLine()?.Trim();
            if (string.IsNullOrEmpty(text))
            {
                Console.WriteLine("Текст вопроса не может быть пустым.");
                return;
            }
            var options = new List<string>();
            Console.WriteLine("Введите варианты ответов (по одному, пустая строка для завершения):");
            for (int i = 0; i < 10; i++) 
            {
                Console.Write($"Вариант {i + 1}: ");
                string opt = Console.ReadLine()?.Trim();
                if (string.IsNullOrEmpty(opt))
                    break;
                options.Add(opt);
            }
            if (options.Count < 2)
            {
                Console.WriteLine("Для вопроса нужно как минимум 2 варианта.");
                return;
            }
            int correctIndex = -1;
            while (true)
            {
                Console.Write($"Введите номер правильного ответа (1-{options.Count}): ");
                if (int.TryParse(Console.ReadLine(), out int choice) && choice >= 1 && choice <= options.Count)
                {
                    correctIndex = choice - 1;
                    break;
                }
                Console.WriteLine("Некорректный ввод. Попробуйте снова.");
            }
            Questions.Add(new Question(text, options, correctIndex));
            Console.WriteLine("Вопрос добавлен!");
            Save(); 
        }
        // Запуск викторины
        public void Run()
        {
            if (Questions.Count == 0)
            {
                Console.WriteLine("Нет вопросов для викторины. Сначала добавьте вопросы.");
                return;
            }
            Console.Clear();
            Console.WriteLine("=== Начало викторины ===\n");
            int correctCount = 0;
            var random = new Random();
            // Перемешиваем вопросы для разнообразия
            var shuffled = Questions.OrderBy(q => random.Next()).ToList();
            for (int i = 0; i < shuffled.Count; i++)
            {
                var q = shuffled[i];
                Console.WriteLine($"Вопрос {i + 1} из {shuffled.Count}:");
                Console.WriteLine(q);
                Console.Write("Ваш ответ (номер варианта): ");
                string input = Console.ReadLine()?.Trim();

                if (int.TryParse(input, out int userAnswer) && userAnswer >= 1 && userAnswer <= q.Options.Count)
                {
                    if (q.CheckAnswer(userAnswer))
                    {
                        Console.WriteLine("Правильно!\n");
                        correctCount++;
                    }
                    else
                    {
                        Console.WriteLine($"Неправильно. Правильный ответ: {q.CorrectAnswerIndex + 1}\n");
                    }
                }
                else
                {
                    Console.WriteLine("Некорректный ввод. Ответ засчитан как неправильный.\n");
                }
            }
            Console.WriteLine($"=== Викторина завершена ===\nПравильных ответов: {correctCount} из {shuffled.Count}");
            Console.WriteLine($"Процент: {(double)correctCount / shuffled.Count * 100:F2}%");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8;

            var quiz = new Quiz();
            quiz.Load();

            bool exit = false;
            while (!exit)
            {
                Console.WriteLine("\n=== Меню ===");
                Console.WriteLine("1. Начать викторину");
                Console.WriteLine("2. Добавить вопрос");
                Console.WriteLine("3. Показать количество вопросов");
                Console.WriteLine("4. Выйти");
                Console.Write("Выберите действие: ");

                string choice = Console.ReadLine()?.Trim();
                switch (choice)
                {
                    case "1":
                        quiz.Run();
                        break;
                    case "2":
                        quiz.AddQuestion();
                        break;
                    case "3":
                        Console.WriteLine($"Всего вопросов: {quiz.Questions.Count}");
                        break;
                    case "4":
                        exit = true;
                        quiz.Save();
                        Console.WriteLine("До свидания!");
                        break;
                    default:
                        Console.WriteLine("Неверный выбор. Попробуйте снова.");
                        break;
                }
                if (!exit)
                {
                    Console.WriteLine("\nНажмите любую клавишу для продолжения...");
                    Console.ReadKey(true);
                }
            }
        }
    }
}