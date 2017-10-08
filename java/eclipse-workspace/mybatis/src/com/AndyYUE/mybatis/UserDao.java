package com.AndyYUE.mybatis;

import java.awt.List;

public interface UserDao {
	
//	1、	根据用户ID来查询用户信息；
	public student findUserById(String id);
//	2、	根据用户名称来模糊查询用户信息列表；
	public List findUsersByName(String Sname);
//	3、	添加用户； 
	public void insertUser(student stu);

}
