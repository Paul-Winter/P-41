using System;
using System.Collections.Generic;
using System.Text;

namespace Урок__9._Делегаты_и_события
{
    public class Teacher
    {
        public event ExamDelegate examEvent;
        public void Exam(string task)
        {
            if (examEvent != null)
            {
                examEvent(task);
            }
        }
    }
}
