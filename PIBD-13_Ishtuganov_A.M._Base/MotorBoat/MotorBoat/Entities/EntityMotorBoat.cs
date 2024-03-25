namespace MotorBoat.Entities
{
    /// <summary>
    /// Класс-сущность "Моторная лодка"
    /// </summary>
    public class EntityMotorBoat : EntityBoat
    {
        /// <summary>
        /// Дополнительный цвет (для опциональных элементов)
        /// </summary>
        public Color AdditionalColor { get; private set; }
        /// <summary>
        /// Признак (опция) наличия защитного стекла
        /// </summary>
        public bool ProtectiveGlass { get; private set; }
        /// <summary>
        /// Признак (опция) наличия мотора
        /// </summary>
        public bool Engine { get; private set; }
        /// <summary>
        /// Шаг перемещения лодки
        /// </summary>
        public double Step => Speed * 100 / Weight;
        /// <summary>
        /// Инициализация полей объекта-класса моторной лодки
        /// </summary>
        /// <param name="speed">Скорость</param>
        /// <param name="weight">Вес лодки</param>
        /// <param name="bodyColor">Основной цвет</param>
        /// <param name="additionalColor">Дополнительный цвет</param>
        /// <param name="protectiveGlass">Признак наличия защитного стекла</param>
        /// <param name="engine">Признак наличия мотора</param>
        public EntityMotorBoat(int speed, double weight, Color bodyColor, Color additionalColor,
            bool protectiveGlass, bool engine) : base(speed, weight, bodyColor)
        {
            AdditionalColor = additionalColor;
            ProtectiveGlass = protectiveGlass;
            Engine = engine;
        }
    }
}
