#include <iostream>
#include <queue>
#include<deque>
#include <vector>
#include<functional>
#pragma warning(disable:4996)
using namespace std;
#include <stdlib.h>

//namespace myspace {
//    ////////////// 自己 实现堆 调整 /////////////
//    template <class T, class Container = vector<T>, class Compare = less<T> >
//    class priority_queue
//    {
//    public:
//        priority_queue() : c(), comp(Compare())
//        {}
//    
//        priority_queue(const T *first, const T *last)
//            : c(first, last),  comp(Compare())
//        {
//            int curpos = c.size()/2  - 1;
//            while (curpos >= 0) {
//                _adjust_dowm(curpos);
//                curpos--;
//            }          
//        }
//        bool empty() const {
//            return size() == 0;
//        }
//        size_t size() const {
//            return c.size();
//        }
//        const T& top() const {
//            return c.front();
//        }
//
//        void push(const T& x) {
//            c.push_back(x);
//            _adjustup(c.size() - 1);
//        }
//        void show() {  //这里自己写了一个show（）方便测试查看结构
//            for (int i = 0; i < size(); ++i) {
//                cout << c[i] << " ";
//            }
//            cout << endl;
//        }
//        void pop() {
//
//            std::swap(c.front(), c.back());
//            _adjust_dowm(0);
//            c.pop_back();      
//        }
//
//    private:
//        void _adjust_dowm(int start) {     //大堆向下调整
//            int n = c.size();
//            int i = start;     //父节点
//            int j = 2*i+1;     //子节点      
//            T tmp = c[i];
//            while (j <n) {
//                
//                if (j < n-1 && comp(c[j], c[j + 1]))
//                    j++;
//                if (comp(tmp ,c[j])) {
//                    c[i] = c[j];
//                    i=j;  
//                    j = 2 * i + 1;
//                }
//                else {
//                    break;
//                }
//            }
//            c[i] = tmp; //出循环时 i=j
//            
//        }
//        void _adjustup(int start)
//        {
//            int n = c.size();
//            int j = c.size() - 1;
//            int i = (j - 1) / 2;
//            T tmp = c[j];
//            while (j > 0) {
//                if (comp(c[i],tmp)) {
//                    c[j] = c[i];
//                    j=i;
//                    i= (j - 1) / 2;
//                }
//                else {
//                    break;
//                }
//            }
//            c[j] = tmp;
//        }
//
//    private:
//        Container c;
//        Compare comp;
//    };
//
//};


//int main() {
//    int arr[] = { 5,9,2,4,1 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    myspace::priority_queue<int, vector<int>, greater<int>>  pq1(arr,arr+n);
//    pq1.push(6);
//    pq1.push(11);
//    cout << pq1.size() << endl;
//    return 0;
//}


namespace myspace1
{
    /////////////priority_queue /////////   默认为大堆结构
        //利用这四个堆的函数实现
        //make_heap()  //默认大堆
        //push_heap()
        //pop_heap()
        //sort_heap()
    template <class T, class Container = vector<T>, class Compare = less<T> >
    class priority_queue
    {
    public:
        priority_queue() :sz(0), comp(Compare())
        {}

        template <class InputIterator>
        priority_queue(InputIterator first, InputIterator last)
            : c(first, last), comp(Compare())
        {
            make_heap(c.begin(), c.end(), comp);
            //根据传入的仿函数参数 comp=less<>()  制作大堆   comp=greater<>()则制作小堆
            sz = c.size();
        }
        bool empty() const {
            return sz == 0;
        }
        size_t size() const {
            return sz;
        }
        const T& top() const {
            return c.front();
        }

        void push(const T& x) {
            c.push_back(x);  //先把数据尾部插入
            push_heap(c.begin(), c.end(), comp);
            sz++;
        }
        void show() {  //这里自己写了一个show（）方便测试查看结构
            for (int i = 0; i < sz; ++i) {
                cout << c[i] << " ";
            }
            cout << endl;
        }
        void pop() {
            std::swap(c.front(), c.back());
            c.pop_back();
            pop_heap(c.begin(), c.end(), comp);
            sz--;
        }
    private:
        Container c;
        Compare comp;
        size_t sz;
    };
};















