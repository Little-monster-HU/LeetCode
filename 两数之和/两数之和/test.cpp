class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int n = nums.size();
		for (int i = 0; i<n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (nums[i] + nums[j] == target)
				{
					return{ i, j };
				}
			}
		}
		return{};

	}
};


////¹þÏ£·¨

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> map;
		for (int i = 0; i< nums.size(); i++)
		{
			auto item = map.find(target - nums[i]);
			if (item != map.end())
			{
				return{ item->second, i };
			}
			map[nums[i]] = i;

		}
		return{};

	}
};