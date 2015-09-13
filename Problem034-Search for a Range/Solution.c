/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 8ms
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* res=(int*)malloc(sizeof(int)*2);
    int l=0,r=numsSize-1,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(nums[mid]==target)break;
        else if(nums[mid]>target)r=mid-1;
        else l=mid+1;
    }
    if(l<=r){
        l=mid-1;
        while(l>=0 && nums[l]==nums[mid])l--;
        r=mid+1;
        while(r<numsSize && nums[r]==nums[mid])r++;
        res[0]=l+1;res[1]=r-1;
        *returnSize=2;
        return res;
    }else{
        res[0]=-1;res[1]=-1;
        *returnSize=2;
        return res;
    }
}
