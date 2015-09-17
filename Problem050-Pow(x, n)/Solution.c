/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 8ms
 */
double myPow(double x, int n) {
    double tmp=x,res=1.0;
    int flag=0;
    if(n < 0){
        flag = 1;
        n = -n;
    }else if(n == 0)return 1.0;
    while(n>0){
        if(n%2 == 1){
            res*=tmp;
        }
        n/=2;
        tmp*=tmp;
    }
    if(flag == 1)return 1.0/res;
    return res;
}
