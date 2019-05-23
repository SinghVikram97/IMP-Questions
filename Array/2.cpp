Largest Unique Substring
https://leetcode.com/submissions/detail/162924558/

Given a string S,
find the largest substring with no repetition i.e.largest substring which contain all unique characters.

// input - given string
// output - output string that contains largest unique substring
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_set<char> st;
        /// Windows from [start,end) i=start and j=end
        int i=0,j=0; /// Intially window from [0,0) so no element included 
        int maxCount=0;
        while(i<n && j<n){
            // If element doesn't exist in current substring
            if(st.find(s[j])==st.end()){
                // Move window to the right ie. include j in window
                st.insert(s[j]);
                j++;
                maxCount=max(maxCount,j-i);  // Current window is [i,j)
            }
            else{
                // Remove that element from map
                st.erase(s[i]);
                // Increase the start
                i++;
                // Now we can add s[j] as it's duplicate has been removed
            }
        }
        return maxCount;
    }
};
