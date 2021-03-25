#//include"SeqList.h"
#include <stdio.h>
#include <iostream>

using namespace std;
#include<string.h>

namespace  xxx
{
	template <class _TY>
	class List_iterator;

	template<class _TY>
	class List;  //模板LIST前向声明

	template<class _TY>
	class Node
	{
		friend class List_iterator<_TY>;
		friend class List<_TY>;
	public:
		Node() :_value(_TY()), _next(nullptr), _prev(nullptr)//节点初始化
		{}
		Node(const _TY& value, Node* next = nullptr, Node* prev = nullptr)
			: _value(value), _next(next), _prev(prev)//节点初始化
		{}
		~Node() {

		}
	private:
		_TY _value;  //节点的三个成员，双向循环链表
		Node* _next;
		Node* _prev;

	};

	template <class _TY>
	class List_iterator
	{
		friend class List<_TY>;
		typedef List_iterator<_TY> self;
	public:
		List_iterator(Node<_TY>* p) :ptr(p)
		{
		}
		~List_iterator() {

		}


		_TY& operator*() {
			return ptr->_value;
		}

		self& operator++()
		{
			ptr = ptr->_next;
			return *this;
		}
		self& operator--()
		{
			ptr = ptr->_prev;
			return *this;
		}
		self& operator--(_TY)
		{
			self tmp = *this;
			--* this;
			return tmp;
		}

		self& operator++(_TY) {
			self tmp = *this;
			++* this;
			return tmp;
		}


		bool operator!= (const	self& it) {
			return (ptr != it.ptr);
		}
		bool operator== (const	self& it) {
			return (ptr == it.ptr);
		}
		Node<_TY>* getnode()   //返回当前迭代器对应List的节点；
		{
			return ptr;
		}

	private:
		Node<_TY>* ptr;
	};

	template<class _TY>
	class List
	{
	public:
		typedef List_iterator<_TY>  iterator;
		List() :_size(0)  //空LIST构造
		{
			CreateHead();
		}

		List(iterator _first, iterator _last) {   //根据一个迭代器区间构造
			CreateHead();
			while (_first != _last) {
				push_back(*_first);
				_first++;
			}
		}

		List(List& x) :_size(x.size())   //有一个LIST构造另一个LIST
		{
			CreateHead();
			List<_TY> tmp(x.begin(), x.end());
			this->swap(tmp);
		}

		List(int n, const _TY& x)     //构造N个X值的LIST
		{
			CreateHead();
			_size = n;
			while (n--) {
				insert(end(), x);
			}
		}

		~List() {
			clear();
			delete _head;
			_head = nullptr;
		}

	public:
		iterator begin()   //返回头节点的迭代器
		{
			return  (iterator(_head->_next));
		}
		iterator end() {      ////返回尾节点的迭代器
			return iterator(_head);
		}
		int size()const
		{
			return _size;
		}
		bool empty()const
		{
			return _size == 0;
		}

		_TY& front()    //返回头节点的值
		{
			return *begin();
		}

		const _TY& front()const
		{
			return *begin();
		}

		_TY& back()     ////返回尾节点的值
		{
			return *(--end());
		}

		const _TY& back() const
		{
			return *end();
		}



	public:
		void push_back(const _TY& x) {   //尾插
		/*	Node<_TY>* _S = new Node<_TY> (x);  //无insert()接口时这样实现
			_S->_prev = _head->_prev;
			_S->_next = _head;
			_S->_next->_prev = _S;
			_S->_prev->_next = _S;
			++_size;*/
			insert(end(), x);
		}
		void push_front(const _TY& x) {   //头插
		/*	Node<_TY>* _S = new Node<_TY>(x);
			_S->_prev = _head;
			_S->_next = _head->_next;
			_S->_next->_prev = _S;
			_S->_prev->_next = _S;
			++_size;*/
			insert(begin(), x);
		}
		void pop_front() {              //移除头元素
			if (!empty()) {
				Node<_TY>* _S = _head->_next;
				_head->_next = _S->_next;
				_head->_next->_prev = _head;
				delete _S;
				_size--;
			}
		}
		void pop_back() {           //移除尾元素
			if (!empty()) {
				Node<_TY>* _S = _head->_prev;
				_S->_prev->_next = _head;
				_head->_prev = _S->_prev;
				delete _S;
				_size--;
			}
		}

		iterator insert(iterator _P, const _TY& x) {    //根据位置插入
			Node<_TY>* _S = new Node<_TY>(x);
			/*_S->_prev = _P.ptr->_prev;
			_S->_next = _P.ptr;*/
			_S->_prev = _P.getnode()->_prev;
			_S->_next = _P.getnode();

			_S->_prev->_next = _S;
			_S->_next->_prev = _S;
			_size++;
			return iterator(_S);
		}

		iterator erase(iterator _P)   //删除一个迭代器
		{
			Node<_TY>* _Cur = _P.getnode();
			Node<_TY>* _Next_ndoe = _Cur->_next;
			_Cur->_prev->_next = _Cur->_next;
			_Cur->_next->_prev = _Cur->_prev;
			_size--;
			delete _Cur;
			return iterator(_Next_ndoe);
		}

		iterator erase(iterator _first, iterator _last) //删除迭代器区间
		{
			while (_first != _last) {
				_first = erase(_first);
			}
			return _last;
		}

		void swap(List& y)   //交换两个LIST
		{
			Node<_TY>* tmp = _head;
			_head = y._head;
			y._head = tmp;
		}

		void clear()  //清除LIST
		{
			erase(begin(), end());
		}

	protected:
		void CreateHead() {
			_head = new Node<_TY>;
			_head->_value = NULL;
			_head->_next = _head->_prev = _head;
		}

	private:
		Node<_TY>* _head;
		size_t _size;

	};

};


void main()
{
	xxx::List<int> mylist;

	mylist.push_front(1);
	mylist.push_front(2);
	mylist.push_front(3);
	mylist.push_back(6);
	mylist.push_back(7);
	mylist.push_back(8);
	mylist.insert(mylist.begin(), 99);
	mylist.insert(mylist.end(), 999);

	xxx::List<int> mylist1(mylist);
	mylist1.push_back(66);
	mylist1.push_back(77);
	mylist1.push_back(88);

	
	cout << mylist.front() << endl;
	cout << mylist.back() << endl;

	mylist1.swap(mylist);
	xxx::List<int>::iterator it2 = mylist.begin();
	while (!(it2 == mylist.end())) {
		cout << *(it2) << " ";
		it2++;
	}
	cout << endl;
	xxx::List<int>::iterator itt = mylist1.begin();
	while (!(itt == mylist1.end())) {
		cout << *(itt) << " ";
		itt++;
	}

	cout << endl << "size=" << mylist1.size() << endl;

}