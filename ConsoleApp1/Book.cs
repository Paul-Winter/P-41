using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Book : LibraryItem
    {
        public Book(string title, DateTime publicationDate, List<string> authors, string isbn)
            : base(title, publicationDate, authors)
        {
            ISBN = isbn;
        }

        public string ISBN { get; set; }

        public override void DisplayInfo()
        {
            Console.WriteLine($"Title: {Title}, Publication date: {PublicationDate: yyyy-MM-dd}, ISBN: {ISBN}");
            Console.WriteLine("Written by " + string.Join(",",Authors));
        }
    }
}
