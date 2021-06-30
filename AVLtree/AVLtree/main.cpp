#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;



template<class Type>
class AVLTree;

template<class Type>
class AVLNode
{
	friend class AVLTree<Type>;
public:
	AVLNode() :data(Type()), leftChild(nullptr), rightChild(nullptr), bf(0)
	{}
	AVLNode(Type d, AVLNode* left = nullptr, AVLNode* right = nullptr)
		:data(d), leftChild(left), rightChild(right), bf(0)
	{}
	~AVLNode()
	{}
private:
	Type data;
	AVLNode* leftChild;
	AVLNode* rightChild;
	int      bf;
};

template<class Type>
class AVLTree
{
public:
	AVLTree() : root(nullptr)
	{}
public:
	bool Insert(const Type& x)
	{
		return Insert(root, x);
	}

protected:
	bool Insert(AVLNode<Type>*& t, const Type& x);
protected:

	void RotateL(AVLNode<Type>*& ptr)
	{
		AVLNode<Type>* subL = ptr;
		ptr = subL->rightChild;
		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;
		ptr->bf = subL->bf = 0;
	}


	void RotateR(AVLNode<Type>*& ptr)
	{
		AVLNode<Type>* subR = ptr;
		ptr = subR->leftChild;
		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;
		ptr->bf = subR->bf = 0;
	
	}


	void RotateLR(AVLNode<Type>*& ptr)
	{
		AVLNode<Type>* subR = ptr;
		AVLNode<Type>* subL = ptr->leftChild;
		ptr = subL->rightChild;

		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;
		//调整subL->bf
		if (ptr->bf <= 0)
			subL->bf = 0;
		else
			subL->bf = -1;

		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;

		//调整subR->bf
		if (ptr->bf >= 0)
			subR->bf = 0;
		else
			subR->bf = 1;

		ptr->bf = 0;
	}

	void RotateRL(AVLNode<Type>*& ptr){
		AVLNode<Type>* subL = ptr;
		AVLNode<Type>* subR = ptr->rightChild;
		ptr = subR->leftChild;

		subR->leftChild =ptr->rightChild;
		ptr->rightChild = subR;
		//调整subL->bf
		if (ptr->bf <= 0)
			subL->bf = 0;
		else
			subL->bf = -1;

		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;
		
		//调整subR->bf
		if (ptr->bf >= 0)
			subR->bf = 0;
		else
			subR->bf = 1;

		ptr->bf = 0;
	}

private:
	AVLNode<Type>* root;
};

template<class Type>
bool AVLTree<Type>::Insert(AVLNode<Type>*& t, const Type& x)
{
	//先按Bst树插入节点 	
	AVLNode<Type>* p = t;
	stack< AVLNode<Type>*> stk;  //用一个栈记住插入时经过的路线，方便取出父节点
	AVLNode<Type>* pr = nullptr;  //父节点

	while (p != nullptr) {   //寻找插入位置
		if (x == p->data)
			return false;
		pr = p;
		stk.push(pr);
		if (x > p->data) {
			p = p->rightChild;
			continue;
		}	
		if (x < p->data)
			p = p->leftChild;
	}
				
	/////插入
	p =new AVLNode<Type>(x);
	if (pr == nullptr) {   //空树则直接创建根节点返回
		t = p;
		return true;
	}

	if (x > pr->data)
		pr->rightChild = p;
	else
		pr->leftChild = p;

	//////////调整平衡因子///  左数插入  bf -1  ; 右树插入 bf +1
	while (!stk.empty()) {
		pr = stk.top();
		stk.pop();

		if (pr->leftChild==p)  // 左数插入  bf -1 
			pr->bf --;
		else
			pr->bf ++;
		
		if (pr->bf == 0) //树是平衡的  返回
			break;
		else if (pr->bf == 1 || pr->bf == -1)  // 向上回溯  上面可能会不平衡
		{
			p = pr;	
		}
		else {  //树不平衡  需要调整  针对不平衡的节点调整

			if (pr->bf < 0) {
				if (p->bf < 0) {    //  /  右单旋
					RotateR(pr);
				}
				else {   //    <    先左旋后右旋
					RotateLR(pr);
				}
			}
			else {
				if (p->bf > 0) { //    \  左单旋
					RotateL(pr);
				}
				else {//   >    先右旋后左旋
					RotateRL(pr);
				}
			}
			break;
		}
	}


	//连接
	if (stk.empty())
		t = pr;
	else
	{
		AVLNode<Type>* q = stk.top();
		if (pr->data < q->data)
			q->leftChild = pr;
		else
			q->rightChild = pr;
	}

	return true;
}






