/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 48ms
 */
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void quickSort(int* nums,int start,int end){
    int l=start,r=end,tmp=nums[l];
    if(start>=end)return;
    while(l<r){
        while(l<r && nums[r]>=tmp)r--;
        if(l<r)nums[l]=nums[r];
        while(l<r && nums[l]<=tmp)l++;
        if(l<r)nums[r]=nums[l];
    }
    nums[l]=tmp;
    quickSort(nums,start,l-1);
    quickSort(nums,l+1,end);

}
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    int** res = (int**)malloc(sizeof(int*)*1000000);
    int i,j,sum,begin,end,*temp;
    *returnSize=0;
    if(numsSize<4)return res;
    quickSort(nums,0,numsSize-1);
    for(i=0;i<numsSize-3;i++){
        if(i>0 && nums[i]==nums[i-1])continue;
        for(j=i+1;j<numsSize-2;j++){
            if(j>i+1 && nums[j]==nums[j-1])continue;
            begin=j+1;end=numsSize-1;
            while(begin<end){
                sum=nums[i]+nums[j]+nums[begin]+nums[end];
                if(sum==target){
                    temp=(int*)malloc(sizeof(int)*4);
                    temp[0]=nums[i];temp[1]=nums[j];temp[2]=nums[begin];temp[3]=nums[end];
                    res[*returnSize]=temp;
                    (*returnSize)++;
                    begin++;end--;
                    while(begin<end && nums[begin]==nums[begin-1])begin++;
                    while(begin<end && nums[end]==nums[end+1])end--;
                }else if(sum>target){
                    end--;
                    while(begin<end && nums[end]==nums[end+1])end--;
                }
                else{
                    begin++;
                    while(begin<end && nums[begin]==nums[begin-1])begin++;
                }
            }
        }
    }
    return res;
}
