#include <string>
#include <iostream>
using namespace  std;








///
//作业1标题
//黄牛抢票实例
//
//作业内容
//题目描述： 互斥锁保护多个线程对临界资源 - 全局变量tickets票数进行操作的过程。
//本题主要考察互斥锁的基本使用流程，体会互斥锁对临界区的保护功能
//
//
//
//作业2标题
//实现生产者与消费者模型（信号量 + 环形队列）
//作业内容
//1.通过信号量实现线程安全的环形队列，最终实现生产者与消费者模型
//
//
//
//作业3标题
//实现生产者与消费者模型（条件变量 + 互斥锁版本）
//作业内容
//1.通过条件变量 + 互斥锁实现线程安全的阻塞队列，最终实现生产者与消费者模型
//
//
//
//
//
//作业4标题
//完成两个线程通过条件变量实现交替打印的控制
//作业内容
//1.题目描述：线程A打印 - 我是线程A；线程B打印 - 我是线程B； 最终实现交替打印，不能出现连续的相同打印。
//2.本题主要考察条件变量的基本使用流程







//template<class T1, class T2>
//class Data
//{
//public:
//    Data() { cout << "Data<T1, T2>" << endl; }
//private:
//    T1 _d1;
//    T2 _d2;
//};
//
//template <class T1>
//class Data<T1, int>
//{
//public:
//    Data() { cout << "Data<T1, int>" << endl; }
//private:
//    T1 _d1;
//    int _d2;
//};
//
//template <typename T1, typename T2>
//class Data <T1*, T2*>
//{
//public:
//    Data() { cout << "Data<T1*, T2*>" << endl; }
//private:
//    T1 _d1;
//    T2 _d2;
//};
//
//template <typename T1, typename T2>
//class Data <T1&, T2&>
//{
//public:
//    Data(const T1& d1, const T2& d2)
//        : _d1(d1)
//        , _d2(d2)
//    {
//        cout << "Data<T1&, T2&>" << endl;
//    }
//private:
//    const T1& _d1;
//    const T2& _d2;
//};
//int main(){
//    Data<double, int> d1; // 调用特化的int版本     Data<T1, int>
//    Data<int, double> d2; // 调用基础的模板          Data<T1, T2>
//    Data<int*, int*> d3; // 调用特化的指针版本      Data<T1, T2>*
//    Data<int&, int&> d4(1, 2);  // 调用特化的指针版本  Data<T1&, T2&>
//    return 0;
//}



//template<typename Type>
//Type Max(const Type& a, const Type& b){
//    cout << "This is Max<Type>" << endl;
//    return a > b ? a : b;
//}
//template<>
//int Max<int>(const int& a, const int& b){
//    cout << "This is Max<int>" << endl;
//    return a > b ? a : b;
//}
//template<>
//char Max<char>(const char& a, const char& b){
//    cout << "This is Max<char>" << endl;
//    return a > b ? a : b;
//}
//int Max(const int& a, const int& b)
//{
//    cout << "This is Max" << endl;
//    return a > b ? a : b;
//}
//int main()
//{
//    Max(10, 20);        //This is Max            能够直接匹配int参数，调动非模板函数
//    Max(12.34, 23.45);  //This is Max<Type>     double类型参数没有最佳匹配函数，此时只能调动模板函数
//    Max('A', 'B');      //This is Max<char>     直接匹配char参数,调动非模板函数
//    Max<int>(20, 30);   //This is Max<int>      由于进行函数的int特化，所以会调动特化版本的模板函数
//    return 0;
//}



















//
//int firstUniqChar(string s) {
//    char c = s[0];
//    int num[26] = { 0 };
//    string v1;
//    for (int i = 0; i < s.size(); i++) {
//        num[s[i] - 'a']++;
//    }
//    for (int i = 0; i < 26; i++) {
//        if (num[i] == 1) {
//            v1.push_back(i + 'a');
//        }
//    }
//
//    for (int i = 0; i < s.size(); i++) {
//        if (v1.find(s[i])>=0 && v1.find(s[i])<s.size()) {
//            return i;
//        }
//    }
//    return -1;
//}

//string reverseOnlyLetters(string s) {
//    int i = s.size() - 1;
//    int j = 0;
//    while (j< i) {
//        if (isalpha(s[i])) {  //isalpha(s[i]) 判断一个字符是否为字母。
//            if (isalpha(s[j])) {
//                std::swap(s[i], s[j]);
//                i--;
//            }
//            j++;
//        }
//        else {
//            i--;
//        }
//    }
//    return s;
//}





    /*int getlength(string s) {
        int i = s.size();
        int c = 0;
        while (i >= 0 && s[i] != ' ') {
            c++;
            i--;
        }
        return c-1;
    }

int  main()
{
    string line;
    while (getline(cin, line))
    {

        cout <<getlength(line) << endl;
    }
    return 0;
}*/