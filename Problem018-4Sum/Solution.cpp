/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 141ms
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int length=nums.size();
        if(length<4)return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<length-3;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<length-2;j++){
                if(j>i+1 && nums[j]==nums[j-1])continue;
                int begin=j+1,end=length-1;
                while(begin<end){
                    int sum=nums[i]+nums[j]+nums[begin]+nums[end];
                    if(sum==target){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[begin]);
                        temp.push_back(nums[end]);
                        res.push_back(temp);
                        begin++;end--;
                        while(begin<end && nums[begin]==nums[begin-1])begin++;
                        while(begin<end && nums[end]==nums[end+1])end++;
                    }else if(sum>target){
                        end--;
                        while(begin<end && nums[end]==nums[end+1])end--;
                    }else{
                        begin++;
                        while(begin<end && nums[begin]==nums[begin-1])begin++;
                    }
                }
            }
        }
        return res;
    }
};
