#include <stdio.h>
#define N 5
#define uint unsigned int
uint MATRIX[N][N] = {
	//   A B C D E
	{ 0, 999, 999, 999, 5 },  //A 
	{ 0, 0, 5, 999, 7 },		//B
	{ 0, 0, 0, 8, 999 }, 		//C
	{ 0, 0, 0, 0, 10 },		//D
	{ 0, 0, 0, 0, 0 }, 		//E
};
struct TYPE_NODE
{
	uint path;//�ӵ�0λ����Nλ����1����λ,��ʾ���·���������յ� 
	uint distance;//��ʾ���·���ĳ��� 
};
struct TYPE_NODE NODE[N*(N - 1) / 2];
uint init_node()//��NODE�ǵĲ�����ֵ 
{
	int i = 0, j = 0, k = 0;
	for (i = 1; i < (N + 1); ++i)
	{
		for (j = 0; j < i; ++j)
		{
			NODE[k].distance = MATRIX[i][j];
			NODE[k].path = 0;
			NODE[k].path = (1 << i) | (1 << j);
			k++;
		}
	}
	return 0;
}
uint mirror_1()//���ǰ����ϵľ��󷭵����� 
{
	int i = 0, j = 0;
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < i; ++j)
		{
			MATRIX[i][j] = MATRIX[j][i];
		}
	}
	return 0;
}

uint mirror_2()//�����µľ��󷭵����� 
{
	int i = 0, j = 0;
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < i; ++j)
		{
			MATRIX[j][i] = MATRIX[i][j];
		}
	}
	return 0;
}

uint calculate_node()//�������·�� for�õ��е�� 
{
	int i, j, k;
	for (i = 0; i < (N*(N - 1) / 2); ++i)
	{
		for (j = 0; j < (N*(N - 1) / 2); ++j)
		{
			for (k = 0; k < (N*(N - 1) / 2); ++k)
			{
				if ((NODE[k].path) == ((NODE[i].path) ^ (NODE[j].path)))
				{
					if (NODE[k].distance >((NODE[i].distance) + (NODE[j].distance)))
					{
						NODE[k].distance = ((NODE[i].distance) + (NODE[j].distance));//���AB+BC<AC ��AC= AB+BC 
						//printf("oba!\n");
					}
				}
			}
		}
	}
	return 0;
}

uint printf_MATRIX()//�������= = 
{
	int i = 0, j = 0;
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			printf("%3d ", MATRIX[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n\n\n\n");
	return 0;
}

uint return_node()
{
	int i = 0, j = 0, k = 0;
	for (i = 1; i < (N + 1); ++i)
	{
		for (j = 0; j < i; ++j)
		{
			MATRIX[i][j] = NODE[k].distance;
			k++;
		}
	}
	return 0;
}
uint print_NODE()
{
	int i;
	for (i = 0; i < (N*(N - 1) / 2); ++i)
	{
		printf("%3d %3d \n", NODE[i].distance, NODE[i].path);
	}
	return 0;
}
int main()
{
	//int i, j;
	mirror_1();
	printf_MATRIX();
	init_node();
	
	print_NODE();
	printf("\n");
	
	calculate_node();
	
	print_NODE();
	printf("\n");

	return_node();
	//	print_NODE();
	mirror_2();
	printf_MATRIX();
	return 0;
}