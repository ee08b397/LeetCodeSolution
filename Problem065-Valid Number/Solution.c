/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 12ms
 */
bool testE(char* s);
bool testDot(char* s,bool ass){
    int i;
    for(i=0;s[i];i++){
        if(s[i]==' '){
            while(s[i] && s[i]==' ')i++;
            return s[i]=='\0' && ass;
        }else if(s[i]=='e'){
            return testE(s+i+1) && ass;
        }else if(!(s[i]>='0' && s[i]<='9')){
            return false;
        }else{
            ass=true;
        }
    }
    return ass;
}
bool testE(char* s){
    int i;
    bool ass=false;
    for(i=0;s[i];i++){
        if(s[i]=='+' || s[i]=='-'){
            if(i!=0)return false;
        }else if(s[i]==' '){
            while(s[i] && s[i]==' ')i++;
            return s[i]=='\0' && ass;
        }else if(!(s[i]>='0' && s[i]<='9')){
            return false;
        }else{
            ass=true;
        }
    }
    return ass;
}
bool isNumber(char* s) {
    int i=0,j;
    bool ass=false;
    while(s[i] && s[i]==' ')i++;
    j=i;
    for(;s[i];i++){
        if(s[i]=='-' || s[i]=='+'){
            if(i!=j) return false;
        }else if(s[i]=='.'){
            return testDot(s+i+1,ass);
        }else if(s[i]=='e'){
            if(i==j)return false;
            return testE(s+i+1) && ass;
        }else if(s[i]==' '){
            while(s[i] && s[i]==' ')i++;
            return s[i]==0 && ass;
        }else if(!(s[i]>='0' && s[i]<='9')){
            return false;
        }else{
            ass=true;
        }
    }
    return ass;
}
