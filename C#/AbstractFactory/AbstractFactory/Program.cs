using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//道路
public abstract class Road
{

}

//建筑
public abstract class Building
{

}

//地道
public abstract class Tunnel
{

}

//丛林
public abstract class Jungle
{

}

abstract class FacilitiesFactory
{
    public abstract Road CreateRoad();
    public abstract Building CreateBuilding();
    public abstract Tunnel CreateTunnel();
    public abstract Jungle CreateJungle();



}

//客户程序
class GameManager
{
    FacilitiesFactory facilitiesFactory;
    Road road;
    Building building;
    Tunnel tunnel;

    public GameManager(FacilitiesFactory facilitiesFactory)
    {
        this.facilitiesFactory=facilitiesFactory;
    }
    public void BuildGameFactilities()
    {
        road = facilitiesFactory.CreateRoad();
        building = facilitiesFactory.CreateBuilding();
        tunnel = facilitiesFactory.CreateTunnel();
    }
    public void Play()
    {
        //使用具体的方法
        road.AAA();
        building.BBB(road);
        tunnel.CCC();

    }
}




namespace AbstractFactory
{
    class Program
    {
        static void Main(string[] args)
        {


        }
    }
}
