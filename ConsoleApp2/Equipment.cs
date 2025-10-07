using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    internal abstract class Equipment:IComparable<Equipment>,IEnumerable<KeyValuePair<string,double>>
    {
        protected string Name {  get; set; }
        protected int Priority { get; set;}
        protected Dictionary<string, double> Parameters { get; set; }
        protected bool IsRunning {  get; set; }

        private bool _isDisposed;

        private readonly List<IObserver<EquipmentStatus>> _observers;

        protected Equipment(string name, int priority)
        {
            Name = name;
            Priority = priority;
            Parameters = new Dictionary<string, double>();
            IsRunning = false;
            _isDisposed = false;
            _observers = new List<IObserver<EquipmentStatus>>();
        }

        public int CompareTo(Equipment? other)
        {
            if (other == null) return 1;
            return Priority.CompareTo(other.Priority);
        }

        public IEnumerator<KeyValuePair<string, double>> GetEnumerator()
        {
            return Parameters.GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }

        public abstract void Start();
        public abstract void Stop();
        public abstract void PerformOperation();
        public abstract void UpdateParameter(string key, double value);
    }
}
