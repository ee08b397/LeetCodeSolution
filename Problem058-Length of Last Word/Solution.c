/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 0ms
 */
int lengthOfLastWord(char* s) {
    int i,sum=0,length=0;
    for(i=0;s[i];i++){
        if(s[i]==' '){
            if(sum!=0)length = sum;
            sum=0;
        }else{
            sum++;
        }
    }
    if(sum!=0)length=sum;
    return length;
}
