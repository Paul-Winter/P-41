using System;
using System.Collections.Generic;
using System.Text;

namespace Урок__5._Наследование
{
    public partial class PublicParent
    {
        public PublicParent(int id, string name, string surname)
        {
            Console.WriteLine("Вызов конструктора Parent с тремя параметрами");
            this.id = id;
            this.name = name;
            this.surname = surname;
        }
        public PublicParent(string name, string surname) : this(0, name, surname)
        {
            Console.WriteLine("Вызов конструктора Parent с двумя параметрами");
        }
        public PublicParent(int id) : this(id, "unknown", "unknown")
        {
            Console.WriteLine("Вызов конструктора Parent с одним параметром");
        }
        public PublicParent() : this(0, "unknown", "unknown")
        {
            Console.WriteLine("Вызов конструктора Parent по умолчанию");
        }
        public void Print()
        {
            Console.WriteLine($"Работает метод Print класса Parent id = {id}");
        }
    }
}
