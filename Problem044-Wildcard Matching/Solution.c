/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 8ms
 */
bool isMatch(char* s, char* p) {
    char* p_pos=NULL,*s_pos=NULL;
    while(*s){
        if(*p == *s || *p == '?'){
            p++;
            s++;
            continue;
        }
        if(*p=='*'){
            p_pos = p+1;
            s_pos = s;
            p++;
            continue;
        }
        if(s_pos != NULL){
            s_pos++;
            s = s_pos;
            p = p_pos;
            continue;
        }
        return false;
    }
    while(*p && *p == '*')p++;
    return !*p;
}
