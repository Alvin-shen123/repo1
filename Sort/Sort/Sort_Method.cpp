#include <iostream>
#include <vector>

using namespace std;
//1.冒泡
vector<int>& BubbleSort(vector<int> & arr)
{
	for (int i = 0; i < arr.size()-1; i++)
	{
		for (int j = 0; j < arr.size() - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return arr;
}
//2.选择
vector<int>& SelectionSort(vector<int>& arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[min] > arr[j])
				min = j;
		}
		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
	return arr;
}
//3.插入
vector<int>& InsertionSort(vector<int>& arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (arr[i + 1] < arr[j])
			{
				int temp = arr[i + 1];
				arr[i + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return arr;
}
//4.希尔
vector<int>& ShellSort(vector<int>& arr)
{
	for (int gap = arr.size() / 2; gap > 0; gap = gap / 2)
	{

		for (int i = gap; i < arr.size(); i++)
		{
			if (arr[i] < arr[i - gap])
			{
				int temp = arr[i];
				arr[i] = arr[i - gap];
				arr[i - gap] = temp;
			}
		}
	}
	return arr;
}
//5.归并
vector<int>& merge(const vector<int>& left, const vector<int>& right)
{
	vector<int> vec;
	auto begl = left.begin();
	auto begr = right.begin();
	while (begl != left.end() && begr != right.end())
	{
		if (*begl <= *begr)
		{
			vec.push_back(*begl);
			++begl;
		}
		else if (*begl > *begr)
		{
			vec.push_back(*begr);
			begr++;
		}
	}
	if (begl!=left.end())
	{
		vec.push_back(*begl);
		++begl;
	}
	if (begr != right.end())
	{
		vec.push_back(*begr);
		++begr;
	}
	return vec;
}
vector<int>& MergeSort(vector<int>& arr)
{
	int len = arr.size();
	if (len < 2)
		return arr;
	int middle = len / 2;
	vector<int> L(arr.begin(), arr.begin() + middle);
	vector<int> R(arr.begin() + middle, arr.end());
	return merge(MergeSort(L), MergeSort(R));
}
//6.快速
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int& partition(vector<int>& vec, const int& left, const int& right, const int& index)
{
	int val = vec[index];
	swap(vec[index], vec[right]);
	int storeIndex = left;
	for (int i = left; i < right; i++)
	{
		if (vec[i] < val)
		{
			swap(vec[storeIndex], vec[i]);
			++storeIndex;
		}
	}
	swap(vec[right], vec[storeIndex]);
	return storeIndex;
}
vector<int>& QuickSort(vector<int>& arr, int left, int right)
{
	if (left < right)
	{
		int Index = partition(arr, left, right, 0);
		QuickSort(arr, left, Index);
		QuickSort(arr, Index, right);
	}
	return arr;
}
//7.堆
void adjustHeap(vector<int>& vec, int i, int len)
{
	int left = i * 2 + 1, 
		right = left + 1, 
		largest = i;
	if (left<len && vec[left]>vec[largest])
		largest = left;
	if (right<len && vec[right]>vec[largest])
		largest = right;
	if (largest != i)
	{
		swap(vec[i], vec[largest]);
		adjustHeap(vec, largest, len);
	}
}

vector<int>& HeapSort(vector<int>& arr)
{
	int len = arr.size();
	for (int i = arr.size() / 2; i >= 0; i--)
		adjustHeap(arr, i, len);
	for (int i = arr.size() - 1; i > 0; i--)
	{
		swap(arr[i], arr[0]);
		len--;
		adjustHeap(arr, 0, len);
	}
	return arr;
}
//8.计数
vector<int>& CountingSort(vector<int>& arr)
{
	int max_arr = *arr.cbegin();
	for (auto iter = arr.cbegin(); iter != arr.cend(); iter++)
	{
		if (max_arr < *iter)
			max_arr = *iter;
	}
	vector<int> vec(max_arr);//保存arr中各数字出现的次数
	for (auto iter = arr.cbegin(); iter != arr.cend(); iter++)
		++vec[*iter];
	int i = 0;
	auto iter_arr = arr.begin();
	for (auto iter = vec.begin(); iter != vec.end(); iter++)
	{
		while ((*iter)--)
			*iter_arr = i;
		++i;
	}
	return arr;
}
//9.桶
vector<int>& BucketSort(vector<int>& arr)
{

	return arr;
}
//10.基数
vector<int>& RadixSort(vector<int>& arr)
{

	return arr;
}