/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 9ms
 */
int abs(int tar){
    return tar>0?tar:-tar;
}
void quickSort(int* nums,int first,int end){
    int l=first,r=end;
    if(first>=end)return;
    int temp=nums[l];
    while(l<r){
        while(l<r && nums[r]>=temp)r--;
        if(l<r)nums[l]=nums[r];
        while(l<r && nums[l]<=temp)l++;
        if(l<r)nums[r]=nums[l];
    }
    nums[l]=temp;
    quickSort(nums,first,l-1);
    quickSort(nums,l+1,end);
}
int threeSumClosest(int* nums, int numsSize, int target) {
    int begin,end,i,sum,Min=INT_MAX;
    quickSort(nums,0,numsSize-1);
    for(i=0;i<numsSize-2;i++){
        if(i>0 && nums[i]==nums[i-1])continue;
        begin=i+1;end=numsSize-1;
        while(begin<end){
            sum=nums[i]+nums[begin]+nums[end];
            if(abs(sum-target)<abs(Min))Min=sum-target;
            if(sum==target)return target;
            else if(sum>target)end--;
            else begin++;
        }
    }
    return Min+target;
}
