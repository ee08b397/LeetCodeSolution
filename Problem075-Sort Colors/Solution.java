/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 1ms
 */
public class Solution {
    public void sortColors(int[] nums) {
        int i=0,j,k=nums.length-1;
        while(i<=k && nums[i]==0)i++;
        while(k>=0 && nums[k]==2)k--;
        j=i;
        while(j<=k){
            if(nums[j]==0){
                nums[i]^=nums[j];
                nums[j]^=nums[i];
                nums[i]^=nums[j];
                j++;i++;
            }else if(nums[j]==2){
                nums[k]^=nums[j];
                nums[j]^=nums[k];
                nums[k]^=nums[j];
                while(j<=k && nums[k]==2)k--;
            }else j++;
        }
    }
}