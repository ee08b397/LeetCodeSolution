/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 2ms
 */
class Solution {
public:
    bool isValid(string s) {
        int top=-1,index=0,length=s.size();
        char* stack=(char*)malloc(sizeof(char)*length);
        while(index<length){
            if(s[index]==')'){
                if(top>=0 && stack[top]=='(')top--;
                else return false;
            }else if(s[index]=='}'){
                if(top>=0 && stack[top]=='{')top--;
                else return false;
            }else if(s[index]==']'){
                if(top>=0 && stack[top]=='[')top--;
                else return false;
            }else stack[++top]=s[index];
            index++;
        }
        return top==-1;
    }
};
