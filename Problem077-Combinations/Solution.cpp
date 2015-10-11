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
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> returnColumn;
        vector<int> tmp(k);
        getCombine(returnColumn,tmp,0,n,k);
        return returnColumn;
    }
private:
    void getCombine(vector<vector<int>>& returnColumn,vector<int>& tmp,int step,int n,int k){
        if(step==k){
            vector<int> res(tmp);
            returnColumn.push_back(res);
            return;
        }
        for(int i=step==0?1:tmp[step-1]+1;i<=n;i++){
            tmp[step]=i;
            getCombine(returnColumn,tmp,step+1,n,k);
        }
    }
};
