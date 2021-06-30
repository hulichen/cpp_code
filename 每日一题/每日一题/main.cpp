#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>

#include <string>
#include<unordered_map>
#include<thread>
using namespace std;

//double myPow(double x, int n) {
//    if (n == 0) {
//        if (x == 0)
//            return 0;  //错误输入            
//        return 1;
//    }
//    double ret = x;
//    if (n < 0)
//        n = -n;
//    for (int i = 1; i < n; ++i)
//        ret *= x;
//    if (n < 0)
//        return (1 / ret);
//    return ret;
//}
//int  main()
//{
//    cout << myPow(3, -2) << endl;
//    return 0;
//}
//
//void mycmp(string s1, string s) {
//
//    string rets;
//    string num("618");
//    rets.resize(s.size() + 3, '0');
//    int up = 0;
//    for (int k = 0; k < 3; ++k) {
//        for (int i = s.size() - 1; i >= 0; --i) {
//            int tmp = (s[i] - '0') * (num[k] - '0') + (rets[i + k + 1] - '0') + up;
//            up = 0;
//            while (tmp > 9) {
//                up++;
//                tmp -= 10;
//            }
//            rets[i + 1 + k] = tmp + '0';
//        }
//
//        if (up) {
//            rets[0] += up;
//            up = 0;
//        }
//    }
//    rets = rets.substr(0, rets.size() - 2);
//    if (rets[0] == '0')
//        rets = rets.substr(1, rets.size());
//
//    if (rets.size() > s1.size()) 
//        cout << "Yes" << endl;
//  
//    else if(rets.size() < s1.size())
//        cout << "No" << endl;
//    else {
//        if (rets.compare(s1) >= 0)
//            cout << "Yes" << endl;
//        else
//            cout << "No" << endl;
//    }
//     
//    
//}
//
//
//int  main()
//{
//    string s1;
//    string s2;
//    while (cin >> s1 >> s2) {
//        mycmp(s1, s2);
//    }
//    return  0;
//}
// write your code here cpp

//int getnum(int n) {
//    vector<int> ret{ 1,2 };
//    if (n == 1)return 1;
//    if (n == 2) return 2;
//    for(int i = 3; i <= n; ++i) {
//        int tmp = ret[1];
//        ret[1] += ret[0];
//        if (ret[1] >= 10000)
//            ret[1] -= 10000;
//        ret[0] = tmp;
//    }
//    return ret[1];
//}
//
//void printnum(int  a) {
//    vector<int> ret(4, 0);
//    for (int i = 3; i>=0; --i) {
//        ret[i] = a % 10;
//        a /= 10;
//    }
//    for (auto e : ret) {
//        cout << e;
//    }
//}
//int  main()
//{
//    int  len = 0;
//    int n = 0;
//    while (cin >> len)
//    {
//        while (len--) {
//            cin >> n;
//            int a = getnum(n);
//            printnum(a);
//        }
//        cout << endl;
//    }
//    return 0;
//}

//int main()
//{
//    string s;
//    while (getline(cin, s)) {
//        bool flag = true;
//        unordered_map<char, int> m;
//        for(int i =0;i<s.size();++i) {
//            m[s[i]]++;  
//        }
//        for (int i = 0; i < s.size(); ++i) {
//            if (m[s[i]] == 1) {
//                flag = false;
//                cout << s[i] << endl;
//                break;
//            }
//        }
//        if(flag)
//            cout << -1 << endl;
//    }
//    return 0;
//}
///////day21////////

//int main() {
//    int n;
//    string s;
//    while (cin >> n, cin >> s) {
//        vector<int> mp3;
//        for (int i = 1; i <= n; ++i) {
//            mp3.push_back(i);
//        }
//        int ret = 1;
//        if (n <= 4) {
//            for (int i = 0; i < s.size(); ++i) {
//                if (s[i] == 'U') {
//                    ret--;
//                    if (ret <= 0)
//                        ret = n;
//                }
//                if (s[i] == 'D') {
//                    ret++;
//                    if (ret > n)
//                        ret = 1;
//                }
//            }
//
//            for (int i = 1; i <= n; ++i)
//                cout << i << ' ';
//            cout << endl;
//        }
//
//        else {
//            int minnum = 1;
//            int maxnum = 4;
//            for (int i = 0; i < s.size(); ++i) {
//                if (s[i] == 'U') {
//                    ret--;
//                              
//                    if (ret <= 0) {
//                        ret = n;
//                        maxnum = n;
//                        minnum = n - 3;
//                    }
//                    if (ret<minnum || ret>maxnum) {
//                        maxnum--;
//                        minnum--;
//                    }
//                }
//                if (s[i] == 'D') {
//                    ret++;    
//                    if (ret > n) {
//                        ret = 1;
//                        minnum = 1;
//                        maxnum = 4;
//                    }
//                    if (ret<minnum || ret>maxnum) {
//                        maxnum++;
//                        minnum++;
//                    }
//                }
//            }
//            for (int i = minnum; i <= maxnum; ++i)
//                cout << i << ' ';
//            cout << endl;
//        }
//        cout << ret << endl;
//        s.clear();
//    }
//    return 0;
//
//}






