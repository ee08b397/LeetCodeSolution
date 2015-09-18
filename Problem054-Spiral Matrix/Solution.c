/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 0ms
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int* res = (int*)malloc(sizeof(int)*(matrixRowSize*matrixColSize));
    int x=0,y=-1,top=0,xmin=0,xmax=matrixRowSize-1,ymin=0,ymax=matrixColSize-1;
    while(true){
        while(y+1 <= ymax){
            y++;
            res[top++] = matrix[x][y];
        }
        if(++xmin > xmax)break;
        while(x+1 <= xmax){
            x++;
            res[top++] = matrix[x][y];
        }
        if(--ymax < ymin)break;
        while(y-1 >= ymin){
            y--;
            res[top++] = matrix[x][y];
        }
        if(--xmax < xmin)break;
        while(x-1 >= xmin){
            x--;
            res[top++] = matrix[x][y];
        }
        if(++ymin > ymax)break;
    }
    return res;
}
