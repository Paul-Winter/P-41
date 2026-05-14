using System;
using System.Collections.Generic;
using System.Text;

namespace Урок__7._Интерфейсы
{
    internal interface IPerson
    {
        string Surname { get; set; }
        int Age { get; }
        string Gender { get; }
        string Name { set; }
    }
}
