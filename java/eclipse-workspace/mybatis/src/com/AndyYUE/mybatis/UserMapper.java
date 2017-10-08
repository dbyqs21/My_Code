package com.AndyYUE.mybatis;
import com.AndyYUE.mybatis.PO.User;
import java.util.List;

public interface UserMapper {
//	1��	�����û�ID����ѯ�û���Ϣ��
	public student findUserById(String id) throws Exception;
	
//	2��	�����û�������ģ����ѯ�û���Ϣ�б�
	public List findUsersByName(String Sname)throws Exception;
	
//	3��	����û��� 
	public void insertUser(student stu)throws Exception;
	
//	4���ۺϲ�ѯ
	public List<User> findUserList(UserQueryVO vo) throws Exception;
	
//	5���ۺϲ�ѯ��¼����
	public int findUserCount(UserQueryVO vo) throws Exception;

}
