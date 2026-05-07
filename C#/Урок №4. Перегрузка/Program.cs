namespace Урок__4._Перегрузка
{
    public class Program
    {
        static void Main(string[] args)
        {
            Point p1 = new Point(1, 3);
            Point p2 = new Point(2);
            Point p3 = new Point();

            p1.Show();
            p2.Show();
            p3.Show();

            Point pResult = -p2;
            pResult.Show();

            pResult = p1 + p1;
            pResult.Show();
            pResult = p2 - p1;
            pResult.Show();
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

        }
    }
}
