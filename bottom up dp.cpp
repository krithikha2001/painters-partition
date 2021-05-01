#include <climits>
#include <iostream>
#include <time.h>
using namespace std;

int sum(int arr[], int from, int to);
int findMax(int arr[], int n, int k);

// driver function
int main()
{
    int n, k, i;
	int *arr;
	float t;
	cout<<"Enter the number of partitions: ";
    cin>>n;
    cout<<"Enter the number of painters: ";
    cin>>k;
    cout<<"Enter the lengths of partitions: ";
    clock_t start,end;
    arr=(int*)malloc(n*(sizeof(int)));
    for(i=0; i<n; i++){
    	cin>>arr[i];
	}
	cout<<"--------------------------------------------------";
    cout<<endl<<"Minimum time: ";
    start = clock();
	cout<<findMax(arr, n, k)<<endl;
	end=clock();
	cout<<"--------------------------------------------------"<<endl;
	t=(float)(((float)(end-start))/CLOCKS_PER_SEC);
	cout<<"time taken: "<<t;
    return 0;
}

// function to calculate sum between two indices
// in array
int sum(int arr[], int from, int to)
{
    int total = 0;
    for (int i = from; i <= to; i++)
        total += arr[i];
    return total;
}
 
// bottom up tabular dp
int findMax(int arr[], int n, int k)
{
    // initialize table
    int dp[k + 1][n + 1] = { 0 };
    // base cases
    // k=1
    for (int i = 1; i <= n; i++)
        dp[1][i] = sum(arr, 0, i - 1);
    // n=1
    for (int i = 1; i <= k; i++)
        dp[i][1] = arr[0];
    // 2 to k partitions
    for (int i = 2; i <= k; i++) { // 2 to n boards
        for (int j = 2; j <= n; j++) {
            // track minimum
            int best = INT_MAX;
            // i-1 th separator before position arr[p=1..j]
            for (int p = 1; p <= j; p++)
                best = min(best, max(dp[i - 1][p], sum(arr, p, j - 1)));       
            dp[i][j] = best;
        }
    }
    // required
    return dp[k][n];
}
