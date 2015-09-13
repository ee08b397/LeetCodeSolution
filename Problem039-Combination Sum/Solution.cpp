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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int i,j;
        for(i=1,j=1;i<candidates.size();i++){
            if(candidates[i] != candidates[i-1]){
                candidates[j++] = candidates[i];
            }
        }
        //candidates.erase(j,candidates.size());
        vector<vector<int>> returnColumn;
        int prefix[100000];
        DFS(candidates,0,prefix,0,target,returnColumn);
        return returnColumn;
    }
private:
    void DFS(vector<int>& candidates,int step,int prefix[],int prefixSize,int target,vector<vector<int>>& returnColumn){
        if(step > candidates.size())return;
        if(target <=0 )return;
        for(int i=step;i<candidates.size();i++){
            if(candidates[i] > target)break;
            else if(candidates[i] == target){
                vector<int> newColumn;
                for(int j=0;j<prefixSize;j++){
                    newColumn.push_back(prefix[j]);
                }
                newColumn.push_back(target);
                returnColumn.push_back(newColumn);
                break;
            }else{
                prefix[prefixSize] = candidates[i];
                DFS(candidates,i,prefix,prefixSize+1,target-candidates[i],returnColumn);
            }
        }
    }
};
