/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 12ms
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0,j=0,s_pos=-1,p_pos=-1;
        while(i < s.size()){
            if(j < p.size()){
                if(p[j] == '?' || p[j] == s[i]){
                    i++;j++;continue;
                }
                if(p[j]=='*'){
                    j++;
                    p_pos = j;
                    s_pos = i;
                    continue;
                }
            }
            if(s_pos != -1){
                s_pos ++;
                i = s_pos;
                j = p_pos;
                continue;
            }
            return false;
        }
        while(j < p.size() && p[j] == '*')j++;
        return j>= p.size();
    }
};
