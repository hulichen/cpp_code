#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace  std;










//
//
//int subA(vector<int>& A) {
//    int len = A.size();
//    int num = 0;
//
//    int a = A[2]-A[1];
//    int pra = A[1] - A[0];
//    int ppra = 0;
//    for (int i = 1, j = 2; i < len && j < len; i++, j++) {
//        pra= A[j-1] - A[i-1];
//        a = A[j] - A[i];
//        if (pra * a < 0  ) {
//            num++;
//            if (i < len && j < len) {
//                i++;
//                j++;
//            }       
//        }
//   }
//    return num   +1;
//}
//
//int main()
//{
//    int n;
//    int A_i;
//    vector<int> A;
//    cin >> n;
//    while (n--) {
//        cin >> A_i;
//        A.push_back(A_i);
//    }
//    if (A.size() <= 2) {
//        cout << A.size() << endl;
//    }
//    else {
//        cout << subA(A) << endl;
//    }
//    return  0;
//}
//

//
//
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace  std;
//int main() {
//    vector<string> v;
//    string s;
//    while (cin>>s){
//        v.push_back(s);
//    }
//    int n = v.size();
//    n--;
//    while (n--) {
//        cout << v[n] << " ";
//    }
//    max(1, 2);
//    return 0;
//}
//

//
//int main()
//{
//    string s;
//    vector<string> ret;
//    getline(cin, s);
//    int n= s.size();
//    int i = 0;
//    while (i < n) {
//        string s1;
//        while (i < n && s[i] >= '0' && s[i] <= '9') {
//            s1.push_back(s[i]);
//            i++;
//        }
//        if (!s1.empty()) {
//            ret.push_back(s1);
//        }
//        i++;
//    }
//    if (ret.empty()) {
//        return 0;
//    }
//    int a = ret[0].size();
//    int idx = 0;
//    for (int i = 1; i < ret.size(); i++) {
//        if (ret[i].size() > a) {
//            a = ret[i].size();
//            idx = i;
//        }
//    }
//    cout << ret[idx] << endl;
//    return 0;
//}



  





