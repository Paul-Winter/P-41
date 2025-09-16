using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Channels;
using System.Threading.Tasks;

namespace FirstLesson
{
    
    internal class Person
    {
        int age;
        string name;
        int height;
        int weight;

        public Person(int age, string name, int height, int weight)
        {
            this.age = age;
            this.name = name;
            this.height = height;
            this.weight = weight;
        }
        public Person()
        {
            this.age = 20;
            this.name = "name";
            this.height = 170;
            this.weight = 70;
        }

        public void SayHello()
        {
            Console.WriteLine($"Hello,my name is {name}!");
        }

        public int SayAge()
        {
            return age;
        }

        public void SetAge(int a)
        {
            age = a;
            
        }
    }
}
