/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 407ms
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        return Match(s,0,p,0);
    }
    bool Match(string s,int index1,string p,int index2){
        if(index2>=p.size())return index1>=s.size();
        if(index2+1<p.size() && p[index2+1]=='*'){
            while(index1<s.size() && (p[index2]=='.' || p[index2]==s[index1])){
                if(Match(s,index1,p,index2+2))return true;
                index1++;
            }
            return Match(s,index1,p,index2+2);
        }else if(index1<s.size() && (p[index2]=='.' || p[index2]==s[index1])){
            return Match(s,index1+1,p,index2+1);
        }
        return false;
    }
};
