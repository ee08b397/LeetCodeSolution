/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 15ms
 */
int removeDuplicates(int* nums, int numsSize) {
    int i,j;
	if(numsSize <= 1)return numsSize;
	i=j=1;
	for(i=1;i<numsSize;i++){
		if(nums[i-1] !=nums[i]){
			nums[j++]=nums[i];
		}
	}
	return j;
}
