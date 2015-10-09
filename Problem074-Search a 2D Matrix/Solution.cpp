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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=row==0?0:matrix[0].size();
        int start=0,end=row*col-1;
        while(start < end){
            int mid=start+(end-start)/2;
            int i=mid/col;
            int j=mid%col;
            if(target==matrix[i][j])return true;
            else if(target>matrix[i][j])start=mid+1;
            else end=mid-1;
        }
        int i=start/col;
        int j=start%col;
        return target==matrix[i][j];
    }
};
