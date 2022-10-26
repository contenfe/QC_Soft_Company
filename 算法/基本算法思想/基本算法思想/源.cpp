#include<iostream>
#include<stdlib.h>
#include<vector>
#include<math.h>
using namespace std;


int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a > b ? b : a;
}


int maxArea(int *pArray,int len)
{
	int _maxArea = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			_maxArea = max(_maxArea, min(*(pArray + i), *(pArray+j))*(j - i));
		}
	}
	return _maxArea;
}


class Solution
{
public:
	int maxArea(vector<int>& height)
	{
		int left = 0, right = height.size() - 1;
		int ans = 0;
		while (left < right)
		{
			ans = max(ans, (right - left)*min(height[left], height[right]));
			if (height[left] < height[right])
			{
				left++;
			}
			else
			{
				right--;
			}
		}

		return ans;
	}   
	int maxArea(vector<int>& height,int len)
	{
		int left = 0, right = height.size() - 1;
		int ans = 0;
		while (left < right)
		{
			ans = max(ans, (right - left)*min(height[left], height[right]));
			if (height[left] < height[right] && )
			{
				left++;
			}
			else
			{
				right--;
			}
		}

		return ans;
	}
protected:
private:
};


int main(int argc, char **argv)
{
	vector<int> height = { 1,8,6,2,5,4,8,3,7 };
	//cout << maxArea(arry, sizeof(arry) / sizeof arry[0]) << endl;
	
	Solution s;
	cout << s.maxArea(height) << endl;

	return 0;
}