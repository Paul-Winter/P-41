using System;
using System.Collections.Generic;
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
    internal class Car : Vehicle
    {
        public int passagers;
        public override string ToString()
        {
            return $"{name}; {maxspeed}; {passagers};";
        }
        public Car() : base("Обычная машина", 100)
        {
            passagers = 4;
        }
    }
    internal class Tractor : Vehicle
    {
        public int maxWeight;
        public override string ToString()
        {
            return $"{name}; {maxspeed}; {maxWeight};";
        }
        public Tractor() : base("Обычный трактор", 30)
        {
           maxWeight = 15000;
        }
    }
    internal class Motocycle : Vehicle
    {
        public bool ifSidecar;
        public override string ToString()
        {
            return $"{name}; {maxspeed}; {ifSidecar};";
        }
        public Motocycle() : base("Обычный мотоцикл", 150)
        {
            ifSidecar = false;
        }
    }
}
