package com.AndyYUE.mybatis.Test;

import static org.junit.Assert.*;

import java.io.InputStream;

import com.AndyYUE.mybatis.UserDao;
import com.AndyYUE.mybatis.UserDaoImple;
import com.AndyYUE.mybatis.UserMapper;
import com.AndyYUE.mybatis.student;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.junit.Before;
import org.junit.Test;

public class UserTaoTest {

	private SqlSessionFactory sqlsessionfactory;

	@Before
	public void SetUp() throws Exception {
		// ��ȡ�����ļ�
		String result = "SqlMapConfig.xml"; // ȫ�������ļ���·��
		InputStream inputstream = Resources.getResourceAsStream(result);

		// ����SqlSessionFactory
		sqlsessionfactory = new SqlSessionFactoryBuilder().build(inputstream);
	}

	@Test
	public void testFindUserById() {

		UserDao dao = new UserDaoImple(sqlsessionfactory);
		student stu = dao.findUserById("0");
		System.out.println(stu);
	}

	@Test
	public void testFindUsersByName() {
		fail("Not yet implemented");
	}

	@Test
	public void testInsertUser() {
		fail("Not yet implemented");
	}

}
