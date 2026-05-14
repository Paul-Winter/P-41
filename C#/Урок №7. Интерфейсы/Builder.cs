using System;
using System.Collections.Generic;
using System.Text;

namespace Урок__7._Интерфейсы
{
    public class Builder : Employee, IWork
    {
        public int CoffeeBreak()
        {
            return 10;
        }

        public int TimeToDinner(int startTime)
        {
            return startTime + 60;
        }

        public void Work()
        {
            Console.WriteLine("Строим здание");
        }
    }
}
