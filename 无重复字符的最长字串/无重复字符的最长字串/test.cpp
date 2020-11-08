class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() == 0)
		{
			return 0;
		}
		int maxStr = 0;
		int left = 0;
		unordered_set<char> c;
		for (int i = 0; i < s.size(); i++)
		{
			while (c.find(s[i]) != c.end())
			{
				c.erase(s[left]);
				left++;
			}
			maxStr = max(maxStr, i - left + 1);
			c.insert(s[i]);
		}
		return maxStr;
	}
};