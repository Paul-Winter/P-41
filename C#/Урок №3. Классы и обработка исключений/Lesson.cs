using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Урок__3._Классы_и_обработка_исключений
{
    //int num = 12;
    public class Lesson
    {
        public int number = 4;
        public static string name = "Классы";
        static void Main()
        {
            Console.WriteLine("Hello from Lesson class!");
        }
    }

    public class StudentClass
    {
        public string name;
        public int age;
        public StudentClass()
        {
            name = "John Doe";
            age = 4;
        }
    }
    public struct StudentStruct
    {
        public string name;
        public int age = 12;
        public StudentStruct()
        {
            name = "unknown";
            age = 12;
        }
    }
    public struct Point
    {
        public int x;
        public int y;
        public Point()
        {
            x = 0;
            y = 0;
        }
        public Point(int a)
        {
            x = a;
            y = a;
        }
        public Point(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
    }
}
