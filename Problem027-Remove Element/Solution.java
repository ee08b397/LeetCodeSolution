/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 248ms
 */
public class Solution {
    public int removeElement(int[] nums, int val) {
        int size=0,length=nums.length;
        for(int i=0;i<length;i++){
            if(nums[i]!=val)nums[size++]=nums[i];
        }
        return size;
    }
}