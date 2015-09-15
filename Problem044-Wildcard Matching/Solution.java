/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 372ms
 */
public class Solution {
    public boolean isMatch(String s, String p) {
        int i=0,j=0,s_pos=-1,p_pos=-1;
        while(i < s.length()){
            if(j < p.length()){
                if(p.charAt(j) == '?' || p.charAt(j) == s.charAt(i)){
                    i++;j++;continue;
                }
                if(p.charAt(j) =='*'){
                    j++;
                    p_pos = j;
                    s_pos = i;
                    continue;
                }
            }
            if(s_pos != -1){
                s_pos++;
                i = s_pos;
                j = p_pos;
                continue;
            }
            return false;
        }
        while(j< p.length() && p.charAt(j)=='*')j++;
        return j>=p.length();
    }
}