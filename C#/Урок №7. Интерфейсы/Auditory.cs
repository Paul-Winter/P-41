using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace Урок__7._Интерфейсы
{
    public class Auditory : IEnumerable
    {
        Student[] students =
        {
            new Student
            {
                Name = "Анастасия Владимировна",
                Surname = "Дымочкина",
                StudentCard = new StudentCard {Id = 3333, Series = "BC"}
            },
            new Student
            {
                Name = "Эдуард Захарович",
                Surname = "Газарян",
                StudentCard = new StudentCard {Id = 2222, Series = "BB"}
            },
            new Student
            {
                Name = "Артём Романович",
                Surname = "Бочаров",
                StudentCard = new StudentCard {Id = 1111, Series = "AB"}
            },
            new Student
            {
                Name = "Илья Сергеевич",
                Surname = "Лобозев",
                StudentCard = new StudentCard {Id = 4444, Series = "CD"}
            }
        };

        public IEnumerator GetEnumerator()
        {
            return students.GetEnumerator();
        }

        public void Sort()
        {
            Array.Sort(students);
        }
    }
}
