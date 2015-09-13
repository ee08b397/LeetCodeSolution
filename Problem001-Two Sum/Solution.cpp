/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 28ms
 */

#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> map;
        for(int i=0;i<nums.size();i++){
			std::map<int, int>::iterator iter;
            iter = map.find(target-nums[i]);
            if(iter!=map.end()){
                vector<int> vec;
				vec.push_back(iter->second);
				vec.push_back(i+1);
				return vec;
            }
            map[nums[i]]=i+1;
        }
        return vector<int>();
    }
};
