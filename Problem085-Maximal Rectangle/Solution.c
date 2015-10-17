/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 4ms
 */
int maximalRectangle(char** matrix, int matrixRowSize, int matrixColSize) {
    int i,j,max=0,index,area,top=0;
    int* stack = malloc(sizeof(int)*matrixColSize);
    int* map = malloc(sizeof(int)*matrixColSize);
    for(i=0;i<matrixRowSize;i++){
        for(j=0;j<matrixColSize;j++){
            if(matrix[i][j]=='1'){
                if(i==0)map[j]=1;
                else map[j]+=1;
            }else{
                map[j]=0;
            }
            while(top>0 && map[stack[top-1]]>map[j]){
                index=stack[top-1];
                top-=1;
                area=(top==0?j:j-stack[top-1]-1)*map[index];
                max=max>area?max:area;
            }
            stack[top++]=j;
        }
        while(top>0){
            index=stack[top-1];
            top-=1;
            area=(top==0?j:j-stack[top-1]-1)*map[index];
            max=max>area?max:area;
        }
    }
    return max;
}
