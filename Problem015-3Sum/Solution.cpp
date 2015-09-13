/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 66ms
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len=nums.size();
        if(len<3){
            return res;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<len;i++){
            if(nums[i]>0)break;
            if(i>0 && nums[i]==nums[i-1])continue;
            int begin=i+1,end=len-1;
            while(begin<end){
                int sum=nums[i]+nums[begin]+nums[end];
                if(sum==0){
                    vector<int> t;
                    t.push_back(nums[i]);
                    t.push_back(nums[begin]);
                    t.push_back(nums[end]);
                    res.push_back(t);
                    begin++;end--;
                    while(begin<end && nums[begin]==nums[begin-1])begin++;
                    while(begin<end && nums[end]==nums[end+1])end--;
                }else if(sum>0){
                    end--;
                }else begin++;
            }
        }
        return res;
    }
};
