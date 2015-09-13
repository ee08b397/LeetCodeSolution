/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 5ms
 */
int myAtoi(char* str) {
    int flag=1,res=0,dig;
    while(*str==' ')str++;
    if(*str=='-'){
        flag=-1;
        str++;
    }else if(*str=='+'){
        str++;
    }
    while(*str){
        if(*str<'0' || *str>'9'){
            return flag*res;
        }
        dig=*str-'0';
        if(flag==1 && res*10.0+dig>INT_MAX){
            return INT_MAX;
        }else if(flag==-1 && -res*10.0-dig<INT_MIN){
            return INT_MIN;
        }
        res= res*10+dig;
        str++;
    }
    return flag*res;
}
