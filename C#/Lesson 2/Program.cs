using System.Runtime.CompilerServices;
using System.Runtime.ExceptionServices;

namespace ConsoleApp2
{
    internal class Program
    {
        public static bool isVisible = true;
        static void Main(string[] args)
        {
            Console.WriteLine("__________Целочисленные типы данных__________");
            Console.WriteLine("byte                      0 до 255");
            Console.WriteLine("sbyte                  -128 до 127");
            Console.WriteLine("short                -32768 до 32767");
            Console.WriteLine("ushort                    0 до 65535");
            Console.WriteLine("int             -2147483648 до 2147483647");
            Console.WriteLine("uint                      0 до 4294967295");
            Console.WriteLine("long   -9223372036854775808 до 9223372036854775807");
            Console.WriteLine("ulong                     0 до 18446744073709551615");
            Console.WriteLine("\n__________Типы с плавающей точкой__________");
            Console.WriteLine("float          -3,402826e38 до 3,402826e38");
            Console.WriteLine("double        -1,797693е308 до 1,797693е308");
            Console.WriteLine("decimal        -7,922816е28 до 7,922816е28");

            Console.WriteLine("\n\n__________Тип decimal:");
            decimal divided = decimal.One;
            Console.WriteLine(divided);
            decimal divisor = 3;
            divided = divided / divisor;
            Console.WriteLine(divided);
            Console.WriteLine(divided * divisor);
            Console.WriteLine("__________Тип double:");
            double doubleDiv = 1;
            Console.WriteLine(doubleDiv);
            System.Double doubleDivisor = 3;
            doubleDiv = doubleDiv / doubleDivisor;
            Console.WriteLine(doubleDiv);
            Console.WriteLine(doubleDiv * doubleDivisor);
            Console.WriteLine("\n__________Символьный тип данных__________");
            char symbol = '\a';
            //Console.WriteLine(symbol);
            Console.WriteLine("\e[31m Hello TOP Academy!");
            //Console.WriteLine(isVisible);
            //NeMain();

            Console.WriteLine("================================================================================");
            int month;

            do
            {
                Console.Write("Пожалуйста, введите номер месяца: ");
                month = Int32.Parse(Console.ReadLine());
                WhatSeason(month);
            } while (month != 0);

            //FizzBuzz(month);
        }
        public static void TernOper(int number)
        {
            //int num;
            //if (number % 2 == 0)
            //{
            //    num = 1;
            //}
            //else
            //    num = 0;
            // условие ? выражение№1 : выражение№2;
            int num = number % 2 == 0 ? 1 : 0;
        }
        public static void WhatSeason(int numberMonth)
        {
            //if (numberMonth < 1 || numberMonth > 12)
            //{
            //    Console.WriteLine("введите номер месяца");
            //    return;
            //}

            //if (numberMonth == 1)
            //{
            //    Console.WriteLine("Январь");
            //}
            //else if (numberMonth == 2)
            //{
            //    Console.WriteLine("Февраль");
            //}
            //else if (numberMonth == 3)
            //{
            //    Console.WriteLine("Март");
            //}
            //else if (numberMonth == 4)
            //{
            //    Console.WriteLine("Апрель");
            //}
            //else if (numberMonth == 5)
            //{
            //    Console.WriteLine("Май");
            //}
            //else if (numberMonth == 6)
            //{
            //    Console.WriteLine("Июнь");
            //}
            //else if (numberMonth == 7)
            //{
            //    Console.WriteLine("Июль");
            //}
            //else if (numberMonth == 8)
            //{
            //    Console.WriteLine("Август");
            //}
            //else if (numberMonth == 9)
            //{
            //    Console.WriteLine("Сентябрь");
            //}
            //else if (numberMonth == 10)
            //{
            //    Console.WriteLine("Октябрь");
            //}
            //else if (numberMonth == 11)
            //{
            //    Console.WriteLine("Ноябрь");
            //}
            //else
            //{
            //    Console.WriteLine("Декабрь");
            //}

            switch (numberMonth)
            {
                case 12:
                case 1:
                case 2: Console.WriteLine("Зима"); break;
                case 3:
                case 4:
                case 5: Console.WriteLine("Весна"); break;
                case 6:
                case 7:
                case 8: Console.WriteLine("Лето"); break;
                case 9:
                case 10:
                case 11: Console.WriteLine("Осень"); break;
                default: Console.WriteLine("укажите номер месяца"); break;
            }
        }
        
        public static void FizzBuzz(int number)
        {
            if (number < 1 || number > 100)
            {
                Console.WriteLine("Введенное число находится вне диапазона");
                return;
            }
            for (int i = 1; i <= 100; i++)
            {
                //if (i % 3 == 0 && i % 5 == 0)
                //{
                //    Console.WriteLine("Fizz Buzz");
                //}
                if (i % 3 == 0)
                {
                    Console.Write("Fizz ");
                    if (i % 5 == 0)
                    {
                        Console.WriteLine("Buzz");
                    }
                    else
                        Console.WriteLine();
                }
                else if (i % 5 == 0)
                {
                    Console.WriteLine("Buzz");
                }
                else
                {
                    Console.WriteLine(i);
                }
            }
        }
    }
}
