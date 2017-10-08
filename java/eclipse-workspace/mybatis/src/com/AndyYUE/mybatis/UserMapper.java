package com.AndyYUE.mybatis;
import com.AndyYUE.mybatis.PO.User;
import java.util.List;

public interface UserMapper {
//	1、	根据用户ID来查询用户信息；
	public student findUserById(String id) throws Exception;
	
//	2、	根据用户名称来模糊查询用户信息列表；
	public List findUsersByName(String Sname)throws Exception;
	
//	3、	添加用户； 
	public void insertUser(student stu)throws Exception;
	
//	4、综合查询
	public List<User> findUserList(UserQueryVO vo) throws Exception;
	
//	5、综合查询记录总数
	public int findUserCount(UserQueryVO vo) throws Exception;

}
