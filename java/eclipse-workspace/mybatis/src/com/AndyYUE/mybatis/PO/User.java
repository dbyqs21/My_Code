package com.AndyYUE.mybatis.PO;

public class User {
	private String Sno;
	private String Sname;
	private String Ssex;
	private int Sage;
	private String Sdept;
	
	public void setSno(String Sno)
	{
		this.Sno = Sno;
	}
	
	public String getSno()
	{
		return Sno;
	}
	
	public void setSname(String Sname)
	{
		this.Sname = Sname;
	}
	
	public String getSname()
	{
		return Sname;
	}
	
	public void setSsex(String Ssex)
	{
		this.Ssex = Ssex;
	}
	
	public String getSsex()
	{
		return Ssex;
	}
	
	public void setSdept(String Sdept)
	{
		this.Sdept = Sdept;
	}
	
	public String getSdept()
	{
		return Sdept;
	}
	
	public void setSage(int Sage)
	{
		this.Sage = Sage;
	}
	
	public int getSage()
	{
		return Sage;
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return Sno+" "+Sname+" "+Ssex+" "+Sage+" "+Sdept;
	}

}
