using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal abstract class LibraryItem : IComparable<LibraryItem>, IEnumerable<string>,IDisposable, IEquatable<LibraryItem>
    {
        protected LibraryItem(string title, DateTime publicationDate, List<string> authors)
        {
            Title = title;
            PublicationDate = publicationDate;
            Authors = authors;
            IsDisposed = false;
        }

        public string Title { get; set; }
        public DateTime PublicationDate { get; set; }
        protected List<string> Authors { get; set; }

        protected bool IsDisposed { get; set; }

        public int CompareTo(LibraryItem? other)
        {
            if(other == null) return 1;
            return PublicationDate.CompareTo(other.PublicationDate);
        }

        public virtual void Dispose()
        {

            if (!IsDisposed)
            {
                IsDisposed = true;
                Console.WriteLine($"Resourse {Title} disposed");
            }
        }

        public abstract void DisplayInfo();

        public IEnumerator<string> GetEnumerator()
        {
            return Authors.GetEnumerator();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }

        public bool Equals(LibraryItem? other)
        {
            if (other == null) return false;
            return Title.Equals(other.Title);
        }
    }
}
