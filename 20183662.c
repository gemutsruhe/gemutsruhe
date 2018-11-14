#include <stdio.h>

void indexAddMat(int Mat[])
{
	for(int i = 0; i < 9; i++) *(Mat + i + 18) = (*(Mat + i)) + (*(Mat + 9 + i));
}


void ptrProdMat(int *Mat)
{
	for(int i = 0; i < 27; i++) *(Mat + i / 3 + 18) += (*(Mat + 3 * (i / 9) + i % 3)) * (*(Mat + 9 + (i / 3) % 3 + 3 * (i % 3)));
}

int main()
{
	int mat[27] = {0,};
	int *p_mat = mat;
	int *p_mat1 = mat;
	int *p_mat2 = mat+9;
	
	printf("enter 3 X 3 matrix element : ");
	for(int i = 0; i < 9; i++)
	{
		scanf("%d",mat+i);
		*(mat + 9 + 3 * (i % 3) + i / 3) = *(mat + i);
	}
	
	printf("\nsum of matrix\n");
	indexAddMat(mat);
	for(int i = 0; i < 9; i++)
	{
		printf("%4d",*(mat+18+i));
		if(i % 3 == 2) printf("\n");
	}
	printf("\n");
	
	for(int i = 18; i < 27; i++) *(mat+i) = 0;
	
	printf("product of matrix\n");
	ptrProdMat(mat);
	for(int i = 0; i < 9; i++)
	{
		printf("%4d",*(mat+18+i));
		if(i % 3 == 2) printf("\n");
	}
	
	return 0;
}

