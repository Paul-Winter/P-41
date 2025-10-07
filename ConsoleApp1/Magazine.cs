using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Magazine : LibraryItem
    {
        public Magazine(string title, DateTime publicationDate, List<string> authors, int issueNum) 
            : base(title, publicationDate, authors)
        {
            IssueNumber = issueNum;
        }

        public int IssueNumber { get; set; }

        public override void DisplayInfo()
        {
            Console.WriteLine($"Title: {Title}, Publication date: {PublicationDate: yyyy-MM-dd}, Issue number: {IssueNumber}");
            Console.WriteLine("Written by " + string.Join(",", Authors));
        }
    }
}
