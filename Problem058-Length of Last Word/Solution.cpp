/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 4ms
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        const char* str = s.data();
        int sum=0,length=0;
        for(int i=0;str[i];i++){
            if(str[i]==' '){
                if(sum!=0)length=sum;
                sum=0;
            }else{
                sum++;
            }
        }
        if(sum!=0)length = sum;
        return length;
    }
};
