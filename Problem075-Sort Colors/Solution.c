/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 0ms
 */
//Solution 1(use two-pass algorithm):0ms
void sortColors(int* nums, int numsSize) {
    int i,red=0,white=0,blue=0;
    for(i=0;i<numsSize;i++){
        switch(nums[i]){
            case 0:red++;break;
            case 1:white++;break;
            case 2:blue++;break;
        }
    }
    i=0;
    while(red-->0)nums[i++]=0;
    while(white-->0)nums[i++]=1;
    while(blue-->0)nums[i++]=2;
}

//Solution 2(use one-pass algorithm):0ms
void sortColors(int* nums, int numsSize) {
    int i=0,j=0,k=numsSize-1;
    while(i<numsSize && nums[i]==0){
        i++;j++;
    }
    while(k>=0 && nums[k]==2)k--;
    while(j<=k){
        if(nums[j]==0){
            nums[i]^=nums[j];
            nums[j]^=nums[i];
            nums[i]^=nums[j];
            j++;i++;
        }else if(nums[j]==2){
            nums[j]^=nums[k];
            nums[k]^=nums[j];
            nums[j]^=nums[k];
            while(j<=k && nums[k]==2)k--;
        }else j++;
    }
}
