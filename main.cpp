#include <iostream>
#include <string.h>
#include <assert.h>
#pragma warning (disable:4996)
using namespace std;


//求1 + 2 + 3 + ... + n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A ? B : C）。
class Solution;
class Sum {
	friend Solution;
public:
	Sum()
	{
		_ret += _i;
		_i++;
	}
private:
	static int _i;
	static int _ret;
};
int Sum::_i = 1;
int Sum::_ret = 0;

class Solution {
public:
	int Sum_Solution(int n) {
		//Sum arr[n];c99中的变长数组，以前的编译器不支持中括号里面放变量
		//后台会调用5次，调用1次ret和i就会改变，我们让他每次都等于1，ret等于0;
		Sum::_i = 1;
		Sum::_ret = 0;
		Sum* p = new Sum[n];//调用n次构造函数
		return Sum::_ret;
	}
};
int main() {
	Solution d;
	d.Sum_Solution(5);
}


//日期类相关OJ题
	//int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//inline bool Is_leap_year(int m_year) {
	//	return((m_year % 4 == 0 && m_year % 100 != 0) || m_year % 400 == 0);
	//}

	// int GetMonthDay(int year, int month)
	//{
	//	int day = days[month];
	//	if (Is_leap_year(year) && month == 2)
	//	{
	//		day += 1;
	//	}
	//	return day;
	//}


	// inline int Get_year_day(int year) {
	//	if (Is_leap_year(year))
	//		return 366;
	//	return 365;
	//}


	 //int main()
	 //{
		// int numdays;
		//	 int year1, year2, month1, month2, day1, day2;
		//	 while(numdays = 0,scanf("%4d%2d%2d", &year1, &month1, &day1)!=EOF){
		//		   scanf("%4d%2d%2d", &year2, &month2, &day2);	

		//		   int l_year = year2, l_month = month2, l_day = day2; 
		//		   int h_year = year1, h_month = month1, h_day = day1;
		//		   if ((year2*1000+month2*100+day2) > (year1 * 1000 + month1 * 100 + day1)) {
		//			   l_year = year1,l_month = month1, l_day = day1;
		//			   h_year = year2, h_month = month2,h_day = day2;
		//		   }

		//		   for(int i = l_year;i<h_year;++i)
		//		   {
		//			   numdays += 365;
		//			   if (l_month<=2 && Is_leap_year(l_year)) {
		//				   numdays+=1;
		//			   }
		//		   }
		//		   for (int j = l_month; j < h_month; ++j) {
		//			   numdays += GetMonthDay(h_year,j);
		//		   }
		//		   numdays = numdays + (h_day - l_day)+1;	 
		//		   printf("%d\n", numdays);
		//	 }
		//	 return 0;
		// }



	//int main() {
	//	int year, month, day ,sumdays;
	//	while (sumdays = 0,cin >> year>> month >> day) {
	//		for (int i = 1; i < month; i++){
	//			int x = days[i];
	//			if (i==2 && Is_leap_year(year)) {
	//				x++;
	//			}
	//			sumdays += x;			
	//		}
	//		sumdays += day;
	//		cout << sumdays << endl;
	//	}	
	//	return 0;
	//}


	 //void main() {
		// int year,sumdays;
		// int month = 1, day = 1;
		// while (cin >> year >> sumdays) {
		//		for (int i = 1; i <= 12; ++i) {
		//		 int a = days[i];
		//		 if (i == 2 && Is_leap_year(year)) {
		//			 a++;
		//		 }
		//		 if (sumdays >a) {
		//			 sumdays -= a;
		//			 month++;
		//		 }
		//		 else {
		//			 break;
		//		 }	 
		//	 }
		//	 day = sumdays;
		//	 printf("%04d-%02d-%02d\n", year, month, day);
		//	 month = 1, day = 1;
		// }
	 //}

