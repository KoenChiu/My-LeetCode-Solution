/*
��Ŀ����1��2��3��4��5��6��7��8��9������ѡһ������������һ�����γ�һ����ϣ��ܵõ������ֲ�ͬ�ĳ˻���

�������ѧ���㲻����д������һ��......��
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	unsigned short num = 1;
	unsigned short Max = 0x01FF;
	long long result = 1;
	vector<long long> arr;
	vector<long long>::iterator isExist;
	while (num < Max)
	{
		for (int i = 0; i < 9; ++i)
			if (((num >> i) & 0x0001) == 1)
				result = result * (i+1);
		isExist = find(arr.begin(), arr.end(), result);
		if (isExist == arr.end())
			arr.push_back(result);
		result = 1;
		num++;
	}
	return 0;
}