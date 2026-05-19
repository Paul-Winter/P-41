namespace Урок__8._Структуры_и_перечисления
{
    //модификатор_доступа enum Имя_перечисления { элемент1, элемент2, ..., элементN }
    public enum DayOfWeek
    {
        Monday = 1,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        Sunday
    }
    enum Vehicles
    {
        Bike = 500,
        Coupe = 1500,
        Refrigerator = 3500,
        Trailer = 2000,
        Truck = 5000,
        Tank = 12000
    }
    enum DistanceSun : ulong
    {
        Sun = 0,
        Mercury = 5790000,
        Venus = 108200000,
        Earth = 149600000,
        Mars = 227900000,
        Jupiter = 7783000000,
        Saturn = 1427000000,
        Uranus = 4496000000,
        Neptune = 5946000000
    }
    public class Program
    {
        public DayOfWeek NextDay(DayOfWeek today)
        {
            return (today < DayOfWeek.Sunday) ? ++today : DayOfWeek.Monday;
        }
        static void Main(string[] args)
        {
            ExampleClass ec = new ExampleClass(1.12d, 2.13d);
            ExampleStruct es = new ExampleStruct(2.21d, 3);
            Console.WriteLine($"ec: {ec}");
            Console.WriteLine($"es: {es}");

            es.Latitude += 12;
            es.Longitude -= 2;
            Console.WriteLine(es);

            ExampleClass first;
            ExampleStruct second;
            first = ec;
            second = es;
            Console.WriteLine($"first: {first}");
            Console.WriteLine($"second: {second}");

            first.Latitude -= 2;
            first.Longitude += 3;
            second.Latitude -= 12;
            second.Longitude += 11;

            Console.WriteLine($"ec: {ec}");
            Console.WriteLine($"es: {es}");
            Console.WriteLine($"first: {first}");
            Console.WriteLine($"second: {second}");

            //  boxing (упаковка)
            int a = 24;
            Console.WriteLine($"a = {a}; type {a.GetType()}");
            object obj = a;
            Console.WriteLine($"obj = {obj}; type {obj.GetType()}");

            //  unboxing (распаковка)
            int b = (int)obj;
            Console.WriteLine($"b = {b}; type {b.GetType()}");

            // nullable типы
            int? nullInt = 222;
            if (nullInt == null)
            {
                Console.WriteLine("nullInt is null!");
            }
            nullInt = nullInt ?? 100;
            Console.WriteLine($"nullInt = {nullInt}");
            string nullStr = null;
            if (String.IsNullOrEmpty(nullStr))
            {
                Console.WriteLine("nullStr is null or empty!");
            }

            // enumerations (перечисления)
            DayOfWeek today = DayOfWeek.Tuesday;
            Console.WriteLine($"Today is {today}, type {today.GetType()}");
            int tomorrow = (int)DayOfWeek.Wednesday;
            Console.WriteLine($"Tomorrow is {tomorrow}, type {tomorrow.GetType()}");

            while (true)
            {
                Console.WriteLine("Введите планету:\n" +
                    "0\t-\tСолнце\n" +
                    "1\t-\tМеркурий\n" +
                    "2\t-\tВенера\n" +
                    "3\t-\tЗемля\n" +
                    "4\t-\tМарс\n" +
                    "5\t-\tЮпитер\n" +
                    "6\t-\tСатурн\n" +
                    "7\t-\tУран\n" +
                    "8\t-\tНептун\n");
                int planet = Int32.Parse(Console.ReadLine());
                switch (planet)
                {
                    case 0: Console.WriteLine($"Sun: {(ulong)DistanceSun.Sun}"); break;
                    case 1: Console.WriteLine($"Mercury: {(ulong)DistanceSun.Mercury}"); break;
                    case 2: Console.WriteLine($"Venus: {(ulong)DistanceSun.Venus}"); break;
                    case 3: Console.WriteLine($"Earth: {(ulong)DistanceSun.Earth}"); break;
                    case 4: Console.WriteLine($"Mars: {(ulong)DistanceSun.Mars}"); break;
                    case 5: Console.WriteLine($"Jupiter: {(ulong)DistanceSun.Jupiter}"); break;
                    case 6: Console.WriteLine($"Saturn: {(ulong)DistanceSun.Saturn}"); break;
                    case 7: Console.WriteLine($"Uranus: {(ulong)DistanceSun.Uranus}"); break;
                    case 8: Console.WriteLine($"Neptune: {(ulong)DistanceSun.Neptune}"); break;
                    default:
                        Console.WriteLine("Планета отсутствует в Солнечной системе!");
                        return;
                }
            }
        }
    }

    //модификатор_доступа class Имя_класса
    public class ExampleClass
    {
        private double latitude;
        private double longitude;
        public ExampleStruct es;

        public double Latitude
        {
            get => latitude;
            set => latitude = value;
        }
        public double Longitude
        {
            get => longitude;
            set => longitude = value;
        }
        public struct Point
        {

        }

        public class SecondExample
        {

        }

        public ExampleClass(double lat, double lon)
        {
            this.Latitude = lat;
            this.Longitude = lon;
        }
        public ExampleClass() : this(0.0d, 0.0d) { }
        public override string ToString()
        {
            return $"Class:\nLatitude {latitude};\nLongitude {longitude};\n";
        }
    }

    //модификатор_доступа struct Имя_структуры
    public struct ExampleStruct
    {
        private double latitude;
        private double longitude;
        public ExampleClass firstExample;

        public double Latitude
        {
            get => latitude;
            set => latitude = value;
        }
        public double Longitude
        {
            get => longitude;
            set => longitude = value;
        }

        public ExampleStruct(double lat, double lon)
        {
            this.Latitude = lat;
            this.Longitude = lon;
        }
        public ExampleStruct() : this(0.0d, 0.0d) {}
        public override string ToString()
        {
            return $"Struct: ({latitude}; {longitude})\n";
        }
    }
}
