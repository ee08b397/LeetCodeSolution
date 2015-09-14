/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 8ms
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1=num1.size(),len2=num2.size();
        int i,j;
        vector<int> mul;
        for(i=0;i<len1+len2;i++){
            mul.push_back(0);
        }
        for(i=len1-1;i>=0;i--){
            for(j=len2-1;j>=0;j--){
                mul[(len1-1-i)+(len2-1-j)] += (num1[i]-'0')*(num2[j]-'0');
            }
        }
        string multi;
        for(i=0;i<len1+len2;i++){
            mul[i+1] += mul[i]/10;
            mul[i] = mul[i]%10;
        }
        i=len1+len2-1;
        while(i>=0 && mul[i]==0)i--;
        if(i==-1){
            multi = "0";
            return multi;
        }
        multi = string(i+1,'0');
        for(j=0;j<=i;j++){
            multi[i-j] = mul[j]+'0';
        }
        return multi;
    }
};
