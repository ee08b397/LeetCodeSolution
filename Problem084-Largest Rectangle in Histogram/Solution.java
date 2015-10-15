/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 27ms
 */
public class Solution {
    public int largestRectangleArea(int[] height) {
        Stack<Integer> stack = new Stack<Integer>();
        int i,max=0;
        for(i=0;i<height.length;i++){
            while(!stack.empty() && height[stack.peek()]>height[i]){
                int index = stack.pop();
                int area = (stack.empty()?i:i-stack.peek()-1)*height[index];
                max = max>area?max:area;
            }
            stack.push(i);
        }
        while(!stack.empty()){
            int index = stack.pop();
            int area = (stack.empty()?i:i-stack.peek()-1)*height[index];
            max = max>area?max:area;
        }
        return max;
    }
}