// 算法导论第二版 P.10
#include<vector>
#include<iostream>
int main()
{
	vector<int> nums;
	InsertionSort(nums);
}

void InsertionSort(vector<int> &nums)
{
	int key;
	for (auto j = nums.begin() + 1; j != nums.end(); ++j)
	{
		key = *j;
		//将*j插入到已排序的nums[1...j-1]
		auto i = j - 1;//j之前已排好序
		while (i >= nums.begin() && *i > key)
		{
			*(i + 1) = *i;
			i--;
		}
		*(i + 1) = key;
	}
}