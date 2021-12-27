#pragma once
#include <stdio.h>
#include <iostream>
using namespace std;


namespace  mylist {
	template<class _TY>
	class Node {
		friend class List_iterator<_TY>;
		friend class mylist<_TY>;
	public:

		Node(_value=(_TY()), _pre=nullptr,_next=nullptr) 
		{}
		Node(const _TY& value, Node* next = nullptr, Node* pre = nullptr):_value=(value),_next(next),_pre(pre)
		{}
		~Node()
		{}

	private:
		_TY _value;
		Node* _pre;
		Node* _next;
	};


	template<class _TY>
	class List_iterator
	{
		friend class Node<_TY>;
		friend class mylist<_TY>;
	public:
		List_iterator();
		~List_iterator();

	private:


	};




	template<class _TY>
	class mylist
	{
		friend class Node<_TY>;
		friend class List_iterator<_TY>;
	public:
		mylist();
		~mylist();

	private:

	};






};
