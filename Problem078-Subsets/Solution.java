/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 3ms
 */
public class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> returnColumn = new ArrayList<List<Integer>>();
        int[] tmp = new int[nums.length];
        Arrays.sort(nums);
        for(int i=0;i<=nums.length;i++){
            getSubset(returnColumn,tmp,0,-1,nums,i);
        }
        return returnColumn;
    }
    private void getSubset(List<List<Integer>> returnColumn,int[] tmp,int step,int index,int[] nums,int k){
        if(step==k){
            List<Integer> res = new ArrayList<Integer>();
            for(int i=0;i<k;i++)res.add(tmp[i]);
            returnColumn.add(res);
            return;
        }
        for(int i=index+1;i<=nums.length-k+step;i++){
            tmp[step]=nums[i];
            getSubset(returnColumn,tmp,step+1,i,nums,k);
        }
    }
}