using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public abstract class NormalActor
{
    public abstract NormalActor Clone();
}
public abstract class FlyActor
{
    public abstract FlyActor Clone();

}
public abstract class WaterActor
{
    public abstract WaterActor Clone();
    
}
class NormalActorA: NormalActor
{
    public override NormalActor Clone()
    {
        return (NormalActor)this.MemberwiseClone();
    }
}
class NormalActorB: NormalActor
{
    public override NormalActor Clone()
    {
        return (NormalActor)this.MemberwiseClone();
    }
}

class NormalActorC: NormalActor
{
    public override NormalActor Clone()
    {
        return (NormalActor)this.MemberwiseClone();
    }
}

class FlyActorA: FlyActor
{
    public override FlyActor Clone()
    {
        return (FlyActor)this.MemberwiseClone();
    }
}

class FlyActorB: FlyActor
{
    public override FlyActor Clone()
    {
        return (FlyActor)this.MemberwiseClone();
    }
}

class WaterActorA: WaterActor
{
    public override WaterActor Clone()
    {
        return (WaterActor)this.MemberwiseClone();
    }
}
class WaterActorB: WaterActor
{
    public override WaterActor Clone()
    {
        return (WaterActor)this.MemberwiseClone();
    }
}
public class GameSystem
{
    NormalActor normalactor;
    FlyActor flyactor;
    WaterActor wateractor;
    public static void  Run()
    {
        NormalActorA normalactor1 = normalactor.Clone();
        NormalActorB normalactor2 = normalactor.Clone();
        NormalActorC normalactor3 = normalactor.Clone();

        FlyActor flyactor1=flyactor.Clone();
        FlyActor flyactor2=flyactor.Clone();

        WaterActor wateractor1=wateractor.Clone();
        WaterActor wateractor2=wateractor.Clone();
        

    }
}



namespace Prototype
{
    class Program
    {
        static void Main(string[] args)
        {
        }
    }
}
