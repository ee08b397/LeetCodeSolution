/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 4ms
 */
char* simplifyPath(char* path) {
    int top=0,i=0;
    char* dic = (char*)malloc(sizeof(char)*100000);
    while(path[i]!='\0'){
        while(path[i] && path[i]=='/')i++;
        if(path[i]=='\0')break;
        if(path[i]=='.'){
            if(path[i+1]=='/' || path[i+1]=='\0')i++;
            else if(path[i+1]=='.' && (path[i+2]=='/'|| path[i+2]=='\0')){
                i+=2;
                top=top>0?top-1:0;
                while(top>0 && dic[top]!='/')top--;
            }else{
                dic[top++]='/';
                while(path[i] && path[i]!='/')dic[top++] = path[i++];
            }
        }else{
            dic[top++]='/';
            while(path[i] && path[i]!='/')dic[top++] = path[i++];
        }
    }
    if(top==0){
        dic[0]='/';
        dic[1]=0;
    }else{
        dic[top]=0;
    }
    return dic;
}
