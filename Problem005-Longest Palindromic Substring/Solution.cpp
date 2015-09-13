/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 95ms
 */

class Solution {
public:
    string longestPalindrome(string s) {
        int Max=1,Maxf=0,Maxe=0;
        for(int i=0;i<s.size();i++){
            int end = findOdd(s,i);
            if(Max < (end-i)*2+1){
                Max = (end-i)*2+1;
                Maxf=i+i-end;
                Maxe=end;
            }
            end = findEven(s,i);
            if(Max <(end-i)*2){
                Max = (end-i)*2;
                Maxf=i+i+1-end;
                Maxe=end;
            }
        }
        return s.substr(Maxf,Max);
    }
    int findOdd(string s,int center){
        int i=center-1,j=center+1;
        while(i>=0 && j<s.size()){
            if(s[i]!=s[j])return j-1;
            i--;j++;
        }
        return j-1;
    }
    int findEven(string s,int center){
        int i=center,j=center+1;
        while(i>=0 && j<s.size()){
            if(s[i]!=s[j])return j-1;
            i--;j++;
        }
        return j-1;
    }
};
