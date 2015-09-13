/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 8ms
 */

#include<limits.h>
#include<stdio.h>
int lengthOfLongestSubstring(char* s) {
    int i,j,left=0,Max=0,hash[256];
    for(j=0;j<256;j++)hash[j]=INT_MAX;
    for(i=0;s[i];i++){
        if(hash[s[i]]!=INT_MAX && hash[s[i]]>=left)
            left=hash[s[i]]+1;
        hash[s[i]]=i;
        Max = Max>(i-left+1)?Max:(i-left+1);
    }
    return Max;
}
