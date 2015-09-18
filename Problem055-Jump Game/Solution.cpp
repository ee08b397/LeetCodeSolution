/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 16ms
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max=0;
        for(int i=0;i<nums.size();i++){
            if(i > max)return false;
            max = max > i+nums[i] ? max : i+nums[i];
        }
        return max >= nums.size()-1;
    }
};
