/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 20ms
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur=nums.size()==0?0:nums[0]+1,i,j,num;
        for(i=0,j=0;i<nums.size();i++){
            if(cur!=nums[i]){
                cur=nums[i];
                num=1;
            }else num++;
            if(num<=2)nums[j++]=nums[i];
        }
        return j;
    }
};
