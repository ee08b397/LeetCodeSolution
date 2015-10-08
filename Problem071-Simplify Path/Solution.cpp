/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 8ms
 */
class Solution {
public:
    string simplifyPath(string path) {
        char* newpath = (char*)malloc(sizeof(char)*100000);
        int i=0,top=0;
        while(i<path.size()){
            while(i<path.size() && path[i]=='/')i++;
            if(i>=path.size())break;
            if(path[i]=='.' && (i+1>=path.size() || path[i+1]=='/')){
                i++;
            }else if(path[i]=='.' && path[i+1]=='.' && (i+2>=path.size() || path[i+2]=='/')){
                i+=2;
                top=top>0?top-1:0;
                while(top>0 && newpath[top]!='/')top--;
            }else{
                newpath[top++]='/';
                while(i<path.size() && path[i]!='/')newpath[top++]=path[i++];
            }
        }
        if(top==0)return "/";
        else{
            newpath[top]=0;
            return string(newpath);
        }
    }
};
