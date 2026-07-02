using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Урок__4.Прокрутка__индикаторы
{
    public partial class Form1 : Form
    {
        public static string results;
        public static bool[] status = new bool[15];
        public Form1()
        {
            InitializeComponent();
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            MessageBox.Show("Упс!", "Тех. поддержки нет, бог поможет.", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void trackBarSalary_Scroll(object sender, EventArgs e)
        {
            labelSalary.Text = trackBarSalary.Value.ToString();
        }

        private void textBoxSurname_TextChanged(object sender, EventArgs e)
        {
            if (!status[0])
            {
                status[0] = true;
                progressBar1.PerformStep();
            }
        }
    }
}
