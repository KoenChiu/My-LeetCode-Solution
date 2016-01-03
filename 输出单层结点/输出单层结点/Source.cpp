/*
��Ŀ����

����һ�ö������������һ���㷨����������ĳһ��������н�������
�����������ĸ����ָ��TreeNode* root���Լ������Ͻ�����ȣ��뷵
��һ������ListNode���������������н���ֵ���밴���ϴ������ҵ�
˳�����ӣ���֤��Ȳ��������ĸ߶ȣ����Ͻ���ֵΪ�Ǹ������Ҳ�����
100000��
*/

#include <iostream>
using namespace std;
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};

class TreeLevel {
public:
	ListNode* getTreeLevel(TreeNode* root, int dep) {
		// write code here
		if (root == NULL || dep > GetTreeDeep(root))
			return NULL;

	}
	//����������
	int GetTreeDeep(TreeNode* node)
	{
		int deep = 0;
		if (node)
		{
			int leftDeep = GetTreeDeep(node->left);
			int rightDeep = GetTreeDeep(node->right);
			deep = leftDeep >= rightDeep ? (leftDeep+1) : (rightDeep+1);
		}
		return deep;
	}
};

int main()
{
	
	return 0;
}