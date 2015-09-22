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
    string addBinary(string a, string b) {
        int len1=a.length();
        int len2=b.length();
        int len = (len1>len2?len1:len2)+5;
        int i=len1-1,j=len2-1,top=0;
        char* str = (char*)malloc(sizeof(char)*len);
        memset(str,0,sizeof(char)*len);
        while(true){
            if(i<0 && j<0)break;
            else if(i<0)str[top++]+=b[j--]-'0';
            else if(j<0)str[top++]+=a[i--]-'0';
            else str[top++]+=a[i--]-'0'+b[j--]-'0';
        }
        for(i=0;i<len;i++){
            str[i+1]+=str[i]/2;
            str[i]%=2;
            str[i]+='0';
        }
        i--;
        while(i>0 && str[i]=='0')i--;
        j=i;str[i+1]=0;
        i=0;
        while(i<j){
            char tmp = str[i];
            str[i]=str[j];
            str[j]=tmp;
            i++;j--;
        }
        return string(str);
    }
};
