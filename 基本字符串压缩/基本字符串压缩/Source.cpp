/*
��Ŀ����

�����ַ��ظ����ֵĴ�������дһ��������ʵ�ֻ������ַ���ѹ�����ܡ����磬�ַ�����aabcccccaaa����ѹ�����ɡ�a2b1c5a3������ѹ������ַ���û�б�̣��򷵻�ԭ�ȵ��ַ�����
����һ��string iniStringΪ��ѹ���Ĵ�(����С�ڵ���3000)����֤�����ַ����ɴ�СдӢ����ĸ��ɣ�����һ��string��Ϊ�����ѹ�����δ�仯�Ĵ���
��������
"aabcccccaaa"
���أ�"a2b1c5a3"
"welcometonowcoderrrrr"
���أ�"welcometonowcoderrrrr"
*/

#include <iostream>
#include <string>
using namespace std;

class Zipper 
{
public:
	string zipString(string iniString) 
	{
		// write code here
		if (iniString.empty())
			return iniString;
		string returnString;
		string::iterator ptr = iniString.begin();
		while (ptr != iniString.end())
		{
			char temp = *ptr;
			int tempCount = 0;
			while (ptr != iniString.end() && *ptr == temp)
			{
				tempCount++;
				ptr++;
			}
			returnString.push_back(temp);
			returnString.append(intToStr(tempCount));
			
		}
		if (returnString.size() > iniString.size())
			return iniString;
		else
			iniString = returnString;
		return iniString;
	}
	char* intToStr(int num)
	{
		int tmp = 0;
		int i = 0;
		int j = 0;
		char* buf = (char*)calloc(5,sizeof(char));
		for (i = 0; num != 0; ++i)
		{
			tmp = num % 10;
			buf[i] = (char)(tmp + '0');
			num = num / 10;
		}
		for (i = 0, j = strlen(buf)-1; i < j; ++i, --j)
		{
			swap(buf[i], buf[j]);
		}
		return buf;
	}
	void swap(char &a, char &b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
};

int main()
{
	string String = "jjjjjjxxxxxxxooZLLLLLLLLQQQQQQQQQLLLLLLLLECXXXXXXXIIIIIIIIIhjjyyySSooooooooommmuuEEEEEEEEEnnnnnnnffffffAAAAAllllllllbbbbkkkkkkkkkkkkKKKKKKhhhhhhhhhooooooooooYCCCCCCOOOOOOOOOMMMMMMMMMMiiiiiivvvvvvvWWWWkkkkkkwwwwwwwMmmmmmmmmLLLwwwwwwwkkkjjjjjjttttQQQQQQQQQaaaaaaaFFFFFFFlllllllllggggggggggPPPPPPuuuuuuuuaYYYYYYwQQQFFFFFFFFFFaaaaapXXXXXXXxxxxxxQQQQQQQQQsssssGGGGfffffffddddddpppQQQQQQHHHTTTaaaaaaGGGGGGddyyyyyMhhllllllllllNNNNNNNNUUUWWWWWWLLLLLLLLLYYYYYYYYYYTTKKKKKKKKiiiiiiitttttttXXXXXXXXXLLLHZZZZZZZssssjjJJJEEEEEOOOOOttttttttttBBttttttTTTTTTTTTTrrrrttttRRRRRyyooooooaaaaaaaaarrrrrrrPPPPPPPjjPPPPddddddddddHHHHnnnnnnnnnnSSSSSSSSSSzzHHHHHHHHHddddddDDDzzzhhhhhfffffffffftttttteeeeeeeeEEEEEEEEEaaaaaaccccccccccFFFFFFFF";
	Zipper zip;
	cout << String << endl;
	String = zip.zipString(String);
	cout << String << endl;
	
	system("pause");
	return 0;
}