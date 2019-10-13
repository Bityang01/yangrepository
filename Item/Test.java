import java.util.Scanner;
public class Test{
	/*public static int add(int a,int b)
	{
		return a+b;
	}
	public static int add(int a,int b,int c)
	{
		return a+b+c;
	}
	public static double add(double a,double b)
	{
		return a+b;
	}
	public static int facSum(int num)
	{
		int sum=0;
		for(int i=1;i<=num;i++)
		{
			sum=sum+fac(i);
		}
		return sum;
	}
	public static int fac(int num)
	{
		int ret=1;
		for(int i=1;i<=num;i++)
		{
			ret=ret*i;
		}
		return ret;
	}	*/
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		System.out.println("输入姓名");
		String name=in.next();
		//String name=in.nextLine();
		System.out.println("姓名："+name);
		int age=in.nextInt();
		System.out.println("nianling"+age);
		
		
		/*System.out.println(facSum(5));
		
		System.out.println(add(10,20));
		System.out.println(add(10,20,30));
		System.out.println(add(10.2,20.2));
		int[] arr={10,20};
		arr[0]=arr[0]^arr[1];
		arr[1]=arr[0]^arr[1];
		arr[0]=arr[0]^arr[1];
		System.out.println(arr[0]);
		System.out.println(arr[1]);
		
		
		
		Scanner sc = new Scanner(System.in); 
		double sum = 0.0; 
		int num = 0; 
		while (sc.hasNextDouble()) { 
			 double tmp = sc.nextDouble(); 
			 sum += tmp; 
			 num++; 
		}
		System.out.println("sum = " + sum); 
		System.out.println("avg = " + sum / num); 
		sc.close();
		
		
		for(int i=0; ;i++)
		{
			System.out.println(i);
		}
		
		
		double num=1.0;
		System.out.println(Character.MAX_VALUE);
		System.out.println(Character.MIN_VALUE);
		int maxValue = Integer.MAX_VALUE;
		System.out.println(maxValue+1);
		System.out.println(Integer.MAX_VALUE);
		int num=5;
		int ret=0;
		int i=1;
		int sum=1;
		for(i=1;i<=num;i++)
		{
			sum=sum*i;
			ret=ret+sum;
		}
		System.out.println(sum);
		System.out.println(ret);
		
		
		
		double num=10L;
		float tmp=1;
		System.out.println(num);
		System.out.println(Integer.MAX_VALUE);
		System.out.println(Double.MAX_VALUE);
		System.out.println(Float.MAX_VALUE);*/
		//short s1=99;
		//char c1=s1;
		//boolean s1=ture;
		//System.out.println(s);
		//System.out.println(c1);
	}
}