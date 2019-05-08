#include<iostream>
using namespace std;
int main()
{
	cout<<"This is a c++ program.\n";
	return 0;
 }
 int main()
 {
 	int a,b,sum;
 	cin>>a>>b;
 	sum=a+b;
 	cout<<"a+b="<<sum<<endl;
 	return 0;
  }
  {
  	int max(int x,int y);
  	int a,b,c;
  	cin>>a>>b;
  	c=max(a,b);
  	cout<<"max="<<c<<endl;
  	return 0;
   } 
   int max(int x,int y)
   {
   	int z;
   	if(x>y)z=y;
   	else z=x;
   	return (z);
   }
   class Student
   {
   	private:
   		int num;
   		int score;
   	public:
   		void setdata()
   		{cin>>num;
   		 cin>>score;
		   }
	void display()
	{
		cout<<"num="<<num<<endl;
		cout<<"score="<<score<<endl;
	};
   };
   Student stud1,stud2;
   int main()
   {
   	stud1.setdata();
   	stud2.setdata();
   	stud1.display();
   	stud2.display();
   	return 0;
   }
   int main()
   {
   	int a,b,c;
   	a=10;
   	b=23;
   	c=a+b;
   	cout<<"a+b=";
   	cout<<"c";
   	cout<<endl;
   	return 0;
	} 
	int main()
	{
		cout<<"This"<<"is";
		cout<<"a"<<"C++";
		cout<<"program."<<endl;
		return 0;
	}
#include<iostream>
using namespace std;
 #define PI 3.14159
 int main()
 {
 	int radius,high;
 	double volume;
 	cout<<"please input two numbers:"<<endl;
 	cin>>radius>>high;
 	volume=PI*radius*radius*high;
 	cout<<"radius:"<<radius<<"  high:"<<high<<endl;
 	cout<<"the volume is:"<<volume<<endl;
 	return 0;
 }
 #include<iostream.h>
 int n=0;
 int func(int x=10);
 void main()
 {
 	int a,b;
 	a=5;
 	b=func(a);
 	cout<<"\nlocal a="<<a<<endl;
 		<<"local b="<<b<<endl;
 		<<"global n="<<n<<endl;
 	a++;
 	b=func(a);
 	cout<<"\nlocal a="<<a<<endl;
 		<<"local b="<<b<<endl;
 		<<"global n="<<n<<endl;
 	func();
 }
 int func(int x)
 {
 	int a=1;
 	static int b=10;
 	a++;
 	b++;
 	x++;
 	n++;
 	cout<<"\nlocal a="<<a<<endl;
 		<<"local b="<<b<<endl;
 		<<"global n="<<n<<endl;
 	return a+b;
 } 
 #include<iostream>
