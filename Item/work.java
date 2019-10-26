/*import java.util.Scanner;
import java.lang.Math;
public 	class work{
	public static void main(String[] args){*/
		
		//输出一个整数的每一位
		/*Scanner in=new Scanner(System.in);
		int number=in.nextInt();
		while(number!=0)
		{
			System.out.println(number%10);
			number=number/10;
		}
		*/
		
		//二进制中 1 的个数
		/*int count=0;
		int[] arr;
		arr =new int[32];
		Scanner in=new Scanner(System.in);
		int number=in.nextInt();	
		for(int i=0;i<32;i++)
		{
			arr[i]=(number>>i)&1;
			if(arr[i]==1)
			{
				count++;
			}
		}
		System.out.println(count);
		*/
		
		//获取一个数二进制序列中所有的偶数位和奇数位
		/*int[] arr;
		arr =new int[32];
		Scanner in=new Scanner(System.in);
		int number=in.nextInt();	
		for(int i=0;i<32;i++)
		{
			arr[i]=(number>>i)&1;
		}
		for(int j=0;j<32;j++)
		{
			System.out.print(arr[j]);
			j++;
		}
		System.out.println(" ");
		for(int j=1;j<32;j++)
		{
			System.out.print(arr[j]);
			j++;
		}
		*/
		
		
		//模拟三次密码输入的场景
		/*int count=3;
		System.out.println("请设置3位数字密码");
		Scanner in=new Scanner(System.in);
		int passWord=in.nextInt();
		while(count!=0)
		{
			System.out.println("请输入3位数字密码");
			Scanner in1=new Scanner(System.in);
			int number=in.nextInt();
			if(number==passWord)
			{
				System.out.println("输入正确，登录成功");
				break;
			}
			count--;
		}
		*/
		
		
		//求出0～999之间的所有“水仙花数”并输出
		/*int[] arr={0};
		int tmp=0;
		for(int i=100;i<1000;i++)
		{
			tmp=i;
			double sum=0;
			//int count=0;
			while(tmp!=0)
			{
				//arr[count]=tmp%10;
				sum=sum+(tmp%10)*(tmp%10)*(tmp%10);
				//count++;
				tmp=tmp/10;
			}
			if(sum==i)
			{
				System.out.println(i);
			}
		}
		*/
		
		
		// 1到 100 的所有整数中出现多少个数字9
		/*int count=0;
		for(int i=1;i<101;i++)
		{
			if(i%10==9)
			{
				count++;
			}
			if(i/10==9)
			{
				count++;
			}
		}
		System.out.println(count);
		*/
		
		//计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值
		/*double sum=0D;
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
		*/
		
		
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
//	}
//}


//编写一个类Calculator,有两个属性num1,num2,这两个数据的值，不能在定义的同时初始化，最后实现加减乘除四种运算
/*class Calculator{
    public double num1;
    public double num2;
    public double add(double num1,double num2){
        return num1+num2;
    }
    public double Minus(double num1,double num2){
        return num1-num2;
    }

    public double Multiply(double num1,double num2){
        return num1*num2;
    }
    public double Divide(double num1,double num2){
        return num1/num2;
    }
}

public class Demo {
    public static void main(String[] args) {
        Calculator number=new Calculator();
        System.out.println(number.add(10,20));
        System.out.println(number.Minus(20,15));
        number.num1=10;
        number.num2=15;
        System.out.println(number.Multiply(number.num1,number.num2));
        System.out.println(number.Divide(20,4));
    }
}*/


//设计一个包含多个构造函数的类，并分别用这些构造函数来进行实例化对象。
/*class Person{
    public Person(){
        System.out.println("没有参数的构造函数！");
    }
    public Person(String str){
        System.out.println("有一个参数的构造函数！参数是："+str);
    }
    public Person(int num,String str){
        System.out.println("有两个参数的构造函数！参数是："+num+"和"+str);
    }
    public Person(int ...personAge){
        for (int age:personAge) {
            System.out.println("年龄是"+age);
        }
    }
}
public class Demo{
    public static void main(String[] args) {
        Person per=new Person();
        Person per1=new Person("博哥");
        Person per2=new Person(18,"博哥");
        Person per3=new Person(10,20,300,405,69);

    }
}*/


//实现交换两个变量的值。要求：需要交换实参的值。
public class Demo{
    public static void swap(int[] array){
        array[0]=array[0]^array[1];
        array[1]=array[0]^array[1];
        array[0]=array[0]^array[1];
    }
    public static void main(String[] args) {
        int[] arr={10,20};
        System.out.println("交换之前的数arr[0] "+arr[0]+"和arr[1] "+arr[1]);
        swap(arr);
        System.out.println("交换之后的数arr[0] "+arr[0]+"和arr[1] "+arr[1]);
    }
}
