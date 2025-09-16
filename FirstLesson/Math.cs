using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Metadata.Ecma335;
using System.Text;
using System.Threading.Tasks;

namespace FirstLesson
{
    internal class Math
    {
        int height;
        int width;
        public Math(int height,int wight)
        {
            this.height = height;
            this.width = wight;

        }
        public int Area()
        {
            return (height * width);
        }
        public void Areatri()
        {
            Console.WriteLine(height * width * 0.5);
        }
    }

}
