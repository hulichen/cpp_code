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
	class List;  //ģ��LISTǰ������

	template<class _TY>
	class Node
	{
		friend class List_iterator<_TY>;
		friend class List<_TY>;
	public:
		Node() :_value(_TY()), _next(nullptr), _prev(nullptr)//�ڵ��ʼ��
		{}
		Node(const _TY& value, Node* next = nullptr, Node* prev = nullptr)
			: _value(value), _next(next), _prev(prev)//�ڵ��ʼ��
		{}
		~Node() {

		}
	private:
		_TY _value;  //�ڵ��������Ա��˫��ѭ������
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
		Node<_TY>* getnode()   //���ص�ǰ��������ӦList�Ľڵ㣻
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
		List() :_size(0)  //��LIST����
		{
			CreateHead();
		}

		List(iterator _first, iterator _last) {   //����һ�����������乹��
			CreateHead();
			while (_first != _last) {
				push_back(*_first);
				_first++;
			}
		}

		List(List& x) :_size(x.size())   //��һ��LIST������һ��LIST
		{
			CreateHead();
			List<_TY> tmp(x.begin(), x.end());
			this->swap(tmp);
		}

		List(int n, const _TY& x)     //����N��Xֵ��LIST
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
		iterator begin()   //����ͷ�ڵ�ĵ�����
		{
			return  (iterator(_head->_next));
		}
		iterator end() {      ////����β�ڵ�ĵ�����
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

		_TY& front()    //����ͷ�ڵ��ֵ
		{
			return *begin();
		}

		const _TY& front()const
		{
			return *begin();
		}

		_TY& back()     ////����β�ڵ��ֵ
		{
			return *(--end());
		}

		const _TY& back() const
		{
			return *end();
		}



	public:
		void push_back(const _TY& x) {   //β��
		/*	Node<_TY>* _S = new Node<_TY> (x);  //��insert()�ӿ�ʱ����ʵ��
			_S->_prev = _head->_prev;
			_S->_next = _head;
			_S->_next->_prev = _S;
			_S->_prev->_next = _S;
			++_size;*/
			insert(end(), x);
		}
		void push_front(const _TY& x) {   //ͷ��
		/*	Node<_TY>* _S = new Node<_TY>(x);
			_S->_prev = _head;
			_S->_next = _head->_next;
			_S->_next->_prev = _S;
			_S->_prev->_next = _S;
			++_size;*/
			insert(begin(), x);
		}
		void pop_front() {              //�Ƴ�ͷԪ��
			if (!empty()) {
				Node<_TY>* _S = _head->_next;
				_head->_next = _S->_next;
				_head->_next->_prev = _head;
				delete _S;
				_size--;
			}
		}
		void pop_back() {           //�Ƴ�βԪ��
			if (!empty()) {
				Node<_TY>* _S = _head->_prev;
				_S->_prev->_next = _head;
				_head->_prev = _S->_prev;
				delete _S;
				_size--;
			}
		}

		iterator insert(iterator _P, const _TY& x) {    //����λ�ò���
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

		iterator erase(iterator _P)   //ɾ��һ��������
		{
			Node<_TY>* _Cur = _P.getnode();
			Node<_TY>* _Next_ndoe = _Cur->_next;
			_Cur->_prev->_next = _Cur->_next;
			_Cur->_next->_prev = _Cur->_prev;
			_size--;
			delete _Cur;
			return iterator(_Next_ndoe);
		}

		iterator erase(iterator _first, iterator _last) //ɾ������������
		{
			while (_first != _last) {
				_first = erase(_first);
			}
			return _last;
		}

		void swap(List& y)   //��������LIST
		{
			Node<_TY>* tmp = _head;
			_head = y._head;
			y._head = tmp;
		}

		void clear()  //���LIST
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