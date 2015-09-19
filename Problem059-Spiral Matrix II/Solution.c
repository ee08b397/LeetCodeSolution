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
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
    int** returnColumn = (int**)malloc(sizeof(int*)*n);
    int i;
    for(i=0;i<n;i++){
        returnColumn[i] = (int*)malloc(sizeof(int)*n);
    }
    int x=0,y=-1,xmin=0,xmax=n-1,ymin=0,ymax=n-1;
    i=0;
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
