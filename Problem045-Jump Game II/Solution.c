/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 8ms
 */
int jump(int* nums, int numsSize) {
    if(numsSize<=1)return 0;
    int* jumps = (int*)malloc(sizeof(int)*numsSize);
    int i,j,pos=0;
    for(i=1;i<numsSize;i++){
        jumps[i] = 2147483647;
    }
    jumps[0]=0;
    for(i=0;i<numsSize;i++){
        if(i+nums[i] > pos){
            if(i+nums[i] >= numsSize-1)return jumps[i] + 1;
            for(j=pos+1;j<=i+nums[i];j++){
                jumps[j] = jumps[i] + 1;
            }
            pos = i+nums[i];
        }
    }
    return jumps[numsSize-1];
}
