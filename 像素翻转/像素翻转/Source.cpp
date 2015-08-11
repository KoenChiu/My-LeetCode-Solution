/***************************************
ʱ�����ƣ�3��       �ռ����ƣ�32768K

��Ŀ����:
��һ����NxN�����ʾ��ͼ������ÿ��������һ��
int��ʾ�����дһ���㷨���ڲ�ռ�ö����ڴ�ռ�
�������(����ʹ�û������)����ͼ��˳ʱ����ת90�ȡ�
����һ��NxN�ľ��󣬺;���Ľ���N,�뷵����ת��
��NxN����,��֤NС�ڵ���500��ͼ��Ԫ��С�ڵ���256��

����������[[1,2,3],
		  [4,5,6],
		  [7,8,9]],
���أ�[[7,4,1],
	   [8,5,2],
	   [9,6,3]]
***************************************/

#include <iostream>
#include <vector>
#include <iomanip>
#define N 5
using namespace std;

class Transform {
public:
	vector<vector<int> > transformImage(vector< vector<int> > mat, int n)
	{
		// write code here
		if (n > 500)
			return mat;
		int start = 0;
		int end = n - 1;
		int i = 0;
		for (; start < (n / 2); ++start, --end)
		{
			while (i < (end-start))
			{
				mat = transform(mat, start, end);
				++i;
			}
			i = 0;			
		}
		return mat;
	}
	vector< vector<int> > transform(vector< vector<int> > mat, int start, int end)
	{
		int i = start;
		int j = start;
		int tmp = 0;
		for (j = start; j <= end; ++j)
		{
			swap(mat[i][j], tmp);
		}
		j--;
		for (i = i + 1; i <= end; ++i)
		{
			swap(mat[i][j], tmp);
		}
		i--;
		for (j = j - 1; j >= start; --j)
		{
			swap(mat[i][j], tmp);
		}
		j++;
		for (i = i - 1; i >= start; --i)
		{
			swap(mat[i][j], tmp);
		}
		i++;
		return mat;
	}
	void swap(int &a, int &b)
	{
		int temp;
		temp = b;
		b = a;
		a = temp;
	}
};

void Print_Mat(vector< vector<int> > mat)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << setw(3) << mat[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	vector< vector<int> > mat(N);
	for (int i = 0; i < N; ++i)
	{
		mat[i].resize(N);
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			mat[i][j] = (N*i)+(j+1);
		}
	}
	Print_Mat(mat); 
	Transform tran;
	mat = tran.transformImage(mat, N);
	cout << endl;
	Print_Mat(mat);

	return 0;
}