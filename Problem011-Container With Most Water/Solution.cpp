/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 30ms
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int Max=-1,l=0,r=height.size()-1,area,k;
        while(l<r){
            area=(height[l]<height[r]?height[l]:height[r])*(r-l);
            Max=Max<area?area:Max;
            if(height[l]<height[r]){
                k=l;
                while(l<r && height[l]<=height[k])l++;
            }else{
                k=r;
                while(l<r && height[r]<=height[k])r--;
            }
        }
        return Max;
    }
};
