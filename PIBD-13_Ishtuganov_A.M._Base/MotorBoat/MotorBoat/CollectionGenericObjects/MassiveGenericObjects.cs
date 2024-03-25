using MotorBoat.Drawnings;

namespace MotorBoat.CollectionGenericObjects;

/// <summary>
/// Параметризованный набор объектов
/// </summary>
/// <typeparam name="T">Параметр: ограничение - ссылочный тип</typeparam>
public class MassiveGenericObjects<T> : ICollectionGenericObjects<T>
    where T : class
{
    /// <summary>
    /// Массив объектов, которые храним
    /// </summary>
    private T?[] _collection;
    public int Count => _collection.Length;
    public int SetMaxCount { set { if (value > 0) { _collection = new T?[value]; } } }
    /// <summary>
    /// Конструктор
    /// </summary>
    public MassiveGenericObjects()
    {
        _collection = Array.Empty<T?>();
    }
    public T? Get(int position)
    {
        // TODO проверка позиции

        // return _collection[position];
        if (position <= Count)
        {
            return _collection[position];
        }
        else
            return null;
    }
    public int Insert(T obj)
    {
        // TODO вставка в свободное место набора

        // return false;

        for (int i = 0; i < Count; i++)
        {
            if (_collection[i] == null)
            {
                _collection[i] = obj;
                return i;
            }
        }
        return -1;
    }
    public int Insert(T obj, int position)
    {
        // TODO проверка позиции
        // TODO проверка, что элемент массива по этой позиции пустой, если нет, то
        // ищется свободное место после этой позиции и идет вставка туда
        // если нет после, ищем до
        // TODO вставка

        // return false;

        if (position < Count)
        {
            if (_collection[position] == null)
            {
                _collection[position] = obj;
                return position;
            }
            else
            {
                for (int i = 0; i < Count; i++)
                {
                    if (_collection[i] == null)
                    {
                        _collection[i] = obj;
                        return i;
                    }
                }
            }
        }
        return -1;
    }
    public T? Remove(int position)
    {
        // TODO проверка позиции
        // TODO удаление объекта из массива, присвоив элементу массива значение null

        // return true;
        if (position >= Count || position < 0) return null;
        T? myObject = _collection[position];
        _collection[position] = null;
        return myObject;
    }
}
