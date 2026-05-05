using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassLibrary
{
    public class Calculator
    {
        public int Sum(int a, int b)
        {
            return a + b;
        }
        public int Sum(int a, int b, int c)
        {
            return a + b + c;
        }
        //public int Sum(double a, double b)
        //{
        //    return (int)(a + b);
        //}
        public double Sum(double a, double b)
        {
            return a + b;
        }
        public int Sub(int a, int b)
        {
            return a - b;
        }
        public int Mul(int a , int b)
        {
            return a * b;
        }
        public int Div(int a , int b)
        {
            if (b == 0)
            {
                throw new DivideByZeroException();
            }
            return a / b;
        }
    }
}
