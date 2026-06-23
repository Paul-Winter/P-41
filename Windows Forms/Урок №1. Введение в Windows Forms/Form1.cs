using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Урок__1.Введение_в_Windows_Forms
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            DialogResult result = MessageBox.Show("Вы нажали на кнопку!",
                                                  "Это - диалоговое окно",
                                                  MessageBoxButtons.YesNoCancel,
                                                  MessageBoxIcon.Exclamation);
            if (result == DialogResult.Yes)
            {
                MessageBox.Show("Вы нажали кнопку 'YES'");
            }
            else if (result == DialogResult.No)
            {
                MessageBox.Show("Вы нажали кнопку 'NO'");
            }
            else if (result == DialogResult.Cancel)
            {
                this.Close();
            }
        }

        private void Form1_MouseEnter(object sender, EventArgs e)
        {
            label1.Text = "Мышь в окне";
        }

        private void Form1_MouseLeave(object sender, EventArgs e)
        {
            label1.Text = "";
            label2.Text = "";
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            label2.Text = e.X.ToString() + " : "+ e.Y.ToString();
        }
    }
}