//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    int t = 0;
//    cin >> t;
//    for (int i = 0; i < t; ++i) {
//        int n = 0, k = 0;
//        cin >> n >> k;
//        int num = 2 * n;
//        vector<int> v1(num);
//        for (int i = 0; i < num; ++i)
//            cin >> v1[i];
//
//        while (k--) {
//            vector<int> tmp(v1.begin(), v1.end());
//            for (int i = 0; i < n; ++i) {
//                v1[2 * i] = tmp[i];
//                v1[2 * i + 1] = tmp[i + n];
//            }
//        }
//
//        for (int i = 0; i < num; ++i) {
//            cout << v1[i] << ' ';
//        }
//        cout << endl;
//    }
//    return 0;
//}
//
//bool issubstr(string s1, string s2) {
//    for (int i = 0, j = 0; i < s2.size(); ++i) {
//        while (j < s1.size() && s1[j] == s2[i]) {
//            i++; 
//            j++;
//        }
//        if (j == s1.size())
//            return true;
//    }
//    return false;
//}
//int GetMaxSubstr(string s1, string s2) {
//    int mlen = 0;
//    for (int i = 0; i < s1.size(); ++i) {
//        for (int j = i + 1; j <= s1.size(); ++j) {
//            if (issubstr(s1.substr(i, j - i),s2)){
//                mlen = max(mlen, j - i);
//            }
//        }
//    }
//    return mlen;
//}
//
//int main() {
//    string s1, s2;
//    while (cin >> s1, cin >> s2) {
//
//        if (s1.size() > s2.size()) {
//            cout << GetMaxSubstr(s2, s1);
//        }
//        else
//            cout << GetMaxSubstr(s1, s2);
//
//        s1.clear();
//        s2.clear();
//    }
//    return 0;
//}

///////////thread////////
//void fun() {
//    cout << "fun" << endl;
//}
//class A
//{
//public:
//    A(int a) : _a(a)
//    {}
//    // 显式缺省构造函数，由编译器生成
//    A() = default;
//    // 在类中声明，在类外定义时让编译器生成默认赋值运算符重载
//    A& operator=(const A& a);
//private:
//    int _a;
//};
//A& A::operator=(const A& a) = default;
//int main()
//{
//    A a1(10);
//    A a2;
//    a2 = a1;
//    return 0;
//}
//int main()
//{
//    thread* th_ar[10];
//    for (int i = 0; i < 10; ++i)
//    {
//        th_ar[i] = new thread(fun);
//        th_ar[i]->detach();
//    }
//
//    return 0;
//}












/////////////day 18//////////



///////day17//////////
//string  strsum(string s1, string s2) {
//    int len1 = s1.size(), len2 = s2.size();
//    int maxlen = max(s1.size(), s2.size());
//    reverse(s1.begin(), s1.end());
//    reverse(s2.begin(), s2.end());
//    s1.resize(maxlen + 1, '0');
//    s2.resize(maxlen + 1, '0');
//
//    string ret(maxlen + 1, '0');
//    int flag = 0;
//    for (int i = 0; i < maxlen + 1; ++i) {    
//        int a = s1[i] - '0' + s2[i] - '0' + flag;
//        if (a > 9) {
//            a %= 10;
//            flag = 1;
//        }
//        else
//            flag = 0;
//        ret[i] = a + '0';           
//    }
//    if (ret[maxlen] == '0')
//        ret.pop_back();
//    reverse(ret.begin(), ret.end());
//    return ret;
//}
//
//int main()
//{
//    string s1;
//    string s2;
//    while (cin >> s1, cin >> s2) {
//        string s3 = strsum(s1, s2);     
//        cout << s3 << endl;
//    }
//    return 0;
//}

