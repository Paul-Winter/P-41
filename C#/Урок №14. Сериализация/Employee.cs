using System;
using System.Collections.Generic;
using System.Text;

namespace Урок__14._Сериализация
{
    [AttributeUsage(AttributeTargets.Method | AttributeTargets.Class)]
    public class CoderAttribute : Attribute
    {
        string name = "Paul";
        DateTime date = DateTime.Now;
        public CoderAttribute() {}
        public CoderAttribute(string name, string date)
        {
            try
            {
                this.name = name;
                this.date = Convert.ToDateTime(date);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
        public override string ToString()
        {
            return $"Coder: {name}, Date: {date}";
        }
    }
    [Coder]
    public class Employee
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public double Salary { get; set; }

        [Coder("John Doe", "2026-6-11")]
        public void IncreaseWage(double wage)
        {
            Salary += wage;
        }
    }
}
