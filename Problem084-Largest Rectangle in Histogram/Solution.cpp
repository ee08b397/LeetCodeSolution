/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 24ms
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        stack<int> st;
        int max=0,i;
        for(i=0;i<height.size();i++){
            while(!st.empty() && height[st.top()]>height[i]){
                int index = st.top();
                st.pop();
                int area = (st.empty()?i:i-st.top()-1)*height[index];
                max=max>area?max:area;
            }
            st.push(i);
        }
        while(!st.empty()){
            int index = st.top();
            st.pop();
            int area = (st.empty()?i:i-st.top()-1)*height[index];
            max=max>area?max:area;
        }
        return max;
    }
};
