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
    public boolean search(int[] nums, int target) {
        return find(nums,0,nums.length-1,target);
    }
    private boolean find(int[] nums,int left,int right,int target){
        if(left>right)return false;
        int mid=left+(right-left)/2;
        if(nums[mid]==target)return true;
        else if(nums[mid]>target){
            if(nums[mid]<nums[0])return find(nums,left,mid-1,target);
            else return find(nums,mid+1,right,target) || find(nums,left,mid-1,target);
        }else{
            if(nums[mid]>nums[0])return find(nums,mid+1,right,target);
            else return find(nums,mid+1,right,target) || find(nums,left,mid-1,target);
        }
    }
}