/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 4ms
 */
bool search(int* nums, int numsSize, int target) {
    int mid=(numsSize-1)/2;
    if(numsSize<=0)return false;
    if(nums[mid]==target)return true;
    else if(nums[mid] > target){
        if(nums[mid] < nums[0])return search(nums,mid,target);
        else return search(nums,mid,target) || search(nums+mid+1,numsSize-mid-1,target);
    }
    else{
        if(nums[mid]>nums[0])return search(nums+mid+1,numsSize-mid-1,target);
        else return search(nums,mid,target) || search(nums+mid+1,numsSize-mid-1,target);
    }
}
