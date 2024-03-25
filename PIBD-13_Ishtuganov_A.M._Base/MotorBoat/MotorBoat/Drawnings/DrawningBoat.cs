using MotorBoat.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MotorBoat.Drawnings
{
    public class DrawningBoat
    {
        /// <summary>
        /// Класс-сущность
        /// </summary>
        public EntityBoat? EntityBoat { get; protected set; }
        /// <summary>
        /// Ширина окна
        /// </summary>
        private int? _pictureWidth;
        /// <summary>
        /// Высота окна
        /// </summary>
        private int? _pictureHeight;
        /// <summary>
        /// Левая координата прорисовки лодки
        /// </summary>
        protected int? _startPosX;
        /// <summary>
        /// Верхняя кооридната прорисовки лодки
        /// </summary>
        protected int? _startPosY;
        /// <summary>
        /// Ширина прорисовки лодки
        /// </summary>
        private readonly int _drawningBoatWidth = 143;
        /// <summary>
        /// Высота прорисовки лодки
        /// </summary>
        private readonly int _drawningBoatHeight = 38;
        /// <summary>
        /// Координата Х объекта
        /// </summary>
        public int? GetPosX => _startPosX;
        /// <summary>
        /// Координата Y объекта
        /// </summary>
        public int? GetPosY => _startPosY;
        /// <summary>
        /// Ширина объекта
        /// </summary>
        public int GetWidth => _drawningBoatWidth;
        /// <summary>
        /// Высота объекта
        /// </summary>
        public int GetHeight => _drawningBoatHeight;
        /// <summary>
        /// Пустой конструктор
        /// </summary>
        private DrawningBoat()
        {
            _pictureWidth = null;
            _pictureHeight = null;
            _startPosX = null;
            _startPosY = null;
        }
        /// <summary>
        /// Конструктор
        /// </summary>
        /// <param name="speed">Скорость</param>
        /// <param name="weight">Вес</param>
        /// <param name="bodyColor">Основной цвет</param>
        public DrawningBoat(int speed, double weight, Color bodyColor) : this()
        {
            EntityBoat = new EntityBoat(speed, weight, bodyColor);
        }

        /// <summary>
        /// Конструктор для наследников
        /// </summary>
        /// <param name="drawningBoatWidth">Ширина прорисовки лодки</param>
        /// <param name="drawningBoatHeight">Высота прорисовки лодки</param>
        protected DrawningBoat(int drawningBoatWidth, int drawningBoatHeight) : this()
        {
            _drawningBoatWidth = drawningBoatWidth;
            _drawningBoatHeight = drawningBoatHeight;
        }
        /// <summary>
        /// Установка границ поля
        /// </summary>
        /// <param name="width">Ширина поля</param>
        /// <param name="height">Высота поля</param>
        /// <returns>true - границы заданы, false - проверка не пройдена, нельзя
        ///разместить объект в этих размерах</returns>
        public bool SetPictureSize(int width, int height)
        {
            if (width > _drawningBoatWidth && height > _drawningBoatHeight)
            {
                _pictureWidth = width;
                _pictureHeight = height;
                if (_startPosX != null && _startPosY != null)
                {
                    if (_startPosX.Value < 0)
                    {
                        _startPosX = 0;
                    }
                    if (_startPosY.Value < 0)
                    {
                        _startPosY = 0;
                    }
                    if (_startPosX.Value + _drawningBoatWidth > _pictureWidth)
                    {
                        _startPosX = _pictureWidth - _drawningBoatWidth;
                    }
                    if (_startPosY.Value + _drawningBoatHeight > _pictureHeight)
                    {
                        _startPosY = _pictureHeight - _drawningBoatHeight;
                    }
                }

                return true;
            }
            return false;
        }
        /// <summary>
        /// Установка позиции
        /// </summary>
        /// <param name="x">Координата X</param>
        /// <param name="y">Координата Y</param>

        public void SetPosition(int x, int y)
        {
            if (!_pictureHeight.HasValue || !_pictureWidth.HasValue)
            {
                return;
            }
            else
            {
                _startPosX = x;
                _startPosY = y;
                if (_startPosX.Value < 0) _startPosX = 0;
                if (_startPosY.Value < 0) _startPosY = 0;
                if (_startPosX.Value + _drawningBoatWidth > _pictureWidth)
                {
                    _startPosX = _pictureWidth - _drawningBoatWidth;
                }
                if (_startPosY.Value + _drawningBoatHeight > _pictureHeight)
                {
                    _startPosY = _pictureHeight - _drawningBoatHeight;
                }
            }

        }
        /// <summary>
        /// Изменение направления перемещения
        /// </summary>
        /// <param name="direction">Направление</param>
        /// <returns>true - перемещене выполнено, false - перемещение
        /// невозможно</returns>
        public bool MoveTransport(DirectionType direction)
        {
            if (EntityBoat == null || !_startPosX.HasValue || !_startPosY.HasValue)
            {
                return false;
            }
            switch (direction)
            {
                //влево
                case DirectionType.Left:
                    if (_startPosX.Value - EntityBoat.Step > 0)
                    {
                        _startPosX -= (int)EntityBoat.Step;
                    }
                    return true;
                //вверх
                case DirectionType.Up:
                    if (_startPosY.Value - EntityBoat.Step > 0)
                    {
                        _startPosY -= (int)EntityBoat.Step;
                    }
                    return true;
                //вправо
                case DirectionType.Right:
                    if (_startPosX.Value + _drawningBoatWidth + EntityBoat.Step < _pictureWidth)
                    {
                        _startPosX += (int)EntityBoat.Step;
                    }
                    return true;
                //вниз
                case DirectionType.Down:
                    if (_startPosY.Value + _drawningBoatHeight + EntityBoat.Step < _pictureHeight)
                    {
                        _startPosY += (int)EntityBoat.Step;
                    }
                    return true;
                default:
                    return false;
            }

        }
        /// <summary>
        /// Прорисовка объекта
        /// </summary>
        /// <param name="g"></param>
        public virtual void DrawTransport(Graphics g)
        {
            if (EntityBoat == null || !_startPosX.HasValue ||
            !_startPosY.HasValue)
            {
                return;
            }

            Pen pen = new(Color.Black);
            Brush brushBodyColor = new SolidBrush(EntityBoat.BodyColor);

            Point[] body =
            {
                new Point(_startPosX.Value, _startPosY.Value),
                new Point(_startPosX.Value + 100, _startPosY.Value),
                new Point(_startPosX.Value + 145, _startPosY.Value + 20),
                new Point(_startPosX.Value + 100, _startPosY.Value + 40),
                new Point(_startPosX.Value, _startPosY.Value + 40),
                new Point(_startPosX.Value, _startPosY.Value)
            };

            // корпус
            g.FillPolygon(brushBodyColor, body);
            g.DrawPolygon(pen, body);

            //боковина лодки
            g.DrawEllipse(pen, _startPosX.Value + 15, _startPosY.Value + 5, 30, 30);
            g.DrawEllipse(pen, _startPosX.Value + 60, _startPosY.Value + 5, 30, 30);
            g.DrawLine(pen, _startPosX.Value + 27, _startPosY.Value + 5, _startPosX.Value + 73, _startPosY.Value + 5);
            g.DrawLine(pen, _startPosX.Value + 27, _startPosY.Value + 35, _startPosX.Value + 73, _startPosY.Value + 35);
            g.FillRectangle(brushBodyColor, _startPosX.Value + 27, _startPosY.Value + 6, 50, 29);

        }

    }
}
