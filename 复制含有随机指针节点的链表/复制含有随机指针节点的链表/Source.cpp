/*
һ�����������ڵ�����������:
class Node
{
	public int value;
	public Node next;
	public Node rand;
	public Node(int data) 
	{
		this.value = data;
	} 
}
    
	Node���е�value�ǽڵ�ֵ��nextָ���������������nextָ�������
һ������ָ����һ���ڵ㣬randָ����Node����������ָ�룬���ָ�����
ָ�������е�����һ���ڵ㣬Ҳ����ָ��null������һ����Node�ڵ�������
�ɵ��޻��������ͷ�ڵ� head����ʵ��һ���������������������нṹ��
���ƣ������ظ��Ƶ��������ͷ�ڵ㡣Ҫ�������Ҫ���صĶ����⣬����ʹ��
��������ݽṹ������ʱ�临�Ӷ�Ϊ O(N)�����ԭ����Ҫʵ�ֵĺ�����
*/

/*
��Ŀ����

����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ����
�㣬��һ������ָ��ָ������һ���ڵ㣩��
*/

#include <iostream>
using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};



class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		CloneNode(pHead);
		ConnectRandomNodes(pHead);
		return ReturnNodes(pHead);
	}
	void CloneNode(RandomListNode* head);
	void ConnectRandomNodes(RandomListNode* head);
	RandomListNode* ReturnNodes(RandomListNode* head);
};


void Solution::CloneNode(RandomListNode* head)
{
	RandomListNode* ptr = head;
	while (ptr != NULL)
	{
		RandomListNode* newNode = new RandomListNode(ptr->label);
		newNode->next = ptr->next;
		ptr->next = newNode;
		ptr = ptr->next->next;
	}
}

void Solution::ConnectRandomNodes(RandomListNode* head)
{
	RandomListNode* ptr = head;
	while (ptr != NULL)
	{
		ptr->next->random = ((ptr->random == NULL)? NULL:ptr->random->next);
		ptr = ptr->next->next;
	}
}

RandomListNode* Solution::ReturnNodes(RandomListNode* head)
{
	RandomListNode* ptr = head;
	RandomListNode* new_head = head->next;
	RandomListNode* new_ptr = head->next;
	
	while (NULL != new_ptr || NULL != ptr)
	{
		ptr->next = ptr->next->next;
		new_ptr->next = (new_ptr->next == NULL) ? NULL : new_ptr->next->next;
		ptr = ptr->next;
		new_ptr = new_ptr->next;
	}
	return new_head;
}

int main()
{
	RandomListNode* head = new RandomListNode(1);
	RandomListNode* second = new RandomListNode(2);
	RandomListNode* third = new RandomListNode(3);
	RandomListNode* copy_head = NULL;
	head->next = second;
	second->next = third;
	head->random = third;
	second->random = head;
	Solution sol;
	copy_head = sol.Clone(head);
	
	system("pause");
	return 0;
}
