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
            MessageBox.Show("Тех. поддержки нет, бог поможет.", "Упс!", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void textBoxSurname_TextChanged(object sender, EventArgs e)
        {
            if (!status[0])
            {
                status[0] = true;
                progressBar1.PerformStep();
            }
            if (status[0])
            {
                if (textBoxSurname.Text =="")
                {
                    status[0] = false;
                    progressBar1.Value--;
                }
            }
        }

        private void textBoxName_TextChanged(object sender, EventArgs e)
        {
            if (!status[1])
            {
                status[1] = true;
                progressBar1.PerformStep();
            }
            if (status[1])
            {
                if (textBoxName.Text == "")
                {
                    status[1] = false;
                    progressBar1.Value--;
                }
            }
        }

        private void textBoxPatronic_TextChanged(object sender, EventArgs e)
        {
            if (!status[2])
            {
                status[2] = true;
                progressBar1.PerformStep();
            }
            if (status[2])
            {
                if (textBoxPatronic.Text == "")
                {
                    status[2] = false;
                    progressBar1.Value--;
                }
            }
        }

        private void richTextBoxBio_TextChanged(object sender, EventArgs e)
        {
            if (!status[3])
            {
                status[3] = true;
                progressBar1.PerformStep();
            }
            if (status[3])
            {
                if (richTextBoxBio.Text == "")
                {
                    status[3] = false;
                    progressBar1.Value--;
                }
            }
        }

        private void dateTimePickerBirthday_ValueChanged(object sender, EventArgs e)
        {
            if (!status[4])
            {
                status[4] = true;
                progressBar1.PerformStep();
            }
        }

        private void numericUpDownExp_ValueChanged(object sender, EventArgs e)
        {
            if (!status[5])
            {
                status[5] = true;
                progressBar1.PerformStep();
            }
        }

        private void comboBoxVac_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (!status[6])
            {
                status[6] = true;
                progressBar1.PerformStep();
            }
        }

        private void radioButtonMale_CheckedChanged(object sender, EventArgs e)
        {
            if (!status[7])
            {
                status[7] = true;
                progressBar1.PerformStep();
            }
        }

        private void radioButtonFemale_CheckedChanged(object sender, EventArgs e)
        {
            if (!status[7])
            {
                status[7] = true;
                progressBar1.PerformStep();
            }
        }

        private void checkBoxOffice_CheckedChanged(object sender, EventArgs e)
        {
            if (!status[8])
            {
                status[8] = true;
                progressBar1.PerformStep();
            }
        }

        private void checkBoxOnline_CheckedChanged(object sender, EventArgs e)
        {
            if (!status[8])
            {
                status[8] = true;
                progressBar1.PerformStep();
            }
        }

        private void checkBoxComm_CheckedChanged(object sender, EventArgs e)
        {
            if (!status[8])
            {
                status[8] = true;
                progressBar1.PerformStep();
            }
        }
        private void trackBarSalary_Scroll(object sender, EventArgs e)
        {
            if (!status[9])
            {
                status[9] = true;
                progressBar1.PerformStep();
            }
            labelSalary.Text = trackBarSalary.Value.ToString() + " тысяч рублей";
        }

        private void textBoxDistr_TextChanged(object sender, EventArgs e)
        {
            if (!status[9])
            {
                status[9] = true;
                progressBar1.PerformStep();
            }
            if (status[9])
            {
                if (textBoxDistr.Text == "")
                {
                    status[9] = false;
                    progressBar1.Value--;
                }
            }
        }

        private void textBoxCity_TextChanged(object sender, EventArgs e)
        {
            if (!status[10])
            {
                status[10] = true;
                progressBar1.PerformStep();
            }
            if (status[10])
            {
                if (textBoxCity.Text == "")
                {
                    status[10] = false;
                    progressBar1.Value--;
                }
            }
        }

        private void textBoxStreet_TextChanged(object sender, EventArgs e)
        {
            if (!status[11])
            {
                status[11] = true;
                progressBar1.PerformStep();
            }
            if (status[11])
            {
                if (textBoxStreet.Text == "")
                {
                    status[11] = false;
                    progressBar1.Value--;
                }
            }
        }

        private void numericUpDownHouse_ValueChanged(object sender, EventArgs e)
        {
            if (!status[12])
            {
                status[12] = true;
                progressBar1.PerformStep();
            }
        }

        private void monthCalendarStartWork_DateChanged(object sender, DateRangeEventArgs e)
        {
            if (!status[13])
            {
                status[13] = true;
                progressBar1.PerformStep();
            }
        }

        private void buttonSend_Click(object sender, EventArgs e)
        {
            if (progressBar1.Value == progressBar1.Maximum)
            {
                results += "Ф.И.О.: ";
                results += textBoxSurname.Text;
                results += " ";
                results += textBoxName.Text;
                results += " ";
                results += textBoxPatronic.Text;
                results += "\nПол: ";
                results += radioButtonMale.Checked ? "Мужчина\n" : "Женщина\n";
                results += ((int)((DateTime.Now - dateTimePickerBirthday.Value).TotalDays/365.25)).ToString();
                results += " лет\nДата рождения: ";
                results += dateTimePickerBirthday.Value.ToLongDateString();
                results += "\nАдрес проживания: ";
                results += textBoxDistr.Text;
                results += ", ";
                results += textBoxCity.Text;
                results += ", ";
                results += textBoxStreet.Text;
                results += ", ";
                results += numericUpDownHouse.Value.ToString();
                results += "\nВакансия: ";
                results += comboBoxVac.SelectedItem.ToString();
                results += "\nВарианты работы: ";
                results += checkBoxOffice.Checked ? "Офис " : "";
                results += checkBoxOnline.Checked ? "Онлайн " : "";
                results += checkBoxComm.Checked ? "Командировка " : "";
                results += "\nЖелаемая зарплата: ";
                results += labelSalary.Text;
                results += "\nГотов приступить: ";
                results += monthCalendarStartWork.SelectionRange.Start.ToLongDateString();
                results += " - ";
                results += monthCalendarStartWork.SelectionRange.End.ToLongDateString();
                results += "\n\nКраткая биография\n";
                results += richTextBoxBio.Text;
                results += "";
                DialogResult resultDia =MessageBox.Show("Проверьте анкету перед отправкой!\n" + results,"Отправляемая анкета",MessageBoxButtons.OKCancel,MessageBoxIcon.Information);
                if (resultDia == DialogResult.OK)
                {
                    MessageBox.Show("Анкета отправлена!", "Поздравляем!", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    this.Close();
                }
                else
                    results = "";
            }
            else
            {
                MessageBox.Show("Анкета заполнена не до конца!", "Еще рано!", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void labelSalary_Click(object sender, EventArgs e)
        {

        }
    }
}
