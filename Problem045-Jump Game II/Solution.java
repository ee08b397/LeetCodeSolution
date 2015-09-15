/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 396ms
 */
public class Solution {
    public int jump(int[] nums) {
        if(nums.length <= 1)return 0;
        int[] jumps = new int[nums.length];
        jumps[0]=0;
        int pos=0;
        for(int i=0;i<nums.length;i++){
            if(i+nums[i] > pos){
                if(i+nums[i] >= nums.length-1)return jumps[i]+1;
                for(int j=pos+1;j<=i+nums[i];j++){
                    jumps[j] = jumps[i]+1;
                }
                pos = i+nums[i];
            }
        }
        return jumps[nums.length-1];
    }
}