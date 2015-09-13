/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 294ms
 */

public class Solution {
    public String longestPalindrome(String s) {
        int Max=1,Maxf=0,Maxe=0;
        for(int i=0;i<s.length();i++){
            int end = findOdd(s,i);
            if(Max < (end-i)*2+1){
                Max = (end-i)*2+1;
                Maxf = i+i-end;
                Maxe=end;
            }
            end = findEven(s,i);
            if(Max < (end-i)*2){
                Max = (end-i)*2;
                Maxf = i+i+1-end;
                Maxe = end;
            }
        }
        return s.substring(Maxf,Maxe+1);
    }
    public int findOdd(String s,int center){
        int i=center-1,j=center+1;
        while(i>=0 && j<s.length()){
            if(s.charAt(i)!=s.charAt(j))return j-1;
            i--;j++;
        }
        return j-1;
    }
    public int findEven(String s,int center){
        int i=center,j=center+1;
        while(i>=0 && j<s.length()){
            if(s.charAt(i)!=s.charAt(j))return j-1;
            i--;j++;
        }
        return j-1;
    }
}