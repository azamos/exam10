#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "exam.h"

int count1=0; // do not change!

void fx1(){
    count1++;
}


int main(void)
{
    //Q1
    int mat1[5][4] = {{2,1,1,1},{3,1,1,6},{3,5,5,5},{4,5,5,5},{6,5,5,5}}; 
    if (SquareMatrix(mat1,5,4) !=3)
        printf("SquareMatrix  function is wrong for train1_1 (-7)\n");
    int mat2[5][4] = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1},{6,5,5,5}}; 
    if (SquareMatrix(mat2,5,4) !=4)
        printf("SquareMatrix  function is wrong for train1_2 (-7)\n");
    int mat3[5][4] = {{1,2,2,1},{1,2,1,1},{2,1,2,1},{1,1,1,1},{6,5,5,5}}; 
    if (SquareMatrix(mat3,5,4) !=0)
        printf("SquareMatrix  function is wrong for train1_3 (-6)\n");

    
    //Q2
	if (mystrstr("abracadabra","ab") != 2)
		printf("mystrstr function is wrong for train2-1  (-7)\n");

	if (mystrstr("abracadabra","a") != 5)
		printf("mystrstr function is wrong for train2-2  (-7)\n");

	if (mystrstr("bbbb","bb") != 3)
		printf("mystrstr function is wrong for train2-3  (-6)\n");

 //   //Q3
 //   int a1[8]={5,2,4,7,8,9,5, -1};
 //   int res=0, num;
 //   num=bigger(a1, &res);
 //   if(count1<2)
 //       printf ("bigger function is not recursive (-10)\n");
 //   else{
 //      if (res!=24)
	//		printf("bigger function is wrong for train3_1(-10)\n");
 //   }
 //   int a2[8]={5,2,4,7,8,9,2, -1};
 //      res=0;
 //    num=bigger(a2, &res);
 //   if(count1<2)
 //       printf ("bigger function is not recursive (-10)\n");
 //   else{
 //      if (res!=33)
	//		printf("bigger function is wrong for train3_2  (-10)\n");
 //   }


	////4
	//printf("Question 4 will be checked manually, don't worry (-40)\n");
	printf("done");
    return 0;
}