//int  main()
//{
//    int n;
//    while (cin >> n) {
//        vector<int> num1(n + 3, 0);
//        vector<int> num2(n + 3, 0);
//        num1[2] = 1;
//        for (int i = 1; i <= n; i++) {
//            if (i % 2 == 1 && i != 1) {
//                for (int j = 2; j <= n + 2; ++j) {
//                    num1[j] = num2[j] + num2[j - 1] + num2[j - 2];
//                }
//            }
//            else if (i % 2 == 0) {
//                for (int j = 2; j <= n + 2; ++j) {
//                    num2[j] = num1[j] + num1[j - 1] + num1[j - 2];
//                }
//            }
//        }
//
//        if (n % 2 == 0) {
//            for (int i = 2; i < num2.size(); ++i) {
//                if (num2[i] % 2 == 0) {
//                    cout << i - 1;
//                    break;
//                }
//                 
//            }
//        }
//        else {
//            for (int i = 2; i < num1.size(); ++i) {
//                if (num1[i] % 2 == 0) {
//                    cout << i - 1;
//                    break;
//                }
//                  
//            }
//        }
//
//    }
//
//    return 0;
//}
////////////// day 16////



///// <summary>
///// /链接：https://www.nowcoder.com/questionTerminal/d290db02bacc4c40965ac31d16b1c3eb
//来源：牛客网
//
//扑克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A、2各4张，小王1张，大王1张。牌面从小到大用如下字符和字符串表示（其中，小写joker表示小王，大写JOKER表示大王）：
//3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
//输入两手牌，两手牌之间用"-"连接，每手牌的每张牌以空格分隔，"-"两边没有空格，如：4 4 4 4 - joker JOKER。
//请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR。
//基本规则：
//（1）输入每手牌可能是个子、对子、顺子（连续5张）、三个、炸弹（四个）和对王中的一种，不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列；
//（2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系（如，对子跟对子比较，三个跟三个比较），不考虑拆牌情况（如：将对子拆分成个子）；
//（3）大小规则跟大家平时了解的常见规则相同，个子、对子、三个比较牌面大小；顺子比较最小牌大小；炸弹大于前面所有的牌，炸弹之间比较牌面大小；对王是最大的牌；
//
//（4）输入的两手牌不会出现相等的情况
/// </summary>

//#include<iostream>
//#include<string>
//#include<unordered_map>
//using namespace std;
//unordered_map<char, int> helper{ {'3',1},{'4',2},{ '5',3 },{ '6',4 },{ '7',5 },{ '8',6 },
//{ '9',7 },{ '1',8 },{ 'J',9 },{ 'Q',10 },{ 'K',11 },{ 'A',12 },{'2',13} };
//string del_0(string str) {
//    while (str.find('0') != string::npos)
//        str.erase(str.find('0'), 1);
//    return str;
//}
//int main() {
//    string str, s1, s2, s1_, s2_;
//    while (getline(cin, str)) {
//        s1_ = str.substr(0, str.find('-'));
//        s1 = del_0(s1_);
//        s2_ = str.substr(str.find('-') + 1);
//        s2 = del_0(s2_);
//        if (s1 == "joker JOKER" || s2 == "joker JOKER") cout << "joker JOKER" << endl;
//        else if (s1.size() == 7 || s2.size() == 7) {//有炸弹
//            if (s1.size() == 7 && s2.size() == 7)//炸弹比较
//                if (helper[s1[0]] > helper[s2[0]]) cout << s1_ << endl;
//                else cout << s2_ << endl;
//            else if (s1.size() == 7) cout << s1_ << endl;
//            else cout << s2_ << endl;
//        }
//        else if (s1.size() == s2.size())//其余只能同等长度比较
//            if (helper[s1[0]] > helper[s2[0]]) cout << s1_ << endl;
//            else cout << s2_ << endl;
//        else cout << "ERROR" << endl;
//    }
//}

