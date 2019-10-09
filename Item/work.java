import java.util.Scanner;
import java.lang.Math;
public 	class work{
	public static void main(String[] args){
		for(int i=1;i<101;i++)
		{
			int count=0;
			for(int j=2;j<=Math.sqrt(i);j++)
			{
				if(i%j==0)
				{
					count=1;
				}
			}
			if(count==0)
			{
				System.out.println(i+"是素数");
			}else{
				System.out.println(i+"不是素数");
			}
		}
		
		
		/*//给定一个数判断是否是素数
		int count=0;
		Scanner in=new Scanner(System.in);
		int number=in.nextInt();
		for(int i=2;i<=Math.sqrt(number);i++)
		{
			if(number%i==0)
			{
				count=1;
			}
		}
		if(count==0)
			System.out.println(number+"是素数");
		else
			System.out.println(number+"不是素数");
		*/
		
		//根据年龄判断是什么年龄段
		/*Scanner in=new Scanner(System.in);
		int number=in.nextInt();
		if(number<18)
		{
			System.out.println("少年");
		}else{
			if(number<28)
			{
				System.out.println("青年");
			}else{
				if(number<55)
				{
					System.out.println("中年");
				}else{
					System.out.println("老年");
				}
			}
		}
		*/
		
		//给定三个int型变量，求最大值和最小值
		/*int a=10;
		int b=20;
		int c=30;
		System.out.println("最大值是"+((a>b)?a:((b>c)?b:c)));
		System.out.println("最小值是"+((a<b)?((a<c)?a:c):b));
		*/
		
		//给定两个int型变量，交换两个变量的值
		/*int a=10;
		int b=20;
		a=a^b;
		b=a^b;
		a=a^b;
		System.out.println("a="+a+"  b="+b);
		*/
	}
}