#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
#include <assert.h>
using namespace  std;

#define DISPLAY  //调试开关ifdef ...  endif...

class String;
class String_rep;

class String_rep { //字符串引用计数器类
public:
	friend class String;
	friend ostream& operator<<(ostream& out, const String_rep& rep);//重载输出流

	String_rep(const char* str=""):m_count(0)
	{  //构造
#ifdef DISPLAY
		cout << "Create String_rep Obj." << endl;
#endif // DISPLAY

		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}

	~String_rep()
	{ //析构
#ifdef DISPLAY
		cout << "Delete String_rep Obj." << endl;
#endif // DISPLAY
		delete[]  m_data;
		m_data = nullptr;
	}

	String_rep(const String_rep& rep) :m_count(0)
	{//拷贝构造
		m_data = rep.m_data;  //浅拷贝
	}

	String_rep& operator=(const String_rep& rep)
	{  //赋值语句。
		if (this != &rep)
		{
			m_data = rep.m_data;  
		}
		return *this;
	}
public:
	void increment()
	{
		m_count++;
	}
	void decrement() 
	{
		m_count--;
		if (m_count == 0)
			delete this;  //自杀式释放：先调动调用者String自身的析构函数，析构pn，
		                  //然后调动String_rep的析构函数，回收m_data和m_count空间
	}

	char* Getdata()const
	{
		return  m_data;
	}
private:
	char* m_data;
	int m_count;

};

class  String {

	friend ostream& operator<<(ostream& out, const String& s);
public:
	String(const char* str = ""):pn(new String_rep(str))
	{
#ifdef DISPLAY
		cout << "Create String Obj." << endl;
#endif // DISPLAY
		pn->increment();
	}

	~String() 
	{
#ifdef DISPLAY
		cout << "Delete String Obj." << endl;
#endif // DISPLAY
		pn->decrement();
	}

	String(const String& s):pn(s.pn) //拷贝构造--构造的函数的一种重写形式
	{
		pn->increment();
	}  

	String& operator = (const String & s) //赋值语句
	{
		if (this != &s) {
			pn->decrement();
			pn = s.pn; //pn指向新对象，若pn有原对象需要把原对象的计数器 -1.
			pn->increment();
		}
		return *this;
	}

public:
	
	void to_upper() {   //小写字母变大写 需要用写时拷贝--->更改数据的时候用深拷贝。
		pn->decrement();
		String_rep* new_pn = new String_rep(pn->m_data); //重新构造一个引用计数器，拷贝属于自己的数据和计数。
		pn = new_pn;
		pn->increment();

		char* p = pn->m_data;
		while (*p!= '\0') {
			if (*p >= 'a' && *p <= 'z') {
				*p -= 32;
			}
			p++;
		}
	}
private:
	String_rep *pn; //引用计数器指针
};

ostream& operator<<(ostream& out, const String& s) {
	out << s.pn->Getdata();
	return  out;
}

//#include "stringcopy.h"
//using namespace std;
//int  main() {
//	String s1("abcd");
//	String s2 = s1;
//	String s3("fggdasd");
//	s3 = s2;
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	s2.to_upper();
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//
//	return  0;
//}








///////////错误做法//////////
//class String {
//	
//public:
//	friend ostream& operator<<(ostream& out, const String& s);//重载输出流
//	
//	//String(const char* str) {
//	//	if (str == nullptr) { //空串开辟一个空间放\0
//	//		m_data = (char*)malloc(sizeof(char));
//	//		m_data[0] = '\0';
//	//	}
//	//	else {
//	//		m_data= (char*)malloc(sizeof(char) * (strlen(str) + 1));
//	//		strcpy(m_data, str);
//	//	}
//	//}
//
//	String(const char* str = "") {//默认值为空串，空串有\0，strlen计算时有一个空间
//		m_data = new char[strlen(str) + 1];
//		strcpy(m_data, str);
//	}
//	String(const  String& s) { //深拷贝
//
//		//m_data = new char[strlen(s.m_data) + 1];
//		//strcpy(m_data, s.m_data);
//
//		m_data = s.m_data;  //浅拷贝
//		m_count++;  
//
//	}
//	~String() {
//	    /*delete[]m_data;
//		m_data = nullptr;*/
//
//		if (--m_count == 0) {
//			delete[]m_data;
//			m_data = nullptr;
//		}
//	}
//
//	String& operator=(const String& s) { //深赋值
//
//		//if (this != &s) {
//		//	delete[]m_data;
//		//	strcpy(m_data, s.m_data);
//		//}
//
//		if (this != &s) {
//			m_data = s.m_data;
//			m_count++;
//		}
//
//		return *this;
//	}
//public:
//
//	void to_upper() {
//		char* p = m_data;
//		while (*p != '\0') {
//			if (*p > 'a' && *p < 'z') {
//				*p -= 32;
//			}
//		}
//	}
//
//	int getlength()const {
//		return strlen(m_data);
//	}
//
//	
//
//	String operator+(const String& s){//s1+s2
//		int len = getlength() + strlen(s.m_data);
//		char* tmp= (char*)malloc(len+1);
//		memset(tmp,'\0', len + 1);
//		memcpy(tmp, m_data, getlength());
//		memcpy(m_data + getlength(),s.m_data, strlen(s.m_data));
//		return  tmp;
//	}
//	String& operator+=(const String& s) {//s1+=s2
//		int len = getlength() + strlen(s.m_data);
//		m_data = (char*)realloc(m_data, len);
//		strcat(m_data, s.m_data);
//		return *this;
//	}
//	char operator[](int  pos) {  //重载[]  s1='abc' 则s[1]=b
//		assert(pos > 0 && pos < getlength());
//		return  m_data[pos];
//	}
//	char operator[](int  pos) const { //针对const对象调用
//		assert(pos > 0 && pos < getlength());
//		return  m_data[pos];
//	}
//private:
//	char* m_data;
//	static int m_count;
//};
//int String::m_count = 0;
//ostream& operator<<(ostream &out, const String&s) {
//	out <<s.m_data;
//	return out;
//}