//static vector<string>  vv = { "3","4","5","6","7","8","9","10",
//                             "J","Q","K","A","2","joker","JOKER" };
//bool isduizi(vector<string> v, int i) {
//    return strcmp(v[i].c_str(), v[i + 1].c_str()) == 0;
//}
//bool issanlian(vector<string> v, int i) {
//    return  strcmp(v[i].c_str(), v[i + 1].c_str()) == 0
//        && strcmp(v[i + 1].c_str(), v[i + 2].c_str()) == 0;
//}
//bool iszhadan(vector<string> v, int i) {
//    return  strcmp(v[i].c_str(), v[i + 1].c_str()) == 0
//        && strcmp(v[i + 1].c_str(), v[i + 2].c_str()) == 0
//        && strcmp(v[i + 2].c_str(), v[i + 3].c_str()) == 0;
//}
//bool isshunzi(vector<string> v, int i, int j) {
//    int idx = 0;
//    for (; idx < v.size(); ++idx) {
//        if (strcmp(vv[idx].c_str(), v[i].c_str()) == 0) {
//            break;
//        }
//    } 
//    if (idx <= 8){    //每只次判断是否五连
//        int start = i, end = j;
//        for (; start <= end; ) {
//            if (idx < 13&&strcmp(v[start++].c_str(), vv[idx++].c_str()) !=0 ) {
//                return false;
//            }    
//        }
//        return true;
//    }
//    return false;
//}
//
//bool iswangzha(vector<string> v, int i) {
//    return strcmp(v[i].c_str(), v[13].c_str()) == 0
//        && strcmp(v[i + 1].c_str(), v[14].c_str()) == 0;        
//}
//
//int Cmp(vector<string> v1, vector<string> v2) {
//    int ret = 0;  ////0 ERROR   1  v1大  -1 v2大
//    int len1 = v1.size(), len2 = v2.size();
//    if (len1 == len2) {
//        if (len1 >= 5) {
//            for (int i = 0; i < len1 - 5; i++) {
//                if (isshunzi(v1, i, i + 5) && isshunzi(v2, i, i + 5))
//                    continue;
//                else                   
//                    return 0;
//            }
//            return strcmp(v1[0].c_str(), v2[0].c_str());
//        }
//
//        if (len1 == len2 == 4) {
//            if (iszhadan(v1, 0) && iszhadan(v2, 0)) {
//                return strcmp(v1[0].c_str(), v2[0].c_str());
//            }
//            return 0;
//        }
//
//        if (len1 == len2 == 3) {
//            if (issanlian(v1, 0) && issanlian(v2, 0)) {
//                return strcmp(v1[0].c_str(), v2[0].c_str());
//            }
//            return 0;
//        }
//
//        if (len1 == len2 == 2) {
//            if (isduizi(v1, 0) && isduizi(v2, 0)) {
//                return strcmp(v1[0].c_str(), v2[0].c_str());
//            }
//            return 0;
//        }
//    }
//
//}
//
//int  main()
//{
//    vector<string> v1 = { "10","J","Q","k","A","2"};
//    vector<string> v2= { "6", "7", "8", "9", "10" };
//    cout << isshunzi(v1, 0, 4);
//    string s;
//    vector<string> v1;
//    vector<string> v2;
//    while (cin >> s) {
//        int i = 0;
//        int j = 0;
//        while (s[i] != '-') {
//            while (s[i] != ' ') {
//                v1[j].push_back(s[i]);
//            }
//            i++;
//            j++;
//        }
//        i++;
//        for (j = 0; i < s.size(); ++i) {
//            while (s[i] != ' ') {
//                v2[j].push_back(s[i]);
//            }
//            i++;
//            j++;
//        }
//
//        int a = Cmp(v1, v2);
//       
//
//
//
//    return 0;
//}

//int count(int n) {
//    if (n == 1)
//        return 0;
//    
//    int count = 0;
//        for(int i = 2; i <=n; ++i) {
//            int sum = 1;
//            for (int j = 2; j <=i / 2; ++j) {
//                if (i % j == 0) {
//                    sum += j;
//                }    
//            }
//            if (sum == i) {
//                count++;
//            }
//        }
//    return count;
//}
//int main()
//{
//    int n;
//    cin >> n;
//    if (n < 1)
//        return -1;
//    cout << count(n);
//    return 0;
//}







////////////// day 15////
//
//int findMinimum(int n, vector<int> left, vector<int> right) {
//    int num = 0;
//    int left0 = 0;
//    int right0 = 0;
//    int leftmin = INT_MAX;
//    int rightmin = INT_MAX;
//    int leftsum = 0;
//    int rightsum = 0;
//    for (int i = 0; i < n; i++) {
//       
//        if (left[i] == 0||right[i]==0) {
//            num += left[i];
//            num += right[i];
//        }
//        else {
//            leftmin = min(leftmin, left[i]);
//            rightmin = min(rightmin, right[i]);
//            leftsum += left[i];
//            rightsum += right[i];
//        }
//    }
//    int a = min(leftsum- leftmin + 1, rightsum - rightmin + 1);
//    num += (a + 1);
//   
//    return num;
//}
//
//int  main()
//{
//
//    //vector<int> left{ 1, 2, 0, 1, 3, 1 }; 
//    //vector<int> right{ 0, 0, 0, 2, 0, 1 };
//    vector<int> left{ 0, 3, 1, 0, 0, 0, 2 };  
//    vector<int> right{ 3, 2, 1, 4, 4, 4, 1 };
//    int n = left.size();
//    cout << findMinimum(n,left,right) << endl;
//}


