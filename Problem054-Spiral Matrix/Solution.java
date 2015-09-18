/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 252ms
 */
public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<Integer>();
        if(matrix.length==0 || matrix[0].length==0)return res;
        int x=0,y=-1,xmin=0,xmax=matrix.length-1,ymin=0,ymax=matrix[0].length-1;
        while(true){
            while(y+1 <= ymax)res.add(matrix[x][++y]);
            if(++xmin > xmax)break;
            while(x+1 <= xmax)res.add(matrix[++x][y]);
            if(--ymax < ymin)break;
            while(y-1 >= ymin)res.add(matrix[x][--y]);
            if(--xmax < xmin)break;
            while(x-1 >= xmin)res.add(matrix[--x][y]);
            if(++ymin > ymax)break;
        }
        return res;
    }
}