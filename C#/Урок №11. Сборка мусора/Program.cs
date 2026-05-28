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
        }
    }
    public class GarbageHelper
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
    }
    public class Example
    {
        public int a;
        public int b;
    }
}
