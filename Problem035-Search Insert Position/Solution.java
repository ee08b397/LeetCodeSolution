/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 340ms
 */
public class Solution {
    public int searchInsert(int[] nums, int target) {
        int l=0,r=nums.length-1,pos=0,mid;
        while(l<=r){
            mid=(l+r)>>1;
            if(target==nums[mid])return mid;
            else if(target>nums[mid]){
                l=mid+1;pos=mid+1;
            }else{
                r=mid-1;pos=mid;
            }
        }
        return pos;
    }
}