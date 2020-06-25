#pragma once
#include <iostream>
#include <vector>

using std::vector;

vector<int>& BubbleSort(vector<int> & arr);
vector<int>& SelectionSort(vector<int>& arr);
vector<int>& InsertionSort(vector<int>& arr);
vector<int>& ShellSort(vector<int>& arr);
vector<int>& MergeSort(vector<int>& arr);
vector<int>& QuickSort(vector<int>& arr, int left, int right);
vector<int>& HeapSort(vector<int>& arr);
vector<int>& CountingSort(vector<int>& arr);
vector<int>& BucketSort(vector<int>& arr);
vector<int>& RadixSort(vector<int>& arr);