using System;
using System.Collections.Generic;
using System.Text;

namespace Урок__9._Делегаты_и_события
{
    public delegate double CalcDelegate(double a, double b);
    public class Calculator
    {
        // лямбда-выражения
        public double Sum(double a, double b) => a + b;
        public double Sub(double a, double b) => a - b;
        public double Mul(double a, double b) => a * b;
        public double Div(double a, double b) => b != 0 ? a / b : throw new DivideByZeroException();
    }
}
