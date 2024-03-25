using MotorBoat.Drawnings;

namespace MotorBoat.CollectionGenericObjects;

/// <summary>
/// Реализация абстрактной компании - гавань
/// </summary>
public class Harbor : AbstractCompany
{
    /// <summary>
    /// Конструктор
    /// </summary>
    /// <param name="picWidth"></param>
    /// <param name="picHeight"></param>
    /// <param name="collection"></param>
    public Harbor(int picWidth, int picHeight, ICollectionGenericObjects<DrawningBoat> collection)
        : base(picWidth, picHeight, collection)
    {
    }

    protected override void DrawBackgound(Graphics g)
    {
        Pen pen = new Pen(Color.Black, 4f);
        for (int i = 0; i < _pictureHeight / _placeSizeHeight / 2; i++)
        {
            g.DrawLine(pen, 0, i * _placeSizeHeight * 2, _pictureWidth / _placeSizeWidth * _placeSizeWidth, i * _placeSizeHeight * 2);
            for (int j = 0; j < _pictureWidth / _placeSizeWidth + 1; ++j)
            {
                g.DrawLine(pen, j * _placeSizeWidth, i * _placeSizeHeight * 2, j * _placeSizeWidth, i * _placeSizeHeight * 2 + _placeSizeHeight);
            }
        }
    }
    protected override void SetObjectsPosition()
    {
        int nowWidth = 0;
        int nowHeight = 0;

        for (int i = 0; i < (_collection?.Count ?? 0); i++)
        {
            if (nowHeight > _pictureHeight / _placeSizeHeight)
            {
                return;
            }
            if (_collection?.Get(i) != null)
            {
                _collection?.Get(i)?.SetPictureSize(_pictureWidth, _pictureHeight);
                _collection?.Get(i)?.SetPosition(_placeSizeWidth * nowWidth + 30, nowHeight * _placeSizeHeight * 2 + 20);
            }

            if (nowWidth < _pictureWidth / _placeSizeWidth - 1) nowWidth++;
            else
            {
                nowWidth = 0;
                nowHeight++;
            }
        }
    }
}
