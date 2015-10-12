/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 20ms
 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return find(nums,0,nums.size()-1,target);
    }
private:
    bool find(vector<int>& nums,int left,int right,int target){
        if(left>right)return false;
        int mid = left+(right-left)/2;
        if(nums[mid]==target)return true;
        else if(nums[mid] > target){
            if(nums[mid] < nums[0])return find(nums,left,mid-1,target);
            else return find(nums,left,mid-1,target) || find(nums,mid+1,right,target);
        }else{
            if(nums[mid] > nums[0])return find(nums,mid+1,right,target);
            else return find(nums,left,mid-1,target) || find(nums,mid+1,right,target);
        }
    }
};
