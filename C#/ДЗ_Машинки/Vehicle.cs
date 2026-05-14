using System;
using System.Collections.Generic;
using System.ComponentModel.Design;
using System.Text;

namespace ДЗ_Машинки
{
    internal abstract class Vehicle
    {
        protected string name;
        protected int maxspeed;
        public override string ToString()
        {
            return $"{name}; {maxspeed};";
        }
        protected Vehicle(string name, int maxspeed)
        {
            this.maxspeed = maxspeed;
            this.name = name;
        }
        protected Vehicle() : this("unknown", 0) {}
    }
    internal class Car : Vehicle, IDrive
    {
        public int passagers;
        public override string ToString()
        {
            return $"{name}; {maxspeed}; {passagers};";
        }

        public void Drive()
        {
            Console.WriteLine($"{name} едет по трассе со скоростью {maxspeed} км/ч");
        }

        public Car() : base("Обычная машина", 100)
        {
            passagers = 4;
        }
    }
    internal class Tractor : Vehicle, IDrive
    {
        public int maxWeight;
        public override string ToString()
        {
            return $"{name}; {maxspeed}; {maxWeight};";
        }

        public void Drive()
        {
            Console.WriteLine($"{name} перевозит груз весом {maxWeight} кг со скоростью {maxspeed}");
        }

        public Tractor() : base("Обычный трактор", 30)
        {
           maxWeight = 15000;
        }
    }
    internal class Motocycle : Vehicle, IDrive
    {
        public bool ifSidecar;
        public override string ToString()
        {
            return $"{name}; {maxspeed}; {ifSidecar};";
        }

        public void Drive()
        {
            if (ifSidecar)
            {
                Console.WriteLine($"{name} с коляской едет со скоростью {maxspeed}");
            }
            else
            {
                Console.WriteLine($"{name} едет со скоростью {maxspeed}");
            }
        }

        public Motocycle() : base("Обычный мотоцикл", 150)
        {
            ifSidecar = false;
        }
    }
}
