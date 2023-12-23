#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void randomizeArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 200 - 100;
	}
	cout << endl;
}
void shakerSort(int arr[],int n)
{
	bool swapped = true;
	int start = 0;
	int end = n - 1;
	while (swapped)
	{
		swapped = false;
		for (int i = start; i < end; ++i)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
			
		}
		if (!swapped)
		{
			break;
		}

		swapped = false;
		--end;
		for (int i = end - 1; i >= start; --i)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}
		++start;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void printMaxMin(int arr[], int n)
{
	int max = 0;
	int min = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	cout << "The max element: " << max << endl;
	cout << "The min element: " << min << endl;
}

void printIndexOfAverage(int arr[], int n, float average)
{
	int k = 0;
	cout << "\nThe indexes (numbering from 0): ";
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == average)
		{
			cout << i;
			k += 1;
		}
	}
	cout << "\nThe quantity: " << k - 1 << '\n';
}

void printQuantityLeft(int arr[],int n,int a)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < a)
		{
			k += 1;
		}
	}
	cout << "The quantity of elements before number: " << k << '\n';
}

void printQuantityRight(int arr[], int n, int b)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > b)
		{
			k += 1;
		}
	}
	cout << "The quantity of elements after number: " << k << '\n';
}

int binarySearch(int arr[], int value, int start, int end) {
	if (end >= start) {
		int middle = start + (end - start) / 2;
		if (arr[middle] == value) {
			return middle;
		}
		if (arr[middle] > value) {
			return binarySearch(arr, value, start, middle - 1);
		}
		return binarySearch(arr, value, middle + 1, end);
	}
	return -1;
}

void searchElement(int arr[], int n, int c)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == c)
		{
			k += 1;
		}
	}
	if (k == 0)
	{
		cout << "This element is not in the array." << endl;
	}
	else
	{
		cout << "This element is in the array." << endl;
	}
}

void swapElements(int arr[], int n, int index1, int index2)
{
	swap(arr[index1], arr[index2]);
}

void pairwiseInsertSort(int arr[],int n)
{
	int left = 0;
	int right = n - 1;
	for (int k = left; ++left < n; k = ++left) {
		int a1 = arr[k], a2 = arr[left];
		if (a1 < a2) {
			a2 = a1; a1 = arr[left];
		}
		while (a1 < arr[--k]) {
			arr[k + 2] = arr[k];
		}
		k++;
		arr[k + 1] = a1;
		while (a2 < arr[--k]) {
			arr[k + 1] = arr[k];
		}
		arr[k + 1] = a2;
	}
	int last = arr[right];
	while (last < arr[--right]) {
		arr[right + 1] = arr[right];
	}
	arr[right + 1] = last;
}

void copyArray(int arr[],int arr1[],int n)
{
	for (int i = 0; i < n; i++) {
		arr1[i] = arr[i];
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}
int main()
{
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
	nanoseconds result;

	const int n = 100;
	int arr[n];
	randomizeArray(arr, n);
	int arrSort[n];
	copyArray(arr, arrSort, n);

	cout << "Unsorted array: \n";
	printArray(arr, n);

	cout << "Sorted array: \n";
	start = steady_clock::now();
	shakerSort(arrSort, n);
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << "The time of sort: " << result.count() << " nanoseconds\n\n";

	int arr3[n];
	copyArray(arr, arr3, n);
	cout << "In unsorted array: \n";
	start = steady_clock::now();
	printMaxMin(arr3, n);
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << "The time of print: " << result.count() << " nanoseconds\n";
	cout << "In sorted array: \n";
	start = steady_clock::now();
	int max = arrSort[n - 1];
	int min = arrSort[0];
	cout << "The max element: " << max << '\n';
	cout << "The min element: " << min << '\n';
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << "The time of print: " << result.count() << " nanoseconds\n\n";

	int arr4[n];
	copyArray(arrSort, arr4, n);
	float average = round((max + min) / 2);
	cout << "The average of max and min: " << average;
	start = steady_clock::now();
	printIndexOfAverage(arr4, n, average);
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << "The time of print: " << result.count() << " nanoseconds\n\n";

	int a;
	cout << "Enter the number: ";
	cin >> a;
	printQuantityLeft(arrSort, n, a);

	int b;
	cout << "Enter the number: ";
	cin >> b;
	printQuantityRight(arrSort, n, b);

	int c;
	cout << "\nEnter the number: ";
	cin >> c;
	cout << "Binary Search: \n";
	start = steady_clock::now();
	int res = binarySearch(arrSort, c, 0, n - 1);
	if (res == -1)
	{
		cout << "This element is not in the array.\n";
	}
	else
	{
		cout << "This element is in the array.\n";
	}
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << "The time of binary search: " << result.count() << " nanoseconds\n";
	cout << "Standart Search: \n";
	start = steady_clock::now();
	searchElement(arrSort, n, c);
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << "The time of standart search: " << result.count() << " nanoseconds\n\n";

	int arr8[n];
	int index1, index2;
	copyArray(arrSort, arr8, n);
	cout << "Enter the first index of the element you want to swap: ";
	cin >> index1;
	cout << "Enter the second index of the element you want to swap: ";
	cin >> index2;
	start = steady_clock::now();
	swapElements(arr8, n, index1 - 1, index2 - 1);
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	printArray(arr8, n);
	cout << "The time of swap: " << result.count() << " nanoseconds\n\n";


	cout << "IDZ 8: \n";
	int arrIdz[n];
	copyArray(arr, arrIdz, n);
	cout << "Unsorted array: \n";
	printArray(arr, n);
	start = steady_clock::now();
	pairwiseInsertSort(arrIdz, n);
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << "Sorted array by pairwise insert sort: \n";
	printArray(arrIdz, n);
	cout << "The time of pairwise insert sort: " << result.count() << " nanoseconds\n\n";
	return 0;
}