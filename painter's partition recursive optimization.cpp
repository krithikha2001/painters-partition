
#include<bits/stdc++.h>
using namespace std;

// function to calculate sum between two indices
int sum(int arr[], int from, int to)
{
	int total = 0;
	for (int i = from; i <= to; i++)
		total += arr[i];
	return total;
}


int partition(int arr[], int n, int k)
{
	// base cases
	if (k == 1){ // one partition
		return sum(arr, 0, n - 1);
    }
	if (n == 1){ // one board
		return arr[0];
   }

	int best = INT_MAX;
    //optimal case always occurs when we divide A into exactly k partitions
	for (int i = k-1; i <= n; i++){
		best = min(best, max(partition(arr, i, k - 1),sum(arr, i, n - 1)));
    }
	return best;
}

int main()
{
	int n, k, i;
	int *arr;
	cout << "Enter the number of boards of varying length to be painted: ";
    cin>>n;
    cout<<"Enter the number of painters available: ";
    cin>>k;
    cout<<"Enter the lengths of "<<n<<" partitions : ";
    arr=(int*)malloc(n*(sizeof(int)));
    for(i=0; i<n; i++){
    	cin>>arr[i];
	}
	cout<<"--------------------------------------------------";
	cout << endl<< "Minimum time to paint all boards: " << partition(arr, n, k) << endl;
	return 0;
}

