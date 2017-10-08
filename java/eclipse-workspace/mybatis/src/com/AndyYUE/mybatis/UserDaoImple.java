package com.AndyYUE.mybatis;

import java.awt.List;
import java.util.*;
import java.io.InputStream;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

public class UserDaoImple implements UserDao {

	// ����ע��
	private SqlSessionFactory sqlsessionfactory;

	public UserDaoImple(SqlSessionFactory sqlsessionfactory) {
		this.sqlsessionfactory = sqlsessionfactory;
	}

	@Override
	public student findUserById(String id) {
		// ����SqlSession
		SqlSession sqlsession = sqlsessionfactory.openSession();

		student stu = sqlsession.selectOne("test.findUserById", id);
		// �ر���Դ
		sqlsession.close();
		return stu;
	}

	@Override
	public List findUsersByName(String Sname) {
		// TODO Auto-generated method stub
		// ����SqlSession
		SqlSession sqlsession = sqlsessionfactory.openSession();

		java.util.List<student> stu = sqlsession.selectList("test.findUserByName", Sname);
		// �ر���Դ
		sqlsession.close();
		return (List) stu;
	}

	@Override
	public void insertUser(student stu) {
		// TODO Auto-generated method stub
		// ����SqlSession
		SqlSession sqlsession = sqlsessionfactory.openSession();
		sqlsession.insert("test.insertIntoTable", stu); // ����һ����¼
		sqlsession.commit();
	}
	
	

}
