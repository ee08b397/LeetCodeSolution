/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 4ms
 */
public class Solution {
    public String simplifyPath(String path) {
        char[] newpath = new char[path.length()];
        char[] oldpath = path.toCharArray();
        int top=0,i=0;
        while(i<path.length()){
            while(i<path.length() && oldpath[i]=='/')i++;
            if(i>=path.length())break;
            if(oldpath[i]=='.' && (i+1>=path.length() || oldpath[i+1]=='/')){
                i++;
            }else if(oldpath[i]=='.' && oldpath[i+1]=='.' &&(i+2>=path.length() || oldpath[i+2]=='/')){
                i+=2;
                top=top>0?top-1:0;
                while(top>0 && newpath[top]!='/')top--;
            }else{
                newpath[top++]='/';
                while(i<path.length() && oldpath[i]!='/')newpath[top++]=oldpath[i++];
            }
        }
        if(top==0)return "/";
        else{
            return new String(newpath,0,top);
        }
    }
}