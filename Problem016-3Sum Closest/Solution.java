/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 342ms
 */
public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int length=nums.length,Min=Integer.MAX_VALUE;
        Arrays.sort(nums);
        for(int i=0;i<length-2;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int begin=i+1,end=length-1;
            while(begin<end){
                int sum=nums[i]+nums[begin]+nums[end];
                if(Math.abs(sum-target)<Math.abs(Min))Min=sum-target;
                if(sum==target)return target;
                else if(sum>target)end--;
                else begin++;
            }
        }
        return Min+target;
    }
}