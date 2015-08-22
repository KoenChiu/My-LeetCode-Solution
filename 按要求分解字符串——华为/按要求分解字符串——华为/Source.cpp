/****************************************************
��Ҫ��ֽ��ַ���������������M��N��M���������M���ַ�����
N���������ÿ���ַ�����λ����������0�����磺����2,8�� 
��abc�� ����123456789���������Ϊ��abc00000��,��12345678��,
��90000000��
****************************************************/

#include <iostream>
#include <vector>
#include <string>
#define K 4
using namespace std;
void ResolveString(int M,int N,vector<string> &str)
{
	int size = 0;
	for (int i = 0; i < (int)str.size(); ++i)
	{
		size = str[i].size();
		if (size < N)
		{
			for (int j = size; j < N; ++j)
			{
				str[i] += '0';
			}
		}
		else if (size > N)
		{
			string addToStr;
			for (int j = N; j < size; ++j)
			{
				addToStr += str[i][j];
				str[i].pop_back();
			}
			str.push_back(addToStr);
		}
	}
}



int main()
{
	string input_str[K] = { "abc", "123456789","aafffff","dds2334"};
	vector<string> str(input_str, input_str + K);
	ResolveString(K, 8, str);
	for (int i = 0; i < (int)str.size(); ++i)
	{
		cout << str[i] << endl;
	}
	return 0;
}