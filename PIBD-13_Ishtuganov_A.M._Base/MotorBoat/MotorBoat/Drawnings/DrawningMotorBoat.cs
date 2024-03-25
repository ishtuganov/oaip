using MotorBoat.Entities;

namespace MotorBoat.Drawnings
{
    /// <summary>
    /// Класс, отвечающий за прорисовку и перемещение объекта-сущности
    /// </summary>
    public class DrawningMotorBoat : DrawningBoat
    {
        /// <summary>
        /// Конструктор
        /// </summary>
        /// <param name="speed">Скорость</param>
        /// <param name="weight">Вес</param>
        /// <param name="bodyColor">Основной цвет</param>
        /// <param name="additionalColor">Дополнительный цвет</param>
        /// <param name="protectiveGlass">Признак наличия защитного стекла</param>
        /// <param name="engine">Признак наличия мотора</param>
        public DrawningMotorBoat(int speed, double weight, Color bodyColor, Color additionalColor,
            bool protectiveGlass, bool engine) : base(153, 75)
        {
            EntityBoat = new EntityMotorBoat(speed, weight, bodyColor, additionalColor, protectiveGlass, engine);
        }
        /// <summary>
        /// Прорисовка объекта
        /// </summary>
        /// <param name="g"></param>
        public override void DrawTransport(Graphics g)
        {
            if (EntityBoat == null || EntityBoat is not EntityMotorBoat motorBoat
                || !_startPosX.HasValue || !_startPosY.HasValue)
            {
                return;
            }
            Pen pen = new(Color.Black);
            Brush brushAdditionalColor = new SolidBrush(motorBoat.AdditionalColor);

            //защитное стекло спереди
            if (motorBoat.ProtectiveGlass)
            {
                Point[] glass =
                {
                    new Point(_startPosX.Value + 105, _startPosY.Value + 25),
                    new Point(_startPosX.Value + 100, _startPosY.Value),
                    new Point(_startPosX.Value + 90, _startPosY.Value),
                    new Point(_startPosX.Value + 90, _startPosY.Value + 25),
                    new Point(_startPosX.Value + 105, _startPosY.Value + 25)
                };
                g.FillPolygon(brushAdditionalColor, glass);
                g.DrawPolygon(pen, glass);
            }
            _startPosX += 10;
            _startPosY += 25;
            base.DrawTransport(g);
            _startPosX -= 10;
            _startPosY -= 25;
            //мотор
            if (motorBoat.Engine)
            {
                g.FillRectangle(brushAdditionalColor, _startPosX.Value, _startPosY.Value + 50, 10, 25);
                g.DrawRectangle(pen, _startPosX.Value, _startPosY.Value + 50, 10, 25);
            }
        }
    }
}
