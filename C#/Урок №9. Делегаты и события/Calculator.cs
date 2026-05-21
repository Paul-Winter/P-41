using System;
using System.Collections.Generic;
using System.Text;

namespace Урок__9._Делегаты_и_события
{
    public delegate double CalcDelegate(double a, double b);
    public class Calculator
    {
        public double Sum(double a, double b)
        {
            return a + b;
        }
        public double Sub(double a, double b)
        {
            return a - b;
        }
        public double Mul(double a, double b)
        {
            return a * b;
        }
        public double Div(double a, double b)
        {
            if (b != 0)
            {
                return a / b;
            }
            throw new DivideByZeroException();
        }
    }
}
