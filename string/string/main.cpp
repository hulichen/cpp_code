#include <iostream>
#include <string.h>
#include <string>
#include <assert.h>
using namespace std;
#pragma warning(disable:4996)

namespace bit

{
    class string
    {
        friend ostream& operator<<(ostream& _cout, const bit::string& s);
        friend istream& operator>>(istream& _cin, bit::string& s);
    public:
        typedef char* iterator;  //指针充当迭代器
    public:
        string() : _str(nullptr), _size(0), _capacity(0)
        {}

        string(const char* str="")
        {
            _size = strlen(str);
            _capacity = _size;
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }

        string(const string& s):_str(nullptr), _size(0), _capacity(0)
        {
            string tmp(s._str);
            this->swap(tmp);
        }

        string& operator=(const string& s) {
            if (*this != s) {
                string tmp(s);
                this->swap(tmp);
            }
            return *this;
        } 

        ~string() {
            delete[] _str;
            _str = nullptr;
            _size = _capacity = 0;
        }

    public:

        iterator begin() {
            return _str;
        }
        iterator end() {
            return _str + _size;
        }
    public:
        void push_back(char c) {
            if (_size == _capacity) {
                resize(_size + 1, c);
            }
            else{
                _str[_size] = c;
                _size++;
                _str[_size] = '\0';
            }        
        }

        string& operator+=(char c) {
            push_back(c);
            return *this;
        }

        void append(const char* str) {
            
            _size += strlen(str);
            if (_capacity < _size) {
                reserve(_size);
            }
            strcat(_str, str);          
        }

        string& operator+=(const char* str) {           
            append(str);
            return *this;
        }

        void clear() {
            _size = 0;
            _str[0] = '\0';
        }

        void swap(string& s) {
            std::swap(_str, s._str);
            _size = s._size;
            _capacity = s._capacity;    
        }

        const char* c_str()const {
            return _str;
        }


        ///////////////////////////////////////////////////////////////

        //// capacity

        size_t size()const {
            return _size;
        }

        size_t capacity()const {
            return _capacity;
        }

        bool empty()const {
            return _size == 0;
        }

        void resize(size_t n, char c = '\0') {
            if (n > _capacity) {
                reserve(n);
                while (_size < n) {
                    _str[_size] = c;                
                    _size++;
               }
            }
            _str[n] = '\0';                  
            _size = n;
            
        }

        void reserve(size_t n) {   //预留空间
            if (n > _capacity) {
                char *tmp =new char[1.5*n + 1];   //1 为‘\0’的空间
                memcpy(tmp, _str,_capacity+1);  
                delete[] _str;

                _str = tmp;       
                _capacity = 1.5 * n;
            }
        }



public:
        char& operator[](size_t index) {
            return _str[index];
        }
        const char& operator[](size_t index)const {
            return _str[index];
        }

        bool operator<(const string& s) {
            return strcmp(_str, s._str)==-1;
        }

        bool operator<=(const string& s) {
            return !(strcmp(_str, s._str) == 1);
        }

        bool operator>(const string& s) {
            return strcmp(_str, s._str) == 1;
        }

        bool operator>=(const string& s) {
            return !(strcmp(_str, s._str) == -1);
        }

        bool operator==(const string& s) {
            return strcmp(_str, s._str) == 0;
        }

        bool operator!=(const string& s) {
            return strcmp(_str, s._str) != 0;
        }



        //// 返回c在string中第一次出现的位置
        size_t find(char c, size_t pos = 0) const {
            int idx = pos;
            while (idx < _size && _str[idx++] != c);
            return idx>=_size ? -1:idx-1;   //没找到或者越界返回-1
        }


        //// 返回子串s在string中第一次出现的位置
        size_t find(const char* s, size_t pos = 0) const {
            int i = pos;  //_str
            int j = 0;    //s
            while (i < _size && j < strlen(s))
            {
                if (_str[i] == s[j])
                {
                    ++i;
                    ++j;
                }
                else
                {
                    j = 0;
                    i = i - j + 1;
                }
            }
            if (j = strlen(s))
            {
                return i - strlen(s);
            }
            return -1;
        }

        //// 在pos位置上插入字符c/字符串str，并返回该字符的位置
        string& insert(size_t pos, char c) {
            if (_capacity == _size) {
                reserve(_capacity + 10);//多预留十个空间
            }
            int count = _size;
            while (count > pos) {
                _str[count] = _str[count - 1];
                count--;
            }
            _str[pos] = c;
            _str[_size + 1] = '\0';
            _size++;
            return *this;
        }


