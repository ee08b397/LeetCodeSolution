/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 4ms
 */
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int start=0,end=matrixRowSize*matrixColSize-1;
    int i,j,mid;
    while(start < end){
        mid = start+(end-start)/2;
        i=mid/matrixColSize;
        j=mid%matrixColSize;
        if(matrix[i][j]==target)return true;
        else if(matrix[i][j]>target)end=mid-1;
        else start=mid+1;
    }
    i=start/matrixColSize;
    j=start%matrixColSize;
    return target==matrix[i][j];
}
