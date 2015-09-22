/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 0ms
 */
char* addBinary(char* a, char* b) {
    int i=0,len1,len2,j,top=0;
    char tmp;
    while(a[i])i++;
    len1=i;i=0;
    while(b[i])i++;
    len2=i;
    int len = (len1>len2?len1:len2) +2;
    char* str = (char*)malloc(sizeof(char)*len);
    for(i=0;i<len;i++)str[i]=0;
    i=len1-1;j=len2-1;
    while(true){
        if(i<0 && j<0)break;
        else if(i<0){
            str[top++]+= b[j--]-'0';
        }else if(j<0){
            str[top++]+= a[i--]-'0';
        }else{
            str[top++]+= a[i]-'0' + b[j] -'0';
            i--;j--;
        }
    }
    for(i=0;i<len;i++){
        str[i+1] += str[i]/2;
        str[i]%=2;
        str[i]+='0';
    }
	i--;
    while(i>=0 && str[i]=='0')i--;
    if(i<0){
        str[0]='0';
        str[1]=0;
        return str;
    }
    j=i;
	str[i+1]=0;
    i=0;
    while(i<j){
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;j--;
    }
    return str;
}
