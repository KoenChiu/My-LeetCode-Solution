/*
��Ŀ����

���дһ�����������ַ����еĿո�ȫ���滻Ϊ��%20�����ٶ����ַ������㹻�Ŀռ����������ַ�������֪���ַ�������ʵ����(С�ڵ���1000)��ͬʱ��֤�ַ����ɴ�Сд��Ӣ����ĸ��ɡ�
����һ��string iniString Ϊԭʼ�Ĵ����Լ����ĳ��� int len, �����滻���string��
����������
"Mr John Smith��,13
���أ�"Mr%20John%20Smith"
��Hello  World��,12
���أ���Hello%20%20World��
*/
#include <iostream>
#include <string>
using namespace std;
class Replacement {
public:
	string replaceSpace(string iniString, int length) 
	{
		// write code here
		if (iniString.empty() || length < 0)
			return iniString;
		int spaceCount = 0;
		int start = 0;
		while (iniString[start] != '\0')
		{
			if (iniString[start] == ' ')
				spaceCount++;
			start++;
		}
		
		int last = length + 2 * spaceCount;
		string::size_type new_capacity{ 100u };
		iniString.reserve(new_capacity);
		while (start != last && start >= 0 && last >= 0)
		{
			if (iniString[start] == ' ')
			{
				iniString[last--] = '0';
				iniString[last--] = '2';
				iniString[last--] = '%';
				start--;
			}
			else
			{
				iniString[last] = iniString[start];
				last--;
				start--;
			}
		}
		return iniString;
	}
};
int main()
{
	string str = "he wo a";
	/*string::size_type new_capacity{ 100u };
	str.reserve(new_capacity);*/
	//cout << str.size() << endl;
	cout << str << endl;
	Replacement rep;
	str = rep.replaceSpace(str, str.size());
	cout << str << endl;
}
