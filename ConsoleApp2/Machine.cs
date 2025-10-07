using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    internal class Machine : Equipment
    {
        public Machine(string name, int priority) : base(name, priority)
        {
            Parameters["Temperature"] = 20.0;
            Parameters["RPM"] = 0.0;
        }

        public override void PerformOperation()
        {
            if(IsRunning == true)
            {
                UpdateParameter("RPM", 10000.0);
                UpdateParameter("Temperature", 1000.0);
                Console.WriteLine($"{Name} has died");
                IsRunning = false;
            }
            else
            {
                Console.WriteLine($"{Name} isn't working!");
            }
            
        }

        public override void Start()
        {
            IsRunning = true;
            UpdateParameter("RPM", 1000.0);
            Console.WriteLine($"{Name} started!");
        }

        public override void Stop()
        {
            IsRunning= false;
            UpdateParameter("RPM", 0);
            Console.WriteLine($"{Name} stopped!");
        }

        public override void UpdateParameter(string key, double value)
        {
            if (Parameters.ContainsKey(key)) 
            {
                Parameters[key] = value;
            }
        }
    }
}
