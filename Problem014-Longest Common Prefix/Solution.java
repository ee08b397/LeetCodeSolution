/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 263ms
 */
public class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length==0)return "";
        char[] str=strs[0].toCharArray();
        int Min=str.length;
        for(int i=1;i<strs.length;i++){
            char[] s=strs[i].toCharArray();
            int j=0;
            while(j<Min && j<s.length && s[j]==str[j])j++;
            Min = Min>j?j:Min;
        }
        return strs[0].substring(0,Min);
    }
}