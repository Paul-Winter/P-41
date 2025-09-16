using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstLesson
{
    internal class Auto
    {
        int weight;
        string colour;
        string brand;
        int maxSpeed;
        

        public Auto(int weight, string colour, string brand, int maxSpeed)
        {
            this.weight = weight;
            this.colour = colour;
            this.brand = brand;
            this.maxSpeed = maxSpeed;
        }
        public string sayBrand()
        {
            return brand;
        }
        public int calculator(int gas)
        {
            return gas * maxSpeed;

        }
    }

}
