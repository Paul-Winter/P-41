using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Library
    {
        private readonly List<LibraryItem> _items;

        public Library()
        {
            _items = new List<LibraryItem>();
        }

        public void AddItem(LibraryItem item)
        {
            _items.Add(item);
        }

        public void RemoveItem()
        {
            _items.Remove(_items.Last());
        }

        public void ChangeItem(LibraryItem item, int index)
        {
            _items[index] = item;
        }

        public void SortByDate()
        {
            _items.Sort();
        }

        public void DisplayAllItems()
        {
            Console.WriteLine("\n Resourses list:");
            foreach (var item in _items)
            {
                item.DisplayInfo();
            }
        }

        public void SearchByAuthor(string author)
        {
            Console.WriteLine($"\n Searching by author");
            var results = _items.Where(item=>item.Any(a=>a.Equals(author, StringComparison.OrdinalIgnoreCase)));
            foreach (var item in results) 
            {
                item.DisplayInfo();
            }

        }

        public void DisposeAll()
        {
            foreach (var item in _items)
            {
                item.Dispose();
            }
        }
    }
}
