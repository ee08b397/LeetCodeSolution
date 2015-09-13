/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 302ms
 */
public class Solution {
    public boolean isMatch(String s, String p) {
        char[] chs = s.toCharArray();
        char[] chp = p.toCharArray();
        return Match(chs,0,chp,0);
    }
    public boolean Match(char[] chs,int index1,char[] chp,int index2){
        if(index2>=chp.length)return index1>=chs.length;
        if(index2+1<chp.length && chp[index2+1]=='*'){
            while(index1<chs.length && (chp[index2]=='.' || chp[index2]==chs[index1])){
                if(Match(chs,index1,chp,index2+2))return true;
                index1++;
            }
            return Match(chs,index1,chp,index2+2);
        }else if(index1<chs.length && (chp[index2]=='.' || chs[index1]==chp[index2])){
            return Match(chs,index1+1,chp,index2+1);
        }
        return false;
    }
}