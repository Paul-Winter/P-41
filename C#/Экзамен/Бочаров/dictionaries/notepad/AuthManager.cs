using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Text.Json;

namespace DictionaryApplication
{
    public static class AuthManager
    {
        private static readonly string UsersFilePath = "users_db.dat";
        private static List<User> users = new List<User>();
        public static User CurrentUser { get; private set; }

        public static void Initialize()
        {
            LoadUsers();
            while (CurrentUser == null)
            {
                Console.Clear();
                Console.WriteLine("     МОДУЛЬ АВТОРИЗАЦИИ      ");
                Console.WriteLine("1. Вход в систему");
                Console.WriteLine("2. Регистрация нового пользователя");
                Console.WriteLine("3. Завершить работу приложения");
                Console.Write("\nВыберите действие: ");

                string choice = Console.ReadLine();

                switch (choice)
                {
                    case "1": Login(); break;
                    case "2": Register(); break;
                    case "3": Environment.Exit(0); break;
                    default:
                        Console.WriteLine("Ошибка: некорректный ввод.");
                        Console.ReadKey();
                        break;
                }
            }
        }

        private static void Login()
        {
            Console.Clear();
            Console.WriteLine("     АУТЕНТИФИКАЦИЯ       ");
            Console.Write("Введите имя пользователя: ");
            string username = Console.ReadLine().Trim();
            Console.Write("Введите пароль: ");
            string password = Console.ReadLine().Trim();

            User found = users.Find(u => u.Username.Equals(username, StringComparison.OrdinalIgnoreCase));

            if (found != null && found.Password == password)
            {
                CurrentUser = found;
                Console.WriteLine($"\nУведомление: Доступ разрешен. Добро пожаловать, {CurrentUser.Username}.");
                Console.ReadKey();
            }
            else
            {
                Console.WriteLine("\nОшибка: Неверные учетные данные.");
                Console.ReadKey();
            }
        }

        private static void Register()
        {
            Console.Clear();
            Console.WriteLine("     РЕГИСТРАЦИЯ     ");
            Console.Write("Введите новое имя пользователя: ");
            string username = Console.ReadLine().Trim();

            if (users.Exists(u => u.Username.Equals(username, StringComparison.OrdinalIgnoreCase)))
            {
                Console.WriteLine("Ошибка: Имя пользователя уже зарегистрировано в системе.");
                Console.ReadKey();
                return;
            }

            Console.Write("Введите новый пароль: ");
            string password = Console.ReadLine().Trim();

            if (string.IsNullOrEmpty(username) || string.IsNullOrEmpty(password))
            {
                Console.WriteLine("Ошибка: Учетные данные не могут быть пустыми.");
                Console.ReadKey();
                return;
            }

            users.Add(new User { Username = username, Password = password });
            SaveUsers();
            Console.WriteLine("Уведомление: Регистрация успешно завершена.");
            Console.ReadKey();
        }

        private static string ApplicationCipher(string text, int key)
        {
            char[] buffer = text.ToCharArray();
            for (int i = 0; i < buffer.Length; i++)
            {
                buffer[i] = (char)(buffer[i] + key);
            }
            return new string(buffer);
        }

        private static void SaveUsers()
        {
            string json = JsonSerializer.Serialize(users);
            string encrypted = ApplicationCipher(json, 5);
            File.WriteAllText(UsersFilePath, encrypted, Encoding.UTF8);
        }

        private static void LoadUsers()
        {
            if (!File.Exists(UsersFilePath)) return;

            try
            {
                string encrypted = File.ReadAllText(UsersFilePath, Encoding.UTF8);
                string decrypted = ApplicationCipher(encrypted, -5);
                users = JsonSerializer.Deserialize<List<User>>(decrypted) ?? new List<User>();
            }
            catch
            {
                users = new List<User>();
            }
        }
    }
}