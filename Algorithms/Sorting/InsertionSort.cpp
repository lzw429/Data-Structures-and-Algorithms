// �㷨���۵ڶ��� P.10
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
		//��*j���뵽�������nums[1...j-1]
		auto i = j - 1;//j֮ǰ���ź���
		while (i >= nums.begin() && *i > key)
		{
			*(i + 1) = *i;
			i--;
		}
		*(i + 1) = key;
	}
}