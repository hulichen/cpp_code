#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <assert.h>
using namespace  std;

class Date
{
	friend ostream& operator<<(ostream& out, Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	int GetMonthDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			day += 1;
		}
		return day;
	}
	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1):_year(year),_month(month),_day(day)
	{}
	// 拷贝构造函数
	// d2(d1)
	Date(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	// 赋值运算符重载
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d) {
		if (this != &d) {
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	// 析构函数
	~Date() {}

	// 前置++
	Date& operator++() {
		_day++;
		if (_day > GetMonthDay(_year, _month)) {
			_day = 1;
			_month++;
		}
		if (_month > 12) {
			_month = 1;
			_year++;
		}
		return *this;
	}
	// 后置++
	Date operator++(int) {
		Date tmp = *this;
		++(*this);
		return tmp;
	}

	// 前置--
	Date& operator--() {
		_day--;
		if (_day <= 0) {
			_month--;
			if (_month <= 0) {
				_year--;
				_month = 12;
			}
			_day = GetMonthDay(_year, _month);
		}
		return *this;
	}
	// 后置--
	Date operator--(int) {
		Date tmp = *this;
		--* this;
		return tmp;
	}
	
	// ==运算符重载
	bool operator==(const Date& d) {
		return _year == d._year && _month == d._month && _day == d._day;
	}
	// >=运算符重载
	inline bool operator >= (const Date& d) {
		if (_year >= d._year) return true;
		else if (_month >= d._month) return true;
		else if (_day >= d._day) return  true;
		else  return  false;
	}
	// <运算符重载
	bool operator < (const Date& d) {
		return !(*this >= d);
	}
	// <=运算符重载
	bool operator <= (const Date& d) {
		if (_year <= d._year) return true;
		else if (_month <= d._month) return true;
		else if (_day <= d._day) return  true;
		else  return  false;
	}
	// >运算符重载
	bool operator>(const Date& d) {
		return !(*this <= d);
	}


	// !=运算符重载
	bool operator != (const Date& d) {
		return !(_year == d._year || _month || d._month && _day || d._day);
	}


	// 日期-日期 返回天数
	int operator-(const Date& d);



	// 日期+天数
	Date& operator+(int day) {
		assert(day > 0);
		static Date tmp = *this;   //引用发返的临时空间静态开辟，否则出了这个函数被回收
		while (day--)
			++tmp;
		return tmp;
	}
	// 日期-天数
	Date operator-(int day) {
		assert(day > 0);
		static Date tmp = *this;
		while (day--)
			--tmp;
		return tmp;
	}
	// 日期+=天数
	Date operator+=(int day) {
		assert(day > 0);
		while (day--)
			++* this;
		return *this;
	};
	// 日期-=天数
	Date operator-=(int day) {
		assert(day > 0);
		while (day--)
			--* this;
		return *this;
	}

private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& out, Date& d) {
	cout << d._year << ":" << d._month << ":" << d._day;
	return out;
}
istream& operator>>(istream& in, Date& d) {
	in >> d._year >> d._month >> d._day;
	return in;
}











//#include"data.h"
//int  main() {
//	Date d1;
//	Date d2(2020,2, 28);
//	Date d3(d2);
//	Date d4(d2);
//	++d3;
//	cout << d3 << endl;
//	++d3;
//	cout << d3 << endl;
//	d4=d3 - 20;
//	cout << d4 << endl;
//	d3 -= 1;
//	cout << d3 << endl;
//	d4 = d3 + 2;
//	cout << d4 << endl;
//	d3 =d3- 31;
//	cout << d3 << endl;
//	return  0;
//}