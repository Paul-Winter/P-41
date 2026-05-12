using System;
using System.Collections.Generic;
using System.Text;

namespace Урок__5._Наследование
{
    public abstract class Parent
    {
        protected int id;
        protected string surname;
        protected string name;

        protected Parent(int id)
        {
            this.id = id;
        }
        protected Parent()
        {
            
        }
        internal void Print()
        {
            Console.WriteLine("Print from abstract Parent");
        }
    }
}
