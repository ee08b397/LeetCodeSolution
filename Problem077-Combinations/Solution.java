/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 2ms
 */
public class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> returnColumn = new ArrayList<List<Integer>>();
        int[] tmp = new int[k];
        getCombine(returnColumn,tmp,0,n,k);
        return returnColumn;
    }
    private void getCombine(List<List<Integer>> returnColumn,int[] tmp,int step,int n,int k){
        if(step==k){
            List<Integer> res = new ArrayList<Integer>();
            for(int t:tmp)res.add(t);
            returnColumn.add(res);
            return;
        }
        for(int i=step==0?1:tmp[step-1]+1;i<=n;i++){
            tmp[step]=i;
            getCombine(returnColumn,tmp,step+1,n,k);
        }
    }
}