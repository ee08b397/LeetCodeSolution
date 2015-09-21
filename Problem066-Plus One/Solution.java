/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 348ms
 */
public class Solution {
    public int[] plusOne(int[] digits) {
        int len = digits.length;
        digits[len-1]++;
        for(int i=len-1;i>0;i--){
            if(digits[i]>9){
                digits[i-1]+=digits[i]/10;
                digits[i]%=10;
            }
        }
        if(digits[0]>9){
            int[] newDigits = new int[len+1];
            newDigits[0] = digits[0]/10;
            newDigits[1] = digits[0]%10;
            for(int i=2;i<len+1;i++){
                newDigits[i] = digits[i-1];
            }
            return newDigits;
        }
        return digits;
    }
}