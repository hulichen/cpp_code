#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
using  namespace  std;

#include<iostream>
using namespace std;

typedef enum
{
	add = 0,
	sub,
	mul,
	divi
}type;

int main()
{
	int a = 10;
	int b = 20;

	auto func = [=](type i)->int {
		switch (i)
		{
		case add:
			return a + b;
		case sub:
			return a - b;
		case mul:
			return a * b;
		case divi:
			return a / b;
		}
	};

	cout << func(add) << endl;
}

//
//vector<string> topKFrequent(vector<string>& words, int k) {
//	map<string, int> mp1;
//
//	for (auto e : words) {
//		mp1[e]++;
//	}
//	vector<string> ret;
//
//	multimap<int, string> mp2;
//	for (auto e : mp1) {
//		mp2.insert(pair<int, string>(e.second, e.first));
//	}
//
//	auto it = mp2.end();
//	int x = it->first;
//	stack<string>  stk1;
//	while (k != 0) {
//		int y = it->first;
//		
//		if (x == y) {
//			stk1.push(it->second);
//		}
//		else {
//			string s=stk1.top();
//			ret.push_back(s);
//			stk1.pop();
//		}
//		x = y;
//		--it;
//	}
//	return  ret;
//}

/*
	class Compare
	{
	public:
		// 在set中进行排序时的比较规则
		bool operator()(const pair<string, int>& left, const pair<string, int>&
			right)
		{
			return left.second > right.second;
		}
	};
	vector<string> topKFrequent(vector<string>& words, int k)
	{
		// 用<单词，单词出现次数>构建键值对，然后将vector中的单词放进去，统计每个单词出现的次数
			map<string, int> m;
		for (size_t i = 0; i < words.size(); ++i)
			++(m[words[i]]);
		// 将单词按照其出现次数进行排序，出现相同次数的单词集中在一块
		multiset<pair<string, int>, Compare> ms(m.begin(), m.end());
		// 将相同次数的单词放在set中，然后再放到vector中
		set<string> s;
		size_t count = 0; // 统计相同次数单词的个数
		size_t leftCount = k;
		vector<string> ret;
		for (auto& e : ms)
		{
			if (!s.empty())
			{
				// 相同次数的单词已经全部放到set中
				if (count != e.second)
				{
					if (s.size() < leftCount)
					{
						ret.insert(ret.end(), s.begin(), s.end());
						leftCount -= s.size();
						s.clear();
					}
					else
					{
						break;
					}
				}
			}
			count = e.second;
			s.insert(e.first);
		}
		for (auto& e : s)
		{
			if (0 == leftCount)
				break;
			ret.push_back(e);
			leftCount--;
		}
		return ret;
	}



void main()
{
	vector<string> vs1({ "i","love","leetcode","i","love","coding"});

	vector<string> vs2 = topKFrequent(vs1, 4);
	for (auto e : vs2) {
		cout << e << endl;
	}
	return ;
}

/*
//现在有一个用来存放整数的Hash表，
//Hash表的存储单位称为桶，
//每个桶能放3个整数，当一个桶中要放的元素超过3个时，
//则要将新的元素存放在溢出桶中，每个溢出桶也能放3个元素，
//多个溢出桶使用链表串起来。
//此Hash表的基桶数目为素数P，Hash表的hash函数对P取模。代码定义如下：

//现在假设hash_table已经初始化好了，
//insert_new_element()函数目的是把一个新的值插入hash_table中，
//元素插入成功时，函数返回0，否则返回-1，完成函数。
#define P 7
#define NULL_DATA -1
struct bucket_node
{
	int data[3];
	struct bucket_node* next;
};
bucket_node hash_table[P];
int idx[7] = { 0 };
int insert_new_element(int new_element)
{
	//完成此函数
	int i = new_element % 7;
	idx[i]++;
	bucket_node n1 = hash_table[i];
	while (n1.next != NULL) { //找到桶尾部
		n1 = n1.next;
	}
	if (idx[i] % 3 == 0) {
		//链接新桶
		bucket_node* tmp;
		tmp->data[idx[i] % 3] = new_element; //放入元素
	}
	else { 
		hash_table[i].data[idx[i] % 3] = new_element;
	}
	return 0;
}

int main()
{
	Init_bucket_node();
	int array[] = { 15, 14, 21, 87, 96, 293, 35, 24, 149, 19, 63, 16, 103, 77, 5, 153, 145, 356, 51, 68, 705, 453 };
	for (int i = 0; i < sizeof(array) / sizeof(int); i++)
	{
		insert_new_element(array[i]);
	}
	return 0;
}


/*
template<class Type>
class HashTable;

template<class Type>
class HashNode
{
	friend class HashTable<Type>;
public:
	HashNode(Type d):data(d), link(nullptr)
	{}
private:
	Type data;
	HashNode *link;
};

template<class Type>
class HashTable
{
public:
	HashTable()
	{
		memset(hashtable, 0, sizeof(HashNode<Type>*)*HASH_DEFAULT_SIZE);
	}
public:
	void Insert(const Type &x)
	{
		int index = Hash(x);
		HashNode<Type> *s = new HashNode<Type>(x);
		s->link = hashtable[index];
		hashtable[index] = s;
	}
	void Remove(const Type &key)
	{
		int index = Hash(key);
		HashNode<Type> *prev = nullptr;
		HashNode<Type> *p = hashtable[index];
		while(p!=nullptr && p->data!=key)
		{
			prev = p;
			p = p->link;
		}

		if(p == nullptr)
			return;

		if(prev == nullptr)
			hashtable[index] = p->link;
		else
			prev->link = p->link;
		delete p;
	}
public:
	void Show()const
	{
		for(int i=0; i<HASH_DEFAULT_SIZE; ++i)
		{
			cout<<i<<" : ";
			HashNode<Type> *p = hashtable[i];
			while(p != nullptr)
			{
				cout<<p->data<<"-->";
				p = p->link;
			}
			cout<<"Nul."<<endl;
		}
	}
protected:
	int Hash(const Type &key)
	{
		return key % HASH_DEFAULT_SIZE;
	}
private:
	enum {HASH_DEFAULT_SIZE = 7};
	HashNode<Type>* hashtable[HASH_DEFAULT_SIZE];
};

void main()
{
	vector<int> iv{37,2,5, 9,1,13,8,3,6,12};
	HashTable<int> ht;

	for(const auto &e : iv)
		ht.Insert(e);

	ht.Show();

	ht.Remove(9);
	ht.Show();
}




*/



