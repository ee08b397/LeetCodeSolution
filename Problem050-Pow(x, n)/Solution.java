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
    public double myPow(double x, int n) {
        double tmp = x,res = 1.0;
        boolean flag = false;
        if(n < 0){
            flag = true;
            n = -n;
        }
        while(n > 0){
            if(n%2 ==1){
                res*=tmp;
            }
            tmp*=tmp;
            n/=2;
        }
        if(flag)return 1.0/res;
        return res;
    }
}