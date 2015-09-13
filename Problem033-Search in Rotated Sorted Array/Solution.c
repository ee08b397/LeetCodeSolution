/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 3ms
 */
int find(int* nums,int start,int end,int target){
    int l=start,r=end,mid;
    if(start>end)return -1;
    while(l<=r){
        mid=(l+r)>>1;
        if(nums[mid]==target)return mid;
        else if(nums[mid]>target)r=mid-1;
        else l=mid+1;
    }
    return -1;
}
int search(int* nums, int numsSize, int target) {
    int index=0;
    while(index<numsSize-1 && nums[index]<=nums[index+1])index++;
    if(target >= nums[0] && target<=nums[index]){
        return find(nums,0,index,target);
    }else{
        return find(nums,index+1,numsSize-1,target);
    }
}
