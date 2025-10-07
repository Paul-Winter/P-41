namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var library = new Library();
            List<LibraryItem> items = new List<LibraryItem> 
            {

            new Book("The history of public void", new DateTime(2025, 10, 7),
                new List<string> { "Kirill Totskikh", "Sergey Akobyan" }, "1276312"),
            new Magazine("The Fall of public void",
                new DateTime(2025, 10, 7), new List<string> { "Arseniy Grishin", "Nikita Shalnev" }, 112),
            new EResource("Revenge of Public Void", new DateTime(2025, 10, 7),
                new List<string> { "Kirill Totskikh", "Pavel Kordukov" }, "https://bs.com", true)
            };
            foreach (var item in items) 
            {
                library.AddItem(item);
            }

            //library.DisplayAllItems();

            library.SearchByAuthor("Pavel Kordukov");
            library.RemoveItem();

        }
    }
}
