/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 348ms
 */
public class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> returnColumn = new ArrayList<List<Integer>>();
        int[] prefix = new int[100000];
        DFS(candidates,0,target,prefix,0,returnColumn);
        return returnColumn;
    }
    private void DFS(int[] candidates,int step,int target,int[] prefix,int prefixSize,List<List<Integer>> returnColumn){
        if(step > candidates.length)return;
        if(target <= 0)return;
        for(int i=step;i<candidates.length;i++){
            if(i>step && candidates[i] == candidates[i-1])continue;
            if(target < candidates[i])break;
            else if(target == candidates[i]){
                List<Integer> newColumn = new ArrayList<Integer>();
                prefix[prefixSize] = candidates[i];
                for(int j=0;j<prefixSize+1;j++){
                    newColumn.add(prefix[j]);
                }
                returnColumn.add(newColumn);
                break;
            }else{
                prefix[prefixSize] = candidates[i];
                DFS(candidates,i+1,target-candidates[i],prefix,prefixSize+1,returnColumn);
            }
        }
    }
}