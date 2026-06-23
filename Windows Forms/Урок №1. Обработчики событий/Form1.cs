using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Урок__1.Обработчики_событий
{
    public partial class Form1 : Form
    {
        Random random = new Random();
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("УРА!!!");
        }

        private void button2_MouseEnter(object sender, EventArgs e)
        {
            button2.Location = new Point(random.Next(0, this.Width - button2.Width),
                                         random.Next(0, this.Height - button2.Height));
        }
    }
}
