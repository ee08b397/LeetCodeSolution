/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 16ms
 */
int RomanDigit(char* roman,int digit,char a,char b,char c){
    switch(digit){
        case 1:roman[0]=a;return 1;
        case 2:roman[0]=a;roman[1]=a;return 2;
        case 3:roman[0]=a;roman[1]=a;roman[2]=a;return 3;
        case 4:roman[0]=a;roman[1]=b;return 2;
        case 5:roman[0]=b;return 1;
        case 6:roman[0]=b;roman[1]=a;return 2;
        case 7:roman[0]=b;roman[1]=a;roman[2]=a;return 3;
        case 8:roman[0]=b;roman[1]=a;roman[2]=a;roman[3]=a;return 4;
        case 9:roman[0]=a;roman[1]=c;return 2;
    }
    return 0;
}
char* intToRoman(int num) {
    //char digit[9][5]={I,II,III,IV,V,VI,VII,VIII,IX};
    //char tensdig[9][5]={X,XX,XXX,XL,L,LX,LXX,LXXX,XC};
    //char hunsdig[9][5]={C,CC,CCC,CD,D,DC,DCC,DCCC,CM};
    //char thodig[3][3]={M,MM,MMM};
    char* roman=(char*)malloc(sizeof(char)*16);
    int index=0;
    if(num/1000!=0){
        index+=RomanDigit(roman+index,num/1000,'M','#','#');
        num%=1000;
    }
    if(num/100!=0){
        index+=RomanDigit(roman+index,num/100,'C','D','M');
        num%=100;
    }
    if(num/10!=0){
        index+=RomanDigit(roman+index,num/10,'X','L','C');
        num%=10;
    }
    if(num!=0){
        index+=RomanDigit(roman+index,num,'I','V','X');
    }
    roman[index]=0;
    return roman;
}
