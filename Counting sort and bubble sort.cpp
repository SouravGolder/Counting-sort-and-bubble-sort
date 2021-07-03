// Counting sort which takes negative numbers as well
#include<fstream>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;

void countSort(vector<int>& arr)
{
	int max = *max_element(arr.begin(), arr.end());
	int min = *min_element(arr.begin(), arr.end());
	int range = max - min + 1;

	vector<int> count(range), output(arr.size());
	for (int i = 0; i < arr.size(); i++)
		count[arr[i] - min]++;

	for (int i = 1; i < count.size(); i++)
		count[i] += count[i - 1];

	for (int i = arr.size() - 1; i >= 0; i--) {
		output[count[arr[i] - min] - 1] = arr[i];
		count[arr[i] - min]--;
	}

	for (int i = 0; i < arr.size(); i++)
		arr[i] = output[i];
}

void printArray(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << "\n";
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(vector<int>& arr, int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}

int main()
{
	vector<int> arr;
	int data,n;
	ifstream F("1.txt");
    while(!F.eof())
    {
        F>>data;
        arr.push_back(data);
    }
    n=arr.size();
    cout<<"Counting sorted array"<<endl;
    auto start = high_resolution_clock::now();
	countSort(arr);
	printArray(arr);
	auto stop=high_resolution_clock::now();
	auto duration= duration_cast<microseconds>(stop-start);
	cout<<endl<<endl<<"Time count => "<<duration.count()<<" microseconds"<<endl;

	start = high_resolution_clock::now();
	bubbleSort(arr,n);
	cout<<endl<<"Bubble sorted array"<<endl;
	printArray(arr);
	stop=high_resolution_clock::now();
	duration= duration_cast<microseconds>(stop-start);
	cout<<endl<<endl<<"Time count => "<<duration.count()<<" microseconds"<<endl;

	return 0;
}

