using System.Text.RegularExpressions;

namespace Урок__14._Регулярные_выражения
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //string hello = "Hello, World!";
            //Console.WriteLine("Введите строку:");
            //string str2 = Console.ReadLine();
            //Console.WriteLine($"Заданная строка: '{str2}'");
            //Console.WriteLine($"В строке есть буква 'e'? {EFinder(hello)}");

            string emailPattern = @"^([a-z0-9_-]+\.)*[a-z0-9_-]+@[a-z0-9_-]+(\.[a-z0-9_-]+)*\.[a-z]{2,6}$";
            string phonePattern = @"^\+\d{1}\(\d{3}\)\d{3}-\d{2}-\d{2}";
            Console.Write("Введите email: ");
            Regex regex = new Regex(emailPattern);
            string email = Console.ReadLine();
            if (regex.IsMatch(email))
            {
                Console.WriteLine("email введён правильно - поздравляем!");
            }
            else
            {
                Console.WriteLine("некорректный email!");
            }
            Console.Write("Введите телефон: ");
            regex = new Regex(phonePattern);
            string phone = Console.ReadLine();
            if (regex.IsMatch(phone))
            {
                Console.WriteLine("номер телефона введён правильно - поздравляем!");
            }
            else
            {
                Console.WriteLine("некорректный номер!");
            }
        }
        static bool EFinder(string str)
        {
            foreach (char c in str)
            {
                if (c == 'e')
                {
                    return true;
                }
            }
            return false;
        }
    }
}
