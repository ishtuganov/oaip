using MotorBoat.Drawnings;

namespace MotorBoat.MovementStrategy;
/// <summary>
/// Класс-реализация IMoveableObject с использованием DrawningBoat
/// </summary>
public class MoveableBoat : IMoveableObject
{
    /// <summary>
    /// Поле-объект класса DrawningBoat или его наследника
    /// </summary>
    private readonly DrawningBoat? _boat = null;
    /// <summary>
    /// Конструктор
    /// </summary>
    /// <param name="car">Объект класса DrawningBoat</param>
    public MoveableBoat(DrawningBoat boat)
    {
        _boat = boat;
    }
    public ObjectParameters? GetObjectPosition
    {
        get
        {
            if (_boat == null || _boat.EntityBoat == null ||
            !_boat.GetPosX.HasValue || !_boat.GetPosY.HasValue)
            {
                return null;
            }
            return new ObjectParameters(_boat.GetPosX.Value,
            _boat.GetPosY.Value, _boat.GetWidth, _boat.GetHeight);
        }
    }
    public int GetStep => (int)(_boat?.EntityBoat?.Step ?? 0);
    public bool TryMoveObject(MovementDirection direction)
    {
        if (_boat == null || _boat.EntityBoat == null)
        {
            return false;
        }
        return _boat.MoveTransport(GetDirectionType(direction));
    }
    /// <summary>
    /// Конвертация из MovementDirection в DirectionType
    /// </summary>
    /// <param name="direction">MovementDirection</param>
    /// <returns>DirectionType</returns>
    private static DirectionType GetDirectionType(MovementDirection direction)
    {
        return direction switch
        {
            MovementDirection.Left => DirectionType.Left,
            MovementDirection.Right => DirectionType.Right,
            MovementDirection.Up => DirectionType.Up,
            MovementDirection.Down => DirectionType.Down,
            _ => DirectionType.Unknow,
        };
    }
}
