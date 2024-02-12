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
            if (width > _drawningBoatWidth && height > _drawningBoatHeight)
            {
                _pictureWidth = width;
                _pictureHeight = height;
                return true;
            }
            return false;
        }

        public void SetPosition(int x, int y)
        {
            if (!_pictureHeight.HasValue || !_pictureWidth.HasValue)
            {
                return;
            }
            _startPosX = x;
            _startPosY = y;
            if (_startPosX.Value + _drawningBoatWidth > _pictureWidth)
            {
                _startPosX = _pictureWidth - _drawningBoatWidth;
            }
            if (_startPosY.Value + _drawningBoatHeight > _pictureHeight)
            {
                _startPosY = _pictureHeight - _drawningBoatHeight;
            }
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

            Pen pen = new(Color.Black, 3);
            Brush additionalBrush = new SolidBrush(EntityMotorBoat.AdditionalColor);

            if (EntityMotorBoat.BodyKit)
            {
                
            }

            if (EntityMotorBoat.SportLine)
            {
                
            }

        }

    }
}
