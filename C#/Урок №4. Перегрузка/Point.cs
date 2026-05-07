using System;
using System.Collections.Generic;
using System.Text;

namespace Урок__4._Перегрузка
{
    public class Point
    {
        private int x;
        private int y;

        public Point(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
        public Point(int a): this(a, a) {}
        public Point(): this(0, 0) {}
        public void Show()
        {
            Console.WriteLine($"x = {x}; y = {y};");
        }
        //public static тип_возвращаемого_значения operator символ_операции(параметры) {}
        public static Point operator -(Point a)
        {
            return new Point(-a.x, -a.y);
        }
        public static Point operator -(Point a, Point b)
        {
            return new Point(a.x - b.x, a.y - b.y);
        }
        public static Point operator +(Point a, Point b)
        {
            return new Point(a.x + b.x, a.y + b.y);
        }
        public static bool operator ==(Point a, Point b)
        {
            return a.x == b.x && a.y == b.y;
        }
        public static bool operator !=(Point a, Point b)
        {
            return !(a == b);
        }
        public static bool operator true(Point a)
        {
            return a.x != 0 || a.y != 0 ? true : false;
        }
        public static bool operator false(Point a)
        {
            return a.x == 0 && a.y == 0 ? true : false;
        }
        public override string ToString()
        {
            return $"Point ({x};{y})";
        }
    }
}
