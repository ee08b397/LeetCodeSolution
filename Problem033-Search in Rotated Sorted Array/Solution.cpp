/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 6ms
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index=0,len=nums.size();
        while(index<len-1 && nums[index]<=nums[index+1])index++;
        if(target>=nums[0] && target<=nums[index]){
            return find(nums,0,index,target);
        }else{
            return find(nums,index+1,len-1,target);
        }
    }
private:
    int find(vector<int>& nums,int start,int end,int target){
        if(start>end)return -1;
        int l=start,r=end,mid;
        while(l<=r){
            mid=(l+r)>>1;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target)r=mid-1;
            else l=mid+1;
        }
        return -1;
    }
};
