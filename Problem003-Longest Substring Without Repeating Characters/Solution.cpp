/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 76ms
 */

#define INT_MAX 2147483647
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int Max=0,length=0;
        int hash[256];
        for(int j=0;j<256;j++)hash[j]=INT_MAX;
        for(int i=0;i<s.size();i++){
            if(hash[s[i]]!=INT_MAX){
                length = i-hash[s[i]];
                int index = hash[s[i]];
                for(int j=0;j<256;j++)hash[j]=INT_MAX;
                for(int j=index+1;j<=i;j++)hash[s[j]]=j;
            }else{
                hash[s[i]]=i;
                length++;
                Max = Max>length?Max:length;
            }
        }
        return Max;
    }
};
