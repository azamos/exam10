#include "exam.h"
void biggerRec(int arr[], int* result, int* num);
int bigger(int arr[], int* result)

{
	/******** DON'T CHANGE ********/
	fx1(); // do not change!!!
	/******************************/
	
	/*Write your code down here*/
	int num = -1;
	*result = 0;
	biggerRec(arr, result,&num);
	return *result;
}
void biggerRec(int arr[], int* result,int* num) {
	fx1();
	if (*(arr + 1) < 0) {
		*num = *arr;
	}
	if (*num < 0) {
		biggerRec(arr + 1, result, num);
	}
	if (*num > 0) {
		if (*arr > *num) {
			*result += *arr;
		}
	}
}