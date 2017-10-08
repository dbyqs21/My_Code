package com.AndyYUE.mybatis;

import java.awt.List;
import java.util.*;
import java.io.InputStream;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

public class UserDaoImple implements UserDao {

	// 依赖注入
	private SqlSessionFactory sqlsessionfactory;

	public UserDaoImple(SqlSessionFactory sqlsessionfactory) {
		this.sqlsessionfactory = sqlsessionfactory;
	}

	@Override
	public student findUserById(String id) {
		// 创建SqlSession
		SqlSession sqlsession = sqlsessionfactory.openSession();

		student stu = sqlsession.selectOne("test.findUserById", id);
		// 关闭资源
		sqlsession.close();
		return stu;
	}

	@Override
	public List findUsersByName(String Sname) {
		// TODO Auto-generated method stub
		// 创建SqlSession
		SqlSession sqlsession = sqlsessionfactory.openSession();

		java.util.List<student> stu = sqlsession.selectList("test.findUserByName", Sname);
		// 关闭资源
		sqlsession.close();
		return (List) stu;
	}

	@Override
	public void insertUser(student stu) {
		// TODO Auto-generated method stub
		// 创建SqlSession
		SqlSession sqlsession = sqlsessionfactory.openSession();
		sqlsession.insert("test.insertIntoTable", stu); // 插入一条记录
		sqlsession.commit();
	}
	
	

}
