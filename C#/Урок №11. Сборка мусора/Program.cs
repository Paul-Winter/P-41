namespace Урок__11._Сборка_мусора
{
    //  Garbage Collector
    internal class Program
    {
        static void Main(string[] args)
        {
            int a = 10;
            int b = new int();
            Console.WriteLine($"a = {a}");
            Console.WriteLine($"b = {b}");
            Example ex = new Example();
            Console.WriteLine($"ex.a = {ex.a}");
            Console.WriteLine($"ex.b = {ex.b}");
            ex.Dispose();

            Console.WriteLine("_________________________Демонстрация работы System.GC_________________________");
            Console.WriteLine($"Максимальное поколение: {GC.MaxGeneration}");
            GarbageHelper helper = new GarbageHelper();
            Console.WriteLine($"Поколение объекта: {GC.GetGeneration(helper)}");
            Console.WriteLine($"Занято памяти: {GC.GetTotalMemory(false)} байт");
            Console.WriteLine("Создаём мусор...");
            helper.MakeGarbage();
            Console.WriteLine($"Занято памяти: {GC.GetTotalMemory(false)} байт");
            Console.WriteLine("Вызываем сборщик мусора в 0 поколении");
            GC.Collect(0);
            Console.WriteLine($"Занято памяти: {GC.GetTotalMemory(false)} байт");
            Console.WriteLine($"Поколение объекта: {GC.GetGeneration(helper)}");
            Console.WriteLine("Вызываем сборщик мусора во всех поколениях");
            GC.Collect();
            Console.WriteLine($"Занято памяти: {GC.GetTotalMemory(false)} байт");
            Console.WriteLine($"Поколение объекта: {GC.GetGeneration(helper)}");
            Console.WriteLine("_________________________Демонстрация работы финализатора и IDisposable_________________________");

            DisposeExample test1 = new DisposeExample();
            try
            {
                test1.DoSomething();
            }
            finally
            {
                test1.Dispose();
            }

            using (DisposeExample test2 = new DisposeExample())
            {
                test2.DoSomething();
                test2.Dispose();
            }
        }
    }
    public class GarbageHelper : IDisposable
    {
        public class Person
        {
            string name;
            string surname;
            int age;
        }
        public void MakeGarbage()
        {
            for (int i = 0; i < 10000; i++)
            {
                Person p = new Person();
            }
        }

        public void Dispose()
        {
            Console.WriteLine("!!!Очистка ресурсов!!!");
        }
        //protected override void Finalize() { }
        //~GarbageHelper()
        //{

        //}
    }
    public class Example : IDisposable
    {
        public int a;
        public int b;

        public void Dispose()
        {
            Console.WriteLine("!!!Очистка ресурсов!!!");
        }
    }

    public class DisposeExample : IDisposable
    {
        private bool isDisposed = false;
        private void Cleaning(bool disposing)
        {
            if (!isDisposed)
            {
                if (disposing)
                {
                    Console.WriteLine("Освобождаются управляемые ресурсы");
                }
                Console.WriteLine("Освобождаются неуправляемые ресурсы");
            }
            isDisposed = true;
        }
        public void Dispose()
        {
            Cleaning(true);
            GC.SuppressFinalize(this);
        }
        public void DoSomething()
        {
            Console.WriteLine("Выполнение определённых операций");
        }
        public DisposeExample()
        {
            Console.WriteLine("Выделение памяти...\nИнициализация...");
        }
        ~DisposeExample()
        {
            Cleaning(false);
        }
    }
}
