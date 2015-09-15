/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 248ms
 */
public class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> returnColumn = new ArrayList<List<Integer>>();
        int[] prefix = new int[nums.length];
        DFS(nums,0,prefix,0,returnColumn);
        return returnColumn;
    }
    private void DFS(int[] nums,int step,int[] prefix,int prefixSize,List<List<Integer>> returnColumn){
        if(step == nums.length)return;
        if(step == nums.length-1){
            prefix[step] = nums[step];
            List<Integer> newColumn = new ArrayList<Integer>();
            for(int p:prefix){
                newColumn.add(p);
            }
            returnColumn.add(newColumn);
            return;
        }
        for(int i=step;i<nums.length;i++){
            if(i != step){
                nums[i] = nums[i]^nums[step];
                nums[step] = nums[i]^nums[step];
                nums[i] = nums[i]^nums[step];
            }
            prefix[prefixSize] = nums[step];
            DFS(nums,step+1,prefix,prefixSize+1,returnColumn);
            if(i!= step){
                nums[i] = nums[i]^nums[step];
                nums[step] = nums[i]^nums[step];
                nums[i] = nums[i]^nums[step];
            }
        }
    }
}