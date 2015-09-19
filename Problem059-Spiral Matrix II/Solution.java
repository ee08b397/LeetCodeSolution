/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 228ms
 */
public class Solution {
    public int[][] generateMatrix(int n) {
        int[][] returnColumn = new int[n][n];
        int i=0,x=0,y=-1,xmin=0,xmax=n-1,ymin=0,ymax=n-1;
        while(true){
            while(y+1 <= ymax)returnColumn[x][++y] = ++i;
            if(++xmin > xmax)break;
            while(x+1 <= xmax)returnColumn[++x][y] = ++i;
            if(--ymax < ymin)break;
            while(y-1 >= ymin)returnColumn[x][--y] = ++i;
            if(--xmax < xmin)break;
            while(x-1 >= xmin)returnColumn[--x][y] = ++i;
            if(++ymin > ymax)break;
        }
        return returnColumn;
    }
}