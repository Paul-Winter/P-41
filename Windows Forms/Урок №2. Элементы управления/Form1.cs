using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Урок__2.Элементы_управления
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            button2.Enabled = false;
            label2.Text = DateTime.Now.ToLongTimeString();
            timer2.Interval = 500;
            timer2.Start();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            timer1.Stop();
            button2.Enabled = false;
            MessageBox.Show("Таймер отработал!", "Таймер");
        }
        // обработчик старт
        private void button1_Click(object sender, EventArgs e)
        {
            if (numericUpDown1.Value <= 0)
            {
                MessageBox.Show("Количество секунд должно быть больше 0!", "Таймер");
                return;
            }
            button2.Enabled = true;
            timer1.Interval = Decimal.ToInt32(numericUpDown1.Value) * 1000;
            timer1.Start();
        }
        // обработчик стоп
        private void button2_Click(object sender, EventArgs e)
        {
            timer1.Stop();
            button2.Enabled = false;
            MessageBox.Show("Таймер не успел отработать!", "Таймер");
        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            label2.Text = DateTime.Now.ToLongTimeString();
        }
    }

    //DateTime - DateTime = TimeSpan
    //{
    //    int year;           1-9999
    //    int month;          1-12
    //    int day;            1-кол-во дней в месяце
    //    int hour;           0-23
    //    int minute;         0-59
    //    int second;         0-59
    //    int millisecond;    0-999
    //}
}
