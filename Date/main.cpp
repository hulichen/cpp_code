#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out, Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	bool Is_leap_year() {
		return((m_year % 4 == 0 && m_year % 100 != 0) || m_year % 400 == 0);
	}
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month)
	{
		int day = days[month];
		if(Is_leap_year() &&  month==2)
		{
			day += 1;
		}
		return day;
	}

	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1) {
		m_year = year;
		m_month = month;
		m_day = day;
	}

	// �������캯��
	// d2(d1)
	Date (const Date& d) {	
			m_year = d.m_year;
			m_month = d.m_month;
			m_day = d.m_day;
	}

	// ��ֵ���������
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d) {
		if (this != &d) {
			m_year = d.m_year;
			m_month = d.m_month;
			m_day = d.m_day;
		}
		return *this;
	}
	// ��������
	~Date() {

	}

	// ǰ��++
	Date& operator++() {
		m_day++;
		if (m_day > GetMonthDay(m_year, m_month)) {
			m_month++;
			m_day = 1;
		}
		if (m_month > 12) {
			m_month = 1;
			m_year++;
		}
		return *this;
	}
	// ����++
	Date operator++(int) {
		Date tmp = *this;
		++* this;
		return tmp;
	}
	// ����--
	Date operator--(int) {
		Date tmp = *this;
		--* this;
		return tmp;
	}
	// ǰ��--
	Date& operator--() {
		m_day--;
		if (m_day <=0) {
			m_month--;
			if (m_month <= 0) {
				m_year--;
				m_month = 12;
			}
			m_day = GetMonthDay(m_year, m_month);
		}	
		return *this;
	}
	// >���������
	bool operator>(const Date& d) {
		return (m_year > d.m_year)
			|| (m_year == d.m_year  &&  m_month > d.m_month)
			|| (m_year == d.m_year  &&  m_month == d.m_month  &&  m_day > d.m_day);
	}
	// ==���������
	bool operator==(const Date& d) {
		return (m_year==d.m_year &&  m_month==d.m_month  &&  m_day==d.m_day);
	}
	// >=���������
	inline bool operator >= (const Date& d) {
		return !(*this < d);
	}
	// <���������
	bool operator < (const Date& d) {
	return (m_year < d.m_year)
			|| (m_year == d.m_year && m_month < d.m_month)
			|| (m_year == d.m_year && m_month == d.m_month && m_day < d.m_day);
	}
	// <=���������
	bool operator <= (const Date& d) {
		return !(*this > d);
	}
	// !=���������
	bool operator != (const Date& d) {
		return !(m_year == d.m_year && m_month == d.m_month && m_day ==d.m_day);
	}

	//�����������ж�������һ��ĵڼ���
	int GetDayByYMD(int year, int month, int day)
	{
		int days = 0;
		for (int i = 1; i < month; ++i)
		{
			days += GetMonthDay(year, i);
		}
		days += day;
		return days;
	}

	// ����+=����
	Date& operator+=(int day) {
		day += m_day;
		m_day = 0;
		while (day > GetMonthDay(m_year,m_month)){
			day -= GetMonthDay(m_year, m_month);
			if (++m_month == 13) {
				m_month = 1;
				m_year++;
			}
		}
		m_day += day;
		return *this;
	}
	// ����+����
	Date operator+(int day) {
		Date tmp = *this;
		tmp += day;
		return tmp;
	}
	// ����-����
	Date operator-(int day) {
		Date tmp = *this;
		tmp -= day;
		return tmp;
	}
	// ����-=����
	Date& operator-=(int day) {

		while (day > m_day) {
			day -= m_day;
			m_month--;
			if (m_month == 0) {
				m_month = 12;
				m_year--;
			}
			m_day = GetMonthDay(m_year, m_month);	
		}	

		m_day -= day;
		if (m_day == 0) {
			m_month = (m_month - 1);
			if (m_month == 0){
				m_month = 12;
				m_year--;
			}
			m_day = GetMonthDay(m_year, m_month);
		}
		return *this;
	}
	// ����-���� ��������
	int operator-(const Date& d) {	
		int count = 0;
		Date tmp;
		if (*this >=d){
			tmp = d;
			while (!(m_year == tmp.m_year && m_month == tmp.m_month && m_day == tmp.m_day)) {
				tmp++;
				count++;
			}
		}
		else {
			tmp = *this;
			while (!(tmp.m_year == d.m_year && tmp.m_month == d.m_month && tmp.m_day == d.m_day)) {
				tmp++;
				count++;
			}
			count= -count;
		}	
		return count;
	}

	//���������ж��ܼ�
	int GetWeekByYMD(int year, int month, int day)
	{
		//δ���
		return 0;
	}
private:
	int m_year;
	int m_month;
	int m_day;
};

ostream& operator<<(ostream& out, Date& d) {
	out << d.m_year << "��" << d.m_month << "��" << d.m_day<<"��";
	return out;
}
istream& operator>>(istream& in, Date& d) {
	in>>d.m_year >> d.m_month >>d.m_day  ;
	return in;
}

int  main()
{

	Date d1(2020,12,31);
	Date d2(2020, 11, 30);
	Date d3(2020, 6, 1);
	Date d4 = d3;
	Date d5= d2 + 1000;
	Date d6 (d5);
	d6-= 1000;
	cout << d1 << endl;
	cout << d2 << endl;
	cout <<d3 << endl;
	cout << d4 << endl;
	cout << d5 << endl;
	cout << d6 << endl;
	cout << d2-d3<< endl;
	if (d3==d4 && d1>d2 && d5>=d2&& d3<d2 && d1!=d2  ) {
		cout << "true" << endl;
	}
	return 0;
}