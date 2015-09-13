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
    int strStr(string haystack, string needle) {
        int len1=haystack.size(),len2=needle.size();
        int* next=(int*)malloc(sizeof(int)*(len2+1));
        getNext(needle,next,len2);
        int i=0,j=0;
        while(i<len1 && j<len2){
            if(j==-1 || haystack[i]==needle[j]){
                i++;j++;
            }else{
                j=next[j];
            }
        }
        if(j<len2)return -1;
        else return i-len2;
    }
private:
    void getNext(string needle,int* next,int len1){
        int i=0,j=-1;
        next[0]=-1;
        while(i<len1){
            if(j==-1 || needle[i]==needle[j]){
                j++;i++;
                next[i]=j;
            }else{
                j=next[j];
            }
        }
    }
};
