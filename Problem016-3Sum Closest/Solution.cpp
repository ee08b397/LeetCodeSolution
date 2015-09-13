/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 12ms
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int length=nums.size(),Min=2147483647;
        quickSort(nums,0,length-1);
        for(int i=0;i<length-2;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int begin=i+1,end=length-1;
            while(begin<end){
                int sum=nums[i]+nums[begin]+nums[end];
                if(abs(sum-target)<abs(Min))Min=sum-target;
                if(sum==target)return target;
                else if(sum>target)end--;
                else begin++;
            }
        }
        return Min+target;
    }
private:
    int abs(int t){
        return t>0?t:-t;
    }
    void quickSort(vector<int>& nums,int first,int end){
        int l=first,r=end,tmp;
        if(first>=end)return;
        tmp=nums[l];
        while(l<r){
            while(l<r && nums[r]>=tmp)r--;
            if(l<r)nums[l]=nums[r];
            while(l<r && nums[l]<=tmp)l++;
            if(l<r)nums[r]=nums[l];
        }
        nums[l]=tmp;
        quickSort(nums,first,l-1);
        quickSort(nums,l+1,end);
    }
};
