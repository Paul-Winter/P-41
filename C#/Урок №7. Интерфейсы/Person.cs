using System;
using System.Collections.Generic;
using System.Text;

namespace Урок__7._Интерфейсы
{
    internal class Person : IPerson
    {
        public string Surname { get => throw new NotImplementedException(); set => throw new NotImplementedException(); }

        public int Age => throw new NotImplementedException();

        public string Gender => throw new NotImplementedException();

        public string Name { set => throw new NotImplementedException(); }
    }
}
