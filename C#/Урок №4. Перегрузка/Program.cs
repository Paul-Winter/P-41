using System.Net.Http.Headers;

namespace Урок__4._Перегрузка
{
    public class Program
    {
        static void Main(string[] args)
        {
            Point p1 = new Point(1, 3);
            Point p2 = new Point(2);
            Point p3 = new Point();

            Console.WriteLine(p1);
            Console.WriteLine(p2);
            Console.WriteLine(p3);

            Point pResult = -p2;
            Console.WriteLine(pResult);

            pResult = p1 + p1;
            Console.WriteLine(pResult);
            pResult = p2 - p1;
            Console.WriteLine(pResult);
            if (p1)
            {
                Console.WriteLine($"p1 is true");
                Console.WriteLine(p1);
            }
            if (p2)
            {
                Console.WriteLine($"p2 is true");
                Console.WriteLine(p2);
            }
            if (p3)
            {
                Console.WriteLine(p3);
            }
            else
            {
                Console.WriteLine($"p3 is false");
                Console.WriteLine(p3);
            }
            Console.WriteLine($"p1.x = {p1.GetX()}; p1.y = {p1.GetY()}");
            Console.WriteLine("Set p1.x = 42;\nSet p1.y = 12;");
            p1.SetX(42);
            p1.SetY(12);
            Console.WriteLine($"p1.x = {p1.GetX()}; p1.y = {p1.GetY()}");

            Point3D point1 = new Point3D(1, 2, 3);
            Console.WriteLine(point1);
            Console.WriteLine("Set point1.x = -1;\nSet point1.y = 22;\nSet point1.z = 33");
            point1.X = -1;
            point1.Y = 22;
            point1.Z = 33;
            Console.WriteLine(point1);
        }
    }
}