using namespace std;
int main()
{
    double time,money,gongzi;//工作时间，时薪，工资//
    cout<<"please input employee's work time and wage per hour:"<<endl;
    cin>>time>>money;
    if(time<=40)
	{
       gongzi=time*money;
	}//40小时内工资//
    else
	{
       gongzi=40*money;
       if(time<=60)
       gongzi+=(time-40)*1.5*money;//40到60工资//
       else 
	   {
          gongzi+=20*money*1.5;
          gongzi+=(time-60)*3*money;//超60工资//
	   }
	}
cout<<"the employee's wage:"<<endl;
cout<<gongzi<<endl;
return 0;
}
#include <iostream>
using namespace std;
class Product
{public:
Product(int n,int q,float p):num(n),quantity(q),price(p){};
void total();
static float average();
static void display();
private:
int num;
int quantity;
float price;
static float discount;
static float sum;
static int n;
};
void Product::total()
{float rate=1.0;
if(quantity>10) rate=0.98*rate;
sum=sum+quantity*price*rate*(1-discount);
n=n+quantity;
}
void Product::display()
{cout<<sum<<endl;
cout<<average()<<endl;
}
float Product::average()
{return(sum/n);}
float Product::discount=0.05;
float Product::sum=0;
int Product::n=0;
int main()
{
Product Prod[3]={
Product(101,5,23.5),Product(102,12,24.56),Product(103,100,21.5)
};
for(int i=0;i<3;i++)
Prod[i].total();
Product::display();
return 0;
}
#include <iostream>
using namespace std;
class Date;
class Time
{public:
Time(int,int,int);
friend void display(const Date &,const Time &);
private:
int hour;
int minute;
int sec;
};
Time::Time(int h,int m,int s){hour=h;minute=m;sec=s;}
class Date
{public:
Date(int,int,int);
friend void display(const Date &,const Time &);
private:int month;int day;int year;
};
Date::Date(int m,int d,int y){month=m;day=d;year=y;}
void display(const Date &d,const Time &t)
{
cout<<d.month<<"/"<<d.day<<"/"<<d.year<<endl;
cout<<t.hour<<":"<<t.minute<<":"<<t.sec<<endl;
}
int main()
{
Time t1(10,13,56);
Date d1(12,25,2004);
display(d1,t1);
return 0;
}
#include <iostream>
using namespace std;
class Time;
class Date
{public:
Date(int,int,int);
friend Time;
private:
int month;
int day;
int year;
};
Date::Date(int m,int d,int y):month(m),day(d),year(y){ }
class Time
{public:
Time(int,int,int);
void display(const Date &);
private:
int hour;
int minute;
int sec;
};
Time::Time(int h,int m,int s):hour(h),minute(m),sec(s){ }
void Time::display(const Date &d)
{
cout<<d.month<<"/"<<d.day<<"/"<<d.year<<endl;
cout<<hour<<":"<<minute<<":"<<sec<<endl;
}
int main()
{
Time t1(10,13,56);
Date d1(12,25,2004);
t1.display(d1);
return 0;
}
#include<iostream>
#include<cmath>
using namespace std;
class Complex
{
public:
	Complex(){real=0;imag=0;}
	Complex(double r,double i){real =r;imag=i;}
	Complex operator+(Complex &c2);
	Complex operator-(Complex &c2);
	Complex operator*(Complex &c2);
	Complex operator/(Complex &c2);
	void display();
private:
	double real;
	double imag;
};
Complex Complex::operator +(Complex &c2)
{
	Complex c;
	c.real=real+c2.real;
	c.imag=imag+c2.imag;
	return c;
}
Complex Complex::operator -(Complex &c2)
{
	Complex c;
	c.real=real-c2.real;
	c.imag=imag-c2.imag;
	return c;
}
Complex Complex::operator *(Complex &c2)
{
	Complex c;
	c.real=real*c2.real-imag*c2.imag;
	c.imag=real*c2.imag+imag*c2.real;
	return c;
}
Complex Complex::operator /(Complex &c2)
{
	Complex c;
	double t=pow(c2.imag,2)+pow(c2.real,2);
	c.real=(real*c2.real+imag*c2.imag)*t;
	c.imag=(real*c2.imag-real*c2.imag)*t;
	return c;
}
	void Complex::display()
	{
		cout<<"("<<real<<","<<imag<<"i)"<<endl;
	}
int main()
{
	Complex c1(1,2),c2(3,-7),c3,c4,c5,c6;
	c3=c1+c2;
	c4=c1-c2;
	c5=c1*c2;
	c6=c1/c2;
	cout <<"c1=";c1.display();
	cout <<"c2=";c2.display();
	cout <<"c1+c2=";c3.display();
	cout <<"c1-c2=";c4.display();
	cout <<"c1*c2=";c5.display();
	cout <<"c1/c2=";c6.display();
	return 0;
}
#include<iostream>
using namespace std;
class Time
{
private:
	int minute,sec,hour;
public:
	Time(){minute=0;sec=0;}
	Time(int h,int m,int s):hour(h),minute(m),sec(s){}
	Time operator++();
	void display(){cout<<minute<<":"<<sec<<endl;}
};
Time Time::operator ++()
{
	if(++sec>=60)
	{sec-=60;
	++minute;
	if(++minute>=60)
	{minute-=60;
	++hour;}}
	return *this;
}
int main()
{
	Time time1(12,34,0);
	for (int i=0;i<60;i++)
	{
		++time1;
		time1.display();
	}
	return 0;
}
