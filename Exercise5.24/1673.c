#include <stdio.h>
#include <stdlib.h>

int* mostCompetitive(int* nums, int numsSize, int k, int* returnSize) {
    int n = numsSize;
    int* res = (int*)malloc(sizeof(int) * n);
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        while (pos > 0 && n - i + pos > k && res[pos - 1] > nums[i]) 
        {
            pos--;
        }
        res[pos++] = nums[i];
    }
    return res;
}


int main()
{
	int a[] = { 3,2,5,6,9,2,3,1,2,3,3,2 };
	int sz = sizeof(a)/sizeof(int);
    int k = 6;
	int* returnvalue = mostCompetitive(a, sz,k, 5);
    printf("最有竞争力的数组为:");
    int i;
    for (i = 0; i < k; i++)
    {
        printf("%d", *(returnvalue + i));
    }
	return 0;
}