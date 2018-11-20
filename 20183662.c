#include <stdio.h>
#include <malloc.h>

typedef struct birth
{
	int year;
	int month;
	int date;
}birth;

typedef struct private_statement
{
	char name[8];
	birth birth_data;
	char gender[8];
	int phone_number;
}p_s;

void swap_int(int *data1, int *data2)
{
	int temp = *data1;
	*data1 = *data2;
	*data2 = temp;
}

void swap_p_p_s(p_s **data1, p_s **data2)
{
	p_s *temp = *data1;
	*data1 = *data2;
	*data2 = temp; 
}

void name_priority_sort(p_s **p_p_s, int *birth, int num)
{
	int i, j, k;
	for(i = 0; i < num - 1; i++)
	{
		for(j = i + 1; j < num; j++)
		{
			k = 0;
			while(*((char *)*(p_p_s + i) + k) == *((char *)*(p_p_s + j) + k)) k++;
			if(*((char *)*(p_p_s + i) + k) < *((char *)*(p_p_s + j) + k))
			{
				swap_p_p_s(p_p_s + i, p_p_s + j);
				swap_int(birth + i, birth + j);
			}
		}
	}
}

void birth_priority_sort(p_s **p_p_s, int *birth, int num)
{
	int i, j;
	for(i = 0; i < num - 1; i++)
	{
		for(j = i + 1; j < num; j++)
		{
			if(*(birth + i) > *(birth + j))
			{
				swap_p_p_s(p_p_s + i, p_p_s + j);
				swap_int(birth + i, birth + j);
			}
			
		}
	}
}

void print_statement(p_s **p_p_s)
{
	printf("\t\t%s\t",(char *)*p_p_s);
	printf("%04d/%02d%/%02d\t", *((int *)*p_p_s + 2),*((int *)*p_p_s + 3), *((int *)*p_p_s + 4));
	printf("%s\t",(char *)*p_p_s + 20);
	printf("0%d\t\n",*((int *)*p_p_s + 7));
}

int main()
{
	int i, num;
	printf("입력할 명세서의 개수를 입력하시오 : "); 
	scanf("%d",&num);
	p_s **p_p_s = (p_s **)malloc(sizeof(p_s *) * num);
	int *birth = (int *)malloc(sizeof(int *) * num);
	p_s **p_p_s_first = p_p_s;
	
	for(i = 0; i < num; i++)
	{
		printf("개별명세 입력%d : ",i + 1);
		*p_p_s = (p_s *)malloc(sizeof(p_s));
		
		scanf(" %s",(char *)*p_p_s);
		scanf("%d/%d/%d",(int *)*p_p_s + 2, (int *)*p_p_s + 3, (int *)*p_p_s + 4);
		*(birth + i) = *((int *)*p_p_s + 2) * 10000 + *((int *)*p_p_s + 3) * 100 + *((int *)*p_p_s + 4);
		scanf(" %s",(char *)*p_p_s + 20);
		scanf("%d",(int *)*p_p_s + 7);
		
		p_p_s++;
	}
	
	printf("\n입력 순 출력\t이름\t생년월일\t성별\t전화번호\n");
	p_p_s = p_p_s_first;
	for(i = 0; i < num; i++) print_statement(p_p_s++);
	
	printf("\n이름 순 출력\t이름\t생년월일\t성별\t전화번호\n");
	p_p_s = p_p_s_first;
	name_priority_sort(p_p_s, birth, num);
	for(i = 0; i < num; i++) print_statement(p_p_s++);
	
	printf("\n생일 순 출력\t이름\t생년월일\t성별\t전화번호\n");
	p_p_s = p_p_s_first;
	birth_priority_sort(p_p_s, birth, num);
	for(i = 0; i < num; i++) print_statement(p_p_s++);
	
	return 0;
}
