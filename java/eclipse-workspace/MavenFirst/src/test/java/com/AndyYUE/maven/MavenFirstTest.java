package com.AndyYUE.maven;

import org.junit.Test;

import junit.framework.Assert;

public class MavenFirstTest {
	@Test
	public void sayHellowTest()
	{
		MavenFirst mf = new MavenFirst();
		String result=mf.sayHellow("zhangsan");
		Assert.assertEquals("hellow zhangsan", result);
	}

}
