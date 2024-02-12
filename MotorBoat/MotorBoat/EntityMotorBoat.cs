namespace MotorBoat
{
    public class EntityMotorBoat
    {
        public int Speed {  get; private set; }
        public double Weight { get; private set; }
        public Color BodyColor { get; private set; }
        public Color AdditionalColor { get; private set; }
        public bool BodyKit { get; private set; }
        public bool Wing { get; private set; }
        public bool SportLine { get; private set; }
        public double Step => Speed * 100 / Weight;
        public void Init(int speed, double weight, Color bodyColor, Color additionalColor,
            bool bodyKit, bool wing, bool sportLine)
        {
            Speed = speed;
            Weight = weight;
            BodyColor = bodyColor;
            AdditionalColor = additionalColor;
            BodyKit = bodyKit;
            Wing = wing;
            SportLine = sportLine;
        }
    }
}
