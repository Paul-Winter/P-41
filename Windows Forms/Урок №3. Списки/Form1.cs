using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Урок__3.Списки
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            this.listBox1.Items.Add(textBox1.Text);
            this.textBox1.Text = "";
        }

        private void buttonDelete_Click(object sender, EventArgs e)
        {
            if (this.listBox1.Items.Count > 0)
            {
                if (this.listBox1.SelectedItems != null)
                {
                    for (int i = 0; i < this.listBox1.SelectedItems.Count; i++)
                    {
                        this.listBox1.Items.Remove(this.listBox1.SelectedItems[i]);
                    }
                }
            }
        }

        private void buttonFrom_Click(object sender, EventArgs e)
        {
            if (this.listBox1.Items.Count > 0)
            {
                if (this.listBox1.SelectedItems != null)
                {
                    for (int i = 0; i < this.listBox1.SelectedItems.Count; i++)
                    {
                        this.listBox2.Items.Add(this.listBox1.SelectedItems[i]);
                    }
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.listBox1.Items.Clear();
        }
    }
}
