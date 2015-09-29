/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 0ms
 */
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> returnWords;
        int i=0;
        while(i<words.size()){
            int sum=-1;
            int j=i;
            while(i<words.size() && sum+1+words[i].length() <= maxWidth){
                sum+=1+words[i].length();
                i++;
            }
            string tmp=words[j];
            if(i>=words.size() || i-j==1){
                for(int k=j+1;k<i;k++){
                    tmp+=" "+words[k];
                }
                tmp+=string(maxWidth-sum,' ');
            }else{
                int m = (maxWidth-sum)/(i-j-1);
                int n = (maxWidth-sum)%(i-j-1);
                for(int k=j+1;k<i;k++){
                    if(n>0){
                        tmp+=" ";
                        n--;
                    }
                    tmp+=string(m+1,' ')+words[k];
                }
            }
            returnWords.push_back(tmp);
        }
        return returnWords;
    }
};
