/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 14ms
 */
void nextPermutation(int* nums, int numsSize) {
    int j,i=numsSize-1,tmp;
    while(i>0 && nums[i]<=nums[i-1])i--;
    if(i!=0){
        j=numsSize-1;
        while(j>=i && nums[j]<=nums[i-1])j--;
        tmp=nums[j];
        nums[j]=nums[i-1];
        nums[i-1]=tmp;
    }
    j=numsSize-1;
    while(i<j){
        tmp=nums[i];
        nums[i]=nums[j];
        nums[j]=tmp;
        i++;j--;
    }
}
