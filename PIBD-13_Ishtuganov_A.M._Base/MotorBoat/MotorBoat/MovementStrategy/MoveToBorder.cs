using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MotorBoat.MovementStrategy;
/// <summary>
/// Стратегия перемещения объекта к краю экрана
/// </summary>
public class MoveToBorder : AbstractStrategy
{
    protected override bool IsTargetDestinaion()
    {
        ObjectParameters? objParams = GetObjectParameters;
        if (objParams == null)
        {
            return false;
        }
        return objParams.RightBorder + GetStep() >= FieldWidth &&
            objParams.DownBorder + GetStep() >= FieldHeight;
    }

    protected override void MoveToTarget()
    {
        ObjectParameters? objParams = GetObjectParameters;
        if (objParams == null)
        {
            return;
        }

        int diffX = objParams.RightBorder - FieldWidth;
        if (Math.Abs(diffX) > GetStep())
        {
            MoveRight();
        }

        int diffY = objParams.DownBorder - FieldHeight;
        if (Math.Abs(diffY) > GetStep())
        {
            MoveDown();
        }
    }
}
