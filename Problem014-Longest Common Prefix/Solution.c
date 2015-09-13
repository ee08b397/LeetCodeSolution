/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 6ms
 */
char* longestCommonPrefix(char** strs, int strsSize) {
    char* str=strs[0];
    int i,j;
    if(strsSize==0)return "";
    for(i=1;i<strsSize;i++){
        j=0;
        while(str[j] && strs[i][j] && str[j]==strs[i][j])j++;
        str[j]=0;
    }
    return str;
}
