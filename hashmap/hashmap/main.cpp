#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
using  namespace  std;




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
//	//eg:根据m_p大小进行排序
//	//bool operator < (const Test& t) const
//	//{
//	//	return m_p < t.m_p;
//	//}
//	//eg:根据m_s的字母顺序进行排序
//	bool operator < (const Test& t) const
//	{
//		return (strcmp(m_s.c_str(), t.m_s.c_str())) < 0;
//	}
//
//	bool operator > (const Test& t) const
//	{
//		return m_p > t.m_p;
//	}
//
//
//	int m_a;
//	int m_p;
//	string m_s;
//};
//
//void main() {
//	Test t1(1, 4,"苹果");
//	Test t2(1, 10,"草莓");
//	Test t3(1, 30,"樱桃");
//
//	set<Test,greater<>> s;
//	s.insert(t1);
//	s.insert(t2);
//	s.insert(t3);
//	for (auto& e : s) {
//		cout << e.m_a<< " : " << e.m_p << " : " << e.m_s << endl;
//	}
//
//}