        string& insert(size_t pos, const char* str){
            int len = strlen(str);
            int n = _size + len;
            if (n>_capacity ) {
                reserve(n+10);//多预留十个空间
            }
            while (n > pos) {
                _str[n] = _str[n - len];
               n--;
            }
            for (int i = pos; i < pos+len ; i++) {
                _str[i] = str[i - pos];
            }
            return *this;
        }



        //// 删除pos位置上的元素，并返回该元素的下一个位置
        string& erase(size_t pos, size_t len) {
            char * tmp = new char[_size - len + 1];
            memset(tmp, 0, _size - len + 1);
            memcpy(tmp, _str, pos);
            memcpy(tmp+pos, _str+pos+len, _size-len-pos);
            delete[] _str;
            _str = tmp;
            _size -= len;
            return *this;

        }

    private:
        char* _str;
        size_t _capacity;
        size_t _size;
    };
    

    ///输入输出流重载
    ostream& operator<<(ostream& _cout, const bit::string& s)
    {
        _cout << s._str;
        return _cout;
    }
    istream& operator>>(istream& _cin, bit::string& s)
    {
        //预分配100个空间
        char* str = (char*)malloc(sizeof(char) * 100);
        char* buf = str;
        int i = 1;
        //预处理：跳过流里面的所有空格和回车
        while ((*buf = getchar()) == ' ' || (*buf == '\n'));
        for (; ; ++i)
        {
            if (*buf == '\n') //回车跳出
            {
                *buf = '\0';
                break;
            }
            else if (*buf == ' ') //空格跳出
            {
                *buf = '\0';
                break;
            }
            else if (i % 100 == 0) //空间不足
            {
                i += 100; //追加100个空间
                str = (char*)realloc(str, i);
            }
           else  //每次getchar()一个值
            {
                buf = (str + i);//为了避免realloc返回首地址改变，不使用++buf，而是用str加上偏移.
                //每次读取一个字符
                *buf = getchar();
            }
        }
        //输入完成,更新s
        s._str = str;
        s._capacity = s._size = i;
        return _cin;
    }
};





int main()
{
    //系统string接口
    string s1("ddasfghi");
    string s2("dbcdefghi");
    string s3(s2);
    cout << s3 << " capacity:" << s3.capacity() << "  size:" << s3.size() << endl;
    s3.resize(20);
    cout <<s3<< " capacity:" << s3.capacity() << "  size:" << s3.size() << endl;
  /*  s3.resize(2,'x');
    cout <<s3<< " capacity:" << s3.capacity() << "  size:" << s3.size() << endl;*/
    s3.append("dddxxxdpxpxxp");
    cout << s3 << " capacity:" << s3.capacity() << "  size:" << s3.size() << endl;
    cout << s3.find("dp", 0) << endl;

    cout << endl;

   // 自己实现的 bit::string接口测试
    bit::string ss1("ddasfghi");
    cin >> ss1 ;
    bit::string ss2("dbcdefghi");
    bit::string ss3(ss2);
    cout << ss1 << endl;
    cout<<ss3 << " capacity:" << ss3.capacity() << "  size:" << ss3.size() << endl;
    ss3.resize(20);
    cout << ss3 << " capacity:" << ss3.capacity() << "  size:" << ss3.size() << endl;
    //ss3.resize(2, 'x');
    //cout <<ss3 << " capacity:" <<ss3.capacity()<<"  size:"<<ss3.size() << endl;
    ss3+="dddxxxdpxpxxp";
    cout << ss3 << " capacity:" << ss3.capacity() << "  size:" << ss3.size() << endl;
    cout << ss3.find("dp") << endl;

    return 0;
}




















//int main()
//{
//	int nums[] = { 2,2,1 };
//
//	//const char *str[] = { "abc","def","ghi","jkl","mno","pqr","stuv","wxyz" };
//
//	//char str[10][5] = { {0},{0},
//	//					{'a','b','c',0},  //2  str[2]
//	//					{'d','e','f',0},
//	//					{'g','h','i',0},
//	//					{'j','k','l',0},
//	//					{'m','n','o',0},
//	//					{'p','q','r',0},
//	//					{'s','t','u','v',0},
//	//					{'w','x','y','z',0} };  //9 
//	//int a = 2;
//	//int b = 3;
//	//vector<string>  retstr(a * b, "aa");
//	//for (int i = 0; i < a * b; i++) {
//	//	for (int j = 0; j < strlen(str[j]); j++) {
//	//		for (int k = 0; k < strlen(str[k]); k++) {
//	//			retstr[i][0] = str[a][j];
//	//			retstr[i][1] = str[b][k];
//	//		}
//	//	}
//		
//
//
//
//
//	}
//
//	/*	int a = 0;
//		for (auto& e : nums) {
//			a ^= e;
//		}*/
//
//	return 0;
//}

