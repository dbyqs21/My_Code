#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arrayPairSum(vector<int>& nums) {
	int N = nums.end() - nums.begin();
	sort(nums.begin(), nums.end());
	/*for (int i = 0; i<N; ++i)
	for (int j = j = i + 1; j < N; ++j)
	{
		if (nums[i]>nums[j])
		{
			int cnt = nums[i];
			nums[i] = nums[j];
			nums[j] = cnt;
		}
	}*/

	for (int i = 0; i < N; ++i)
		cout << nums[i] << " ";

	// nums.sort();
	int sum = 0;
	for (int i = 0; i < N; i += 2)
		sum += nums[i];
	return sum;
}

int main1()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(4);
	
	cout << arrayPairSum(nums) << endl;
	system("pause");

	return 0;
}