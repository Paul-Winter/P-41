using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstLesson
{
    internal class Doge
    {
        string name;
        int age;
        string colour;
        string breed;
        bool isAlive;

        public Doge(string name, int age, string colour, string breed)
        {
            this.name = name;
            this.age = age;
            this.colour = colour;
            this.breed = breed;
            this.isAlive = true;
        }

        public string sayBreed()
        {
            return breed;
        }

        public void IsAlive()
        {
            if (isAlive)
            {
                Console.WriteLine("Bark Bark");
            }
            else
            {
                Console.WriteLine("F");
            }
        }

        public void Killer()
        {
            isAlive = false;
            Console.WriteLine($"RIP {name}");
        }
    }
}
