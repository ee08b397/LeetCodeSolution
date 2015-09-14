/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 4ms
 */
char* multiply(char* num1, char* num2) {
    int len1=0,len2=0,i,j;
    for(i=0;num1[i];i++){
        len1++;
    }//获得字符串长度
    for(i=0;num2[i];i++){
        len2++;
    }
    int* mul = (int*)malloc(sizeof(int)*(len1+len2));
    for(i=0;i<len1+len2;i++)mul[i]=0;
    for(i=len1-1;i>=0;i--){
        for(j=len2-1;j>=0;j--){
            mul[(len1-1-i)+(len2-1-j)] += (num1[i]-'0')*(num2[j]-'0');
        }
    }
    for(i=0;i<len1+len2;i++){
        mul[i+1] += mul[i]/10;
        mul[i] = mul[i]%10;
    }
    i=len1+len2-1;
    while(i>=0 && mul[i]==0)i--;
    char* multip = (char*)malloc(sizeof(char)*(i+2));
    if(i==-1){
        multip[0]='0';
        multip[1]=0;
        return multip;
    }
    for(j=0;j<=i;j++){
        multip[i-j] = mul[j]+'0';
    }
    multip[j]=0;
    return multip;
}
