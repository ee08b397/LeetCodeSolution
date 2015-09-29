/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 0ms
 */
class Solution {
public:
    int climbStairs(int n) {
        vector<int> a(50);
        a[0]=0;a[1]=1;
        for(int i=2;i<=n+1;i++){
            a[i]=a[i-1]+a[i-2];
        }
        return a[n+1];
    }
};
