using System;
using System.Collections.Generic;
using System.Text;

namespace Урок__9._Делегаты_и_события
{
    public class Dispatcher
    {
        public event AnonymousDelegateDouble eventDouble;
        public event AnonymousDelegateInt eventInt;
        public event AnonymousDelegateVoid eventVoid;

        public double OnEventDouble(double a, double b)
        {
            if (eventDouble != null)
            {
                return eventDouble(a, b);
            }
            throw new NullReferenceException();
        }
        public void OnEventInt(int i = 0)
        {
            if (eventInt != null)
            {
                eventInt(i);
            }
            throw new NullReferenceException();
        }
    }
}
