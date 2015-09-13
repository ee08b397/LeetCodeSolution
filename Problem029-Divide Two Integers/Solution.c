/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 4ms
 */
long long ABS(long long a){
    return a>0?a:-a;
}
int divide(int dividend, int divisor) {
    int i=0,j,flag=0;
    long long sum=0,a,b,map[33],times[33],STOP=1;
    STOP=((long long)2147483647)+1;
    if(divisor==0)return INT_MAX;
    if(dividend==0)return 0;
    if((dividend>0 && divisor>0) || (dividend<0 && divisor<0))flag=1;
    a=ABS((long long)dividend);
    b=ABS((long long)divisor);
    map[0]=b;times[0]=1;
    while(map[i] <= a && i<33){
        i++;
        map[i]=map[i-1]+map[i-1];
        times[i]=times[i-1]+times[i-1];
    }
    for(j=i-1;j>=0;j--){
        while(a >= map[j]){
            a-=map[j];
            sum+=times[j];
        }
    }
    sum=flag?sum:-sum;
    if(sum<INT_MIN || sum > INT_MAX)return INT_MAX;
    return (int)sum;
}
