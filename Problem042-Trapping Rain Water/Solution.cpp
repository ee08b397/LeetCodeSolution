/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 12ms
 */
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int leftmax,rightmax=0,sum;
        st.push(-1);
        for(int i=height.size()-1;i>=0;i--){
            if(rightmax < height[i]){
                st.push(i);
                rightmax = height[i];
            }
        }
        leftmax=0;sum=0;
        for(int i=0;i<height.size();i++){
            if(i == st.top())st.pop();
            if(st.top() == -1)rightmax=0;
            else rightmax = height[st.top()];
            if(height[i]<leftmax && height[i]<rightmax){
                sum+=(leftmax > rightmax ? rightmax : leftmax)-height[i];
            }
            leftmax = leftmax < height[i] ? height[i] : leftmax;
        }
        return sum;
    }
};
