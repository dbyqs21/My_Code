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
		// 读取配置文件
		String result="SqlMapConfig.xml"; //全局配置文件的路径
		InputStream inputstream=Resources.getResourceAsStream(result);
		
		// 创建SqlSessionFactory
		SqlSessionFactory  sqlsessionfactory = new SqlSessionFactoryBuilder().build(inputstream);
		
		
		// 创建SqlSession
		SqlSession sqlsession = sqlsessionfactory.openSession();
		
		// 调用SqlSession的增删改查方法
		// 第一个参的表示statement：表示statement 的唯一标识
		
//		student stu = sqlsession.selectOne("test.findUserId", "200215121"); // 查询一条记录
//		System.out.println(stu);
		
//		List<student> list= sqlsession.selectList("test.findUserByName", "李%"); // 查询0到N条记录
//		System.out.println(list);
		
//		student stu = new student();
//		stu.setSno("201511051");
//		stu.setSsex("男");
//		stu.setSage(21);
//		stu.setSname("hanshu");
//		stu.setSdept("电子");
//		sqlsession.insert("test.insertIntoTable", stu); // 插入一条记录
//		sqlsession.commit();
		
//		sqlsession.update("test.updateTable", "张开");  //更新数据
//		sqlsession.commit();
		
//		sqlsession.delete("test.deleteRow", "0"); // 删除一条记录
//		sqlsession.commit();
		
		// 关闭资源
		sqlsession.close();
	}

}
