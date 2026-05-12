using System;
using System.Collections.Generic;
using System.Text;

namespace Урок__5._Наследование
{
    internal sealed class InternalParent
    {
        protected internal int id;
        protected string surname;
        public string name;
    }

    public partial class PublicParent
    {
        //private int id;
        protected internal int id;
        protected string surname;
        public string name;
    }
}
