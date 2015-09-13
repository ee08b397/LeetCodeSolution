/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 370ms
 */

public class Solution {
    private final static int INT_MAX=2147483647;
    public int lengthOfLongestSubstring(String s) {
        int[] hash = new int[256];
        int length=0,Max=0;
        char[] chs = s.toCharArray();
        for(int j=0;j<256;j++)hash[j]=INT_MAX;
        for(int i=0;i<chs.length;i++){
            char c = chs[i];
            if(hash[c]!=INT_MAX){
                int index = hash[c];
                length = i-index;
                for(int j=0;j<256;j++)hash[j]=INT_MAX;
                for(int j=index+1;j<=i;j++)hash[chs[j]]=j;
            }else{
                hash[chs[i]]=i;
                length++;
                Max = Max>length?Max:length;
            }
        }
        return Max;
    }
}