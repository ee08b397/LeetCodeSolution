import java.util.*;
public class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        for(int i=0;i<nums.length;i++){
            if(map.containsKey(target-nums[i])){
                int[] index={map.get(target-nums[i]),i+1};
                return index;
            }
            map.put(nums[i],i+1);
        }
        return null;
    }
}