#include <stdio.h>
#include <malloc.h>

typedef struct node
{
	int value;
	struct node *next;
}node;

int main()
{
	int i;
	int temp_num, input_num = 0, half_input_num;
	node *p_head, *p_node;
	
	if(scanf("%d",&temp_num) != EOF)
	{
		p_node = (node *)malloc(sizeof(node));
		p_head = p_node;
		*(int *)p_node = temp_num;
	}
	else return 0;
	
	while(scanf("%d",&temp_num) != EOF)
	{
		*((node **)p_node + 1) = (node *)malloc(sizeof(node));
		p_node = *((node **)p_node + 1);
		*(int *)p_node = temp_num;
	}
	*((node **)p_node + 1) = 0;
	p_node = p_head;
	
	printf("입력자료를 입력 순으로 출력\t\t\t");
	while(*((node **)p_node + 1))
	{
		printf("%d ",*(int *)p_node);
		p_node = *((node **)p_node + 1);
		input_num++;
	}
	printf("%d\n",*(int *)p_node);
	input_num++;
	printf("입력된 자료의 개수를 출력\t\t\t%d\n",input_num);

	p_node = p_head;
	if(input_num % 2)
	{
		half_input_num = input_num >> 1;
		for(i = 0; i < half_input_num; i++)	p_node = *((node **)p_node + 1);
		printf("입력자료의 중간위치에 있는 자료의 값 출력\t%d\n",*(int *)p_node);
	}
	else
	{
		half_input_num = input_num >> 1;
		for(i = 0; i < half_input_num - 1; i++)	p_node = *((node **)p_node + 1);
		printf("입력자료의 중간위치에 있는 자료의 값 출력\t%d %d\n",*(int *)p_node, *(int *)*((node **)p_node + 1));
	}
	
	printf("입력자료를 입력 역순으로 출력\t\t\t");
	i = input_num - 1;
	while(i)
	{
		p_node = p_head;
		int j = i--;
		while(j--)
		{
			p_node = *((node **)p_node + 1);
		}
		printf("%d ",*(int *)p_node);
	}
	printf("%d\n",*(int *)p_head);
	
	printf("입력자료에서 홀수번째 자료를 모두 삭제\n");
	p_node = p_head;
	if(input_num > 1)
	{
		p_head = *((node **)p_node + 1);
		free(p_node);
		p_node = p_head;
		if(input_num % 2)
		{
			while(*((node**)(*((node **)p_node + 1)) + 1))
			{
				node *p_del_node = *((node **)p_node + 1);
				*((node **)p_node + 1) = *((node**)(*((node **)p_node + 1)) + 1);
				p_node = *((node **)p_node + 1);
				free(p_del_node);	
			}
		}
		else
		{
			while(*((node **)p_node + 1))
			{
				node *p_del_node = *((node **)p_node + 1);
				*((node **)p_node + 1) = *((node**)(*((node **)p_node + 1)) + 1);
				p_node = *((node **)p_node + 1);
				free(p_del_node);
			}
		}
		*((node **)p_node + 1) = 0;
	}
	else if(input_num == 1)
	{
		free(p_head);
	}
	
	
	printf("남은 자료를 순서대로 출력\t\t\t");
	p_node = p_head;
	while(*((node **)p_node + 1))
	{
		printf("%d ",*(int *)p_node);
		p_node = *((node **)p_node + 1);
	}
	printf("%d\n",*(int *)p_node);
	
	p_node = p_head;
	while(*((node **)p_node + 1))
	{
		p_head = *((node **)p_node + 1);
		free(p_node);
		p_node = p_head;
	}
	
	return 0;
}