//void TestBSTree();
//template<class K, class V>
//class BSTree;
//
//template<class K, class V>
//struct BSTreeNode
//{
//	BSTreeNode<K, V>* _left;
//	BSTreeNode<K, V>* _right;
//	K _key;
//	V _value;
//
//
//	BSTreeNode(const K& key, const V& value)
//		:_left(nullptr)
//		, _right(nullptr)
//		, _key(key)
//		, _value(value)
//	{}
//	~BSTreeNode() {
//		_left = nullptr;
//		_right = nullptr;
//		delete _key;
//	}
//};
//
//template<class K, class V>
//class BSTree
//{
//	typedef BSTreeNode<K, V> Node;
//public:
//	bool Insert(const K& key, const V& value) {
//		if (_root == nullptr) {
//			_root = new BSTreeNode<K, V>(key, value);
//			return true;
//		}
//		BSTreeNode<K, V>* pr = nullptr;
//		BSTreeNode<K, V>* cur = _root;
//		while (cur != nullptr) {  //寻找插入位置
//			pr = cur;
//			if (key < cur->_key) {
//				cur = cur->_left;
//			}
//			else if (key > cur->_key)
//				cur = cur->_right;
//			else
//				return false;
//		}
//		if (key > pr->_key) {
//			pr->_right= new BSTreeNode<K, V>(key, value);
//		}
//		else
//		{
//			pr->_left = new BSTreeNode<K, V>(key, value);
//		}		
//	}
//
//	Node* Find(const K& key) {
//		if (_root == nullptr)
//			return nullptr;
//		BSTreeNode<K, V>* cur = _root;
//		while (cur != nullptr) {  //寻找位置
//			if (key < cur->_key) {
//				cur = cur->_left;
//			}
//			else if (key > cur->_key)
//				cur = cur->_right;
//			else  //相等返回
//				return cur;
//		}
//		return nullptr;
//	}
//	Node* Parent(Node* t, Node* key)const
//	{
//		if (t == nullptr || key == t)
//			return nullptr;
//		if (key == t->_left || key == t->_ight)
//			return t;
//		if (key->_key < t->_key)
//			return Parent(t->_left, key);
//		else if (key->_key > t->_key)
//			return Parent(t->_right, key);
//	}
//	
//	////////删除方法有点问题
//	//bool Erase(const K& key) {
//	//	if (_root == nullptr)
//	//		return false;
//	//	BSTreeNode<K, V>* pr = nullptr;
//	//	BSTreeNode<K, V>* cur = Find(key);
//	//	if (cur == nullptr) { //没找到
//	//		return false;
//	//	}
//
//
//	//	if (cur->_left && cur->_right) {//左右子树都存在
//	//		BSTreeNode<K, V>* q = cur->_left;
//	//		while (q->_right != nullptr) {
//	//			q = q->_right;
//	//		}
//	//		swap(cur->_key, q->_key);
//	//		swap(cur->_value, q->_value);
//	//		cur = q;	
//	//	}
//
//	//	pr = Parent(_root, cur);
//	//	if (pr == nullptr) {//要删除头节点  且为左右树不同时存在
//	//		if (cur->_left == nullptr)
//	//			cur = cur->_right;
//	//		else
//	//			cur = cur->_left;
//	//	}
//	//	//要删非头节点 
//	//	else {
//	//		if (pr->_left == cur) {
//	//			if (cur->_left == nullptr)
//	//				cur= cur->_right;
//	//			else
//	//				cur = cur->_left;
//	//		}
//	//		else if (pr->_right == cur) {
//	//			if (cur->_left == nullptr)
//	//				cur = cur->_right;
//	//			else
//	//				cur = cur->_left;
//	//		}
//
//	//	}
//
//
//	//	delete cur;
//	//	return true;
//
//	//}
//
//	void _InOrder(Node* root) {
//		if (root == nullptr) {
//			return ;
//		}
//		_InOrder(root->_left);
//		cout << root->_key << ":" << root->_value << endl;
//		_InOrder(root->_right);
//	}
//	void InOrder() {
//		_InOrder(_root);
//	}
//
//private:
//	Node* _root = nullptr;
//};
//
//
//
//void TestBSTree()
//{
//	BSTree<string, string> dict;
//	dict.Insert("3", "33");
//	dict.Insert("9", "99");
//	dict.Insert("1", "11");
//	dict.Insert("7", "77");
//	dict.Insert("8", "88");
//	dict.Insert("2", "22");
//	dict.Insert("0", "00");
//	dict.Insert("4", "44");
//
//	dict.InOrder();
//	//dict.Erase("1");
//	//dict.Erase("9");
//	//dict.Erase("4");
//	dict.InOrder();
//	cout << endl;
//
//	string str;
//	while (cin >> str)  //测试查找
//	if(cin >> str)
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
//
//int main()
//{
//
//	TestBSTree();
//
//    return 0;
//}
/*






//class A
//{
//public:
//    A() :m_iVal(0) { test(); }
//    virtual void func() { std::cout << m_iVal << " "; }
//    void test() { func(); }
//public:
//    int m_iVal;
//};
//
//class B : public A
//{
//public:
//    B() { test(); }
//    virtual void func()
//    {
//        ++m_iVal;
//        std::cout << m_iVal << " ";
//    }
//};
//
//int main(int argc, char* argv[])
//{
//    A* p = new B;
//    p->test();
//    return 0;
//}
//
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//    
//};
//class Solution {
//public:
//    vector<vector<int>> levelOrderBottom(TreeNode* root) {
//        queue<TreeNode*> q1;
//        queue<TreeNode*> q2;
//        vector<vector<int>> num;
//        if (root == nullptr) {
//            return num;
//        }
//        q1.push(root);
//        TreeNode* cur = root;
//
//        while (!q1.empty() || !q2.empty()) {
//            if (!q1.empty()) {
//                num.push_back(vector <int>());
//                while (!q1.empty()) {
//                    cur = q1.front();
//                    num[num.size() - 1].push_back(cur->val);
//                    q1.pop();
//                    if (cur->left != nullptr)
//                        q2.push(cur->left);
//                    if (cur->right != nullptr)
//                        q2.push(cur->right);
//                }
//            }
//
//            if (!q2.empty()) {
//                num.push_back(vector <int>());
//                while (!q2.empty()) {
//                    cur = q2.front();
//                    num[num.size() - 1].push_back(cur->val);
//                    q2.pop();
//                    if (cur->left != nullptr)
//                        q1.push(cur->left);
//                    if (cur->right != nullptr)
//                        q1.push(cur->right);
//                }
//            }
//
//
//        }
//        reverse(num.begin(), num.end());
//        return num;
//    }
//};



//class A
//{
//public:
//    virtual void f()
//    {
//        cout << "A::f()" << endl;
//    }
//};
//
//class B : public A
//{
//    virtual void f()
//    {
//        cout << "B::f()" << endl;
//    }
//};
//
//
//
//int  main()
//{
//    A a1;
//    A* pa = (A*)new B;
//    pa->f();
//
//	return 0;
//}




//bool Erase(const K& key)
//{
//	Node* parent = nullptr;
//	Node* cur = _root;
//	while (cur)
//	{
//		if (cur->_key < key)
//		{
//			parent = cur;
//			cur = cur->_right;
//		}
//		else if (cur->_key > key)
//		{
//			parent = cur;
//			cur = cur->_left;
//		}
//		else
//		{
//			/* 1.左为空
//			 2.右为空
//			 3.左右都不为空*/
//			if (cur->_left == nullptr)
//			{
//				if (parent == nullptr)
//				{
//					_root = cur->_right;
//				}
//				else
//				{
//					if (cur == parent->_left)
//						parent->_left = cur->_right;
//					else
//						parent->_right = cur->_right;
//				}
//
//				delete cur;
//			}
//			else if (cur->_right == nullptr)
//			{
//				if (parent == nullptr)
//				{
//					_root = cur->_left;
//				}
//				else
//				{
//					if (cur == parent->_left)
//						parent->_left = cur->_left;
//					else
//						parent->_right = cur->_left;
//				}
//				delete cur;
//			}
//			else
//			{
//				// 替换法删除  左树的最大节点(最右节点) 或者是右树的最小节点(最左节点)
//				Node* minNodeParent = cur;  // 这里要注意不能初始化给空
//				Node* minNode = cur->_right;
//				while (minNode->_left)
//				{
//					minNodeParent = minNode;
//					minNode = minNode->_left;
//				}
//				swap(cur->_key, minNode->_key);
//				// 转换成删除minNode
//				// 因为minNode是作为空的节点，可以直接删除
//				if (minNodeParent->_right == minNode)
//					minNodeParent->_right = minNode->_right;
//				else
//					minNodeParent->_left = minNode->_right;
//				delete minNode;
//			}
//			return true;		
//		}
//	}
//	return false;
//}