/**************************************************
��Ŀ����

ʵ��һ�����������������Ƿ�ƽ�⣬ƽ��Ķ������£�����
���е�����һ����㣬�����������ĸ߶Ȳ����1��
����ָ����������ָ��TreeNode* root���뷵��һ��bool��
����������Ƿ�ƽ�⡣
**************************************************/
#include <iostream>
#include <stdlib.h>
using namespace std;

struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Balance {
public:
	bool isBalance(TreeNode* root) {
		// write code here
		if (root == NULL)
			return true;
		int left_depth = Get_Depth(root->left);
		int right_depth = Get_Depth(root->right);
		int diff = left_depth-right_depth;
		diff = abs(diff);
		if (diff > 1)
			return false; 
		else
			return (isBalance(root->left) && isBalance(root->right));

	}

	int Get_Depth(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int left_depth = Get_Depth(root->left);
		int right_depth = Get_Depth(root->right);
		if (left_depth > right_depth)
			return left_depth + 1;
		else
			return right_depth + 1;
	}
	
};

int main()
{
	
	
	return 0;
}