using System.Net.Http.Headers;

namespace Урок__7._Интерфейсы
{
    internal class Program
    {
        // модификатор_доступа interface IИмя_интерфейса {}
        static void Main(string[] args)
        {
            Human human;
            //human = new Human();

            Console.WriteLine("Вызываем каждого по очереди:");
            Builder builder = new Builder();
            Welder welder = new Welder();
            Installer installer = new Installer();
            builder.Work();
            welder.Work();
            installer.Work();

            Console.WriteLine("Вызываем всех работников:");
            IWork ibuilder = new Builder();
            IWork iwelder = new Welder();
            IWork iinstaller = new Installer();
            IWork[] workers = new IWork[]
            {
                ibuilder,
                iwelder,
                iinstaller
            };
            foreach (IWork worker in workers)
            {
                Console.WriteLine("___Начало_работы___");
                worker.Work();
                Console.WriteLine($"Перекур: {worker.CoffeeBreak()} минут");
                worker.Work();
                Console.WriteLine("___Обеденный_перерыв___");
                Console.WriteLine($"Кушаем до: {worker.TimeToDinner(200)} минут");
            }
            Console.WriteLine("____________________Студенты_в_аудитории:________________________________________");
            Auditory gray102 = new Auditory();
            foreach (Student student in gray102)
            {
                Console.WriteLine(student);
            }
            Console.WriteLine("____________________Сортируем_студентов_по_фамилии:________________________________________");
            gray102.Sort();
            foreach (Student student in gray102)
            {
                Console.WriteLine(student);
            }
            Console.WriteLine("____________________Копируем_студентов:________________________________________");
            Student st1 = new Student { Name = "John", Surname = "Doe", StudentCard = new StudentCard { Id = 123, Series = "AA" } };
            Console.WriteLine("копирование:");
            Console.WriteLine(st1);
            Student st2 = (Student)st1.Clone();
            Console.WriteLine(st2);
            st2.StudentCard.Id = 222;
            Console.WriteLine("изменение:");
            Console.WriteLine(st1);
            Console.WriteLine(st2);
        }
    }
}
