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
char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    int* wordlen = (int*)malloc(sizeof(int)*wordsSize);
    char** returnWords = (char**)malloc(sizeof(char*)*wordsSize);
    int sum,i,j,k,n,m,top;
    for(i=0;i<wordsSize;i++){
        wordlen[i] = strlen(words[i]);
    }
    i=0;*returnSize=0;
    while(i<wordsSize){
        sum=-1;j=i;
        top=0;
        //while(i<wordsSize && wordlen[i]==0)i++;
        returnWords[*returnSize] = (char*)malloc(sizeof(char)*(maxWidth+1));/*
        if(i>=wordsSize){
            for(k=0;k<maxWidth;k++)
            returnWords[*returnSize][top++]=' ';
            returnWords[*returnSize][top]=0;
            (*returnSize)++;
            return returnWords;
        }*/
        while(i<wordsSize && sum+wordlen[i]+1 <= maxWidth){
            sum+=wordlen[i++]+1;
        }
        for(k=0;words[j][k];k++){
            returnWords[*returnSize][top++]=words[j][k];
        }
        if(i-j==1){
            while(top<maxWidth)returnWords[*returnSize][top++]=' ';
            returnWords[*returnSize][top]=0;
        }else if(i>=wordsSize){
            j++;
            while(j<i){
                returnWords[*returnSize][top++]=' ';
                for(k=0;words[j][k];k++){
                    returnWords[*returnSize][top++]=words[j][k];
                }
                j++;
            }
            while(top<maxWidth)returnWords[*returnSize][top++]=' ';
            returnWords[*returnSize][top]=0;
        }else{
            m=(maxWidth-sum)/(i-j-1);
            n=(maxWidth-sum)%(i-j-1);
            j++;
            while(j<i){
                for(k=0;k<m+1;k++){
                    returnWords[*returnSize][top++]=' ';
                }
                if(n>0){
                    returnWords[*returnSize][top++]=' ';
                    n--;
                }
                for(k=0;words[j][k];k++){
                    returnWords[*returnSize][top++]=words[j][k];
                }
                j++;
            }
            returnWords[*returnSize][top]=0;
        }
        returnSize[0]++;
    }
    return returnWords;
}
