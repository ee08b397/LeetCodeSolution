/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 1ms
 */
public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int row=matrix.length;
        int col=row==0?0:matrix[0].length;
        int start=0,end=row*col-1;
        while(start <= end){
            int mid=start+(end-start)/2;
            int i=mid/col;
            int j=mid%col;
            if(target==matrix[i][j])return true;
            else if(target>matrix[i][j])start=mid+1;
            else end=mid-1;
        }
        return false;
    }
}