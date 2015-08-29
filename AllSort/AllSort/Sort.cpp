#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void print(vector<int> &num)
{
	vector<int>::iterator i;
	for (i = num.begin(); i != num.end(); ++i)
	{
		printf("%3d", *i);
	}
	printf("\n");
}
unsigned int Partition(vector<int> &num, unsigned int left, unsigned int right)
{
	unsigned int i = left;
	unsigned int j = right;
	int Pivot = num[left];
	while (i < j)
	{
		while (i<j && num[j] >= Pivot)
			j--;
		while (i<j && num[i] <= Pivot)
			i++;
		if (i < j)
			swap(num[i], num[j]);
	}
	swap(num[i], num[left]);
	return i;
}
/*��������*/
void InsertSort(vector<int> &num)
{
	if (num.empty())
		return;
	for (unsigned int i = 1; i < num.size(); i++)
	{
		int temp = num[i];
		int j = i - 1;
		while (j >= 0 && num[j] >= temp)
		{
			num[j + 1] = num[j];
			j--;
		}
		num[j + 1] = temp;
	}
}
/*���ֲ�������δ��ɣ������޸�bug��*/
void BinInsertSort(vector<int> &num)
{
	if (num.empty())
		return;
	for (unsigned int i = 1; i < num.size(); i++)
	{
		int temp = num[i];
		int left = 0;
		int right = i - 1;
		while (left <= right)
		{
			int middle = (right - left) / 2;
			if (num[middle] > temp)
			{
				right = middle - 1;
			}
			else if (num[middle] < temp)
			{
				left = middle + 1;
			}
		}
		for (int j = i - 1; j >= left; --j)
		{
			num[j + 1] = num[j];
		}
		num[left] = temp;
	}
		
}
/*ϣ������*/
void ShellSort(vector<int> &num)
{
	const int n = 5;
	unsigned int i;
	int temp,j;
	unsigned int gap = 0;
	while (gap <= num.size())
	{
		gap = gap * 3 + 1;
	}
	while (gap > 0)
	{
		for (i = gap; i < num.size(); i++)
		{
			j = i - gap;
			temp = num[i];
			while ((j >= 0) && (num[j] > temp))
			{
				num[j + gap] = num[j];
				j = j - gap;
			}
			num[j + gap] = temp;
		}
		gap = (gap - 1) / 3;
	}
}
/*ѡ������*/
void SelectSort(vector<int> &num)
{
	if (num.empty())
		return;
	for (unsigned int i = 0; i < num.size()-1; ++i)
	{
		int Min = i;
		for (unsigned int j = i + 1; j < num.size(); ++j)
		{
			if (num[j] < num[Min])
			{
				Min = j;
			}
		}
		if (Min != i)
		{
			swap(num[Min], num[i]);
		}
	}
}
/*ð������*/
void BubbleSort(vector<int> &num)
{
	if (num.empty())
		return;
	//�ܹ���Ҫ�Ƚ�n-1�Σ���i����Ƚ�n-i��
	for (unsigned int i = 0; i < num.size()-1; i++)
	{
		for (unsigned int j = 0; j < (num.size() - (i + 1)); ++j)
		{
			if (num[j] > num[j+1])
			{
				swap(num[j+1], num[j]);
			}
		}
	}
}
/*��������*/
void QuickSort(vector<int> &num,unsigned left,unsigned right)
{
	if (num.empty())
		return;
	if (left < right)
	{
		int i = Partition(num, left, right);
		QuickSort(num,left, i - 1);
		QuickSort(num, i+1, right);
	}
}


int main()
{
	vector<int> num = { 5, 3, 7, 1, 9, 2, 4, 8, 6 };
	//vector<int> num = {9,8,7,6,5,4,3,2,1};
	QuickSort(num,0,num.size()-1);
	print(num);
	system("pause");
	return 0;
}