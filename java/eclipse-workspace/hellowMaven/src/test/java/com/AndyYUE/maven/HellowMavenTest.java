package com.AndyYUE.maven;

import org.junit.Test;
import static junit.framework.Assert.*;

public class HellowMavenTest
{
	@Test
	public void sayHellowTest()
	{
		HellowMaven hm = new HellowMaven();
		String result = hm.sayHellow("zhangsan");
		assertEquals("hellow zhangsan",result);
		
	}
}