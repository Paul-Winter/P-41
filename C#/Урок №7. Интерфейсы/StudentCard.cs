using System;
using System.Collections.Generic;
using System.Text;

namespace Урок__7._Интерфейсы
{
    public class StudentCard
    {
        public int Id { get; set; }
        public string Series { get; set; }
        public override string ToString()
        {
            return $"Студенческий билет №{Series}{Id}";
        }
    }
}