//void main() {
//	int m, year, month, day, days;
//	cin >> m;
//	while (m > 0) {
//		cin >> year >> month >> day >> days;
//
//		days += day;
//		day = 0;
//		int a = Get_year_day(year);
//		while (days > a) {
//			if (a == 366 && month > 2) {
//				a--;
//			}
//			days -= a;
//		}
//
//		while (days > GetMonthDay(year, month)) {
//			days -= GetMonthDay(year, month);
//			month++;
//			if (month == 13) {
//				month = 1;
//				year++;
//			}
//		}
//		day += days;
//		cout << year << "-" << month << "-" << day << endl;
//		m--;
//	}	
//}
//


















//class A
//{
//public:
//	class B
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << k << endl;//OK
//			cout << a.h << endl;//OK
//		}
//	private:
//		double m_data;
//	};
//private:
//	static int k;
//	int h;
//};
//int A::k = 1;
//int main()
//{
//	A::B b;
//	b.foo(A());
//	cout << sizeof(A::B) << " " << sizeof(A) << endl;
//	return 0;
//}
//






//class Date; // 前置声明
//class Time
//{
//	friend class Date; // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
//public:
//	Time(int hour, int minute, int second)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//		,_t(9,30,45)
//	{}
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// 直接访问时间类私有的成员变量
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//void main()
//{
//	Time t1(11,2,3);
//	Date d1(2020,3,15);
//	Date d2 = d1;
//	d1.SetTimeOfDate(1, 10, 11);
//}













//class String
//{
//	friend ostream& operator<<(ostream& out, const String& s);
//
//public:
//	String(const char* str="" )  //空串有\0 开辟一个空间拷贝\0
//	{
//		m_data = (char*)malloc(sizeof(char)* (strlen(str) + 1));
//		memcpy(m_data, str, sizeof(char) * (strlen(str) + 1));
//	
//	}
//	String(const String& s) {  //拷贝构造——深拷贝
//		m_data = (char*)malloc(sizeof(char) * (strlen(s.m_data) + 1));
//		memcpy(m_data, s.m_data, sizeof(char) * (strlen(s.m_data) + 1));
//	}
//	String& operator=(const String& s) { //深赋值语句
//		if (this != &s) {
//			free(m_data);  //先释放掉原来的空间，否则内存泄漏
//			m_data = (char*)malloc(sizeof(char) * (strlen(s.m_data) + 1));
//			memcpy(m_data, s.m_data, sizeof(char) * (strlen(s.m_data) + 1));
//		}
//		return *this;
//	}
//	/*String operator+(const String& s) {
//		String* tmp = this;
//		tmp->m_data = (char*)malloc(sizeof(char) * ( strlen(m_data) + strlen(s.m_data)+1 ));
//		memcpy(tmp->m_data, this, strlen(m_data));
//		strcat(tmp->m_data, s.m_data);
//		return *tmp;
//	}*/
//
//	String& operator+=(const String& s);
//
//
//	inline int length()const
//	{
//		return strlen(m_data);
//	}
//	char operator[](int pos) 
//	{
//		assert(pos >= 0 && pos < length());
//		return m_data[pos];
//	}
//	char operator[](int pos)const 
//	{
//		assert(pos >= 0 && pos < length());
//		return m_data[pos];
//	}
//
//
//
//	~String()
//	{
//		free(m_data);
//		m_data = nullptr;
//	}
//
//
//private:
//	char* m_data;
//
//};
//ostream& operator<<(ostream& out, const String& s) {
//	out << s.m_data;
//	return out;
//}
//
//void main()
//{
//	String str("abc");
//	String str1;
//	String str2("dddkkk");
//	String str3;
//	String str4;
//	String str5;
//	str1 = str;
//	cout << str[2] << " " << str1 << endl;
//	//str3 = str + str2;
//	cout<< str2<<" " << endl;
//
//
//}











//class A
//{
//public:
//    A(int a) :_a1(a), _a2(_a1) {}
//    void Print()
//    {
//        cout << _a1 << " " << _a2 << endl;
//    }
//private:
//    int _a2;
//    int _a1;
//};
//
//void main()
//{
//    A aa(1);
//    aa.Print();
//}