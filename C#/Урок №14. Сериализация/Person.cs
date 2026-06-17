using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Channels;

namespace Урок__14._Сериализация
{
    [Serializable]
    public class Person
    {
        public string Name { get; set; }
        public int Age { get; set; }
        private int id;

        [NonSerialized]
        const string Planet = "Earth";
        public Person() {}

        public Person(int ident)
        {
            id = ident;
        }
        public override string ToString()
        {
            return $"Name: {Name}, Age: {Age}, Id: {id}, Planet: {Planet}";
        }
    }
}
