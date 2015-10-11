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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> returnColumn;
        sort(nums.begin(),nums.end());
        vector<int> tmp(nums.size());
        for(int i=0;i<=nums.size();i++){
            getSubset(returnColumn,tmp,0,-1,nums,i);
        }
        return returnColumn;
    }
private:
    void getSubset(vector<vector<int>>& returnColumn,vector<int>& tmp,int step,int index,vector<int> nums,int k){
        if(step==k){
            vector<int> res(tmp.begin(),tmp.begin()+k);
            returnColumn.push_back(res);
            return;
        }
        for(int i=index+1;i<=nums.size()-k+step;i++){
            tmp[step]=nums[i];
            getSubset(returnColumn,tmp,step+1,i,nums,k);
        }
    }
};
