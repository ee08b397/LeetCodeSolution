/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 8ms
 */
bool canJump(int* nums, int numsSize) {
    int max=0,i;
    for(i=0;i<numsSize;i++){
        if(i > max)return false;
        max = max > i+nums[i] ? max : i+nums[i];
    }
    return max>=numsSize-1;
}