namespace myspace2
{

    /////////////stack/////////
    template<class T, class Con = deque<T> >
    class stack
    {
    public:
        stack()
        {}

        void push(const T& x) {
            _c.push_back(x);
        }
        void pop() {
            _c.pop_back();
        }
        T& top() {
            return _c.back();
        }
        const T& top()const {
            return _c.back();
        }
        size_t size()const {
            return _c.size();
        }
        bool empty()const {
            return _c.empty();
        }
    private:
        Con _c;
    };


    /////////////queue/////////
    template<class T, class Con = deque<T>>
    class queue
    {
    public:
        queue()
        {}

        void push(const T& x) {
            _c.push_back(x);
        }
        void pop() {
            _c.pop_front();
        }
        T& back() {
            return _c.back();
        }
        const T& back()const {
            return _c.back();
        }
        T& front() {
            return _c.front();
        }
        const T& front()const {
            return _c.front();
        }
        size_t size()const {
            return _c.size();
        }
        bool empty()const {
            
            return _c.empty();
        }
    private:
        Con _c;
    };
};

int main() {
 
  

  
    //int arr[] = { 5,9,2,4,1 };
    //myspace1::priority_queue<int, vector<int>, greater<int>>  pq1(arr, arr + 5);  //greater<int>()为小堆
    //pq1.show();
    //pq1.pop();
    //pq1.show();
    //pq1.push(6);
    //pq1.push(11);
    //pq1.show();
    //cout << pq1.size() << endl;
    //cout << endl;

    ////系统queue
        //queue<int>  s1;
        //for (int i = 0; i < 10; i++) {
        //    s1.push(i);
        //}
        //while (!s1.empty())
        //{
        //    cout << ' ' << s1.front();
        //    s1.pop();
        //}
        //cout << '\n';
        /// ///////////////////////
        //myspace2::stack<int> ss11;
        //for (int i = 0; i < 10; i++) {
        //    ss11.push(i);
        //}
        //while (!ss11.empty()){
        //    cout << ' ' << ss11.top();
        //    ss11.pop();
        //}
        //cout << '\n';
        //myspace2::queue<int> ss1;
        //for (int i = 0; i < 10; i++) {
        //    ss1.push(i);
        //}
        //while (!ss1.empty()){
        //    cout << ' ' << ss1.front();
        //    ss1.pop();
        //}
        //cout << '\n';
        //return 0;
}










//int main()
//{
//	priority_queue<int> a;
//	priority_queue<int, vector<int>, greater<int> > c;  //小堆
//	priority_queue<string> b;
//	for (int i = 0; i < 5; i++)
//	{
//		a.push(i);
//		c.push(i);
//	}
//	while (!a.empty())
//	{
//		cout << a.top() << ' ';
//		a.pop();
//	}
//	cout << endl;
//	while (!c.empty())
//	{
//		cout << c.top() << ' ';
//		c.pop();
//	}
//	cout << endl;
//	b.push("abc");
//	b.push("abcd");	
//	b.push("cbd");
//	while (!b.empty())	{
//		cout << b.top() << ' ';
//		b.pop();
//	}
//	cout << endl;
//	return 0;
//}





//void main()
//{
//	queue<char> Q;
//	char x, y;
//	x = 'n'; y = 'g';
//	Q.push(x); Q.push('i'); Q.push(y);
//	Q.pop(); Q.push('r'); Q.push('t'); Q.push(x);
//	Q.pop(); Q.push('s');
//	while (!Q.empty())
//	{
//		x = Q.front();
//		Q.pop();
//		cout << x;
//	};
//	cout << y;
//}


//void main()
//{
//	stack<char> S;
//	char x, y;
//	x = 'n'; y = 'g';
//	S.push(x); S.push('i'); S.push(y);
//	S.pop(); S.push('r'); S.push('t'); S.push(x);
//	S.pop(); S.push('s');
//	while (!S.empty())
//	{
//		x = S.top();
//		S.pop();
//		cout << x;
//	};
//	cout << y;
//
//}

