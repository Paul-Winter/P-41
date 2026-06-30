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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void UpdateColor()
        {
            Color color = Color.FromArgb(this.trackBar1.Value, this.trackBar2.Value, this.trackBar3.Value);
            this.BackColor = color;
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            this.UpdateColor();
        }

        private void trackBar2_Scroll(object sender, EventArgs e)
        {
            this.UpdateColor();
        }

        private void trackBar3_Scroll(object sender, EventArgs e)
        {
            this.UpdateColor();
        }
    }
}
