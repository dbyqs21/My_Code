package com.AndyYUE.mybatis.Test;

import static org.junit.Assert.*;

import java.io.IOException;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

import com.AndyYUE.mybatis.UserMapper;
import com.AndyYUE.mybatis.UserQueryVO;
import com.AndyYUE.mybatis.student;
import com.AndyYUE.mybatis.PO.User;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.junit.Before;
import org.junit.Test;
import com.AndyYUE.mybatis.student;
public class UserMapperTest {

	@Before
	public void setUp() throws Exception {
	}

	@Test
	public void testFindUserById() throws Exception {
		// ����UserMapper����
		// ��ȡ�����ļ�
		String result = "SqlMapConfig.xml"; // ȫ�������ļ���·��
		InputStream inputstream = Resources.getResourceAsStream(result);

		// ����SqlSessionFactory
		SqlSessionFactory sqlsessionfactory = new SqlSessionFactoryBuilder().build(inputstream);

		// ����SqlSession
		SqlSession sqlsession = sqlsessionfactory.openSession();
		
		UserMapper usermapper = sqlsession.getMapper(UserMapper.class);
		
		
		User user = new User();
//		user.setSname("����");
//		user.setSsex("��");
		
		List<String> idList = new ArrayList<>();
		idList.add("200215121");
		idList.add("200215122");
		idList.add("200215123");
		
		
		UserQueryVO vo = new UserQueryVO(user);
		vo.setIdList(idList);
		
//		List<User> list = usermapper.findUserList(vo);
		int count = usermapper.findUserCount(vo);
//		student stu = usermapper.findUserById("200215121");
//		student stu2 = usermapper.findUserById("200215121");
		System.out.println(count);
		
		sqlsession.close();
				
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
