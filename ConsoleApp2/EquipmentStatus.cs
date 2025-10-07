using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    internal class EquipmentStatus
    {
        public EquipmentStatus(string status,  double value)
        {
            Status = status;
            TimeStamp = DateTime.Now;
            Value = value;
        }

        public string Status { get; set; }
        public DateTime TimeStamp { get; set; }
        public double Value { get; set; }

        public override string ToString() 
        {
            return $"[{TimeStamp:yyyy-MM-dd HH:mm:ss}]";
        }
    }
}
