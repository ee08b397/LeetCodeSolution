/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 4ms
 */
int min(int a,int b){
    return a>b?b:a;
}
int trap(int* height, int heightSize) {
    int * stack = (int*)malloc(sizeof(int)*(heightSize+1));
    int i,max=0,rightmax,top=0,sum=0;
    stack[0]=-1;
    for(i=heightSize-1;i>=0;i--){
        if(max < height[i]){
            top++;
            stack[top] = i;
            max = height[i];
        }
    }
    max=0;
    for(i=0;i<heightSize;i++){
        if(stack[top] == i)top--;
        if(stack[top] == -1)rightmax = 0;
        else rightmax = height[stack[top]];
        if(height[i]<max && height[i]<rightmax){
            sum+=min(max,rightmax)-height[i];
        }
        max = max>height[i]?max:height[i];
    }
    return sum;
}
