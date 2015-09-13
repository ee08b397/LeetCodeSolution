/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 122ms
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        char str[11];
        int index=0;
        while(x>0){
            str[index++]=x%10;
            x/=10;
        }
        int i=0,j=index-1;
        while(i<j){
            if(str[i]!=str[j])return false;
            i++;j--;
        }
        return true;
    }
};
