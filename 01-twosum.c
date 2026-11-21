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

// 2026/11/21 Note:
// 1. 在vscode 要自己加上 main 來呼叫函式，自己賦值

// # 針對 twosum() 遇到的問題
// 1. twoSum() 回傳一個指向整數的指標(twoSum will return a pointer to an int.)
//  - 用int* (指標) 宣告，所以要回傳一個指標。 
//  - NULL 是指標，代表空、沒有結果。 不建議回傳 0

// 2. result 為什麼可以當作陣列?
// - malloc(sizeof(int)*2) 會一次借一塊「連續」的記憶體，
// 大小剛好放兩個 int, result 存的是這塊的起點位址.
// - C 語言的陣列本質就是「連續排列的同型別資料」，所以 
// result[1] 只是「從起點往後跳 1 個 int 的位置」。