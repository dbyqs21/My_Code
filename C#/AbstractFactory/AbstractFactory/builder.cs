using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public abstract class  House
{

}

public abstract class Door
{

}
public abstract class Windows
{

}

public abstract class Floor
{

}
public abstract class wall
{

}

public abstract class HouseCelling
{

}

//接口部分(变化的部分，就是复杂对象的各个组成部分的系列是变化的)
public abstract class Builder
{
     public  abstract void buildDoor();
     public  abstract void buildWall();
     public  abstract void buildWindows();
     public  abstract void buildFloor();
     public  abstract void buildHouseCelling();

     public abstract House getHouse();
}

//最稳定的部分，不用发生变化（构建复杂对象的算法是稳定的）
public class GameManager
{
    public static House CreateHouse(Builder builder)
    {
        builder.buildDoor();
        builder.buildDoor(); //由于是抽象方法，所以调用不明却
        builder.buildWall();
        builder.buildWindows();

        return builder.getHouse(); //返回创建好的对象
    }
}
