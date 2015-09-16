/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 300ms
 */
public class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> returnColumn = new ArrayList<List<Integer>>();
        Integer[] prefix = new Integer[nums.length];
        int[] visited = new int[nums.length];
        DFS(nums,0,prefix,visited,returnColumn);
        return returnColumn;
    }
    private void DFS(int[] nums,int step,Integer[] prefix,int[] visited,List<List<Integer>> returnColumn){
        if(step >= nums.length){
            returnColumn.add(Arrays.asList(Arrays.copyOf(prefix,prefix.length)));
            return;
        }
        for(int i=0;i<nums.length;i++){
            if(visited[i] == 1)continue;
            if(i>0 && nums[i] == nums[i-1] && visited[i-1] ==0)continue;
            visited[i] = 1;
            prefix[step] = nums[i];
            DFS(nums,step+1,prefix,visited,returnColumn);
            visited[i] = 0;
        }
    }
}