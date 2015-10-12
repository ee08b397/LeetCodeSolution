/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 8ms
 */
int removeDuplicates(int* nums, int numsSize) {
    int num=0,cur=numsSize==0?0:nums[0]+1,i,j;
    for(i=0,j=0;i<numsSize;i++){
        if(nums[i]!=cur){
            cur=nums[i];
            num=1;
        }else{
            num++;
        }
        if(num<=2)nums[j++]=nums[i];
    }
    return j;
}