//
//int  main()
//{
//    int n;
//    cin >> n;
//    vector<int> num(n, 0);
//    vector<int> num1;  //+
//    vector<int> num2;  //**
//    for (int i = 0; i < n; ++i){
//        cin >> num[i];
//    }
//
//    for (int i = 0; i < num.size(); ++i) {
//        int n = num1.size();
//        for (int j = 0; j < n; ++j) {
//                num1.push_back(num[i]+num1[j]);
//                num2.push_back(num[i]* num1[j]);  
//       }
//        num1.push_back(num[i]);
//        num2.push_back(num[i]);
//    }
//    int c = 0;
//    for (int i = 0; i < num1.size(); ++i) {
//        if (num1[i] > num2[i])
//            c++;
//    }
//    cout << c-1;
//    return 0;
//}

//class Data {
//public:
//    Data(int year, int month, int day) : m_year(year), m_month(month), m_day(day)
//    {}
//
//    int getOutDay()
//    {
//        int sumday = 0;
//        if (Is29day() && m_month >= 3) {
//            num[2] = 29;
//        }
//        for (int i = 1; i < m_month; i++) {
//            sumday += num[i];
//        }
//        sumday += m_day;
//        num[2] = 28;
//        return sumday;
//    }
//private:
//    bool Is29day() {
//        return (m_year % 4 == 0) && (m_year % 100 != 0 || m_year % 400 == 0);
//    }
//private:
//    int m_year;
//    int m_month;
//    int m_day;
//    int num[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//};
//
//int  main()
//{
//    int year, month, day;
//    cin >> year;
//    cin >> month;
//    cin >> day;
//    Data  d1(year, month, day);
//    cout << d1.getOutDay();
//    return  0;
//}



