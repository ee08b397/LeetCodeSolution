/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 8ms
 */
int mySqrt(int x) {
    int left=0,right=46340 > x? x:46340,mid;
    while(left < right){
        mid = left + (right-left)/2;
        if(mid*mid == x)return mid;
        else if(mid*mid > x){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return left*left > x ? left-1 : left;
}
