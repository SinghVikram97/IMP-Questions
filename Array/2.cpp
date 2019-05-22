Largest Unique Substring

Given a string S,
find the largest substring with no repetition i.e.largest substring which contain all unique characters.

void findLargestUniqueSubstring(char input[], char output[])
{

  string s(input);
  int n = s.length();
  string ans;

  int i = 0;
  int j = 1;

  unordered_set<char> mySet;
  mySet.insert(s[0]);
  int maxLength = -1;
  int length = 1;

  while (i <= j && j < n)
  {

    if (mySet.find(s[j]) != mySet.end())
    {
      // Cut our window from length
      auto it = mySet.find(s[j]);
      mySet.erase(it);
      i++;
      length--;
    }
    else
    {
      // Increase our window

      mySet.insert(s[j]);
      j++;
      length++;
      maxLength = max(maxLength, length);
    }
  }
  cout << maxLength << endl;
}
