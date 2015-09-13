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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> returnColumn;
        int prefix[100000];
        DFS(candidates,0,target,prefix,0,returnColumn);
        return returnColumn;
    }
private:
    void DFS(vector<int>& candidates,int step,int target,int prefix[],int prefixSize,vector<vector<int>>& returnColumn){
        if(step >= candidates.size())return;
        if(target <= 0)return;
        for(int i=step;i<candidates.size();i++){
            if(i>step && candidates[i] == candidates[i-1])continue;
            if(target < candidates[i])return;
            else if(target == candidates[i]){
                vector<int> newColumn;
                prefix[prefixSize] = candidates[i];
                for(int j=0;j<prefixSize+1;j++){
                    newColumn.push_back(prefix[j]);
                }
                returnColumn.push_back(newColumn);
                break;
            }else{
                prefix[prefixSize] = candidates[i];
                DFS(candidates,i+1,target - candidates[i],prefix,prefixSize+1,returnColumn);
            }
        }
    }
};
