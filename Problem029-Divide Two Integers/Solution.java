/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 260ms
 */
public class Solution {
    public int divide(int dividend, int divisor) {
        long a,b,flag=0,sum=0;
        long[] map=new long[33],times=new long[33];
        if(dividend<0 && divisor<0)flag=1;
        else if(dividend>0 && divisor>0)flag=1;
        a=Math.abs((long)dividend);
        b=Math.abs((long)divisor);
        int i=0;
        map[0]=b;times[0]=1;
        while(map[i]<=a){
            i++;
            map[i]=map[i-1]+map[i-1];
            times[i]=times[i-1]+times[i-1];
        }
        for(int j=i-1;j>=0;j--){
            while(a >= map[j]){
                a-=map[j];
                sum+=times[j];
            }
        }
        sum=flag==1?sum:-sum;
        if(sum>Integer.MAX_VALUE || sum<Integer.MIN_VALUE)return Integer.MAX_VALUE;
        return (int)sum;
    }
}