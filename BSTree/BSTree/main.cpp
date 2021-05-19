#include <iostream>
#include <vector>
using namespace std;




template<class _Ty>
class BSTree;

template<class _Ty>
class BSTNode
{
	friend class BSTree<_Ty>;
public:
	BSTNode() : data(_Ty()), leftChild(nullptr), rightChild(nullptr)
	{}
	BSTNode(_Ty val, BSTNode* left = nullptr, BSTNode* right = nullptr)
		: data(val), leftChild(left), rightChild(right)
	{}
	~BSTNode()
	{}
private:
	_Ty data;
	BSTNode* leftChild;
	BSTNode* rightChild;
};

template<class _Ty>
class BSTree
{
public:
	BSTree():root(nullptr)
	{}
	BSTree(vector<_Ty> & num)  : root(nullptr)
	{
		for (const auto e : num) {
			Insert1(root, e);
			//Insert2(root,e);
		}
	}
	~BSTree()
	{}

	/// <summary>
	/// ���Ĺ��� ��ɾ
	/// <returns>
	bool Insert(const _Ty& x)
	{
		return Insert2(root, x); 
		//return Insert1(root, x);
	}

	bool Remove(const _Ty& key)
	{
		return Remove1(root, key);
		//return Remove2(root, key);
	}
	

	/// <summary>
	/// ��������
	/// </summary>
public:
	void Order()const   //������� ����鿴���
	{
		Order(root);
	}

	BSTNode<_Ty>* Min()const   //������Сֵ
	{
		return Min(root);
	}
	BSTNode<_Ty>* Max()const  //�������ֵ
	{
		return Max(root);
	}
	
	BSTNode<_Ty>* Parent(BSTNode<_Ty>* key)const   //Ѱ�ҽڵ�ĸ��ڵ�
	{
		return Parent(root, key);
	}
	BSTNode<_Ty>* Search(const _Ty& key)const
	{
		return Search(root, key);
	}
	

protected:
	bool Insert1(BSTNode<_Ty>*& t, int x)  //�ݹ�
	{
		if (t == nullptr) {
			t = new BSTNode<_Ty>(x);
			return true;
		}
		
		if (x > t->data) {
			return  Insert1(t->rightChild, x);
		}
		if (x < t->data) {
			return  Insert1(t->leftChild, x);
		}
		return false;
	}
	bool Insert2(BSTNode<_Ty>* &t, const _Ty& x)  //�ǵݹ�  ��Ҫ�ҵ���ǰ�ڵ�ĸ��ڵ�
	{  
		if (t == nullptr) {
			t = new BSTNode<_Ty>(x);
			return true;
		}
		BSTNode<_Ty>* p = t;    //��ǰ�ڵ�
		BSTNode<_Ty>* pre = t;  //���ڵ�
		while (p) {             //�Ƚϴ�С�ߵ���֧��ͷ��������ʱp=nullptr
			pre = p;
			if (x > t->data) {
				p = p->rightChild;
			}
			else if (x < t->data) {
				p = p->leftChild;
			}
		}	
		//Ȼ��Ƚ�x��pre->data�Ĵ�С���������������������������
		if (x > pre->data) {
			pre->rightChild= new BSTNode<_Ty>(x);
		}
		else {
			pre->leftChild = new BSTNode<_Ty>(x);
		}
		return true;
	}

	bool Remove1(BSTNode<_Ty>* &t, const _Ty& key)  //�ݹ�
	{
		if (t == nullptr)
			return false;
		if (key < t->data)
			return Remove1(t->leftChild,key);
		else if (key < t->data)
			return Remove1(t->rightChild, key);
		else{  //�ҵ�����ɾ��   
			
			if (t->leftChild && t->rightChild) {
				BSTNode<_Ty> * q = t->rightChild;
				while (q->leftChild)
					q = q->leftChild;
				t->data = q->data;
				Remove1(t->rightChild, t->data);
			}
			else {
				BSTNode<_Ty>*  p = t;
				if (t->leftChild != nullptr)
					t = t->leftChild;
				else
					t = t->rightChild;
				delete p;
			}			
		}
		return true;
	}

	bool Remove2(BSTNode<_Ty>*& t, const _Ty& key)  //�ǵݹ�
	{
		if (t == nullptr)
			return false;
		BSTNode<_Ty>* cur = Search(key);
		if (cur == nullptr)
			return false;

		if (cur->leftChild && cur->rightChild) {  //�������������� ��ѡ���滻����������Сֵ�������������ֵ			
			BSTNode<_Ty>* q = cur->leftChild;
			while (q->rightChild != nullptr)
				q = q->rightChild;
			cur->data = q->data;
			cur = q;
		}

		BSTNode<_Ty>* p = Parent(t,cur);
		if (p == nullptr) //ɾ�����ڵ�  ��ʱֻ�������������� ���߶���
		{
			if (cur->leftChild != nullptr)
				cur = cur->leftChild;
			else
				cur = cur->rightChild;
		}
		else {	//�Ǹ��ڵ�
			if (p->leftChild==cur) { //curΪ���� ��curֻ��һ������
				if (cur->leftChild == nullptr)
					p->leftChild = cur->rightChild;
				else
					p->leftChild = cur->leftChild;
			}
			else if (p->rightChild== cur) {//curΪ���� ��curֻ��һ������
				if (cur->leftChild == nullptr)
					p->rightChild = cur->rightChild;
				else
					p->rightChild = cur->leftChild;
			}
			
			
		}	
		delete cur;
		return true;
	}

protected:

	void Order(BSTNode<_Ty>* t)const   //������� ����鿴���
	{
		if (t == nullptr) {
			return;
		}
		Order(t->leftChild);
		printf("%d  ", t->data);
		Order(t->rightChild);
	}

	BSTNode<_Ty>* Min(BSTNode<_Ty>*&t)
	{
		while (t&&t->leftChild != nullptr) {   //t==nullptrʱ����nullptr
			t = t->leftChild;
		}
		return t;
	}

	BSTNode<_Ty>* Max(BSTNode<_Ty>* t)const
	{
		while (t && t->rightChild != nullptr)
			t = t->rightChild;
		return t;
	}

	BSTNode<_Ty>* Parent(BSTNode<_Ty>* t, BSTNode<_Ty>* key)const
	{
		if (t == nullptr || key == t)
			return nullptr;
		if (key == t->leftChild || key == t->rightChild)
			return t;
		if (key->data < t->data)
			return Parent(t->leftChild, key);
		else if (key->data > t->data)
			return Parent(t->rightChild, key);
	}

	BSTNode<_Ty>* Search(BSTNode<_Ty>* t, const _Ty& key)const
	{
		if (t == nullptr)
			return t;
		if (key < t->data)
			return Search(t->leftChild, key);
		else if (key > t->data)
			return Search(t->rightChild, key);
		return t;
	}

private:
	BSTNode<_Ty>* root;

};

int main()
{
	vector<int>  v1{53,78,17,45,23,9,65,87,81,94 };
	BSTree<int> b1(v1);
	b1.Insert(88);
	b1.Order();
	cout << endl;
	b1.Remove(17);
	b1.Remove(53);

	b1.Order();
	return 0;
}