//int  main()
//{
//    string str;
//    getline(cin, str);
//    vector<string> v;
//    
//    int idx = 0;
//    while (idx < str.size()) {
//        while (idx <= str.size() && str[idx] == ' ')
//            idx++;
//        string s;
//        if (idx <= str.size() && str[idx] == '\"') {
//            idx++;
//            while (idx <= str.size() &&  !(str[idx] == '\"' && (idx+1 <= str.size()-1 && str[idx+1] == ' '))) {
//                s.push_back(str[idx]);
//                idx++;
//            }
//        }
//        else {
//            while (idx <= str.size()&&str[idx] != ' ') {
//                s.push_back(str[idx]);
//                idx++;
//            }
//        }
//        idx++;
//        v.push_back(s);
//        while (idx <= str.size()&&str[idx] == ' ')
//            idx++;
//    }
//    cout << v.size()<<endl;
//    for (auto e : v)
//        cout << e << endl;
//    return 0;
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<int> maxyueshu(int a,int b) {
//    vector<int> v;
//    for (int i = a / 2; i > 1; --i) {
//        if (a % i == 0&&i<=b)
//            v.push_back(i);
//    }
//    return v;
//}
//
//int  main()
//{
//    int n, m;
//    cin >> n;
//     cin >> m;
//    int c = 0;
//    int i = n;
//    while (i != m) {
//        vector<int> v = maxyueshu(i,m-i);
//        bool flag = false;
//        i += v[0];
//        if (i > m) {
//            i -= v[0];
//            for (int j = 1; j < v.size(); ++j) {
//                if (i + v[j] <= m) {
//                    i += v[j];
//                    break;
//                    flag = true;
//                }
//            }
//        }
//        if (!flag) {
//              ///  
//        }
//        c++;
//    }
//    cout << c;
//    return 0;
//}

//int binInsert(int n, int m, int j, int i) {
//
//    return n|=(m<<j);
//}
//
//void main() {
//    cout << binInsert(1024, 19, 2, 6) << endl;
//}
//void bit_set(unsigned char* p_data, unsigned char position, bool flag) {
//    
//    if (flag && !((*p_data >> position) & 1 ==0))
//        (*p_data) |=  (1 << position);
//    else if (!flag && ((*p_data >> position)&1==1))
//        (*p_data)  &= (0 << position);
//
//
//}
//void  main()
//{
//    unsigned char value = 43;
//    bit_set(&value, 2, true);
//    cout << value << endl;  //47
//}




//

//int main()
//{
//    int n;
//    vector<int> num;
//    cin >> n;
//    for (int i = 0; i < 8; ++i) {
//        num.push_back(n % 10);
//        n /= 10;
//    }
//    int count = 0;
//    int maxcount = 0;
//    bool first_flag = true;
//    for (int i = 0; i <7; ++i) {
//        if (num[i] == 1 && num[i + 1] == 1) {
//            if (first_flag) {
//                first_flag = false;
//                count++;
//            }
//            count++;
//            maxcount = max(maxcount, count);
//        }
//        else {
//            count = 0;
//            first_flag = true;
//        }
//    }
//    cout << maxcount;
//    return 0;
//}


//
//int main()
//{
//    int n;
//    vector<int> num;
//    cin >> n;
//    for (int i = 8; i >=0; --i) {
//        num.push_back((n >> i) & 1);
//    }
//    int count = 0;
//    int maxcount = 0;
//    bool first_flag = true;
//    for (int i = 0; i < num.size() - 1; ++i) {  
//        if (num[i] == 1&& num[i+1]==1 ) {
//            if (first_flag) {
//                first_flag = false;
//                count++;
//            }          
//            count++;
//            maxcount = max(maxcount, count);
//        }
//        else {
//            count = 0;
//            first_flag = true;
//        }
//    }
//    cout << maxcount;
//    return 0;
//}


//int getLCA(int a, int b) {
//    while ((a != b) && (a/2 != b) && (b / 2 != a)) {
//        if (b > a)
//            b = b / 2;
//        else
//            a = a / 2;
//    }
//    if (a == b || a / 2 == b)
//        return b;
//    if (b / 2 == a)
//        return a;
//}
//
//int  main() {
//    cout<<getLCA(127,128);
//}

//class Solutsdion {
//public:
//    bool containsDuplicate(vector<int>& nums) {
//        unordered_map<int, int> mp; 
//        for (auto e : nums) {
//            mp[e]++;
//            if (mp[e] >= 2) 
//                return true;
//        }
//        return false;
//    }
//};
//
//class Solution25354 {
//public:
//    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//        vector<int> v;
//        unordered_map<int, int> mp;
//        for (auto e : nums1) {
//            mp[e]++;
//        }
//        
//        for (auto e : nums2) {
//            auto it = mp.find(e);
//            if (it != mp.end()) {
//                mp[e]--;
//                if ((*it).second >= 0) {
//                    v.push_back(e);
//                }          
//            }
//        }
//        return  v;
//    }
//};
//
//class Solution4546 {
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        vector<int> v;
//        unordered_map<int, int> mp;
//        for (auto e : nums1) {
//            mp[e];
//        }
//
//        for (auto e : nums2) {
//            auto it = mp.find(e);
//            if (it!= mp.end()) {
//                mp[e]--;
//                if ((*it).second = -1) {
//                    v.push_back(e);
//                }
//            }               
//        }
//        return v;
//    }
//};
//class Solution1 {
//public:
//    int repeatedNTimes(vector<int>& nums) {
//        unordered_map<int, int> mp;
//        for (auto e : nums) {
//            mp[e]++;
//            if (mp[e] == 2)
//                return e;
//        }
//        return -1;
//    }
//};

//class Board {
//public:
//    bool check(int i, int j, vector<vector<int> >& board) {
//        if ((board[i - 1][j - 1] == 1 && board[i + 1][j + 1] == 1) ||
//            (board[i - 1][j + 1] == 1 && board[i + 1][j - 1] == 1) ||
//            (board[i][j + 1] == 1 && board[i][j - 1] == 1) ||
//            (board[i - 1][j] == 1 && board[i + 1][j] == 1))
//            return true;
//        return false;
//    }
//    bool checkWon(vector<vector<int> > board) {
//        for (int i = 1; i < board.size(); ++i) {
//            for (int j = 1; j < board[0].size() - 1; ++j) {
//                if (board[i][j] == 1 && check(i, j, board)) {
//                    return true;
//                }
//            }
//        }
//        for (int i = 0; i < board.size(); i = i + board.size() - 1) {
//            for (int j = 0; j < board[0].size() - 2; ++j) {
//                if (board[i][j] == board[i][j + 1] == board[i][j + 2] == 1)
//                    return true;
//            }
//        }
//        for (int j = 0; j < board[0].size(); j += board[0].size() - 1) {
//            for (int i = 0; i < board.size() - 2; ++i) {
//                if (board[i][j] == board[i + 1][j] == board[i + 2][j] == 1)
//                    return true;
//            }
//        }
//        return false;
//    }
//};

//
//int main() {
//    int A[] = { 2,1,2,55,6,6,999,45,26 };
//    unordered_map<int, int> m;
//    for (auto e : A)
//        m[e];
//
//    return 0;
//}


//#include <iostream>
//#include <string>
//#include <string.h>
//using namespace std;
//
//int main()
//{
//    string s;
//    cin >> s;
//    int score = 0;
//    bool flag_C = false;
//    bool flag_c = false;
//    int len_num = 0;
//    int len_char = 0;
//    for (int i = 0; i < s.size(); ++i) {
//        if (isdigit(s[i])) {
//            len_num++;
//        }
//        else if (isalpha(s[i])) {
//            if (islower(s[i]))
//                flag_c = true;
//            else
//                flag_C = true;
//        }
//        else
//            len_char++;
//    }
//
//    if (s.size() >= 8) score += 25;
//    else if (s.size() >= 5) score += 10;
//    else score += 5;
//
//    if (flag_c || flag_C) score += 10;
//    if (flag_c && flag_C) score += 10;
//    if (len_num >= 1) {
//        score += 10;
//        if (len_num >= 2)
//            score += 10;
//    }
//    if (len_char >= 1) {
//        score += 10;
//        if (len_char >= 2)
//            score += 15;
//    }
//
//    if (len_num && flag_c && flag_C && len_char) score += 5;
//    else if (len_num && len_char && (flag_c || flag_C));
//    else if (len_num && flag_c)  score += 2;
//
//    if (score >= 90) cout << "VERY_SECURE";
//    else if (score >= 80) cout << "SECURE";
//    else if (score >= 70) cout << "VERY_STRONG";
//    else if (score >= 60) cout << "STRONG";
//    else if (score >= 50) cout << "AVERANG";
//    else if (score >= 25) cout << "WEAK";
//    else cout << "VERY_WEAK";
//    return 0;
//}




//
//class Solution00 {
//public:
//    vector<string> uncommonFromSentences(string s1, string s2) {
//        vector<string> v;
//        unordered_map<string, int> mp;
//        string s;
//        for (int i = 0; i < s1.size(); ++i) {
//            while (s1[i] != ' ' && s1[i] != '\0') {
//                s += s1[i++];
//            }
//            unordered_map<string, int>::iterator it = mp.find(s);
//            if (it == mp.end()) {
//                mp.insert({ s,1 });
//            }
//            else {
//                (*it).second++;
//            }
//            s.clear();
//        }
//
//        for (int i = 0; i < s2.size(); ++i) {
//            while (s2[i] != ' ' && s2[i] != '\0') {
//                s += s2[i++];
//            }
//            unordered_map<string, int>::iterator it = mp.find(s);
//            if (it == mp.end()) {
//                mp.insert({ s,1 });
//            }
//            else {
//                (*it).second++;
//            }
//            s.clear();
//        }
//
//        for (auto e : mp) {
//            if (e.second == 1) {
//                v.push_back(e.first);
//            }
//        }
//        return v;
//    }
//};



//int Getminnum(int a, int b) {
//    int m_max = max(a, b);
//    int m_min = min(a, b);
//    int i = m_max;
//    while (1) {
//        
//        if (i % m_max == 0 && i % m_min == 0) {
//            break;
//        }
//        i += m_max;
//    }
//    return i;
//}
//
//int main() {
//    int a, b;
//
//    cin >> a;
//    cin >> b;
//    cout << Getminnum(a, b);
//    return 0;
//}
//
//#include <iostream>
//#include <vector>
//using namespace std;
//bool Isnum(int a) {
//    bool numfalg = false;
//    for (int j = 2; j <= a / 2; ++j) {
//        if (a % j == 0)
//            numfalg = true;
//    }
//    return !numfalg;
//}
//int  main()
//{
//    int n;
//    cin >> n;
//    vector<int>  num;
//    if (n == 2) {
//        cout << 2;
//    }
//    else if (n == 3) {
//        cout << 2 << ' ' << 3;
//    }
//    else {
//        num.push_back(2);
//        num.push_back(3);
//    }
//
//    bool flag = true;
//    for (int i = 5; i <= n;) {
//        if (Isnum(i)) {
//            num.push_back(i);
//        }
//        if (flag) {
//            i += 2;
//            flag = false;
//        }
//        else {
//            i += 4;
//            flag = true;
//        }
//    }
//    for (auto e : num) {
//        cout << e << ' ';
//    }
//
//    return 0;
//}
//int main() {
//	int h, w;
//	cin >> h;
//	cin >> w;
//
//	vector<vector<bool>> num(h,vector<bool> (w,true) );
//	for (int i = 0; i < h; i++) {
//		for (int j = i; j < w; j++) {
//			if (num[i][j] == true) {
//				if (i - 2 >= 0)
//					num[i - 2][j] = false;
//				if(i+2 <h)
//					num[i + 2][j] = false;
//				if(j-2>=0)
//					num[i][j-2] = false;
//				if (j +2 <w)
//					num[i][j + 2] = false;
//			}
//		}
//	}
//
//	for (int i = 0; i < h; i++) {
//		for (int j = 0; j < w; j++) {
//			if ( (i != j) && num[i][j] ==true) {
//				if (i - 2 >= 0)
//					num[i - 2][j] = false;
//				if (i + 2 < h)
//					num[i + 2][j] = false;
//				if (j - 2 >= 0)
//					num[i][j - 2] = false;
//				if (j + 2 < w)
//					num[i][j + 2] = false;
//			}
//		}
//	}
//	int count = 0;
//	for (int i = 0; i < h; i++) {
//		for (int j = 0; j < w; j++) {
//			if (num[i][j] == true)
//				count++;
//		}
//	}
//	cout << count;
//	return 0;
//}

//#include <queue>
//
//	int StrToInt(string str) {
//		queue<int> q;
//		int i = 0;
//		int flag = 1;
//		if (str[0] == '-' || str[0] == '+') {
//			if (str[0] == '-') {
//				flag = -1;
//			}
//			i++;
//		}
//
//		for (; i < str.size(); ++i) {
//			if (str[i] <= '9' && str[i] >= '0') {
//				q.push(str[i] - '0');
//			}
//			else
//				return 0;
//		}
//
//		int  ret = flag * q.front();
//		q.pop();
//
//		if (ret == 0)
//			return 0;
//
//		while (!q.empty()) {
//			ret = ret * 10 + q.front();
//			q.pop();
//		}
//		return ret;
//	}
//
//
//
//int main() {
//
//	string str1("-56134434234219");
//	int a = StrToInt(str1);
//	cout << a << endl;
//	return 0;
//}

//int main()
//{
//
//    //cout << INT_MIN;
//   /* int n = 0;
//    cin >> n;
//    vector<int> num;
//    for (int i = 0; i < n; i++) {
//        int a;
//        cin >> a;
//        num.push_back(a);
//    }
//    int presum = INT_MIN;
//    int sum = 0;
//    for (int i = 0; i < n; i++) {
//        sum += num[i];
//        presum = max(sum, presum);
//        if (sum < 0) {
//            sum = 0;
//        }
//    }
//    cout << presum;
//    return 0;*/
//}
//


//#include <iostream>
//#include <string>
//using namespace std;
//
//bool Iscycle(const string& s) {
//    int n = s.size() - 1;
//    int i = 0;
//    while (i <= n) {
//        if (s[i] == s[n]) {
//            i++;
//            n--;
//        }
//        else
//            return false;
//    }
//    return true;
//}
//
//int main()
//{
//    string s1;
//    string s2;
//    cin >> s1;
//    cin >> s2;
//    int count = 0;
//    for (int i = 0; i < s1.size(); i++) {
//        string s3 = s1;
//         s3.insert(i, s2);
//        if (Iscycle(s3)) {
//            count++;
//        }
//    }
//    string s3 = s1 + s2;
//    if (Iscycle(s3)) {
//        count++;
//    }
//    cout << count;
//    return 0;
//}
//





















//#include<string>
//#include<iostream>
//using namespace std;
//#pragma warning(disable:4996)
//
//int  main() {
//    int a = 0, b = 0, c = 0, d = 0;
//    cin>> a;
//    cin >> b;
//    cin >> c;
//    cin >> d;
//    cout << a << " " << b << endl;
//
//    int A = (a + c) / 2;
//    int B = (b + d) / 2;
//    int C = B - b;
//    if (C == d - B && A >= 0 && A <= 30 && B >= 0 && B <= 30 && C >= 0 && C <= 30) {
//        cout << A << ' ' << B << ' ' << C;
//    }
//    else
//        cout << "No";
//    return 0;
//}




//#include <stack>
//#include<string>
//#include<iostream>
//#include <algorithm>
//using namespace std;
//#pragma warning(disable:4996)
//
//void ten2n(int num, int n) {
//   int a;
//   stack<char> stk;
//    while (num!=0) {
//        a = num % n;
//        num /= n;
//        if (a > 9) {
//            stk.push(a-10+'A');
//        }
//        else
//            stk.push(a + '0');
//    }
//    while (!stk.empty()) {
//        cout << stk.top();
//        stk.pop();
//    } 
//}
//
//int  main() {
//    int  num;
//    int  n;
//    scanf("%d %d", &num, &n);
//    if (n >= 2 && n <= 16) {
//        ten2n(num, n);
//    }  
//    return 0;
//}