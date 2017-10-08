package com.AndyYUE.maven;

public class MavenSecondTest {
	@Test
	public void sayHellowTest()
	{
		MavenSecond ms = new MavenSecond();
		String result=ms.sayHellow("zhangsan");
		Assert.assertEquals("hellow zhangsan", result);
	}

}


