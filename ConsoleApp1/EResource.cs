using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class EResource :LibraryItem
    {
        private readonly string _url;
        private bool _connectionActive;

        public EResource(string title, DateTime publicationDate, List<string> authors, string url, bool connectionActive) :
            base(title, publicationDate, authors)
        {
            _url = url;
            _connectionActive = connectionActive;
        }

        public override void DisplayInfo()
        {
            Console.WriteLine($"Resourse name: {Title}, Publication date: {PublicationDate: yyyy-MM-dd}, URL: {_url}");
            Console.WriteLine("Written by " + string.Join(",", Authors));
        }

        public override void Dispose()
        {
            if (_connectionActive)
            {
                _connectionActive = false;
                Console.WriteLine($"Connection {_url} closed");
            }
            base.Dispose();
        }
    }
}
