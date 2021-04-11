#include <stdio.h>
#include <iostream>
#include<string.h>

using namespace std;

namespace xxx {

	template<typename _Ty>
	class vector
	{	
	public:
		typedef _Ty* iterator;  //指针充当迭代器

		vector():_first(nullptr),_last(nullptr),_end(nullptr)
		{}
		
		vector(int n, const _Ty& value ):_first(nullptr), _last(nullptr), _end(nullptr)   //n个value的初始化
		{
			reverse(n);
			while (n--) {
				push_back(value);
			}
		}

		vector(iterator first, iterator last) {   //根据迭代器区间创建
			iterator p = first;
			size_t n = last - first;
			reverse(n);
			while (n--) {
				push_back(*p);
				p++;
			}
		}
		vector(vector<_Ty> &v) :_first(nullptr), _last(nullptr), _end(nullptr) //根据vector构造
		{
			reverse(v.size());
			iterator p = v.begin();
			iterator it = begin();
			while (p != v.end()) {
				*it = *p;
				it++;
				p++;
			}
			_last = _first + v.size();
		}

		~vector() {
			delete[] _first;
			_first = _end = _last = nullptr;
		}


	public:

		_Ty& operator[](size_t pos) {
			return *(_first + pos);
		}


		iterator begin()
		{
			return _first;
		}
		iterator end()
		{
			return _last;
		}
		_Ty front(){
			return *_first;
		}
		_Ty back() {
			return *(--_last);
		}

		void push_back(const _Ty & x) {
			insert(end(), x);
		}
		void push_front(const _Ty& x) {
			insert(begin(), x);
		}
		void reverse(size_t n) { //预留空间，需要跟现有容量比较；
			if (n > capacity()) {//扩容
				size_t old_size = size();
				_Ty* new_first = new _Ty[n]();
				memcpy(new_first, _first, sizeof(_Ty) * old_size);
				delete[] _first;

				_first = new_first;
				_last = _first + old_size;
				_end = _first + n;
			}


		}


		iterator insert(iterator _P, const _Ty& x) { 
			if (_last == _end) {//如果容量不够则扩容；
				/*size_t p_size = _P - _first;
				size_t old_size = capacity();
				size_t new_size = old_size==0 ?  1:old_size* 2;
				_Ty* new_first = new _Ty[new_size];
				memcpy(new_first, _first, sizeof(_Ty) * old_size);
				delete[] _first;
				_first = new_first;
				_last = _first + old_size;
				_end = _first + new_size;*/

				/////////////
				size_t p_size = _P-_first;
				size_t new_size = (size()== 0  ?  1 : 2 * size());
				reverse(new_size);
				////////////

				_P = _first + p_size;
			}
			iterator end = _last;
			while (end > _P) {
				*end = *(end - 1);
				--end;
			}
			*_P = x;
			++_last;
			return _P;
		}


		void swap(vector<_Ty> &v) {
			iterator tmp1=_first, tmp2=_last, tmp3=_end;
			_first = v._first, _last = v._last, _end = v._end;
			v._first = tmp1, v._last = tmp2, v._end = tmp3;
		}
		void resize(size_t n, const _Ty& value=_Ty()) {
			if (n <= capacity()) {
				_last = _first + n;
				return;
			}
			else {
				reverse(n);
				while (_last != _end) {
					*_last = value;
					_last++;
				}
			}
			
		}
		iterator& erase(iterator _P) {
			iterator cur = _P;
			while (_P < _last) {
				*_P = *(_P+1);
				_P++;
			}
			_last--;
			return _P;
		}


		size_t capacity()const
		{
			return _end - _first;
		}
		size_t size()const {
			return _last-_first;
		}
		bool empty() {
			return size() == 0;
		}
		void clear() {
			_first = _last = _end = nullptr;
		}
	private:
		iterator   _first;  //头元素
		iterator  _last;    //尾元素         size = _last -_first
		iterator  _end;     //总空间尾部    capcaity = _end - _first

	};


};



int main()
{

	int a[] = { 2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10 };
	xxx::vector<int> v1(&a[3],&a[10]);//根据迭代器区间创建

	xxx::vector<int> v2(v1);
	
	v2.push_back(999);
	
	v2.swap(v1);
	v2.resize(20);
	v2.push_front(9999);
	cout << "v2size:" << v2.size() << "   v2capacity:" << v2.capacity() << endl;
	xxx::vector<int>::iterator x = find(v2.begin(), v2.end(), 9999); //find()为系统自带的全局的查找函数
	v2.erase(x);  //移除

	cout << "v2size:" << v2.size() << "   v2capacity:" << v2.capacity() << endl;
	cout << "v1size:" << v1.size() << "   v1capacity:" << v1.capacity() << endl;
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << endl;
	for (auto& x : v2) {
		cout << x << " ";
	}


	//xxx::vector<int> v;
	//v.push_back(4);
	//v.push_back(5);
	//v.push_back(6);
	//auto pos = v.begin();
	//pos = v.insert(pos, 3);
	//pos = v.insert(pos, 2);
	//pos = v.insert(pos, 1);
	//v.push_front(99);
	//v.push_front(100);


	//v.reverse(50);
	//cout << "daxiao:" << v.size() << "   rongliang:" << v.capacity() << endl;
	//cout << v.size() << " " << v.capacity() << " " << *v.begin() << " " << * v.end() << " " << v.empty()<< endl; 
	//cout << " " << v.back() << " " << v.front()<<endl;

	return 0;
}