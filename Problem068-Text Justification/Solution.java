/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 1ms
 */
public class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> returnWords = new ArrayList<String>();
        int i=0;
        while(i<words.length){
            int sum=-1;
            int j=i;
            while(i<words.length && sum+1+words[i].length()<=maxWidth){
                sum+=1+words[i].length();
                i++;
            }
            String tmp = words[j];
            if(i>=words.length || i-j==1){
                for(int k=j+1;k<i;k++){
                    tmp+=" "+words[k];
                }
                int len = maxWidth-sum;
                while(len-- > 0)tmp+=" ";
            }else{
                int m = (maxWidth-sum)/(i-j-1);
                int n = (maxWidth-sum)%(i-j-1);
                for(int k=j+1;k<i;k++){
                    if(n>0){
                        tmp+=" ";
                        n--;
                    }
                    for(int l=0;l<m+1;l++)tmp+=" ";
                    tmp+=words[k];
                }
            }
            returnWords.add(tmp);
        }
        return returnWords;
    }
}