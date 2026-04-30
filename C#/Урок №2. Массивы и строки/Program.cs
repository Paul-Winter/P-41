using System.ComponentModel;

namespace Урок__2._Массивы_и_строки
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //  тип_элементов_массива [] имя_массива;
            int[] myArray;
            int[,] myArrSec;
            int[,,] myArrTer;
            string[] myStrings;
            //myArray = new int[10] { 1,2,3,4,5,6,7,8,9,10};
            myArray = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            Console.WriteLine("MyArray:");
            for (int i = 0; i < myArray.Length; i++)
            {
                Console.Write("i = " + i + "; value = " + myArray[i] + "\n");
            }
            bool myBool = true;
            int myInt = 1234;
            double myDouble = 12345.6789;
            string myString = "sdlkfjsdlk";
            Console.WriteLine(myBool);
            Console.WriteLine(myInt);
            Console.WriteLine(myDouble);
            Console.WriteLine(myString);
            string hello = "hello";
            string space = " ";
            string world = "world";
            string hw = hello + space + world + space + myDouble;
            Console.WriteLine(hw);
            Console.WriteLine("{0}{2}{1}", world, hello, space);
            Console.WriteLine($"My int value = {myInt};\nMy double value = {myDouble};\nMy bool value is {myBool}");
            Console.WriteLine("_______________________________________________________________________________");
            int a = 10;
            int b = 5;
            Console.WriteLine($"a = {a};\tb = {b};");
            Console.WriteLine($"Increment(a) = {Increment(a)}");
            Console.WriteLine($"Increment(b) = {Increment(b)}");
            a = Increment(a);
            b = Increment(b);
            Console.WriteLine($"a = {a};\tb = {b};");
            Console.WriteLine("Increment MyArray:");
            IncArray(myArray);
            for (int i = 0; i < myArray.Length; i++)
            {
                Console.Write("i = " + i + "; value = " + myArray[i] + "\n");
            }
            myArrSec = new int[,]
            {
                {11,12,13}, {14,15,16},
                {17,18,19}, {20,21,22},
                {11,12,13}, {14,15,16},
                {23,24,25}, {26,27,28}
            };
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    Console.Write(myArrSec[i,j] + " ");
                }
                Console.WriteLine();
            }

            Console.WriteLine($"MyArray.Length = {myArray.Length}");
            Console.WriteLine($"MyArrSec.LongLength = {myArrSec.LongLength}");
            Console.WriteLine($"MyArray.Max = {myArray.Max()}");
            Console.WriteLine($"MyArray.Min = {myArray.Min()}");
            Console.WriteLine($"MyArray.Average = {myArray.Average()}");
            Console.WriteLine("_______________________________________________________________________________");
            string str1 = "Первая строка";
            char[] charArr = { 'В', 'т', 'о', 'р', 'а', 'я', ' ', 'с', 'т', 'р', 'о', 'к', 'а' };
            string str2 = new string(charArr);
            string str3 = new string(charArr, 6, 6);
            string str4 = new string('@', 8);
            myStrings = new string[] { str1, str2, str3, str4};
            for (int i = 0; i < myStrings.Length; i++)
            {
                Console.WriteLine(myStrings[i]);
            }
            Console.WriteLine(str1.Replace('а','А'));
            string text = "The quick brown fox jumps over the lazy dog.";
            Console.WriteLine(text);
            myStrings = text.Split(' ');
            for (int i = 0; i < myStrings.Length; i++)
            {
                //Console.WriteLine(myStrings[i]);
            }
            for (int i = 0; i < args.Length; i++)
            {
                Console.WriteLine(args[i]);
            }
        }
        public static int Increment(int x)
        {
            return ++x;
        }
        public static void IncArray(int[] array)
        {
            for (int i = 0; i < array.Length; i++)
            {
                ++array[i];
            }
        }
    }
}
