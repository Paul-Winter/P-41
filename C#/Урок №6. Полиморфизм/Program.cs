using System.Net.Http.Headers;

namespace Урок__6._Полиморфизм
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Human human = new Human();
            Employee employee = new Employee(1, "John", "Doe", 1000.01d);
            Scientist scientist = new Scientist(2, "Ivan", "Ivanov", 1000000, "physics");
            Worker worker = new Worker(3, "Sidor", "Petrov", 500000, "most higher building");
            Manager manager = new Manager(4, "Makar", "Smirnov", 1234567, "CEO");

            Console.WriteLine("Обращаемся к каждому:");
            Console.WriteLine($"{employee}\n{scientist}\n{worker}\n{manager}");
            //employee.Print();
            //scientist.Print();
            //worker.Print();
            //manager.Print();
            Console.WriteLine();
            Employee[] employees = new Employee[]
            {
                employee,
                scientist,
                worker,
                manager
            };
            Console.WriteLine("Обращаемся как к работникам (Employee):");
            foreach (Employee emp in employees)
            {
                //emp.Print();
                Console.WriteLine(emp);
            }
            Console.WriteLine();
            Human[] humans = new Employee[]
            {
                employee,
                scientist,
                worker,
                manager
            };
            Console.WriteLine("Обращаемся как к людям (Human):");
            foreach (Human emp in humans)
            {
                //emp.Print();
                Console.WriteLine(emp);
            }
            Console.WriteLine();
        }
    }
    public abstract class Human
    {
        protected int id;
        protected string name;
        protected string surname;
        protected Human(int id, string name, string surname)
        {
            this.id = id;
            this.name = name;
            this.surname = surname;
        }
        public virtual void Print()
        {
            Console.WriteLine($"Human.Print {id}; {name}; {surname};");
        }
        public override string ToString()
        {
            return $"Human.Print {id}; {name}; {surname};";
        }
    }
    public class Employee : Human
    {
        protected double salary;
        public Employee(int id, string name, string surname, double salary) : base(id, name, surname)
        {
            this.salary = salary;
        }
        public override void Print()
        {
            Console.WriteLine($"Employee.Print {id}; {name}; {surname}; {salary}");
        }
        public override string ToString()
        {
            return $"Employee.Print {id}; {name}; {surname}; {salary}";
        }
    }
    public class Scientist : Employee
    {
        private string science;
        public Scientist(int id, string name, string surname, double salary, string science) :
            base(id, name, surname, salary)
        {
            this.science = science;
        }
        public override void Print()
        {
            Console.WriteLine($"Scientist.Print {id}; {name}; {surname}; {salary}; {science}");
        }
        public override string ToString()
        {
            return $"Scientist.Print {id}; {name}; {surname}; {salary}; {science}";
        }
    }
    public class Worker : Employee
    {
        private string project;
        public Worker(int id, string name, string surname, double salary, string project) :
            base(id, name, surname, salary)
        {
            this.project = project;
        }
        public override void Print()
        {
            Console.WriteLine($"Worker.Print {id}; {name}; {surname}; {salary}; {project}");
        }
        public override string ToString()
        {
            return $"Worker.Print {id}; {name}; {surname}; {salary}; {project}";
        }
    }
    public class Manager : Employee
    {
        private string department;
        public Manager(int id, string name, string surname, double salary, string department) :
            base(id, name, surname, salary)
        {
            this.department = department;
        }
        public void Print()
        {
            Console.WriteLine($"Scientist.Print {id}; {name}; {surname}; {salary}; {department}");
        }
        public override string ToString()
        {
            return $"Scientist.Print {id}; {name}; {surname}; {salary}; {department}";
        }
    }
}
