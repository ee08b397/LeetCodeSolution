/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 2ms
 */
void getNext(char *needle,int* next){
    int i=0,j=-1;
    next[0]=-1;
    while(needle[i]){
        if(j==-1 || needle[j]==needle[i]){
            j++;
            i++;
            next[i]=j;
        }else{
            j=next[j];
        }
    }
}
int strStr(char* haystack, char* needle) {
    int length=strlen(needle),i=0,j=0;
    int *next=(int*)malloc(sizeof(int)*(length+1));
    getNext(needle,next);
    while(j==-1 || (haystack[i] && needle[j])){
        if(j==-1 || haystack[i]==needle[j]){
            j++;i++;
        }else{
            j=next[j];
        }
    }
    if(needle[j])return -1;
    else return i-length;
}