int main()
{
	vector<int> iv{ 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	AVLTree<int> avl;

	for (const auto& e : iv)
		avl.Insert(e);

	return 0;
}



//template<class K, class V>
//class BSTree
//{
//	typedef BSTreeNode<K, V> Node;
//public:
//	bool Insert(const K& key, const V& value);
//	Node* Find(const K& key);
//	bool Erase(const K& key);
//	void _InOrder(Node* root);
//	void InOrder();
//private:
//	Node* _root = nullptr;
//};
//
//void TestBSTree()
//{
//	BSTree<string, string> dict;
//	dict.Insert("insert", "插入");
//	dict.Insert("erase", "删除");
//	dict.Insert("left", "左边");
//	dict.Insert("string", "字符串");
//
//	string str;
//	while (cin >> str)
//	{
//		auto ret = dict.Find(str);
//		if (ret)
//		{
//			cout << str << ":" << ret->_value << endl;
//		}
//		else
//		{
//			cout << "单词拼写错误" << endl;
//		}
//	}
//
//	string strs[] = { "苹果", "西瓜", "苹果", "樱桃", "苹果", "樱桃", "苹果", "樱桃", "苹果" };
//	// 统计水果出现的次
//	BSTree<string, int> countTree;
//	for (auto str : strs)
//	{
//		auto ret = countTree.Find(str);
//		if (ret == NULL)
//		{
//			countTree.Insert(str, 1);
//		}
//		else
//		{
//			ret->_value++;
//		}
//	}
//	countTree.InOrder();

//}









/////////////////////////////
//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode() : val(0), left(nullptr), right(nullptr) {}
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//
//};

//vector<int> preorderTraversal(TreeNode* root) {
//    vector<int> num;
//    stack<TreeNode*> s1;
//    TreeNode* cur = root;
//    while (cur != nullptr || !s1.empty()) {
//        while (cur != nullptr) {
//            s1.push(cur);
//            num.push_back(cur->val);
//            cur = cur->left;
//        }
//        cur = s1.top();
//        s1.pop();
//        num.push_back(cur->val);
//        cur = cur->right;
//
//    }
//
//    return num;
//}

//class Solution {
//public:
//    string tree2str(TreeNode* root) {
//        string str;
//        stack<TreeNode*>  stk;
//        TreeNode* cur = root;
//        if (cur != nullptr)
//            while (cur != nullptr || !stk.empty()) {
//                if (cur != nullptr) {
//                    stk.push(cur);
//                    if(cur !=root){
//                        str.push_back('(');
//                    }  
//                    str.push_back(cur->val+48);
//                    cur = cur->left;
//                }
//
//                cur = stk.top();
//                stk.pop();
//                if (cur != root) 
//                    str.push_back(')');
//                cur = cur->right;         
//
//        return str;
//    }
//};
//
//class Solution {
//public:
//    vector<int> preorderTraversal(TreeNode* root) {
//        vector<int> num;
//        if (root == nullptr)
//            return num;
//        stack<TreeNode*> s1;
//        TreeNode* cur = root;
//        s1.push(root);
//        num.push_back(root->val);
//        while (!s1.empty()) {
//            while (cur->left != nullptr) {  //左数不空 入栈 打印
//                s1.push(cur->left);
//                num.push_back(s1.top()->val);
//                cur = cur->left;
//            }
//
//
//            TreeNode* p = s1.top();
//            s1.pop();
//            if (p->right != nullptr) {
//                s1.push(p->right);
//                num.push_back(p->right->val);
//                cur = p->right;
//            }
//        }
//        return num;
//    }
//};
