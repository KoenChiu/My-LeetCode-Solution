#include <iostream>
using namespace std;

class Base
{
public:
	void fun(int n);
	void fun(char c);
};

void Base::fun(int n)
{
	cout << n << endl;
}

void Base::fun(char c)
{
	int n = (int)c;
	fun(n); // ����ֱ�ӵ���
	this->fun(n); // ���߼���this
}

int main()
{
	Base b;
	b.fun('A');
	return 0;
}