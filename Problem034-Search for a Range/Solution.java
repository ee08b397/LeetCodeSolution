/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 407ms
 */
public class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] res = new int[2];
        int l=0,len=nums.length,r=len-1,mid=0;
        while(l<=r){
            mid=(l+r)>>1;
            if(nums[mid]==target)break;
            else if(nums[mid]>target)r=mid-1;
            else l=mid+1;
        }
        if(l<=r){
            l=mid-1;
            while(l>=0 && nums[l]==nums[mid])l--;
            r=mid+1;
            while(r<len && nums[r]==nums[mid])r++;
            res[0]=l+1;
            res[1]=r-1;
        }else{
            res[0]=-1;
            res[1]=-1;
        }
        return res;
    }
}