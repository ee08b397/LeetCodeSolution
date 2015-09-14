/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 0ms
 */
int firstMissingPositive(int* nums, int numsSize) {
    int i=0,tmp;
    for(i=0;i<numsSize;i++){
        if(nums[i] > 0 && nums[i]<numsSize){
            if(nums[nums[i]-1] == nums[i])continue;
            tmp = nums[nums[i]-1];
            nums[nums[i]-1] = nums[i];
            nums[i] = tmp;
            i--;
        }
    }
    for(i=0;i<numsSize;i++){
        if(nums[i]-1 !=i)return i+1;
    }
    return i+1;
}
