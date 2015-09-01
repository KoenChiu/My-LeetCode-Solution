/*���´������ԣ�http://www.cnblogs.com/xwdreamer/archive/2012/10/12/2721938.html ��лԭ����*/

#include<iostream>
#include<stdlib.h>
using namespace std;

void printArray(int arry[], int len)
{
	for (int i = 0; i<len; i++)
		cout << arry[i] << " ";
	cout << endl;
}
int MergeArray(int arry[], int start, int mid, int end, int temp[])//����Ĺ鲢����
{
	//int leftLen=mid-start+1;//arry[start...mid]���γ���
	//int rightLlen=end-mid;//arry[mid+1...end]�Ұ�γ���

	int i = mid;
	int j = end;
	int k = 0;//��ʱ����ĩβ����
	int count = 0;
	//�趨����ָ��ij�ֱ�ָ���������������βԪ�أ���С����һ�����뵽��ʱ������ȥ��
	while (i >= start&&j>mid)
	{
		if (arry[i]>arry[j])
		{
			temp[k++] = arry[i--];//����ʱ��������һ��λ�ÿ�ʼ����
			count += j - mid;//��Ϊarry[mid+1...j...end]������ģ����arry[i]>arry[j]����ôҲ����arry[j]֮ǰ��Ԫ�أ���a[mid+1...j]һ����j-(mid+1)+1=j-mid

		}
		else
		{
			temp[k++] = arry[j--];
		}
	}
	cout << "����MergeArrayʱ��count��" << count << endl;
	while (i >= start)//��ʾǰ��������л���Ԫ��δ������ʱ����
	{
		temp[k++] = arry[i--];
	}

	while (j>mid)
	{
		temp[k++] = arry[j--];
	}

	//����ʱ�����е�Ԫ��д�ص�ԭ���鵱��ȥ��
	for (i = 0; i<k; i++)
		arry[end - i] = temp[i];

	printArray(arry, 8);//�������һ�ι鲢�Ժ�����飬��������������
	return count;

}

int InversePairsCore(int arry[], int start, int end, int temp[])
{
	int inversions = 0;
	if (start<end)
	{
		int mid = (start + end) / 2;
		inversions += InversePairsCore(arry, start, mid, temp);//�����ε��������Ŀ
		inversions += InversePairsCore(arry, mid + 1, end, temp);//���Ұ�ε��������Ŀ
		inversions += MergeArray(arry, start, mid, end, temp);//���������Ұ��������Ժ�������������Ȼ��������֮�������ԡ���С�������ֻ��һ��Ԫ�ء�
	}
	return inversions;
}


int InversePairs(int arry[], int len)
{
	int *temp = new int[len];
	int count = InversePairsCore(arry, 0, len - 1, temp);
	delete[] temp;
	return count;
}

void main()
{
	//int arry[]={7,5,6,4};
	int arry[] = { 1, 3, 7, 8, 2, 4, 6, 5 };
	int len = sizeof(arry) / sizeof(int);
	//printArray(arry,len);
	int count = InversePairs(arry, len);
	//printArray(arry,len);
	//cout<<count<<endl;
	system("pause");
}