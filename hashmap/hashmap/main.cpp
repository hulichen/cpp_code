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
		// ��set�н�������ʱ�ıȽϹ���
		bool operator()(const pair<string, int>& left, const pair<string, int>&
			right)
		{
			return left.second > right.second;
		}
	};
	vector<string> topKFrequent(vector<string>& words, int k)
	{
		// ��<���ʣ����ʳ��ִ���>������ֵ�ԣ�Ȼ��vector�еĵ��ʷŽ�ȥ��ͳ��ÿ�����ʳ��ֵĴ���
			map<string, int> m;
		for (size_t i = 0; i < words.size(); ++i)
			++(m[words[i]]);
		// �����ʰ�������ִ����������򣬳�����ͬ�����ĵ��ʼ�����һ��
		multiset<pair<string, int>, Compare> ms(m.begin(), m.end());
		// ����ͬ�����ĵ��ʷ���set�У�Ȼ���ٷŵ�vector��
		set<string> s;
		size_t count = 0; // ͳ����ͬ�������ʵĸ���
		size_t leftCount = k;
		vector<string> ret;
		for (auto& e : ms)
		{
			if (!s.empty())
			{
				// ��ͬ�����ĵ����Ѿ�ȫ���ŵ�set��
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
//������һ���������������Hash��
//Hash��Ĵ洢��λ��ΪͰ��
//ÿ��Ͱ�ܷ�3����������һ��Ͱ��Ҫ�ŵ�Ԫ�س���3��ʱ��
//��Ҫ���µ�Ԫ�ش�������Ͱ�У�ÿ�����ͰҲ�ܷ�3��Ԫ�أ�
//������Ͱʹ������������
//��Hash��Ļ�Ͱ��ĿΪ����P��Hash���hash������Pȡģ�����붨�����£�

//���ڼ���hash_table�Ѿ���ʼ�����ˣ�
//insert_new_element()����Ŀ���ǰ�һ���µ�ֵ����hash_table�У�
//Ԫ�ز���ɹ�ʱ����������0�����򷵻�-1����ɺ�����
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
	//��ɴ˺���
	int i = new_element % 7;
	idx[i]++;
	bucket_node n1 = hash_table[i];
	while (n1.next != NULL) { //�ҵ�Ͱβ��
		n1 = n1.next;
	}
	if (idx[i] % 3 == 0) {
		//������Ͱ
		bucket_node* tmp;
		tmp->data[idx[i] % 3] = new_element; //����Ԫ��
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
//	//////eg:����m_p��С��������
//	////bool operator < (const Test& t) const
//	////{
//	////	return m_p < t.m_p;
//	////}
//	////eg:����m_s����ĸ˳���������
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
//bool MyCompare1(const Test& t1, const Test& t2)  {//��ͨ�ĺ���
//	return t1.m_p > t2.m_p;
//}
//
//
//void main() {
//	Test t1(1, 4,"ƻ��");
//	Test t2(1, 10,"��ݮ");
//	Test t3(1, 30,"ӣ��");
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
