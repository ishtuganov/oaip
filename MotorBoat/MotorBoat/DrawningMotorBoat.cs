using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MotorBoat
{
    public class DrawningMotorBoat
    {
        public EntityMotorBoat? EntityMotorBoat { get; private set; }

        private int? _pictureWidth;
        private int? _pictureHeight;
        private int? _startPosX;
        private int? _startPosY;
        private readonly int _drawningBoatWidth = 110;
        private readonly int _drawningBoatHeight = 60;
        public void Init(int speed, double weight, Color bodyColor, Color additionalColor,
            bool bodyKit, bool wing, bool sportLine)
        {
            EntityMotorBoat = new EntityMotorBoat();
            EntityMotorBoat.Init(speed, weight, bodyColor, additionalColor, bodyKit, wing, sportLine);
            _pictureWidth = null;
            _pictureHeight = null;
            _startPosX = null;
            _startPosY = null;
        }

        public bool SetPictureSize(int width, int height)
        {
            // TODO проверка, что объект "влезает" в размеры поля
            // если влезает, сохраняем границы и корректируем позицию объекта, если она была уже установлена
            /*if (width >= _drawningBoatWidth && height >= _drawningBoatHeight)
            {*/
            _pictureWidth = width;
            _pictureHeight = height;
            return true;
        }

        public void SetPosition(int x, int y)
        {
            if (!_pictureHeight.HasValue || !_pictureWidth.HasValue)
            {
                return;
            }
            // TODO если при установке объекта в эти координаты, он будет "выходить" за границы формы
            // то надо изменить координаты, чтобы он оставался в этих границах
            _startPosX = x;
            _startPosY = y;
            /*if (x + _drawningBoatWidth / 2 > _pictureWidth.Value)
                _startPosX = _pictureWidth.Value - _drawningBoatWidth / 2;
            if (x - _drawningBoatWidth / 2 < 0)
                _startPosX = 0 + _drawningBoatWidth / 2;
            if (y + _drawningBoatHeight  / 2 > _pictureHeight.Value)
                _startPosY = _pictureHeight.Value - _drawningBoatHeight / 2;
            if (y - _drawningBoatHeight / 2 < 0)
                _startPosY = 0 + _drawningBoatHeight / 2;*/
        }

        public bool MoveTransport(DirectionType direction)
        {
            if (EntityMotorBoat == null || !_startPosX.HasValue ||
            !_startPosY.HasValue)
            {
                return false;
            }
            switch (direction)
            {
                case DirectionType.Left:
                    if (_startPosX.Value - EntityMotorBoat.Step > 0)
                    {
                        _startPosX -= (int)EntityMotorBoat.Step;
                    }
                    return true;
                case DirectionType.Up:
                    if (_startPosY.Value - EntityMotorBoat.Step > 0)
                    {
                        _startPosY -= (int)EntityMotorBoat.Step;
                    }
                    return true;
                case DirectionType.Right:
                    if (_startPosX.Value + EntityMotorBoat.Step < _pictureWidth)
                    {
                        _startPosX += (int)EntityMotorBoat.Step;
                    }
                    return true;
                case DirectionType.Down:
                    if (_startPosY.Value + EntityMotorBoat.Step < _pictureHeight)
                    {
                        _startPosY += (int)EntityMotorBoat.Step;
                    }
                    return true;
                default:
                    return false;
            }
        }

        public void DrawTransport(Graphics g)
        {
            if (EntityMotorBoat == null || !_startPosX.HasValue ||
            !_startPosY.HasValue)
            {
                return;
            }

            Pen pen = new(Color.Black);
            Brush additionalBrush = new SolidBrush(EntityMotorBoat.AdditionalColor);

            if (EntityMotorBoat.BodyKit)
            {
                g.DrawEllipse(pen, _startPosX.Value + 90, _startPosY.Value,
                20, 20);
                g.DrawEllipse(pen, _startPosX.Value + 90, _startPosY.Value +
                40, 20, 20);
                g.DrawRectangle(pen, _startPosX.Value + 90, _startPosY.Value +
                10, 20, 40);
                g.DrawRectangle(pen, _startPosX.Value + 90, _startPosY.Value,
                15, 15);
                g.DrawRectangle(pen, _startPosX.Value + 90, _startPosY.Value +
                45, 15, 15);
                g.FillEllipse(additionalBrush, _startPosX.Value + 90,
                _startPosY.Value, 20, 20);
                g.FillEllipse(additionalBrush, _startPosX.Value + 90,
                _startPosY.Value + 40, 20, 20);
                g.FillRectangle(additionalBrush, _startPosX.Value + 90,
                _startPosY.Value + 10, 20, 40);
                g.FillRectangle(additionalBrush, _startPosX.Value + 90,
                _startPosY.Value + 1, 15, 15);
                g.FillRectangle(additionalBrush, _startPosX.Value + 90,
                _startPosY.Value + 45, 15, 15);
                g.DrawEllipse(pen, _startPosX.Value, _startPosY.Value, 20,
                20);
                g.DrawEllipse(pen, _startPosX.Value, _startPosY.Value + 40,
                20, 20);
                g.DrawRectangle(pen, _startPosX.Value, _startPosY.Value + 10,
                20, 40);
                g.DrawRectangle(pen, _startPosX.Value + 5, _startPosY.Value,
                14, 15);
                g.DrawRectangle(pen, _startPosX.Value + 5, _startPosY.Value +
                45, 14, 15);
                g.FillEllipse(additionalBrush, _startPosX.Value,
                _startPosY.Value, 20, 20);
                g.FillEllipse(additionalBrush, _startPosX.Value,
                _startPosY.Value + 40, 20, 20);
                g.FillRectangle(additionalBrush, _startPosX.Value + 1,
                _startPosY.Value + 10, 25, 40);
                g.FillRectangle(additionalBrush, _startPosX.Value + 5,
                _startPosY.Value + 1, 15, 15);
                g.FillRectangle(additionalBrush, _startPosX.Value + 5,
                _startPosY.Value + 45, 15, 15);
                g.DrawRectangle(pen, _startPosX.Value + 35, _startPosY.Value,
                39, 15);
                g.DrawRectangle(pen, _startPosX.Value + 35, _startPosY.Value +
                45, 39, 15);
                g.FillRectangle(additionalBrush, _startPosX.Value + 35,
                _startPosY.Value + 1, 40, 15);
                g.FillRectangle(additionalBrush, _startPosX.Value + 35,
                _startPosY.Value + 45, 40, 15);
            }
            //границы автомобиля
            g.DrawEllipse(pen, _startPosX.Value + 10, _startPosY.Value + 5, 20,
            20);
            g.DrawEllipse(pen, _startPosX.Value + 10, _startPosY.Value + 35, 20,
            20);
            g.DrawEllipse(pen, _startPosX.Value + 80, _startPosY.Value + 5, 20,
            20);
            g.DrawEllipse(pen, _startPosX.Value + 80, _startPosY.Value + 35, 20, 20);
            g.DrawRectangle(pen, _startPosX.Value + 9, _startPosY.Value + 15, 10,
            30);
            g.DrawRectangle(pen, _startPosX.Value + 90, _startPosY.Value + 15,
            10, 30);
            g.DrawRectangle(pen, _startPosX.Value + 20, _startPosY.Value + 4, 70,
            52);
            //задние фары
            Brush brRed = new SolidBrush(Color.Red);
            g.FillEllipse(brRed, _startPosX.Value + 10, _startPosY.Value + 5, 20,
            20);
            g.FillEllipse(brRed, _startPosX.Value + 10, _startPosY.Value + 35,
            20, 20);
            //передние фары
            Brush brYellow = new SolidBrush(Color.Yellow);
            g.FillEllipse(brYellow, _startPosX.Value + 80, _startPosY.Value + 5,
            20, 20);
            g.FillEllipse(brYellow, _startPosX.Value + 80, _startPosY.Value + 35,
            20, 20);
            //кузов
            Brush br = new SolidBrush(EntityMotorBoat.BodyColor);
            g.FillRectangle(br, _startPosX.Value + 10, _startPosY.Value + 15, 10,
            30);
            g.FillRectangle(br, _startPosX.Value + 90, _startPosY.Value + 15, 10,
            30);
            g.FillRectangle(br, _startPosX.Value + 20, _startPosY.Value + 5, 70,
            50);
            //стекла
            Brush brBlue = new SolidBrush(Color.LightBlue);
            g.FillRectangle(brBlue, _startPosX.Value + 70, _startPosY.Value + 10,
            5, 40);
            g.FillRectangle(brBlue, _startPosX.Value + 30, _startPosY.Value + 10,
            5, 40);
            g.FillRectangle(brBlue, _startPosX.Value + 35, _startPosY.Value + 8,
            35, 2);
            g.FillRectangle(brBlue, _startPosX.Value + 35, _startPosY.Value + 51,
            35, 2);
            //выделяем рамкой крышу
            g.DrawRectangle(pen, _startPosX.Value + 35, _startPosY.Value + 10,
            35, 40);
            g.DrawRectangle(pen, _startPosX.Value + 75, _startPosY.Value + 15,
            25, 30);
            g.DrawRectangle(pen, _startPosX.Value + 10, _startPosY.Value + 15,
            15, 30);
            // спортивная линия
            if (EntityMotorBoat.SportLine)
            {
                g.FillRectangle(additionalBrush, _startPosX.Value + 75,
                _startPosY.Value + 23, 25, 15);
                g.FillRectangle(additionalBrush, _startPosX.Value + 35,
                _startPosY.Value + 23, 35, 15);
                g.FillRectangle(additionalBrush, _startPosX.Value + 10,
                _startPosY.Value + 23, 20, 15);
            }
            // крыло
            if (EntityMotorBoat.Wing)
            {
                g.FillRectangle(additionalBrush, _startPosX.Value,
                _startPosY.Value + 5, 10, 50);
                g.DrawRectangle(pen, _startPosX.Value, _startPosY.Value + 5,
                10, 50);
            }

        }

    }
}
