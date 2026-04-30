namespace TestStrings
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string str = "Y";

            for (int i = 0; i < 1000000; i++)
            {
                str += "Y";
            }

            Console.WriteLine(str);
        }
    }
}
