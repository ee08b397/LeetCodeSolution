/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 448ms
 */
public class Solution {
    public String addBinary(String a, String b) {
        char[] str1 = a.toCharArray();
        char[] str2 = b.toCharArray();
        int len1=a.length(),len2=b.length(),top=0;
        int len = Math.max(len1,len2)+2;
        int[] str = new int[len];
        int i,j;
        for(i=0;i<len;i++)str[i]=0;
        i=len1-1;j=len2-1;
        while(true){
            if(i<0 && j<0)break;
            else if(i<0)str[top++]+=(int)(str2[j--]-'0');
            else if(j<0)str[top++]+=(int)(str1[i--]-'0');
            else str[top++]+=(int)(str2[j--]-'0')+(int)(str1[i--]-'0');
        }
        for(i=0;i<len-1;i++){
            str[i+1]+=str[i]/2;
            str[i]%=2;
        }
        i--;
        while(i>0 && str[i]==0)i--;
        top=i+1;j=i;i=0;
        while(i<j){
            int tmp = str[i];
            str[i]=str[j];
            str[j]=tmp;
            i++;j--;
        }
        char[] s = new char[top];
        for(i=0;i<top;i++)s[i]=(char)(str[i]+'0');
        return new String(s);
    }
}