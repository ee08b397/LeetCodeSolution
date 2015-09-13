/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 3ms
 */
int longestValidParentheses(char* s) {
    int len=strlen(s),max=0,top=0,i,tmp;
    int* pos_stack=(int*)malloc(sizeof(int)*len);
    char* str_stack=(char*)malloc(sizeof(char)*len);
    for(i=0;s[i];i++){
        if(s[i]=='('){
            str_stack[top]='(';
            pos_stack[top]=i;
            top++;
        }else{
            if(str_stack[top-1]=='('){
                top--;
                if(top==0)tmp=i+1;
                else tmp=i-pos_stack[top-1];
                max=max>tmp?max:tmp;
            }else{
                str_stack[top]=')';
                pos_stack[top]=i;
                top++;
            }
        }
    }
    return max;
}
