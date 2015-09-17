/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 332ms
 */
public class Solution {
    public int maxSubArray(int[] nums) {
        int max=-2147483648,sum=0;
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
            max = max>sum?max:sum;
            if(sum<0)sum=0;
        }
        return max;
    }
}