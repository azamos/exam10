#ifndef EXAM_H_
#define EXAM_H_

#ifndef NULL
#define NULL 0
#endif

#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#define N 5
#define M 4 


typedef struct
{
	int from_ID;
	int to_ID;
	char* productName; 
	int category;
	float amount;
	char* date;
	char *review;
}shopDetails;

typedef struct
{
	char* name;
	int id;
	shopDetails ** shoppingArr;
	int numberOfShoppings;
}member;

typedef struct
{
	member** members;
	int memberSize;
	shopDetails** shopping;
	int totaSize;
}AE;

//Q4
int addShopRequest (AE* pAE, int fromID, int toID, char *productName, int category, float amount, char* date);
int deleteAE(AE* pAE);

//Q1
int SquareMatrix(int mat[N][M], int n, int m);

//Q2 
int mystrstr(char *s, char *t);

//Q3
int bigger(int arr[], int *result);
void fx1();




#endif