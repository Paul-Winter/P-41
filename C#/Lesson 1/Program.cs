using System;

namespace ConsoleApp1
{
    public class Program
    {
        public static int Main()
        {
            Console.Write("Привет! Как тебя зовут? ");
            String name = Console.ReadLine();
            const string abc = "dlskfjsdfjasdklfjs";
            int def = 14;
            Console.Clear();
            Console.Write($"Hello {name}. Укажите свой год рождения: ");
            int birthyear = Int32.Parse(Console.ReadLine());
            Console.Clear();
            int age = 2026 - birthyear;

            if (age > def)
            {
                Console.WriteLine($"Йоу, {name}! Тебе уже {age} лет");
            }
            else if (age == def)
            {
                Console.WriteLine("Тебе 14 лет! Пора получать паспорт!");
            }
            else
            {
                Console.WriteLine("Тю, малолетка!");
            }
            return 0;
        }
    }
}
