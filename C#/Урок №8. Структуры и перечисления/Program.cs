namespace Урок__8._Структуры_и_перечисления
{
    public class Program
    {
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
