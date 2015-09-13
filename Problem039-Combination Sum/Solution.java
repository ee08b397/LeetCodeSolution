/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 308ms
 */
public class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        int i,j;
        for(i=1,j=1;i<candidates.length;i++){
            if(candidates[i] != candidates[i-1]){
                candidates[j] = candidates[i];
                j++;
            } 
        }
        candidates = Arrays.copyOf(candidates,j);
        List<List<Integer>> returnColumn = new ArrayList<List<Integer>>();
        int[] prefix = new int[10000];
        com_Sum(candidates,0,target,prefix,0,returnColumn);
        return returnColumn;
    }
    private void com_Sum(int[] candidates,int step,int target,int[] prefix,int prefixSize,List<List<Integer>> returnColumn){
        if(step >= candidates.length)return;
        if(target <=0) return;
        for(int i=step;i<candidates.length;i++){
            if(candidates[i] > target)break;
            else if(candidates[i] == target){
                List<Integer> newColumn = new ArrayList<Integer>();
                for(int j=0;j<prefixSize;j++){
                    newColumn.add(prefix[j]);
                }
                newColumn.add(candidates[i]);
                returnColumn.add(newColumn);
                break;
            }else{
                prefix[prefixSize] = candidates[i];
                com_Sum(candidates,i,target - candidates[i],prefix,prefixSize+1,returnColumn);
            }
        }
    }
}