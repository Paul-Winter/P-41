using System;
using System.Collections.Generic;
using System.Text;

namespace Урок__7._Интерфейсы
{
    public class Welder : Employee, IWork
    {
        public void Work()
        {
            Console.WriteLine("Скрепляем металлоконструкцию");
        }
        public int CoffeeBreak()
        {
            return 15;
        }
        public int TimeToDinner(int startTime)
        {
            return startTime + 90;
        }
    }
}
