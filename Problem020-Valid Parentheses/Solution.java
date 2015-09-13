/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 251ms
 */
public class Solution {
    public boolean isValid(String s) {
        int length=s.length(),top=-1,index=0;
        char[] stack=new char[length];
        char[] str=s.toCharArray();
        while(index<length){
            if(str[index]==')'){
                if(top>=0 && stack[top]=='(')top--;
                else return false;
            }else if(str[index]=='}'){
                if(top>=0 && stack[top]=='{')top--;
                else return false;
            }else if(str[index]==']'){
                if(top>=0 && stack[top]=='[')top--;
                else return false;
            }else stack[++top]=str[index];
            index++;
        }
        return top==-1;
    }
}