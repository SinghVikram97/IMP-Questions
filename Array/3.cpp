/// https://www.geeksforgeeks.org/count-palindrome-sub-strings-string/

/// Select a given element as mid element or as a right element

int countPalindromeSubstrings(char s[]) {

    string word(s);
    int n=word.length();
    int count=0;
    
    for(int i=0;i<n;i++){

        /// Select word[i] as middle element
        int left=i;
        int right=i;
        
        while(left>=0 && right<n){
            if(word[left]==word[right]){
                count++;
                left--;
                right++;
            }
            else{
                break;
            }
        }
        
        // Select word[i] as right element
        left=i-1;
        right=i;
        
        while(left>=0 && right<n){
            if(word[left]==word[right]){
                count++;
                left--;
                right++;
            }
            else{
                break;
            }
        }
        
    }
    return count;
}
