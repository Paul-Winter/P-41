namespace FirstLesson
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Auto car = new Auto(2, "Green", "Lada", 110);
            
            
            Console.WriteLine(car.calculator(10));
        }
    }
}
