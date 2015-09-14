/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 316ms
 */
public class Solution {
    public String multiply(String num1, String num2) {
        int len1=num1.length(),len2=num2.length();
        int[] mul = new int[len1+len2+1];
        int i,j;
        for(i=len1-1;i>=0;i--){
            for(j=len2-1;j>=0;j--){
                mul[(len1-1-i)+(len2-1-j)] += (num1.charAt(i)-'0')*(num2.charAt(j)-'0');
            }
        }
        for(i=0;i<len1+len2;i++){
            mul[i+1] += mul[i]/10;
            mul[i] = mul[i]%10;
        }
        i=len1+len2-1;
        while(i>=0 && mul[i] ==0)i--;
        if(i==-1){
            return "0";
        }
        char[] multi = new char[i+1];
        for(j=0;j<=i;j++){
            multi[i-j] = (char)(mul[j] + '0');
        }
        return new String(multi);
    }
}