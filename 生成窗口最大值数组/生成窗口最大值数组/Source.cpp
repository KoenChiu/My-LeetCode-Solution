/*
��һ����������arr��һ����СΪw�Ĵ��ڴ����������߻������ұߣ�����ÿ�����ұ߻�һ��λ�á�
���磬����Ϊ[4,3,5,4,3,3,6,7]�����ڴ�СΪ3ʱ��

[4 3 5] 4 3 3 6 7 ���������ֵΪ5
4 [3 5 4] 3 3 6 7 ���������ֵΪ5
4 3 [5 4 3] 3 6 7 ���������ֵΪ5
4 3 5 [4 3 3] 6 7 ���������ֵΪ4
4 3 5 4 [3 3 6] 7 ���������ֵΪ6
4 3 5 4 3 [3 6 7] ���������ֵΪ7

������鳤��Ϊn�����ڴ�СΪw����һ������n-w+1�����ڵ����ֵ����ʵ��һ������������һ����
��arr�����ڴ�Сw������һ������Ϊn-w+1������res,res[i]��ʾÿһ�ִ���״̬�µ����ֵ���Ա�
��Ϊ�������Ӧ�÷���[5,5,5,4,6,7]��
*/

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> maxInWindows(const vector<int> num, unsigned int size)
{
	vector<int> maxInWindow;
	if (num.size() >= size && size >= 1)
	{
		deque<int> index;//��Ż������������ֵ���±�
		for (unsigned int i = 0; i < size; ++i)//һ��ʼ�Ƚ���������װ��
		{
			while (!index.empty() && num[i] >= num[index.back()])//����������>=indexβ��
				index.pop_back();//��index��β������
			index.push_back(i);//�����������±�ѹ��index��
		}

		for (unsigned int i = size; i < num.size(); ++i)//ÿ�λ�������һλ
		{
			maxInWindow.push_back(num[index.front()]);

			while (!index.empty() && num[i] >= num[index.back()])
				index.pop_back();
			if (!index.empty() && index.front() <= (int)(i - size))//indexͷ�����ֱ�����
				index.pop_front();
			index.push_back(i);
		}
		maxInWindow.push_back(num[index.front()]);

	}

	return maxInWindow;
}




int main()
{
	vector<int> max;
	vector<int> num = {2,3,4,2,6,2,5,1};
	unsigned int windowSize = 3;
	max = maxInWindows(num, windowSize);
	for (unsigned int i = 0; i < max.size(); ++i)
	{
		cout << max[i] <<" ";
	}
	cout << endl;
	system("pause");
	return 0;
}
