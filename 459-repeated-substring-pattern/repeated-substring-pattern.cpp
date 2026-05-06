class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
       int m=n/2; 
        for(int i=m;i>=1;i--){  // isko hmm 1 se bhi start kr sakte the likn last se first iteration me 2 append 2it me 3 to ye jyada optemie hai
             string ans="";
            if(n%i==0){
               string sub=s.substr(0,i);
                int k=n/i;
                for(int j=0;j<k;j++){
                  ans=ans+sub;  
                }
            }
            
            if(ans==s) return true;
        }
        return false;
    }
};

//
