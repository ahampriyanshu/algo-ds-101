#include <stdio.h>

int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}

int maxSubArray(int* nums, int numsSize){
    int i,ans;
    int maxSum[numsSize+1];
    
    for(i=0;i<numsSize;i++)
    {
        if(i==0)
        {
            maxSum[i]=nums[0];
        }
        else
        {
        maxSum[i] = max( nums[i], nums[i] + maxSum[i - 1] );
        }
    }
    ans = maxSum[0];
    for(i=0;i<numsSize;i++)
    {
        if(ans<maxSum[i])
        {
            ans = maxSum[i];
        }
    }
    return ans;

}

int main() {
    int numsSize,i;
    scanf("%d",&numsSize);
    int nums[numsSize];
    for(i=0;i<numsSize;i++)
    {
        scanf("%d",&nums[i]);
    }
    printf("%d",maxSubArray(nums,numsSize));
    return 0;
}
