using System;
using System.Collections.Generic;
using System.Text;

namespace Урок__4._Перегрузка
{
    public class Point3D
    {
        private int x;
        private int y;
        //private int z;

        public int X
        {
            get
            {
                return x;
            }
            set
            {
                if (value < 0)
                    x = 0;
                else if (value > 100)
                    x = 100;
                else
                    x = value;
            }
        }

        public int Y { get => y; set => y = value; }
        public int Z { get; set; }
        public Point3D(int x, int y, int z)
        {
            this.x = x;
            this.y = y;
            this.Z = z;
        }
        public override string ToString()
        {
            return $"{x};{y};{Z}";
        }
    }
}
