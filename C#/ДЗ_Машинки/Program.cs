namespace ДЗ_Машинки
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello, World!");
            Vehicle[] vehicles = new Vehicle[] {
                new Car(),
                new Tractor(),
                new Motocycle() };
            foreach (Vehicle vehicle in vehicles)
            {
                Console.WriteLine(vehicle);
            }
            IDrive[] drives = new IDrive[] {
                new Car(),
                new Tractor(),
                new Motocycle() };
            foreach (IDrive drive in drives)
            {
                drive.Drive();
            }
        }
    }
}