//////////zuoye
//
//int main(void)
//{
//	vector<int>array;
//	array.push_back(100);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(300);
//	array.push_back(500);
//	vector<int>::iterator itor;
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		if (*itor == 300)
//		{
//			itor = array.erase(itor);
//		}
//	}
//	for (itor = array.begin(); itor != array.end(); itor++)
//	{
//		cout << *itor << " ";
//	}
//	return 0;
//}











//实现string类的接口，并完成测试，要求利用深拷贝和深赋值实现
//	class string
//	{
//	public:
//		string(const char* str = "") :_str(nullptr)
//		{
//			assert(str!=nullptr);
//			_str = new char[strlen(str) + 1];
//			memcpy(_str, str, strlen(str) + 1);
//		}
//		string(const string& s) 
//		{
//			_str = new char[strlen(s._str) + 1];
//			memcpy(_str, s._str, strlen(s._str) + 1);
//		}
//		string& operator=(const string& s)
//
//		{
//			if (&s != this) {
//				string tmp = string(s);
//				std::swap(*this, tmp);
//			}
//			return *this;
//		}
//
//		~string() {
//			if (_str) {
//				delete[] _str;
//				_str = nullptr;
//			}
//		}
//	public:
//		size_t size() {
//			char* p = _str;
//			while (p++ != 0);
//			return p-_str;
//		}
//	private:
//		char* _str;
//	};
//
//
//int main() {
//	char str1[] = "xxxcccvvvff";
//	std::string s1("sadasd");
//	
//	cout << s1 << endl;
//
//	cout << s1.size() << endl;
//	return 0;
//}

//int main()
//
//{
//	string s1 = "hello world";
//	string s2 = "change world";
//	string::iterator it = s1.begin();
//	swap(s1, s2);
//	//while (it != s1.end())
////		cout << *it;
//	cout << endl;
//	return 0;
//}








//int main()
//{	
//	string str = "Hello Bit.";
//	string::iterator it = str.begin();
//	while (it != str.end())
//	{
//		if (*it != ' ')
//			cout << *it;
//		else
//			str.erase(it);
//		it++;
//	}
//	return 0;
//}

//int main(int argc, char* argv[])
//{
//	string strText = "How are you?";
//	string strSeparator = " ";
//	string strResult;
//	int size_pos = 0;
//	int size_prev_pos = 0;
//	         //3
//			//8
//			//-1
//	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
//	{
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//		cout << strResult << " ";//How are 
//		//4                   4
//		//8					8
//		size_prev_pos = ++size_pos;
//	}
//	//    8					12
//	if (size_prev_pos != strText.size())
//	{
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//		cout << strResult << " ";
//	}
//	cout << endl;
//	return 0;
//}




/*int main(int argc, char* argv[])
{
	string a = "hello world";
	string b = a;
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	string c = b;
	c = "";
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	a = "";
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	return 0;
}
*/


//int main()
//{
//	int ar[] = { 0,1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int n = sizeof(ar) / sizeof(int);
//	list<int> mylist(ar, ar + n);
//	list<int>::iterator pos = find(mylist.begin(), mylist.end(), 5);
//	reverse(mylist.begin(), pos);
//	reverse(pos, mylist.end());
//	list<int>::const_reverse_iterator crit = mylist.crbegin();
//	while (crit != mylist.crend())
//	{
//		cout << *crit << " ";
//		++crit;
//	}
//	cout << endl;
//
//}

//int main()
//
//{
//	int array[] = { 1, 2, 3, 4, 0, 5, 6, 7, 8, 9 };
//	int n = sizeof(array) / sizeof(int);
//	list<int> mylist(array, array + n);
//	auto it = mylist.begin();
//	while (it != mylist.end())
//	{
//		if (*it != 0)
//			cout << *it << " ";
//		else
//			it = mylist.erase(it);
//		++it;
//	}
//	return 0;
//}

