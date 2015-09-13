/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 7ms
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int max=0,top=0,len=s.size();
        int* pos_stack=(int*)malloc(sizeof(int)*len);
        char* str_stack=(char*)malloc(sizeof(char)*len);
        for(int i=0;i<len;i++){
            if(s[i]=='('){
                str_stack[top]='(';
                pos_stack[top]=i;
                top++;
            }else{
                if(str_stack[top-1]=='('){
                    int tmp;
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
};
