/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 2ms
 */
int removeElement(int* nums, int numsSize, int val) {
    int size=0,i;
    for(i=0;i<numsSize;i++){
        if(nums[i]!=val)nums[size++]=nums[i];
    }
    return size;
}
