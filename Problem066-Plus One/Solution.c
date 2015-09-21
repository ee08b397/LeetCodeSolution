/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 0ms
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i=digitsSize-1;
    int* newDigits;
    digits[i]+=1;
    while(i>0){
        if(digits[i]>9){
            digits[i-1]+=digits[i]/10;
            digits[i]%=10;
        }
        i--;
    }
    if(digits[0]>9){
        *returnSize=digitsSize+1;
        newDigits = (int*)malloc(sizeof(int)*(digitsSize+1));
        newDigits[0]=digits[0]/10;
        newDigits[1]=digits[0]%10;
        for(i=2;i<digitsSize+1;i++){
            newDigits[i] = digits[i-1];
        }
        return newDigits;
    }
    *returnSize=digitsSize;
    return digits;
}
