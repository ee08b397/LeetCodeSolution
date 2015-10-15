/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 8ms
 */
int largestRectangleArea(int* height, int heightSize) {
    int* stack = (int*)malloc(sizeof(int)*heightSize);
    int i,top=0,max=0,area;
    for(i=0;i<heightSize;i++){
        while(top>0 && height[stack[top-1]]>height[i]){
            area = (top==1?i:(i-stack[top-2]-1))*height[stack[top-1]];
            max=max>area?max:area;
            top-=1;
        }
        stack[top++]=i;
    }
    while(top>0){
        area = (top==1?i:(i-stack[top-2]-1))*height[stack[top-1]];
        max=max>area?max:area;
        top-=1;
    }
    return max;
}
