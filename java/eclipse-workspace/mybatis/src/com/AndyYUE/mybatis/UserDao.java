package com.AndyYUE.mybatis;

import java.awt.List;

public interface UserDao {
	
//	1��	�����û�ID����ѯ�û���Ϣ��
	public student findUserById(String id);
//	2��	�����û�������ģ����ѯ�û���Ϣ�б�
	public List findUsersByName(String Sname);
//	3��	����û��� 
	public void insertUser(student stu);

}
