#include <stdio.h>

typedef struct birth_date
{
	int year;
	int month;
	int day;
}b_d;

typedef struct individual_statement
{
	char name[20];
	b_d date;
	int phone_number;
	char adress[30];
	char gender;
}i_s;

void struct_print(i_s *user_data)
{
	printf("%s\n",(char *)user_data);
	printf("%4d\n",*((int *)user_data + 5));
	printf("%02d\n",*((int *)user_data + 6));
	printf("%02d\n",*((int *)user_data + 7));
	printf("%c\n",*((char *)user_data + 66));
	printf("%s\n",(char *)user_data+36);
	printf("0%d\n",*((int *)user_data + 8));
}

void swap(i_s *person1, i_s *person2)
{
	i_s temp;
	temp = *person1;
	*person1 = *person2;
	*person2 = temp;
}

void swap_birth(int *birth1, int *birth2)
{
	int temp;
	temp = *birth1;
	*birth1 = *birth2;
	*birth2 = temp;
}

void name_priority_sort(i_s *user_data, int *birth, int user_num)
{
	i_s *p_user_data;
	for(int i = 0; i < user_num - 1; i++)
	{
		p_user_data = user_data + i;
		for(int j = i + 1; j < user_num; j++)
		{
			while(1)
			{
				if(*(char *)p_user_data == *(char *)(p_user_data + 1))
				{
					p_user_data = (i_s *)((char *)p_user_data + 1);
					continue;
				}
				else if(*(char *)p_user_data < *((char *)(p_user_data + 1) + 1))
				{
					swap(user_data + i, user_data + j);
					swap_birth(birth + i, birth + j);
				}
				break;
			}
			
		}
	}
}

void birth_priority_sort(i_s *user_data, int *birth, int user_num)
{
	for(int i = 0; i < user_num - 1; i++)
	{
		for(int j = i + 1; j < user_num; j++)
		{
			if(*(birth + i) > *(birth + j))
			{
				swap(user_data + i, user_data + j);
				swap_birth(birth + i, birth + j);
			}
		}
	}
}

int main()
{
	i_s user_data[10];
	i_s temp;
	i_s *p_user_data = user_data;
	int birth[10];
	int *p_birth = birth;
	char state = 0;
	int i, user_num;
	
	while(1)
	{
		//printf("이름 생년월일 성별(M/W) 주소 전화번호(-없이)를 입력하시오\nex)\n오혜성\n19990711\nM\n전남 무안군 일로읍\n01092364701\n");
		printf("이름(ex.오혜성)\n"); 
		scanf("%s",(char *)p_user_data);
		printf("생년월일(ex.19990711)\n");
		scanf("%d",p_birth);
		*((int *)p_user_data + 5) = ((*p_birth)/10000);
		*((int *)p_user_data + 6) = ((*p_birth)%10000)/100;
		*((int *)p_user_data + 7) = ((*p_birth)%10000)%100;
		printf("성별(ex.M/W)\n");
		scanf(" %c",(char *)p_user_data + 66);
		printf("주소(ex.전남 무안군 일로읍)\n");
		scanf(" %[^\n]s",(char *)p_user_data + 36);
		printf("전화번호(ex.01092364701)\n");
		scanf(" %d",(int *)p_user_data + 8);
		
		while(1)
		{
			printf("정보를 더 입력 하시겠습니까?(Y/N)\n");
			rewind(stdin);
			scanf("%c",&state);
			if(state == 'N' || state == 'Y') break;
		}
		
		if('N' == state) break;
		
		p_user_data++;
		p_birth++;
	}
	
	user_num = (p_user_data - user_data + 1);
	
	for(i = 0; i < user_num; i++) struct_print(user_data + i);
	name_priority_sort(user_data, birth, user_num);
	for(i = 0; i < user_num; i++) struct_print(user_data + i);
	birth_priority_sort(user_data, birth, user_num);
	for(i = 0; i < user_num; i++) struct_print(user_data + i);
	
	return 0;
}
