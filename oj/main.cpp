#include <string>
#include <iostream>
using namespace  std;








///
//��ҵ1����
//��ţ��Ʊʵ��
//
//��ҵ����
//��Ŀ������ ��������������̶߳��ٽ���Դ - ȫ�ֱ���ticketsƱ�����в����Ĺ��̡�
//������Ҫ���컥�����Ļ���ʹ�����̣���ụ�������ٽ����ı�������
//
//
//
//��ҵ2����
//ʵ����������������ģ�ͣ��ź��� + ���ζ��У�
//��ҵ����
//1.ͨ���ź���ʵ���̰߳�ȫ�Ļ��ζ��У�����ʵ����������������ģ��
//
//
//
//��ҵ3����
//ʵ����������������ģ�ͣ��������� + �������汾��
//��ҵ����
//1.ͨ���������� + ������ʵ���̰߳�ȫ���������У�����ʵ����������������ģ��
//
//
//
//
//
//��ҵ4����
//��������߳�ͨ����������ʵ�ֽ����ӡ�Ŀ���
//��ҵ����
//1.��Ŀ�������߳�A��ӡ - �����߳�A���߳�B��ӡ - �����߳�B�� ����ʵ�ֽ����ӡ�����ܳ�����������ͬ��ӡ��
//2.������Ҫ�������������Ļ���ʹ������







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
//    Data<double, int> d1; // �����ػ���int�汾     Data<T1, int>
//    Data<int, double> d2; // ���û�����ģ��          Data<T1, T2>
//    Data<int*, int*> d3; // �����ػ���ָ��汾      Data<T1, T2>*
//    Data<int&, int&> d4(1, 2);  // �����ػ���ָ��汾  Data<T1&, T2&>
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
//    Max(10, 20);        //This is Max            �ܹ�ֱ��ƥ��int������������ģ�庯��
//    Max(12.34, 23.45);  //This is Max<Type>     double���Ͳ���û�����ƥ�亯������ʱֻ�ܵ���ģ�庯��
//    Max('A', 'B');      //This is Max<char>     ֱ��ƥ��char����,������ģ�庯��
//    Max<int>(20, 30);   //This is Max<int>      ���ڽ��к�����int�ػ������Ի�����ػ��汾��ģ�庯��
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
//        if (isalpha(s[i])) {  //isalpha(s[i]) �ж�һ���ַ��Ƿ�Ϊ��ĸ��
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