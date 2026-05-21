using System;
using System.Collections.Generic;
using System.Text;

namespace Урок__9._Делегаты_и_события
{
    public delegate void ExamDelegate(string task);
    public class Student
    {
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public DateTime BirthDate { get; set; }
        public void Exam(string task)
        {
            Console.WriteLine($"Студент {LastName} {FirstName} выполняет {task}");
        }
    }
}
