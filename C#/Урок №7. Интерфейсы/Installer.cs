using System;
using System.Collections.Generic;
using System.Text;

namespace Урок__7._Интерфейсы
{
    public class Installer : Employee, IWork
    {
        public int CoffeeBreak()
        {
            return 5;
        }

        public int TimeToDinner(int startTime)
        {
            return startTime + 120;
        }

        public void Work()
        {
            Console.WriteLine("Производится сборка");
        }
    }
}
