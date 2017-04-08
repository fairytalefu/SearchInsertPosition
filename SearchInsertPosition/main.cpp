#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	static int searchInsert(vector<int>& nums, int target) 
	{
	
		int numsSize = nums.size();
		if (numsSize == 0)
			return -1;
		int  i = 0;
		vector<int>::iterator it;
		if (numsSize == 1)
		{
			if (nums.at(0) ==  target)
			{
				nums.push_back(target);
				return 0;
			}

			if (nums.at(0) < target)
			{
				nums.push_back(target);
				return 1;
			}
			else
			{
				nums.insert(nums.begin(), target);
				return 0;
			}
			
		}
		else 
		{
			for (it = nums.begin();it<nums.end();)
			{
			
				if (*it == target)
				{
					return i;
				}
				if (*it <= target)
				{
					it++;
				}
				else
				{
					nums.insert(nums.begin() + i, target);
					return i;
				}
				i++;
		
			}
			nums.push_back(target);
			return numsSize;
		}

	}
};

int main()
{
	vector<int> inputArray;
	inputArray.push_back(1);
	int res = Solution::searchInsert(inputArray, 1);
	cout << res << endl;
	return 0;
}