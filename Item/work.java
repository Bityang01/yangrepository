import java.util.Scanner;
import java.lang.Math;
public 	class work{
	public static void main(String[] args){
		double sum=0D;
		for(double i=1;i<101;i++)
		{
			if(i%2==0)
			{
				sum=sum+((-1)*(1/i));
			}else{
				sum=sum+(1/i);
			}
		}
		System.out.println(sum);
	
		
		
		//求两个数的最大公约数
		/*Scanner in=new Scanner(System.in);
		int number1=in.nextInt();
		int number2=in.nextInt();
		int numberMax=(number1>number2)?number1:number2;
		int numberMin=(number1>number2)?number2:number1;
		for(int i=numberMin;i>0;i--)
		{
			if((number1%i==0)&&(number2%i)==0)
			{
				System.out.println("最大公约数是"+i);
				break;
			}
		}
		*/
		
		//乘法口诀表
		/*for(int i=1;i<10;i++)
		{
			for(int j=1;j<=i;j++)
			{
				System.out.print(j+"*"+i+"="+i*j+"   ");
			}
			System.out.print("\n");
		}
		*/
		
		//1000到2000之间的闰年
		/*for(int year=1000;year<2001;year++)
		{
			if(((year%4==0)&&(year%100!=0))||(year%400==0))
			{
				System.out.println(year+"是闰年");
			}else{
				System.out.println(year+"不是闰年");
			}
		}
		*/
		
		//1-100之间的素数
		/*for(int i=1;i<101;i++)
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
		*/
		
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