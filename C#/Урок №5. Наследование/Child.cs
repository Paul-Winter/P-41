using System;
using System.Collections.Generic;
using System.Text;

namespace Урок__5._Наследование
{
    //internal class Child : InternalParent
    //internal class Child : PublicParent
    public class Child : Parent
    {
        public Child(int id) : base(id)
        {
            Console.WriteLine("Вызов конструктора Child с одним параметром");
        }
        public Child()
        {
            Console.WriteLine("Вызов конструктора Child по умолчанию");
        }
        public void Print()
        {
            Console.WriteLine($"Работает метод Print класса Child id = {id}");
        }
        public void ShowChild()
        {
            Print();
            base.Print();
            Console.WriteLine($"id: {id}; surname: {surname}; name: {name};");
            //Console.WriteLine($"id: {base.id}; surname: {base.surname}; name: {base.name};");
        }
    }
}
