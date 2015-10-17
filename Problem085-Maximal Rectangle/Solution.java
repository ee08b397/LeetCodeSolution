/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 42ms
 */
public class Solution {
    public int maximalRectangle(char[][] matrix) {
        int i,j,max=0;
        int row = matrix.length;
        int col = row==0?0:matrix[0].length;
        Stack<Integer> stack = new Stack<Integer>();
        int[] map = new int[col];
        for(i=0;i<col;i++)map[i]=0;
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(matrix[i][j]=='1')map[j]++;
                else map[j]=0;
                while(!stack.empty() && map[stack.peek()]>map[j]){
                    int index = stack.pop();
                    int area = (stack.empty()?j:j-stack.peek()-1)*map[index];
                    max = max>area?max:area;
                }
                stack.push(j);
            }
            while(!stack.empty()){
                int index = stack.pop();
                int area = (stack.empty()?j:j-stack.peek()-1)*map[index];
                max = max>area?max:area;
            }
        }
        return max;
    }
}