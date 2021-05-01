#include <climits>
#include <iostream>
#include <time.h>
using namespace std;

int findMax(int arr[], int n, int k);
 
// driver function
int main(){
	int n, k, i;
	int *arr;
	cout<<"Enter the number of partitions: ";
    cin>>n;
    cout<<"Enter the number of painters: ";
    cin>>k;
    cout<<"Enter the lengths of partitions: ";
    arr=(int*)malloc(n*(sizeof(int)));
    
    for(i=0; i<n; i++){
    	cin>>arr[i];
	}
	cout<<"--------------------------------------------------";
    cout<<endl<<"Minimum time: ";
    clock_t start,end;
    float t;
    start=clock();
	cout<<findMax(arr, n, k) << endl;
	end=clock();
	t=(float)(((float)(end-start))/CLOCKS_PER_SEC);
	cout<<endl<<"time taken: "<<t;
    return 0;
}

// bottom up tabular dp
int findMax(int arr[], int n, int k){
    // initialize table
    int dp[k + 1][n + 1] = { 0 };
    // base cases
    // k=1
    int sum[n+1] = {0};
    // sum from 1 to i elements of arr
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i-1] + arr[i-1];
	for (int i = 1; i <= n; i++)
		dp[1][i] = sum[i];
    // 2 to k partitions
    for (int i = 2; i <= k; i++) { // 2 to n boards
        for (int j = 2; j <= n; j++) {
            // track minimum
            int best = INT_MAX;
            // i-1 th separator before position arr[p=1..j]
            for (int p = 1; p <= j; p++)
                best =  min(best, max(dp[i-1][p], sum[j] - sum[p]));
            dp[i][j] = best;
        }
    }
    // required
    return dp[k][n];
}
