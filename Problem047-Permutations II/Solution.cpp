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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> returnColumn;
        vector<int> prefix(nums.size());
        vector<int> visited(nums.size(),0);
        DFS(nums,0,prefix,visited,returnColumn);
        return returnColumn;
    }
private:
    void DFS(vector<int>& nums,int step,vector<int>& prefix,vector<int>& visited,vector<vector<int>>& returnColumn){
        if(step >= nums.size()){
            returnColumn.push_back(vector<int>(prefix));
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i] == 1)continue;
            if(i>0 && nums[i] == nums[i-1] && visited[i-1]==0)continue;
            visited[i] = 1;
            prefix[step] = nums[i];
            DFS(nums,step+1,prefix,visited,returnColumn);
            visited[i] = 0;
        }
    }
};
