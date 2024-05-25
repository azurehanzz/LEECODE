#include <stdio.h>
#include<stdlib.h>
//找到满足插值条件的下标
int* findIndices(int* nums, int numsSize, int indexDifference, int valueDifference, int* returnSize) {
	int i, j;
	int* preturn = (int*)malloc(sizeof(int) * 2);
	for (i = 0; i < numsSize; i++)
	{
		preturn[0] = i;
		for (j = i; j < numsSize; j++)
		{
			if (j - i >= indexDifference)
			{
				if (nums[i] - nums[j] >= valueDifference || nums[i] - nums[j] <= -valueDifference)
				{
					preturn[1] = j;
					return preturn;
				}
			}
		}
	}
	preturn[0] = -1;
	preturn[1] = -1;
	return preturn;

}


void main() {

	int arr[4] = { 5,1,4,1 };
	int sz = sizeof(arr) / sizeof(int);
	int* revalue = findIndices(arr, sz, 2, 4, NULL);
	int ii;
	printf("返回值为:");
	for (ii = 0; ii < 2; ii++)
	{
		printf("%d ", revalue[ii]);
	}
	return;
}