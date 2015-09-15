/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 28ms
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> returnColumn;
        vector<int> prefix(nums.size(),0);
        DFS(nums,0,prefix,0,returnColumn);
        return returnColumn;
    }
private:
    void DFS(vector<int>& nums,int step,vector<int>& prefix,int prefixSize,vector<vector<int>>& returnColumn){
        if(step >= nums.size())return;
        if(step == nums.size()-1){
            prefix[step] = nums[step];
            vector<int> newColumn(prefix);
            returnColumn.push_back(newColumn);
            return;
        }
        for(int i=step;i<nums.size();i++){
            if(i != step){
                nums[i] = nums[i]^nums[step];
                nums[step] = nums[i]^nums[step];
                nums[i] = nums[i]^nums[step];
            }
            prefix[prefixSize] = nums[step];
            DFS(nums,step+1,prefix,prefixSize+1,returnColumn);
            if(i != step){
                nums[i] = nums[i]^nums[step];
                nums[step] = nums[i]^nums[step];
                nums[i] = nums[i]^nums[step];
            }
        }
    }
};
