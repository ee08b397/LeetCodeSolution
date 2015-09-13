/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 21ms
 */
bool isMatch(char* s, char* p) {
    if(s==NULL || p==NULL)return false;
    if(!*p) return !*s;
    if(*(p+1)=='*'){
        while((*p==*s)||(*s && *p=='.')){
            if(isMatch(s,p+2))return true;
            s++;
        }
        return isMatch(s,p+2);
    }else if((*p==*s)||(*s && *p=='.')){
        return isMatch(s+1,p+1);
    }
    return false;
}
