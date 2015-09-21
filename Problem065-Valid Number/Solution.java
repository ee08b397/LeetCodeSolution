/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 292ms
 */
public class Solution {
    public boolean isNumber(String s) {
        char[] str = s.toCharArray();
        int len=s.length();
        int i=0;
        while(i<len && str[i]==' ')i++;
        int j=i;
        boolean ass=false;
        for(;i<len;i++){
            if(str[i]=='-' || str[i]=='+'){
                if(j!=i)return false;
            }else if(str[i]=='.'){
                return testDot(str,i+1,len,ass);
            }else if(str[i]=='e'){
                return testE(str,i+1,len) && ass;
            }else if(str[i]==' '){
                while(i<len && str[i]==' ')i++;
                return i>=len && ass;
            }else if(!(str[i]>='0' && str[i]<='9')){
                return false;
            }else{
                ass=true;
            }
        }
        return ass;
    }
    private boolean testDot(char[] str,int i,int len,boolean ass){
        for(;i<len;i++){
            if(str[i]=='e'){
                return testE(str,i+1,len) && ass;
            }else if(str[i]==' '){
                while(i<len && str[i]==' ')i++;
                return i>=len && ass;
            }else if(!(str[i]>='0' && str[i]<='9')){
                return false;
            }else{
                ass=true;
            }
        }
        return ass;
    }
    private boolean testE(char[] str,int i,int len){
        int j=i;
        boolean ass=false;
        for(;i<len;i++){
            if(str[i]=='-' || str[i]=='+'){
                if(i!=j)return false;
            }else if(str[i]==' '){
                while(i<len && str[i]==' ')i++;
                return i>=len && ass;
            }else if(!(str[i]>='0' && str[i]<='9')){
                return false;
            }else{
                ass=true;
            }
        }
        return ass;
    }
}