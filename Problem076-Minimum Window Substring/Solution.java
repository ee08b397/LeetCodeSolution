/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 5ms
 */
public class Solution {
    public String minWindow(String s, String t) {
        int[] hash=new int[128];
        int[] hash1=new int[128];
        int[] hash2=new int[128];
        int i,start=0,end,minstart=0,minend=2147483647;
        for(i=0;i<128;i++){
            hash[i]=-1;
            hash1[i]=0;
            hash2[i]=0;
        }
        char[] tc = t.toCharArray();
        for(i=0;i<tc.length;i++){
            int k = (int)tc[i];
            hash[k]=0;
            hash1[k]++;
            hash2[k]++;
        }
        int len = tc.length;
        char[] sc = s.toCharArray();
        for(i=0;i<sc.length;i++){
            int k = (int)sc[i];
            if(hash[k]!=-1){
                if(hash1[k]>0){
                    hash1[k]--;
                    len--;
                }
                hash[k]++;
                k=(int)sc[start];
                while(hash[k] > hash2[k] || hash[k]==-1){
                    if(hash[k]>hash2[k])hash[k]--;
                    start++;
                    k=(int)sc[start];
                }
                if(len==0){
                    end=i;
                    if(minend-minstart > end-start){
                        minstart=start;
                        minend=end;
                    }
                }
            }
        }
        if(minend==2147483647)return "";
        return s.substring(minstart,minend+1);
    }
}