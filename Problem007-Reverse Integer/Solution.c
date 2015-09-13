/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 10ms
 */
int reverse(int x) {
    int flag=x>0?1:-1,res=0;
    x=x>0?x:-x;
    while(x>0){
        if((2147483647.0-x%10)/10<res)return 0;
        res=res*10+x%10;
        x=x/10;
    }
    return res*flag;
}