//
//int  main()
//{
//	pair<int, int> va[] = { {5,500} ,{1,100},{2,200},{3,300} };
//	map<int, int> mp;
//	for (int i = 0; i < sizeof(va) / sizeof(va[0]); ++i) {
//		mp.insert(va[i]);
//	}
//	map<int, int>::iterator it = mp.begin();
//	//while (it != mp.end()) {
//	//	cout << it->first << " : " << it->second << endl;
//	//	++it;
//	//}
//	for (auto& e : mp) {
//		cout << e.first << " : " << e.second << endl;
//	}
//
//	
//
//
//	return  0;
//}



//
//struct Test
//{
//public:
//	Test(int a, int p, string s) :m_a(a), m_p(p), m_s(s)
//	{}
//
//	//////eg:根据m_p大小进行排序
//	////bool operator < (const Test& t) const
//	////{
//	////	return m_p < t.m_p;
//	////}
//	////eg:根据m_s的字母顺序进行排序
//	//bool operator < (const Test& t) const
//	//{
//	//	return (strcmp(m_s.c_str(), t.m_s.c_str())) < 0;
//	//}
//
//	//bool operator > (const Test& t) const
//	//{
//	//	return m_p > t.m_p;
//	//}
//
//
//	int m_a;
//	int m_p;
//	string m_s;
//};
//
//class myCompare
//{
//public:
//	bool operator()(const Test& t1, const Test& t2) const
//	{
//		return t1.m_p > t2.m_p;
//	}
//};
//
//
//bool MyCompare1(const Test& t1, const Test& t2)  {//普通的函数
//	return t1.m_p > t2.m_p;
//}
//
//
//void main() {
//	Test t1(1, 4,"苹果");
//	Test t2(1, 10,"草莓");
//	Test t3(1, 30,"樱桃");
//	map<Test, int, function<bool (const Test&, const Test& )> > s;
//	//map<Test,int> s;
//	//map<Test, int,greater<>> s;
//	s.insert(pair<Test, int>(t1, 1));
//	s.insert(pair<Test, int>(t2, 2));
//	s.insert(pair<Test, int>(t3, 3));
//	for (auto& e : s) 
//		cout << e.first.m_a<< " : " << e.first.m_p << " : " << e.first.m_s << endl;
//
//}
