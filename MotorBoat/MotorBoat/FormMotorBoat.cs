using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MotorBoat
{
    public partial class FormMotorBoat : Form
    {
        private DrawningMotorBoat? _drawningMotorBoat;
        /// <summary>
        /// Конструктор формы
        /// </summary>
        public FormMotorBoat()
        {
            InitializeComponent();
        }
        /// <summary>
        /// Метод прорисовки катера
        /// </summary>
        private void Draw()
        {
            if (_drawningMotorBoat == null)
            {
                return;
            }
            Bitmap bmp = new(pictureBoxMotorBoat.Width,
            pictureBoxMotorBoat.Height);
            Graphics gr = Graphics.FromImage(bmp);
            _drawningMotorBoat.DrawTransport(gr);
            pictureBoxMotorBoat.Image = bmp;
        }
        /// <summary>
        /// Обработка нажатия кнопки "Создать"
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void ButtonCreateMotorBoat_Click(object sender, EventArgs e)
        {
            Random random = new();
            _drawningMotorBoat = new DrawningMotorBoat();
        _drawningMotorBoat.Init(random.Next(100, 300), random.Next(1000,
        3000),
        Color.FromArgb(random.Next(0, 256), random.Next(0, 256),
        random.Next(0, 256)),
        Color.FromArgb(random.Next(0, 256), random.Next(0, 256),
        random.Next(0, 256)),
        Convert.ToBoolean(random.Next(0, 2)),
        Convert.ToBoolean(random.Next(0, 2)), Convert.ToBoolean(random.Next(0, 2)));
            _drawningMotorBoat.SetPictureSize(pictureBoxMotorBoat.Width,
            pictureBoxMotorBoat.Height);
            _drawningMotorBoat.SetPosition(random.Next(10, 100), random.Next(10,
            100));
            Draw();
        }
        /// <summary>
        /// Перемещение объекта по форме (нажатие кнопок навигации)
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void ButtonMove_Click(object sender, EventArgs e)
        {
            if (_drawningMotorBoat == null)
            {
                return;
            }
            string name = ((Button)sender)?.Name ?? string.Empty;
            bool result = false;
            switch (name)
            {
                case "buttonUp":
                    result =
                    _drawningMotorBoat.MoveTransport(DirectionType.Up);
                    break;
                case "buttonDown":
                    result =
                    _drawningMotorBoat.MoveTransport(DirectionType.Down);
                    break;
                case "buttonLeft":
                    result =
                    _drawningMotorBoat.MoveTransport(DirectionType.Left);
                    break;
                case "buttonRight":
                    result =
                    _drawningMotorBoat.MoveTransport(DirectionType.Right);
                    break;
            }
            if (result)
            {
                Draw();
            }
        }
    }
}
