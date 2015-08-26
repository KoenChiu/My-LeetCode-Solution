#include <iostream>
#include <vector>
using namespace std;

/*num������ֻ��һ��������һ�Σ�����������2��*/
int singleNumber_1(vector<int> num)
{
	if (num.empty())
		return NULL;
	int result = 0;
	vector<int>::iterator i = num.begin();
	for (; i != num.end(); ++i)
	{
		result ^= *i;
	}
	return result;
}

/*num������ֻ��һ��������һ�Σ�����������times��*/
int singleNumber_2(vector<int> num,int times)
{
	if (num.empty())
		return NULL;
	int result=0;
	vector<int>::iterator p = num.begin();
	for (int i = 0; i < 32; ++i)
	{
		int count = 0;
		int bitValue = 0;
		int mask = 1<<i;
		for (p = num.begin(); p != num.end(); ++p)
		{
			bitValue = ((*p) & mask);
			if (bitValue>0 || bitValue < 0)
				count++;
		}
		if ((count % times) > 0)
		{
			result = result | mask;
		}
	}
	return result;
}

int singleNumber_3(vector<int> num)
{
	int one = 0;
	// ����һ�εı�־λ
	int accumulation = 0;
	// ���۱�־λ
	vector<int>::iterator i;
	for (i = num.begin(); i!=num.end(); ++i)
	{
		accumulation |= (*i) & one;
		// ֻҪ�ڶ��λ������ϳ��֣���Ϊ1
		one ^= (*i);
		// ���������α�����ż��������
		int t = one & accumulation;
		// �����ε�ʱ��one��accumulation�������˸�λ��ֵ
		one &= ~t;
		// ����������εĸ�λ��ֵ
		accumulation &= ~t;
	}
	return one;
	
}


int main()
{
	vector<int> num = { 1,1,1,3,2,2,2};
	int result = 0;
	result = singleNumber_3(num);
	cout << result << endl;

	
	
	system("pause");
	return 0;
}