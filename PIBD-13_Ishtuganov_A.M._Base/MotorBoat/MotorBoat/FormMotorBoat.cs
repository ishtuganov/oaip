using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MotorBoat.Drawnings;
using MotorBoat.MovementStrategy;

namespace MotorBoat
{
    /// <summary>
    /// Форма работы с объектом "Моторная лодка"
    /// </summary>
    public partial class FormMotorBoat : Form
    {
        /// <summary>
        /// Поле для прорисовки объекта
        /// </summary>
        private DrawningBoat? _drawningBoat;
        /// <summary>
        /// Стратегия перемещения
        /// </summary>
        private AbstractStrategy? _strategy;
        /// <summary>
        /// Получение объекта
        /// </summary>
        public DrawningBoat SetBoat
        {
            set
            {
                _drawningBoat = value; ;
                _drawningBoat.SetPictureSize(pictureBoxMotorBoat.Width, pictureBoxMotorBoat.Height);
                comboBoxStrategy.Enabled = true;
                _strategy = null;
                Draw();
            }
        }
        /// <summary>
        /// Конструктор формы
        /// </summary>
        public FormMotorBoat()
        {
            InitializeComponent();
            _strategy = null;
        }
        /// <summary>
        /// Метод прорисовки катера
        /// </summary>
        private void Draw()
        {
            if (_drawningBoat == null)
            {
                return;
            }
            Bitmap bmp = new(pictureBoxMotorBoat.Width,
            pictureBoxMotorBoat.Height);
            Graphics gr = Graphics.FromImage(bmp);
            _drawningBoat.DrawTransport(gr);
            pictureBoxMotorBoat.Image = bmp;
        }
        /// <summary>
        /// Перемещение объекта по форме (нажатие кнопок навигации)
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void ButtonMove_Click(object sender, EventArgs e)
        {
            if (_drawningBoat == null)
            {
                return;
            }
            string name = ((Button)sender)?.Name ?? string.Empty;
            bool result = false;
            switch (name)
            {
                case "buttonUp":
                    result =
                    _drawningBoat.MoveTransport(DirectionType.Up);
                    break;
                case "buttonDown":
                    result =
                    _drawningBoat.MoveTransport(DirectionType.Down);
                    break;
                case "buttonLeft":
                    result =
                    _drawningBoat.MoveTransport(DirectionType.Left);
                    break;
                case "buttonRight":
                    result =
                    _drawningBoat.MoveTransport(DirectionType.Right);
                    break;
            }
            if (result)
            {
                Draw();
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void buttonStrategyStep_Click(object sender, EventArgs e)
        {
            if (_drawningBoat == null)
            {
                return;
            }
            if (comboBoxStrategy.Enabled)
            {
                _strategy = comboBoxStrategy.SelectedIndex switch
                {
                    0 => new MoveToCenter(),
                    1 => new MoveToBorder(),
                    _ => null,
                };
                if (_strategy == null)
                {
                    return;
                }
                _strategy.SetData(new MoveableBoat(_drawningBoat),
                pictureBoxMotorBoat.Width, pictureBoxMotorBoat.Height);
            }
            if (_strategy == null)
            {
                return;
            }
            comboBoxStrategy.Enabled = false;
            _strategy.MakeStep();
            Draw();
            if (_strategy.GetStatus() == StrategyStatus.Finish)
            {
                comboBoxStrategy.Enabled = true;
                _strategy = null;
            }
        }

    }
}
