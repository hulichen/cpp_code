//include "data.h"
//#include <deque>
//#include <queue>
#include "mypri_queue.h"


//多态理解


class Animal
{
public:
	virtual void Eat(){cout<<"Animal::Eat()"<<endl;}
	virtual void Foot(){cout<<"Animal::Foot()"<<endl;}
	virtual void Sleep(){cout<<"Animal::Sleep()"<<endl;}
};

class Person : public Animal
{
public:
	void Eat(){cout<<"Person::Eat()"<<endl;}
	void Foot(){cout<<"Person::Foot()"<<endl;}
	void Sleep(){cout<<"Person::Sleep()"<<endl;}
};

class Bird : public Animal
{
public:
	void Eat(){cout<<"Bird::Eat()"<<endl;}
	void Foot(){cout<<"Bird::Foot()"<<endl;}
	void Sleep(){cout<<"Bird::Sleep()"<<endl;}
};

class Dog : public Animal
{
public:
	void Eat(){cout<<"Dog::Eat()"<<endl;}
	void Foot(){cout<<"Dog::Foot()"<<endl;}
	void Sleep(){cout<<"Dog::Sleep()"<<endl;}
};

//多态  完成不同的功能
void Active(Animal *pa)
{
	pa->Eat();
	pa->Foot();
	pa->Sleep();
}

void main()
{
	Person p;
	Bird b;
	Dog d;
	Active(&p);
	Active(&b);
	Active(&d);
}









/*

///继承理解
class Person //基类
{
public:
	Person(string name, int age) :m_age(age), m_name(name)
	{}
	void Print()
	{
		cout << m_name << " : " << m_age << endl;
	}
protected:
	string m_name;
private:
	
	int    m_age;
};
//继承
class Student : public Person     //Student为派生类
{
public:
	Student(string name, int age, int scores = 0) :Person(name, age), math_scores(scores)
	{}
	void stuprintf() {
		cout << m_name;
	}
private:
	int math_scores;
};
class D :protected Student
{
public:
	D(string name, int age, int scores = 0, int math_scores=1):Student(name,age,math_scores)
	{}


};

void main()
{
	Person s1("jack",18);
	Student s2("张三疯", 20);
	D s3("hitton", 58, 100);
	s2.Print();
	

}




/*
class IntArray
{
public:
	IntArray()
	{
		for(int i=1; i<=10; ++i)
		{
			ar[i-1] = i;
		}
	}

	int GetSum(int time)
	{
		int sum = 0;
		for(int i=0; i<10; ++i)
		{
			sum += ar[i];
		}
		return sum *time;
	}

private:
	int ar[10];
};

class FloatArray
{
public:
	FloatArray()
	{
		for(int i=0; i<10; ++i)
		{
			ar[i] = i + 1.11;
		}
	}

	float GetSum(float time)
	{
		 float sum = 0.0f;
		for(int i=0; i<10; ++i)
		{
			sum += ar[i];
		}
		return sum *time;
	}
private:
	float ar[10];
};
////////////////////////////////////////////////////////////
template<class Type>
class NumTraits
{};

template<>
class NumTraits<IntArray>
{
public:
	typedef int return_type;
	typedef int arg_type;
};

template<>
class NumTraits<FloatArray>
{
public:
	typedef float return_type;
	typedef float arg_type;
};

template<class Type>
class CApply
{
public:
	//完美兼顾  //typename NumTraits<Type>::return_type   告诉编译器typename后面的东西为一个类型
	typename NumTraits<Type>::return_type GetSum(Type &obj,typename NumTraits<Type>::arg_type time)
	{
		return obj.GetSum(time);
	}
};

void  main()
{
	IntArray intA;
	FloatArray floatA;  

	CApply<IntArray> obj;
	cout<<obj.GetSum(intA,3)<<endl;
	

	CApply<FloatArray> obj1;
	cout<<obj1.GetSum(floatA,2.3)<<endl;
}


*/





//
//int  main() {
//	mypri_queue::priority_queue<int>  pq1;
//	pq1.push(1);
//
//
//
//	return 0;
//}






























//namespace myqueue {
//	template<class _TY, class Cont = deque<_TY> >
//	class queue {
//	public:
//		queue() {};
//		~queue() {};
//	public:
//		bool empty()const
//		{
//			return _c.empty();
//		}
//		size_t size()
//		{
//			return _c.size();
//		}
//		_TY& front()
//		{
//			return _c.front();
//		}
//		_TY& back()
//		{
//			return _c.back();
//		}
//		void pop()
//		{
//			_c.pop_front();
//		}
//		void push(_TY aa)
//		{
//			_c.push_back(aa);
//		}
//
//	private:
//		Cont _c;
//	};
//
//};




//int  main() {
//	//int* p1 = (int*)malloc(sizeof(int));
//	//int* p2 = (int*)calloc(4, sizeof(int));
//	//int* p3 = (int*)realloc(p2, sizeof(int) * 10);
//	//free(p3);
//
//
//
//	return  0;
//}


