/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i,j;
    for( i = 0; i< numsSize; i++){
        for( j = i +1; j< numsSize; j++){
        if((nums[i]+nums[j]==target)){
            int * result = malloc(sizeof(int)*2);
            result[0]=i;
            result[1]=j;
            *returnSize =2;
            return result;
        }
        }
    }
    *returnSize =0;
    return NULL;
}

int main(){
    int nums[] = {2,7,11,15};
    int numsSize = 4;
    int target = 9;
    int returnSize = 0;
    int *ans = twoSum(nums, numsSize, target, &returnSize);
    if(ans != NULL){
            printf("[%d, %d]", ans[0], ans[1]);
            free(ans);
    }
    return 0;
}