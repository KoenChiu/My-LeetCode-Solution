/**********************************************************************************************
1�������������ཻ��һϵ������
����������л�,Ҳ�����޻������������������ͷ�ڵ� head1 �� head2, ��������������ཻ,Ҳ���ܲ��ཻ��
��ʵ��һ������,������������ཻ,�뷵���ཻ �ĵ�һ���ڵ�;������ཻ,���� null ���ɡ�
Ҫ��:�������1�ĳ���ΪN������2�ĳ���ΪM��ʱ�临�Ӷ���ﵽO(N+M)������ռ临�Ӷ���ﵽO(1)��
**********************************************************************************************/
#include <iostream>
#include "SingleList.h"

ListNode<int>* CrossNode(Single_List<int> &list1, Single_List<int> &list2)
{
	int minus = list1.GetLength() > list2.GetLength() ? list1.GetLength() - list2.GetLength() : list2.GetLength() - list1.GetLength();
	ListNode<int>* p1 = list1.List_head();
	ListNode<int>* p2 = list2.List_head();
	if (list1.GetLength() > list2.GetLength())
	{
		for (int i = 0; i < minus; ++i)
		{
			p1 = p1->next;
		}
	}
	else
	{
		for (int i = 0; i < minus; ++i)
		{
			p2 = p2->next;
		}
	}
	while (p1 != p2 && p1 != NULL && p2 != NULL)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}

int main()
{
	Single_List<int> list1;
	Single_List<int> list2;
	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int arr2[] = { 1, 2, 3, 4 };
	list1.push_back(arr1, (sizeof(arr1) / sizeof(int)));
	list2.push_back(arr2, (sizeof(arr2) / sizeof(int)));
	ListNode<int>* p2 = list2.List_tail();
	ListNode<int>* p1 = list1.GetNNode(7);
	p2->next = p1;
	list1.print();
	list2.print();
	ListNode<int>* cNode = CrossNode(list1, list2);
	cout << "The first cross Node is : " << cNode->val << endl;
	//system("pause");
	return 0;
}