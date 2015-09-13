/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 1ms
 */
bool isValid(char* s) {
    char stack[1000000];
    int top=-1;
    while(*s){
        if(*s==')'){
            if(top>=0 && stack[top]=='(')top--;
            else return false;
        }else if(*s=='}'){
            if(top>=0 && stack[top]=='{')top--;
            else return false;
        }else if(*s==']'){
            if(top>=0 && stack[top]=='[')top--;
            else return false;
        }else stack[++top]=*s;
        s++;
    }
    return top==-1;
}
