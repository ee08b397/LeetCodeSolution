/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 527ms
 */
public class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> res=new ArrayList<List<Integer>>();
        int length=nums.length;
        if(length<4)return res;
        Arrays.sort(nums);
        for(int i=0;i<length-3;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<length-2;j++){
                if(j>i+1 && nums[j]==nums[j-1])continue;
                int begin=j+1,end=length-1;
                while(begin<end){
                    int sum=nums[i]+nums[j]+nums[begin]+nums[end];
                    if(sum==target){
                        List<Integer> temp = new ArrayList<Integer>();
                        temp.add(nums[i]);
                        temp.add(nums[j]);
                        temp.add(nums[begin]);
                        temp.add(nums[end]);
                        res.add(temp);
                        begin++;end--;
                        while(begin<end && nums[begin]==nums[begin-1])begin++;
                        while(begin<end && nums[end]==nums[end+1])end--;
                    }else if(sum>target){
                        end--;
                        while(begin<end && nums[end]==nums[end+1])end--;
                    }else{
                        begin++;
                        while(begin<end && nums[begin]==nums[begin-1])begin++;
                    }
                }
            }
        }
        return res;
    }
}