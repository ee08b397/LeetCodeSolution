/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 373ms
 */
public class Solution {
    public int maxArea(int[] height) {
        int Max=-1,l=0,r=height.length-1;
        while(l<r){
            int area=(height[l]<height[r]?height[l]:height[r])*(r-l);
            Max=Max<area?area:Max;
            if(height[l]<height[r]){
                int k=l;
                while(l<r && height[l]<=height[k])l++;
            }else{
                int k=r;
                while(l<r && height[r]<=height[k])r--;
            }
        }
        return Max;
    }
}