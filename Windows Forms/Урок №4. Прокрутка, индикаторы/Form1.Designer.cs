namespace Урок__4.Прокрутка__индикаторы
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.linkLabel1 = new System.Windows.Forms.LinkLabel();
            this.textBoxSurname = new System.Windows.Forms.TextBox();
            this.richTextBoxBio = new System.Windows.Forms.RichTextBox();
            this.buttonSend = new System.Windows.Forms.Button();
            this.radioButtonMale = new System.Windows.Forms.RadioButton();
            this.dateTimePickerBirthday = new System.Windows.Forms.DateTimePicker();
            this.checkBoxOffice = new System.Windows.Forms.CheckBox();
            this.monthCalendarStartWork = new System.Windows.Forms.MonthCalendar();
            this.numericUpDownHouse = new System.Windows.Forms.NumericUpDown();
            this.comboBoxVac = new System.Windows.Forms.ComboBox();
            this.trackBarSalary = new System.Windows.Forms.TrackBar();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.textBoxName = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.textBoxPatronic = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.radioButtonFemale = new System.Windows.Forms.RadioButton();
            this.label11 = new System.Windows.Forms.Label();
            this.checkBoxOnline = new System.Windows.Forms.CheckBox();
            this.checkBoxComm = new System.Windows.Forms.CheckBox();
            this.label12 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.labelSalary = new System.Windows.Forms.Label();
            this.label15 = new System.Windows.Forms.Label();
            this.textBoxDistr = new System.Windows.Forms.TextBox();
            this.label16 = new System.Windows.Forms.Label();
            this.textBoxStreet = new System.Windows.Forms.TextBox();
            this.label17 = new System.Windows.Forms.Label();
            this.textBoxCity = new System.Windows.Forms.TextBox();
            this.label18 = new System.Windows.Forms.Label();
            this.numericUpDownExp = new System.Windows.Forms.NumericUpDown();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownHouse)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarSalary)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownExp)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F);
            this.label1.Location = new System.Drawing.Point(238, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(356, 31);
            this.label1.TabIndex = 0;
            this.label1.Text = "Анкета о приеме на работу";
            // 
            // linkLabel1
            // 
            this.linkLabel1.AutoSize = true;
            this.linkLabel1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.linkLabel1.Location = new System.Drawing.Point(12, 15);
            this.linkLabel1.Name = "linkLabel1";
            this.linkLabel1.Size = new System.Drawing.Size(87, 20);
            this.linkLabel1.TabIndex = 1;
            this.linkLabel1.TabStop = true;
            this.linkLabel1.Text = "Поддерка";
            this.linkLabel1.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linkLabel1_LinkClicked);
            // 
            // textBoxSurname
            // 
            this.textBoxSurname.Location = new System.Drawing.Point(99, 46);
            this.textBoxSurname.Name = "textBoxSurname";
            this.textBoxSurname.Size = new System.Drawing.Size(232, 20);
            this.textBoxSurname.TabIndex = 2;
            this.textBoxSurname.TextChanged += new System.EventHandler(this.textBoxSurname_TextChanged);
            // 
            // richTextBoxBio
            // 
            this.richTextBoxBio.Location = new System.Drawing.Point(16, 146);
            this.richTextBoxBio.Name = "richTextBoxBio";
            this.richTextBoxBio.Size = new System.Drawing.Size(315, 357);
            this.richTextBoxBio.TabIndex = 3;
            this.richTextBoxBio.Text = "";
            // 
            // buttonSend
            // 
            this.buttonSend.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.buttonSend.Location = new System.Drawing.Point(601, 363);
            this.buttonSend.Name = "buttonSend";
            this.buttonSend.Size = new System.Drawing.Size(217, 43);
            this.buttonSend.TabIndex = 4;
            this.buttonSend.Text = "Отправить";
            this.buttonSend.UseVisualStyleBackColor = true;
            // 
            // radioButtonMale
            // 
            this.radioButtonMale.AutoSize = true;
            this.radioButtonMale.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.radioButtonMale.Location = new System.Drawing.Point(367, 242);
            this.radioButtonMale.Name = "radioButtonMale";
            this.radioButtonMale.Size = new System.Drawing.Size(92, 24);
            this.radioButtonMale.TabIndex = 5;
            this.radioButtonMale.TabStop = true;
            this.radioButtonMale.Text = "Мужской";
            this.radioButtonMale.UseVisualStyleBackColor = true;
            // 
            // dateTimePickerBirthday
            // 
            this.dateTimePickerBirthday.Location = new System.Drawing.Point(367, 71);
            this.dateTimePickerBirthday.Name = "dateTimePickerBirthday";
            this.dateTimePickerBirthday.Size = new System.Drawing.Size(164, 20);
            this.dateTimePickerBirthday.TabIndex = 6;
            // 
            // checkBoxOffice
            // 
            this.checkBoxOffice.AutoSize = true;
            this.checkBoxOffice.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.checkBoxOffice.Location = new System.Drawing.Point(367, 322);
            this.checkBoxOffice.Name = "checkBoxOffice";
            this.checkBoxOffice.Size = new System.Drawing.Size(72, 24);
            this.checkBoxOffice.TabIndex = 7;
            this.checkBoxOffice.Text = "Офис";
            this.checkBoxOffice.UseVisualStyleBackColor = true;
            // 
            // monthCalendarStartWork
            // 
            this.monthCalendarStartWork.Location = new System.Drawing.Point(621, 189);
            this.monthCalendarStartWork.Name = "monthCalendarStartWork";
            this.monthCalendarStartWork.TabIndex = 8;
            // 
            // numericUpDownHouse
            // 
            this.numericUpDownHouse.Location = new System.Drawing.Point(658, 131);
            this.numericUpDownHouse.Maximum = new decimal(new int[] {
            2000,
            0,
            0,
            0});
            this.numericUpDownHouse.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDownHouse.Name = "numericUpDownHouse";
            this.numericUpDownHouse.Size = new System.Drawing.Size(160, 20);
            this.numericUpDownHouse.TabIndex = 9;
            this.numericUpDownHouse.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // comboBoxVac
            // 
            this.comboBoxVac.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.comboBoxVac.FormattingEnabled = true;
            this.comboBoxVac.Items.AddRange(new object[] {
            "Администратор",
            "Менеджер",
            "Бухгалтер",
            "Senior Специалист",
            "Middle Специалист",
            "Junior Специалист"});
            this.comboBoxVac.Location = new System.Drawing.Point(367, 187);
            this.comboBoxVac.Name = "comboBoxVac";
            this.comboBoxVac.Size = new System.Drawing.Size(164, 28);
            this.comboBoxVac.TabIndex = 10;
            // 
            // trackBarSalary
            // 
            this.trackBarSalary.Location = new System.Drawing.Point(358, 458);
            this.trackBarSalary.Maximum = 1000;
            this.trackBarSalary.Minimum = 17;
            this.trackBarSalary.Name = "trackBarSalary";
            this.trackBarSalary.Size = new System.Drawing.Size(460, 45);
            this.trackBarSalary.TabIndex = 12;
            this.trackBarSalary.TickFrequency = 10;
            this.trackBarSalary.Value = 17;
            this.trackBarSalary.Scroll += new System.EventHandler(this.trackBarSalary_Scroll);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label2.Location = new System.Drawing.Point(12, 44);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(81, 20);
            this.label2.TabIndex = 14;
            this.label2.Text = "Фамилия";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label3.Location = new System.Drawing.Point(53, 69);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(40, 20);
            this.label3.TabIndex = 16;
            this.label3.Text = "Имя";
            // 
            // textBoxName
            // 
            this.textBoxName.Location = new System.Drawing.Point(99, 71);
            this.textBoxName.Name = "textBoxName";
            this.textBoxName.Size = new System.Drawing.Size(232, 20);
            this.textBoxName.TabIndex = 15;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label4.Location = new System.Drawing.Point(12, 95);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(83, 20);
            this.label4.TabIndex = 18;
            this.label4.Text = "Отчество";
            // 
            // textBoxPatronic
            // 
            this.textBoxPatronic.Location = new System.Drawing.Point(99, 97);
            this.textBoxPatronic.Name = "textBoxPatronic";
            this.textBoxPatronic.Size = new System.Drawing.Size(232, 20);
            this.textBoxPatronic.TabIndex = 17;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label5.Location = new System.Drawing.Point(95, 123);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(161, 20);
            this.label5.TabIndex = 19;
            this.label5.Text = "Краткая биография";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label6.Location = new System.Drawing.Point(379, 46);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(128, 20);
            this.label6.TabIndex = 20;
            this.label6.Text = "Дата рождения";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label7.Location = new System.Drawing.Point(623, 160);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(162, 20);
            this.label7.TabIndex = 21;
            this.label7.Text = "Когда хотите выйти";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label8.Location = new System.Drawing.Point(354, 103);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(189, 20);
            this.label8.TabIndex = 22;
            this.label8.Text = "Опыт работы в месяцах";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label9.Location = new System.Drawing.Point(407, 160);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(81, 20);
            this.label9.TabIndex = 23;
            this.label9.Text = "Вакансии";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label10.Location = new System.Drawing.Point(424, 219);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(40, 20);
            this.label10.TabIndex = 24;
            this.label10.Text = "Пол";
            // 
            // radioButtonFemale
            // 
            this.radioButtonFemale.AutoSize = true;
            this.radioButtonFemale.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.radioButtonFemale.Location = new System.Drawing.Point(367, 272);
            this.radioButtonFemale.Name = "radioButtonFemale";
            this.radioButtonFemale.Size = new System.Drawing.Size(92, 24);
            this.radioButtonFemale.TabIndex = 25;
            this.radioButtonFemale.TabStop = true;
            this.radioButtonFemale.Text = "Женский";
            this.radioButtonFemale.UseVisualStyleBackColor = true;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label11.Location = new System.Drawing.Point(379, 299);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(131, 20);
            this.label11.TabIndex = 26;
            this.label11.Text = "Формат работы";
            // 
            // checkBoxOnline
            // 
            this.checkBoxOnline.AutoSize = true;
            this.checkBoxOnline.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.checkBoxOnline.Location = new System.Drawing.Point(367, 352);
            this.checkBoxOnline.Name = "checkBoxOnline";
            this.checkBoxOnline.Size = new System.Drawing.Size(104, 24);
            this.checkBoxOnline.TabIndex = 27;
            this.checkBoxOnline.Text = "Удаленно";
            this.checkBoxOnline.UseVisualStyleBackColor = true;
            // 
            // checkBoxComm
            // 
            this.checkBoxComm.AutoSize = true;
            this.checkBoxComm.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.checkBoxComm.Location = new System.Drawing.Point(367, 382);
            this.checkBoxComm.Name = "checkBoxComm";
            this.checkBoxComm.Size = new System.Drawing.Size(140, 24);
            this.checkBoxComm.TabIndex = 28;
            this.checkBoxComm.Text = "Командировки";
            this.checkBoxComm.UseVisualStyleBackColor = true;
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label12.Location = new System.Drawing.Point(363, 421);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(184, 20);
            this.label12.TabIndex = 29;
            this.label12.Text = "Зарплатные ожидания";
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label13.Location = new System.Drawing.Point(706, 421);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(112, 20);
            this.label13.TabIndex = 30;
            this.label13.Text = "тысяч рублей";
            // 
            // labelSalary
            // 
            this.labelSalary.AutoSize = true;
            this.labelSalary.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.labelSalary.Location = new System.Drawing.Point(654, 421);
            this.labelSalary.Name = "labelSalary";
            this.labelSalary.Size = new System.Drawing.Size(27, 20);
            this.labelSalary.TabIndex = 31;
            this.labelSalary.Text = "17";
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label15.Location = new System.Drawing.Point(591, 52);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(52, 20);
            this.label15.TabIndex = 37;
            this.label15.Text = "Округ";
            // 
            // textBoxDistr
            // 
            this.textBoxDistr.Location = new System.Drawing.Point(658, 54);
            this.textBoxDistr.Name = "textBoxDistr";
            this.textBoxDistr.Size = new System.Drawing.Size(160, 20);
            this.textBoxDistr.TabIndex = 36;
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label16.Location = new System.Drawing.Point(587, 105);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(56, 20);
            this.label16.TabIndex = 35;
            this.label16.Text = "Улица";
            // 
            // textBoxStreet
            // 
            this.textBoxStreet.Location = new System.Drawing.Point(658, 105);
            this.textBoxStreet.Name = "textBoxStreet";
            this.textBoxStreet.Size = new System.Drawing.Size(160, 20);
            this.textBoxStreet.TabIndex = 34;
            // 
            // label17
            // 
            this.label17.AutoSize = true;
            this.label17.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label17.Location = new System.Drawing.Point(587, 78);
            this.label17.Name = "label17";
            this.label17.Size = new System.Drawing.Size(56, 20);
            this.label17.TabIndex = 33;
            this.label17.Text = "Город";
            // 
            // textBoxCity
            // 
            this.textBoxCity.Location = new System.Drawing.Point(658, 80);
            this.textBoxCity.Name = "textBoxCity";
            this.textBoxCity.Size = new System.Drawing.Size(160, 20);
            this.textBoxCity.TabIndex = 32;
            // 
            // label18
            // 
            this.label18.AutoSize = true;
            this.label18.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label18.Location = new System.Drawing.Point(597, 131);
            this.label18.Name = "label18";
            this.label18.Size = new System.Drawing.Size(41, 20);
            this.label18.TabIndex = 38;
            this.label18.Text = "Дом";
            // 
            // numericUpDownExp
            // 
            this.numericUpDownExp.Location = new System.Drawing.Point(358, 126);
            this.numericUpDownExp.Maximum = new decimal(new int[] {
            600,
            0,
            0,
            0});
            this.numericUpDownExp.Name = "numericUpDownExp";
            this.numericUpDownExp.Size = new System.Drawing.Size(185, 20);
            this.numericUpDownExp.TabIndex = 39;
            this.numericUpDownExp.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // progressBar1
            // 
            this.progressBar1.Location = new System.Drawing.Point(16, 509);
            this.progressBar1.Maximum = 15;
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(802, 23);
            this.progressBar1.Step = 1;
            this.progressBar1.TabIndex = 40;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(830, 538);
            this.Controls.Add(this.progressBar1);
            this.Controls.Add(this.numericUpDownExp);
            this.Controls.Add(this.label18);
            this.Controls.Add(this.label15);
            this.Controls.Add(this.textBoxDistr);
            this.Controls.Add(this.label16);
            this.Controls.Add(this.textBoxStreet);
            this.Controls.Add(this.label17);
            this.Controls.Add(this.textBoxCity);
            this.Controls.Add(this.labelSalary);
            this.Controls.Add(this.label13);
            this.Controls.Add(this.label12);
            this.Controls.Add(this.checkBoxComm);
            this.Controls.Add(this.checkBoxOnline);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.radioButtonFemale);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.textBoxPatronic);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.textBoxName);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.trackBarSalary);
            this.Controls.Add(this.comboBoxVac);
            this.Controls.Add(this.numericUpDownHouse);
            this.Controls.Add(this.monthCalendarStartWork);
            this.Controls.Add(this.checkBoxOffice);
            this.Controls.Add(this.dateTimePickerBirthday);
            this.Controls.Add(this.radioButtonMale);
            this.Controls.Add(this.buttonSend);
            this.Controls.Add(this.richTextBoxBio);
            this.Controls.Add(this.textBoxSurname);
            this.Controls.Add(this.linkLabel1);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Анкета";
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownHouse)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarSalary)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDownExp)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.LinkLabel linkLabel1;
        private System.Windows.Forms.TextBox textBoxSurname;
        private System.Windows.Forms.RichTextBox richTextBoxBio;
        private System.Windows.Forms.Button buttonSend;
        private System.Windows.Forms.RadioButton radioButtonMale;
        private System.Windows.Forms.DateTimePicker dateTimePickerBirthday;
        private System.Windows.Forms.CheckBox checkBoxOffice;
        private System.Windows.Forms.MonthCalendar monthCalendarStartWork;
        private System.Windows.Forms.NumericUpDown numericUpDownHouse;
        private System.Windows.Forms.ComboBox comboBoxVac;
        private System.Windows.Forms.TrackBar trackBarSalary;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBoxName;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox textBoxPatronic;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.RadioButton radioButtonFemale;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.CheckBox checkBoxOnline;
        private System.Windows.Forms.CheckBox checkBoxComm;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label labelSalary;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.TextBox textBoxDistr;
        private System.Windows.Forms.Label label16;
        private System.Windows.Forms.TextBox textBoxStreet;
        private System.Windows.Forms.Label label17;
        private System.Windows.Forms.TextBox textBoxCity;
        private System.Windows.Forms.Label label18;
        private System.Windows.Forms.NumericUpDown numericUpDownExp;
        private System.Windows.Forms.ProgressBar progressBar1;
    }
}

