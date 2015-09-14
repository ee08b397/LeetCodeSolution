/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 332ms
 */
public class Solution {
    public int trap(int[] height) {
        Stack<Integer> st = new Stack<Integer>();
        st.push(-1);
        int rightmax=0;
        for(int i=height.length-1;i>=0;i--){
            if(rightmax < height[i]){
                st.push(i);
                rightmax = height[i];
            }
        }
        int leftmax=0,sum=0;
        for(int i=0;i<height.length;i++){
            if(i==st.peek())st.pop();
            if(st.peek() == -1)rightmax = 0;
            else rightmax = height[st.peek()];
            if(height[i]<leftmax && height[i]<rightmax){
                sum+=Math.min(leftmax,rightmax) - height[i];
            }
            leftmax = Math.max(leftmax,height[i]);
        }
        return sum;
    }
}