using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;






public class RomanHouse : House
    {

    }

public  class RomanDoor:Door
{

}
public  class RomanWindows:Windows
{

}

public  class RomanFloor:Floor
{

}
public  class RomanWall:wall
{

}

public  class RomanHouseCelling:HouseCelling
{

}
public class RomanHouseBuilder : Builder
{
    public override void buildDoor()
    {
        //具体实现

    }
    public override void buildWall()
    {
        //具体实现
    }
    public override void buildWindows()
    {
        //具体实现
    }
    public override void buildFloor()
    {
        //具体实现
    }
    public override void buildHouseCelling()
    {
        //具体实现
    }

    public override House getHouse()
    {

        //具体实现
     
    }
}


