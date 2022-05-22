#include<iostream>
#include<bitset>
#include<vector>
#include<string>
#include<map>
using namespace std;

#define _N 1000

template<class T>
struct KeyToInt1
{
	size_t operator()(const T& str)
	{
		return BKDRHash(str.c_str()) % _N;
	}
	size_t BKDRHash(const char* str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
};


template<class T>
struct KeyToInt2
{
	size_t operator()(const T& str)
	{
		return SDBMHash(str.c_str()) % _N;
	}
	size_t SDBMHash(const char* str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = 65599 * hash + ch;
		}
		return hash;
	}
};

template<class T>
struct KeyToInt3
{
	size_t operator()(const T& str)
	{
		return RSHash(str.c_str()) % _N;
	}
	size_t RSHash(const char* str)
	{
		register size_t hash = 0;
		size_t magic = 63689;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * magic + ch;
			magic *= 378551;
		}
		return hash;
	}
};



template<class K,
	class hashfcn1 = KeyToInt1<K>,
	class hashfcn2 = KeyToInt2<K>,
	class hashfcn3 = KeyToInt3<K>>
	class BloomFilte
{
public:
	BloomFilte() :size(0)
	{}
public:
	void insert(const K& key)
	{
		size_t index1 = hashfcn1()(key);
		size_t index2 = hashfcn2()(key);
		size_t index3 = hashfcn3()(key);
		_bmp.set(index1);
		_bmp.set(index2);
		_bmp.set(index3);
	}
	bool test(const K& key)
	{
		size_t index1 = hashfcn1()(key);
		if (!_bmp.test(index1))
			return false;
		size_t index2 = hashfcn2()(key);
		if (!_bmp.test(index2))
			return false;
		size_t index3 = hashfcn3()(key);
		if (!_bmp.test(index3))
			return false;

		return true;
	}
private:
	bitset<_N> _bmp;
	size_t     size;
};

void main()
{
	string url = "http://www.taobao.com";
	string url2 = "http://www.baidu.com";
	string url3 = "http://www.taobao.con";
	BloomFilte<string> bf;
	bf.insert(url.c_str());

	cout << bf.test(url) << endl; // 1
	cout << bf.test(url3) << endl;
}

/*
////////////* bitsetÄ£ÄâÊµÏÖ
namespace bit
{
	template<size_t _N>
	class bitset
	{
	public:
		typedef unsigned long _Ty;
	public:
		bitset()
		{
			_Tidy();
		}
	public:
		bitset<_N>& set()
		{
			_Tidy(~(_Ty)0);
			return (*this);
		}
		bitset<_N>& set(size_t _P, bool _X = true)
		{
			if (_X)
				_A[_P / _Nb] |= (_Ty)1 << _P % _Nb;
			else
				_A[_P / _Nb] &= ~((_Ty)1 << _P % _Nb);
			return (*this);
		}
		size_t size() const
		{
			return (_N);
		}
		bool test(size_t _P) const
		{
			return ((_A[_P / _Nb] & ((_Ty)1 << _P % _Nb)) != 0);
		}
		bool any() const
		{
			for (int _I = _Nw; 0 <= _I; --_I)
				if (_A[_I] != 0)
					return (true);
			return (false);
		}
		bool none() const
		{
			return (!any());
		}
		size_t count() const
		{
			size_t _V = 0;
			for (int _I = _Nw; 0 <= _I; --_I)
				for (_Ty _X = _A[_I]; _X != 0; _X >>= 4)
					_V += "\0\1\1\2\1\2\2\3"
					"\1\2\2\3\2\3\3\4"[_X & 0xF];
			return (_V);
		}

		class reference
		{
			friend class bitset<_N>;
		public:
			reference& operator=(bool _X)
			{
				_Pbs->set(_Off, _X);
				return (*this);
			}
			reference& operator=(const reference& _Bs)
			{
				_Pbs->set(_Off, bool(_Bs));
				return (*this);
			}
			reference& flip()
			{
				_Pbs->flip(_Off);
				return (*this);
			}
			bool operator~() const
			{
				return (!_Pbs->test(_Off));
			}
			operator bool() const
			{
				return (_Pbs->test(_Off));
			}
		private:
			reference(bitset<_N>& _X, size_t _P)
				: _Pbs(&_X), _Off(_P) {}
			bitset<_N>* _Pbs;
			size_t _Off;
		};

		reference operator[](size_t _P)
		{
			return (reference(*this, _P));
		}
	private:
		void _Tidy(_Ty _X = 0)
		{
			for (int _I = _Nw; 0 <= _I; --_I)
				_A[_I] = _X;
			if (_X != 0)
				_Trim();
		}
		void _Trim()
		{
			if (_N % _Nb != 0)
				_A[_Nw] &= ((_Ty)1 << _N % _Nb) - 1;
		}
	private:
		enum
		{
			//#define CHAR_BIT 8
			_Nb = CHAR_BIT * sizeof(_Ty),
			_Nw = _N == 0 ? 0 : (_N - 1) / _Nb
		};
		_Ty _A[_Nw + 1];

	private:
		friend ostream& operator<<(ostream& _O, const bitset<_N>& _R)
		{
			for (size_t _P = _N; 0 < _P;)
				_O << (_R.test(--_P) ? '1' : '0');
			return (_O);
		}
	};

};

void main()
{
	bit::bitset<20> bt;
	cout << "bt = " << bt << endl;
	//bt.set(3);
	//reference r1 = r2;
	bt[3] = 1;
	cout << "bt = " << bt << endl;
	cout << "count = " << bt.count() << endl;

}




/*
int main()
{


	std::bitset<4> foo;
	foo[1] = 1;             // 0010
	foo[2] = foo[1];        // 0110
	for (int i = 0; i < foo.count(); i++)
		cout << foo[i];



/*
	std::bitset<4> foo(std::string("1001"));
	std::bitset<4> bar("0011");

	std::cout << (foo ^= bar) << '\n';       // 1010 (XOR,assign)
	std::cout << (foo &= bar) << '\n';       // 0010 (AND,assign)
	std::cout << (foo |= bar) << '\n';       // 0011 (OR,assign)

	std::cout << (foo <<= 2) << '\n';        // 1100 (SHL,assign)
	std::cout << (foo >>= 1) << '\n';        // 0110 (SHR,assign)

	std::cout << (~bar) << '\n';             // 1100 (NOT)
	std::cout << (bar << 1) << '\n';         // 0110 (SHL)
	std::cout << (bar >> 1) << '\n';         // 0001 (SHR)

	std::cout << (foo == bar) << '\n';       // false (0110==0011)
	std::cout << (foo != bar) << '\n';       // true  (0110!=0011)

	std::cout << (foo & bar) << '\n';        // 0010
	std::cout << (foo | bar) << '\n';        // 0111
	std::cout << (foo ^ bar) << '\n';        // 0101

	/*
	std::bitset<16> foo;
	std::bitset<16> bar(0xfa2);
	std::bitset<16> baz(std::string("0101111001"));

	std::cout << "foo: " << foo << '\n';
	std::cout << "bar: " << bar << '\n';
	std::cout << "baz: " << baz << '\n';
	
		return 0;
}
	*/



