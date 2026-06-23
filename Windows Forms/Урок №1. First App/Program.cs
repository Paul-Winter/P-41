using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Урок__1.First_App
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Form form1 = new Form();
            form1.Text = "First Windows Forms Application";
            form1.ShowDialog();
        }
    }
}
