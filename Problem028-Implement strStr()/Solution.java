/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 323ms
 */
public class Solution {
    public int strStr(String haystack, String needle) {
        char[] chs1=haystack.toCharArray();
        char[] chs2=needle.toCharArray();
        int len1=chs1.length,len2=chs2.length;
        int[] next=new int[len2+1];
        getNext(chs2,next,len2);
        int i=0,j=0;
        while(i<len1 && j<len2){
            if(j==-1 || chs1[i]==chs2[j]){
                i++;j++;
            }else{
                j=next[j];
            }
        }
        if(j<len2)return -1;
        return i-len2;
    }
    private void getNext(char[] chs,int[] next,int len){
        int i=0,j=-1;
        next[0]=-1;
        while(i<len){
            if(j==-1 || chs[i]==chs[j]){
                i++;j++;
                next[i]=j;
            }else{
                j=next[j];
            }
        }
    }
}