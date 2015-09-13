/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 8ms
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,pos=0,mid;
        while(l<=r){
            mid=(l+r)>>1;
            if(nums[mid]==target)return mid;
            else if(target<nums[mid]){
                r=mid-1;pos=mid;
            }else{
                l=mid+1;pos=mid+1;
            }
        }
        return pos;
    }
};
