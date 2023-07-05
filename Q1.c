#include "exam.h"

int SquareMatrix(int mat[N][M], int n, int m)
{
	int maxSize = 0;
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < m - 1; j++) {
			/*
			* first, try to find a cube of mimimal size, i.e 2.
			* If we find such a cube, we start by setting currentCubeSize to 2.
			* We then iteratively try to see if the cube extends further then currentCubeSize,
			* by checking bottom encompassing row of currentCube,
			* and rightmost encompassing column of currentCube.
			* If valid, we increase currentCubeSize, and continue,
			* until we can go no further.
			*/
			if (mat[i][j] == mat[i][j + 1]&&
				mat[i][j + 1]== mat[i+1][j + 1]&&
				mat[i+1][j + 1]==mat[i+1][j]) {
				int currentCubeSize = 2;
				/*
				* Now, trying to see if part of a larger cube:
				*/
				int value = mat[i][j];
				while (i+currentCubeSize < n && j + currentCubeSize < m) {
					/*
					* First, checking the row bellow the current cube
					*/
					int rowBelowIsValid = 1;
					for (int col = j; col <= j + currentCubeSize; col++) {
						if (mat[i+currentCubeSize][col] != value) {
							rowBelowIsValid = 0;
							break;
						}
					}
					if (!rowBelowIsValid) {
						break;
					}
					int columnToTheRightIsValid = 1;
					for (int row = i; row <= i + currentCubeSize; row++) {
						if (mat[row][j+currentCubeSize] != value) {
							columnToTheRightIsValid = 0;
							break;
						}
					}
					if (!columnToTheRightIsValid) {
						break;
					}
					/*
					* current size increases only if both rowBelowIsValid && columnToTheRightIsValid
					*/
					currentCubeSize++;
				}

				/*
				* At last, if the current cube is the largest we have found,
				* set maxSize to its size.
				*/
				if (maxSize < currentCubeSize) {
					maxSize = currentCubeSize;
				}
			}
		}
	}
	return maxSize;
}

