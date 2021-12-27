#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
#include <assert.h>
using namespace  std;

#define DISPLAY  //���Կ���ifdef ...  endif...

class String;
class String_rep;

class String_rep { //�ַ������ü�������
public:
	friend class String;
	friend ostream& operator<<(ostream& out, const String_rep& rep);//���������

	String_rep(const char* str=""):m_count(0)
	{  //����
#ifdef DISPLAY
		cout << "Create String_rep Obj." << endl;
#endif // DISPLAY

		m_data = new char[strlen(str) + 1];
		strcpy(m_data, str);
	}

	~String_rep()
	{ //����
#ifdef DISPLAY
		cout << "Delete String_rep Obj." << endl;
#endif // DISPLAY
		delete[]  m_data;
		m_data = nullptr;
	}

	String_rep(const String_rep& rep) :m_count(0)
	{//��������
		m_data = rep.m_data;  //ǳ����
	}

	String_rep& operator=(const String_rep& rep)
	{  //��ֵ��䡣
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
			delete this;  //��ɱʽ�ͷţ��ȵ���������String�������������������pn��
		                  //Ȼ�����String_rep����������������m_data��m_count�ռ�
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

	String(const String& s):pn(s.pn) //��������--����ĺ�����һ����д��ʽ
	{
		pn->increment();
	}  

	String& operator = (const String & s) //��ֵ���
	{
		if (this != &s) {
			pn->decrement();
			pn = s.pn; //pnָ���¶�����pn��ԭ������Ҫ��ԭ����ļ����� -1.
			pn->increment();
		}
		return *this;
	}

public:
	
	void to_upper() {   //Сд��ĸ���д ��Ҫ��дʱ����--->�������ݵ�ʱ���������
		pn->decrement();
		String_rep* new_pn = new String_rep(pn->m_data); //���¹���һ�����ü����������������Լ������ݺͼ�����
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
	String_rep *pn; //���ü�����ָ��
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








///////////��������//////////
//class String {
//	
//public:
//	friend ostream& operator<<(ostream& out, const String& s);//���������
//	
//	//String(const char* str) {
//	//	if (str == nullptr) { //�մ�����һ���ռ��\0
//	//		m_data = (char*)malloc(sizeof(char));
//	//		m_data[0] = '\0';
//	//	}
//	//	else {
//	//		m_data= (char*)malloc(sizeof(char) * (strlen(str) + 1));
//	//		strcpy(m_data, str);
//	//	}
//	//}
//
//	String(const char* str = "") {//Ĭ��ֵΪ�մ����մ���\0��strlen����ʱ��һ���ռ�
//		m_data = new char[strlen(str) + 1];
//		strcpy(m_data, str);
//	}
//	String(const  String& s) { //���
//
//		//m_data = new char[strlen(s.m_data) + 1];
//		//strcpy(m_data, s.m_data);
//
//		m_data = s.m_data;  //ǳ����
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
//	String& operator=(const String& s) { //�ֵ
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
//	char operator[](int  pos) {  //����[]  s1='abc' ��s[1]=b
//		assert(pos > 0 && pos < getlength());
//		return  m_data[pos];
//	}
//	char operator[](int  pos) const { //���const�������
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





