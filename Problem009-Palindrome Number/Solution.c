/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 53ms
 */
bool isPalindrome(int x) {
    int i,j,index=0;
    char str[12];
    if(x<0)return false;
    while(x>0){
        str[index++]=x%10+'0';
        x=x/10;
    }
    i=0;j=index-1;
    while(i<j){
        if(str[i]!=str[j])return false;
        i++;j--;
    }
    return true;
}
