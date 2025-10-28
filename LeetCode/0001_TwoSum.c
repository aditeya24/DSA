/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *ans = (int *)malloc(2 * sizeof(int));
    ans[0]=0,ans[1]=0;
    *returnSize = 2;
    for(int i=0;i<numsSize-1;i++){
        int trgt=target-nums[i];
        for(int j=i+1;j<numsSize;j++){
            if(nums[j]==trgt){
                ans[0]=i,ans[1]=j;
                return ans;
            }
        }
    }
    return ans;
}

