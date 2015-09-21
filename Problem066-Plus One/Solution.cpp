/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 4ms
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int i;
        digits[len-1]++;
        for(i=len-1;i>0;i--){
            if(digits[i]>9){
                digits[i-1] += digits[i]/10;
                digits[i]=digits[i]%10;
            }
        }
        if(digits[0]>9){
            vector<int> newDigits(len+1);
            newDigits[0] = digits[0]/10;
            newDigits[1] = digits[0]%10;
            for(i=2;i<len+1;i++){
                newDigits[i] = digits[i-1];
            }
            return newDigits;
        }
        return digits;
    }
};
