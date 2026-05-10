class Solution {
public:// O(n) o(1) approach dheko hme ya to last me se remove krne hai ya starting me se
// man lo starting se  element reove kiya or end se 5 to bich wale charater ek substring 
// hi honge chhe sabhi element starting se remove krlo to end me ek substring bhegi
// to hme ek esi substring dhudni hai max length ki jisme a ki total freq minus k elemnt
// ho ese b or c ke liye bhi . esa ku esa isliye man lo k= 2 or hmari string a ki freq 8
// to hme esi substring dhudni hai jismee 6 a ho kuki agr substring me 7 a ho gye ya usse jayda . remove krne ke liye k=2 element bachenge hi nhi
    int takeCharacters(string s, int k) {
        vector<int>freq(3,0);
        for(auto &ch:s){
            freq[ch-'a']++;
        }
         if(freq[0]<k || freq[1]<k || freq[2]<k) return -1;
        int i=0;
        int n=s.size();
        int maxi=-1;
        for(int j=0;j<n;j++){
            freq[s[j]-'a']--;
            while(freq[0]<k || freq[1]<k || freq[2]<k){
                freq[s[i]-'a']++;
                i++;
            }

            maxi=max(maxi,j-i+1);
        }
      return n-maxi;
    }
};