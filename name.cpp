// C++ program to implement the approach
#include <bits/stdc++.h>
using namespace std;

// Predicate function
int isValid(int* arr, int N, int K,
			int height)
{
	// Sum of chocolate cut
	int sum = 0;

	// Finding the chocolate cut
	// at this height
	for (int i = 0; i < N; i++) {
		if (height < arr[i])
			sum += arr[i] - height;
	}

	// Return true if valid cut
	return (sum >= K);
}

int maxHeight(int* arr, int N, int K)
{

	// High as max height
	int high = *max_element(arr, arr + N);

	// Low as min height
	int low = 0;

	// Mid element for binary search
	int mid;

	// Binary search function
	while (high - low > 1) {

		// Update mid
		mid = (high + low) / 2;

		// Update high/low
		if (isValid(arr, N, K, mid)) {
			low = mid;
		}
		else {
			high = mid - 1;
		}
	}

	// After binary search we get 2 elements
	// high and low which we can manually compare
	if (isValid(arr, N, K, high)) {
		return high;
	}
	else {
		return low;
	}
}

// Driver code
int main()
{
	// Defining input
	int arr[4] = { 15, 20, 8, 17 };
	int N = 4;
	int K = 7;

	// Calling the function
	cout << maxHeight(arr, N, K);
	return 0;
}
