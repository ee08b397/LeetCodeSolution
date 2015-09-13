/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 437ms
 */
public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        int len=nums.length;
        if(len<3)return res;
        Arrays.sort(nums);
        for(int i=0;i<len;i++){
            if(nums[i]>0)break;
            if(i>0 && nums[i]==nums[i-1])continue;
            int begin=i+1,end=len-1;
            while(begin<end){
                int sum=nums[i]+nums[begin]+nums[end];
                if(sum==0){
                    List<Integer> list = new ArrayList<Integer>();
                    list.add(nums[i]);list.add(nums[begin]);list.add(nums[end]);
                    res.add(list);
                    begin++;end--;
                    while(begin<end && nums[begin]==nums[begin-1])begin++;
                    while(begin<end && nums[end]==nums[end+1])end--;
                }else if(sum>0)end--;
                else begin++;
            }
        }
        return res;
    }
}