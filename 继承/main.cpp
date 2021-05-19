#include<iostream>
using namespace  std;
#include <string>




//
//class Alimal
//{
//public:
//	virtual void Eat()
//	{cout << "Alimal::Eat()" << endl;}
//	virtual void Foot()
//	{cout << "Alimal::Foot()" << endl;}
//	virtual void Sleep()
//	{cout << "Alimal::Sleep()" << endl;}
//};
//class Person : public Alimal
//{
//public:
//	void Eat()
//	{cout << "Person::Eat()" << endl;}
//	void Foot()
//	{cout << "Person::Foot()" << endl;}
//	void Sleep()
//	{cout << "Person::Sleep()" << endl;}
//};
//class Bird : public Alimal
//{
//public:
//	void Eat()
//	{cout << "Bird::Eat()" << endl;}
//	void Foot()
//	{cout << "Bird::Foot()" << endl;}
//	void Sleep()
//	{cout << "Bird::Sleep()" << endl;}
//};
//class Dog : public Alimal
//{
//public:
//	void Eat()
//	{cout << "Dog::Eat()" << endl;}
//	void Foot()
//	{cout << "Dog::Foot()" << endl;}
//	void Sleep()
//	{cout << "Dog::Sleep()" << endl;}
//};
//
////多态  完成不同的功能
//void Active(Alimal* pa)
//{
//	pa->Eat();
//	pa->Foot();
//	pa->Sleep();
//}
//void main()
//{
//	Person p;
//	Bird b;
//	Dog d;
//	Active(&b);
//	Active(&d);
//
//}


class Base
{
public:
	void fun()
	{
		cout << "Base::fun()" << endl;
	}
	void fun(int a)
	{
		cout << "Base::fun(int)" << endl;
	}
	void fun(int a, int b)
	{
		cout << "Base::fun(int, int)" << endl;
	}
private:
	int m_a = 0;
	int m_b = 0;
};
class D :public Base
{
public:
	//同名隐藏
	void fun(int a, int b, int c)
	{
		cout << "D::fun(int,int,int)" << endl;
	}
	void show()
	{
		cout << "D::show()" << endl;
	}
private:
	int m_c = 0;
};
void main()
{
	D d;
	Base* pb = &d;
	pb->fun();
}






//class Base
//{
//public:
//	 void fun()
//	{
//		cout << "Base::fun()" << endl;
//	}
//	void fun(int a)
//	{
//		cout << "Base::fun(int)" << endl;
//	}
//	void fun(int a, int b)
//	{
//		cout << "Base::fun(int, int)" << endl;
//	}
//private:
//	int m_a = 0;
//	int m_b = 0;
//};
//class D :public Base
//{
//public:
//	//同名隐藏
//	void fun(int a, int b, int c)
//	{
//		cout << "D::fun(int,int,int)" << endl;
//	}
//	void show()
//	{
//		cout << "D::show()" << endl;
//	}
//private:
//	int m_c = 0;
//};
//void main()
//{
//	D d;
//	Base* pb = &d;
//	pb->fun();
//}
//赋值兼容规则
//void main()
//{
//	Base  b;
//	D     d;
//	b = d;
//	Base *pb = &d;
//	Base &rb = d;  //初始化
//	rb.fun();
//	rb.fun();
//	rb.fun(1,2);
//	//rb.fun(1,2,3);
//}
//int  main()
//{
//	D d;
//	//d.fun();
//	//d.fu1n();
//	//d.fun(1,2);
//	d.fun(1,2,3);
//	return 0;
//}











//
//class Base
//{
//public:
//	Base(int a) :m_a(a)
//	{cout << "Base::Base()" << endl;}
//	Base(const Base& b)
//	{cout << "Base::Base(const Base &b)" << endl;}
//
//	Base& operator=(const Base& b)
//	{
//		if (this != &b)
//		{
//			m_a = b.m_a;
//		}
//		cout << "Base::Base& operator=(const Base& b)" << endl;
//		return *this;
//	}
//	~Base()
//	{cout << "Base::~Base()" << endl;}
//private:
//	int m_a;
//};
//class D : public Base
//{
//public:
//	D(int d = 0) : m_d(d), Base(100)
//	{cout << "D::D()" << endl;}
//	D(const D& d) : Base(d)
//	{cout << "D::D(const Base &b)" << endl;}
//
//	D& operator=(const D& d)
//	{
//		if (this != &d)
//		{
//			Base::operator=(d);
//			m_d = d.m_d;
//		}
//		cout << "D::D& operator=(const D& d)" << endl;
//		return *this;
//	}
//	~D()
//	{cout << "D::~D()" << endl;}
//private:
//	int m_d;
//};
//void main()
//{
//	D d;
//	D d1 = d;
//	D d2;
//	d2 = d1;
//}












//public:
//	Base(int a = 0) :m_a(a)
//	{
//		cout << "Base::Base()" << endl;
//	}
//	~Base()
//	{
//		cout << "Base::~Base()" << endl;
//	}
//
//public:
//		D(int d = 0) :m_d(d)
//		{
//			cout << "D::D()" << endl;
//		}
//		~D()
//		{
//			cout << "D::~D()" << endl;
//		}

//class Base
//{
//public:
//	void fun()
//	{cout << "Base::fun()" << endl;}
//	void list()
//	{cout << "Base::list()" << endl;}
//private:
//	int m_a;
//};
//class D : public Base
//{
//public:
//	void show()
//	{cout << "D::show()" << endl;}
//
//	//同名隐藏
//	void fun()
//	{cout << "D::fun()" << endl;}
//private:
//	int m_d;
//};
//void main()
//{
//	D d;
//	Base b;
//	Base *pb = &d;
//	//pb->show(); //pb为父类，父类只能调动父类的方法
//	d.fun();
//	d.Base::fun();
//	d.list();
//}

















//class Person
//{
//public:
//	Person(string name, int age) :m_age(age),m_name(name)
//	{}
//	void Print()
//	{cout << m_name << " : " << m_age << endl;}
//public:
//	string m_name ;
//	int    m_age ;
//};
////继承
//class Student : public Person
//{
//public:
//	Student(string name, int age,int scores=0):Person(name, age), math_scores(scores)
//	{}
//private:
//	int math_scores;  
//};



//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//void Test()
//{
//	Assistant a;
//	a._name = "peter";
//}
//void main()
//{
//	Test();
//}






//class A
//{
//public:
//	A() { cout << "A::A()" << endl; }
//	~A() { cout << "A::~A()" << endl; }
//	int a;
//};
//
//class B : public A
//{
//public:
//	B() { cout << "B::B()" << endl; }
//	~B() { cout << "B::~B()" << endl; }
//	int b;
//};
//
//void main()
//{
//	B b;
//}


//class A { 
//public: 
//	void test(float a)
//	{ cout << a; }
//}; 
//class B :public A 
//{ public: 
//	void test(int b) 
//	{ cout << b; }
//}; 
//void main() 
//{
//	A* a = new A; 
//	B* b = new B; 
//	a = b;
//	a->test(1.1); 
//}


//class A
//{
//public:
//	void f1() { cout << "A::f1()" << endl; }
//	virtual void f2() { cout << "A::f2()" << endl; }
//	virtual void f3() { cout << "A::f3()" << endl; }
//};
//
//class B : public A
//{
//public:
//	virtual void f1() { cout << "B::f1()" << endl; }
//	virtual void f2() { cout << "B::f2()" << endl; }
//	void f3() { cout << "B::f3()" << endl; }
//};