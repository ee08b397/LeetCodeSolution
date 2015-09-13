/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 14ms
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int l=0,len=nums.size(),r=len-1,mid;
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
            res.push_back(l+1);
            res.push_back(r-1);
        }else{
            res.push_back(-1);
            res.push_back(-1);
        }
        return res;
    }
};
