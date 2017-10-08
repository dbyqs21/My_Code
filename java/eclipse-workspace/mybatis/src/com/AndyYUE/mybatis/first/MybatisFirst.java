package com.AndyYUE.mybatis.first;

import java.io.IOException;
import java.io.InputStream;
import java.util.List;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.junit.Test;

import com.AndyYUE.mybatis.student;

public class MybatisFirst {
	@Test
	public void findeUserTest() throws IOException
	{
		// ��ȡ�����ļ�
		String result="SqlMapConfig.xml"; //ȫ�������ļ���·��
		InputStream inputstream=Resources.getResourceAsStream(result);
		
		// ����SqlSessionFactory
		SqlSessionFactory  sqlsessionfactory = new SqlSessionFactoryBuilder().build(inputstream);
		
		
		// ����SqlSession
		SqlSession sqlsession = sqlsessionfactory.openSession();
		
		// ����SqlSession����ɾ�Ĳ鷽��
		// ��һ���εı�ʾstatement����ʾstatement ��Ψһ��ʶ
		
//		student stu = sqlsession.selectOne("test.findUserId", "200215121"); // ��ѯһ����¼
//		System.out.println(stu);
		
//		List<student> list= sqlsession.selectList("test.findUserByName", "��%"); // ��ѯ0��N����¼
//		System.out.println(list);
		
//		student stu = new student();
//		stu.setSno("201511051");
//		stu.setSsex("��");
//		stu.setSage(21);
//		stu.setSname("hanshu");
//		stu.setSdept("����");
//		sqlsession.insert("test.insertIntoTable", stu); // ����һ����¼
//		sqlsession.commit();
		
//		sqlsession.update("test.updateTable", "�ſ�");  //��������
//		sqlsession.commit();
		
//		sqlsession.delete("test.deleteRow", "0"); // ɾ��һ����¼
//		sqlsession.commit();
		
		// �ر���Դ
		sqlsession.close();
	}

}
