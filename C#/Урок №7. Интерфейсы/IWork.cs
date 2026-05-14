using System;
using System.Collections.Generic;
using System.Text;

namespace Урок__7._Интерфейсы
{
    public interface IWork
    {
        void Work();
        int CoffeeBreak();
        int TimeToDinner(int startTime);
    }
}
