/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 12ms
 */
class Solution {
public:
    bool isNumber(string s) {
        const char* str = s.data();
        int len = s.length();
        int i=0,j;
        bool ass = false;
        while(i<len && str[i]==' ')i++;
        j=i;
        for(;i<len;i++){
            if(str[i]=='+' || str[i]=='-'){
                if(i!=j)return false;
            }else if(str[i] =='.'){
                return testDot(str+i+1,ass,len-i-1);
            }else if(str[i]=='e'){
                return testE(str+i+1,len-i-1) && ass;
            }else if(str[i]==' '){
                while(i<len && str[i]==' ')i++;
                return i>=len && ass;
            }else if(!(str[i]>='0' && str[i]<='9')){
                return false;
            }else{
                ass=true;
            }
        }
        return ass;
    }
private:
    bool testDot(const char* str,bool ass,int len){
        int i;
        for(i=0;i<len;i++){
            if(str[i]=='e'){
                return testE(str+i+1,len-i-1) && ass;
            }else if(str[i]==' '){
                while(i<len && str[i]==' ')i++;
                return i>=len && ass;
            }else if(!(str[i]>='0' && str[i]<='9')){
                return false;
            }else{
                ass=true;
            }
        }
        return ass;
    }
    bool testE(const char* str,int len){
        int i;
        bool ass = false;
        for(i=0;i<len;i++){
            if(str[i]=='-' || str[i]=='+'){
                if(i!=0)return false;
            }else if(str[i]==' '){
                while(i<len && str[i]==' ')i++;
                return i>=len && ass;
            }else if(!(str[i]>='0' && str[i]<='9')){
                return false;
            }else{
                ass=true;
            }
        }
        return ass;
    }
};
