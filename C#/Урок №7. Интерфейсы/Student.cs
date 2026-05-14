using System;
using System.Collections.Generic;
using System.Text;

namespace Урок__7._Интерфейсы
{
    public class Student : IComparable, ICloneable
    {
        public string Name { get; set; }
        public string Surname { get; set; }
        public StudentCard StudentCard { get; set; }

        public object Clone()
        {
            //return this.MemberwiseClone();
            Student temp = (Student)this.MemberwiseClone();
            temp.StudentCard = new StudentCard
            {
                Id = this.StudentCard.Id,
                Series = this.StudentCard.Series
            };
            return temp;
        }

        public int CompareTo(object obj)
        {
            if (obj is Student)
            {
                return Surname.CompareTo((obj as Student).Surname);
            }
            throw new NotImplementedException();
        }

        //public int CompareTo(object? obj)
        //{
        //    return Surname.CompareTo(obj);
        //}

        public override string ToString()
        {
            return $"Студент {Surname} {Name}\n" + StudentCard.ToString();
        }
    }
}
