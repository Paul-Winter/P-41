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
            
        }
    }
}
