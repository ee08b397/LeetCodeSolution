/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 305ms
 */
public class Solution {
    public String intToRoman(int num) {
        StringBuilder sb = new StringBuilder();
        if(num/1000!=0){
            RomanDigit(sb,num/1000,"M","#","#");
            num%=1000;
        }
        if(num/100!=0){
            RomanDigit(sb,num/100,"C","D","M");
            num%=100;
        }
        if(num/10!=0){
            RomanDigit(sb,num/10,"X","L","C");
            num%=10;
        }
        if(num!=0){
            RomanDigit(sb,num,"I","V","X");
        }
        return new String(sb);
    }
    private void RomanDigit(StringBuilder sb,int digit,String a,String b,String c){
        switch(digit){
            case 1:sb.append(a);return;
            case 2:sb.append(a+a);return;
            case 3:sb.append(a+a+a);return;
            case 4:sb.append(a+b);return;
            case 5:sb.append(b);return;
            case 6:sb.append(b+a);return;
            case 7:sb.append(b+a+a);return;
            case 8:sb.append(b+a+a+a);return;
            case 9:sb.append(a+c);return;
        }
        return;
    }
}