using System;
using System.Collections.Generic;
using System.Text;

namespace Урок__7._Интерфейсы
{
    public class IC : IA, IB
    {
        void Show()
        {

        }

        void IA.Show()
        {
            Show();
        }

        void IB.Show()
        {
            Show();
        }
    }
}
