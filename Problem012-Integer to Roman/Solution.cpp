/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 50ms
 */
class Solution {
public:
    string intToRoman(int num) {
        char* roman=(char*)malloc(sizeof(char)*16);
        int index=0;
        if(num/1000){
            index+=RomanDigit(roman+index,num/1000,'M','#','#');
            num%=1000;
        }
        if(num/100){
            index+=RomanDigit(roman+index,num/100,'C','D','M');
            num%=100;
        }
        if(num/10){
            index+=RomanDigit(roman+index,num/10,'X','L','C');
            num%=10;
        }
        if(num){
            index+=RomanDigit(roman+index,num,'I','V','X');
        }
        roman[index]=0;
        return string(roman);
    }
private:
    int RomanDigit(char* s,int digit,char a,char b,char c){
        switch(digit){
            case 1:s[0]=a;return 1;
            case 2:s[0]=a;s[1]=a;return 2;
            case 3:s[0]=a;s[1]=a;s[2]=a;return 3;
            case 4:s[0]=a;s[1]=b;return 2;
            case 5:s[0]=b;return 1;
            case 6:s[0]=b;s[1]=a;return 2;
            case 7:s[0]=b;s[1]=a;s[2]=a;return 3;
            case 8:s[0]=b;s[1]=a;s[2]=a;s[3]=a;return 4;
            case 9:s[0]=a;s[1]=c;return 2;
        }
        return 0;
    }
};
