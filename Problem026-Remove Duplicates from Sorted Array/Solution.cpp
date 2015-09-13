/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 38ms
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size=0,len=nums.size();
        for(int i=0;i<len;i++){
            if(i==0 || nums[i]!=nums[i-1]){
                nums[size]=nums[i];
                size++;
            }
        }
        return size;
    }
};
