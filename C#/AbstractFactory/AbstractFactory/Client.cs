using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class  App
{
    public static void main()
    {
        string assemblyName = ConfigurationSettings["builferAsse"];
        House hourse=GameManager.CreateHouse(new RomanHouseBuilder());
    }

}

class Client
{

}

