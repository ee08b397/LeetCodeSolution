/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 17ms
 */
class Solution {
public:
    int myAtoi(string str) {
        int index=0;
        while(str[index]==' ')index++;
        int flag=1;
        if(str[index]=='-'){
            index++;
            flag=-1;
        }else if(str[index]=='+'){
            index++;
        }
        int res=0;
        while(index<str.size()){
            if(str[index]<'0' || str[index]>'9'){
                return flag*res;
            }
            int digit=str[index]-'0';
            if(flag==1 && res*10.0+digit>INT_MAX){
                return INT_MAX;
            }else if(flag==-1 && -(res*10.0+digit)<INT_MIN){
                return INT_MIN;
            }
            res = res*10+digit;
            index++;
        }
        return flag*res;
    }
};
