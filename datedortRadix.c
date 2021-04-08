// C++ program to sort an array
// of dates using Radix Sort

#include <stdio.h>
#include <stdlib.h>
//using namespace std;

// Utilitiy function to obtain
// maximum date or month or year
int getMax(int arr[][3],int n, int q)
{
	int maxi = -1;
	for(int i=0;i<n;i++){
		//maxi = max(maxi,arr[i][q]);
		if(maxi<arr[i][q])
			maxi=arr[i][q];
	}
	return maxi;
}

// A function to do counting sort of arr[]
// according to given q i.e.
// (0 for day, 1 for month, 2 for year)
void sortDatesUtil(int arr[][3],
				int n, int q)
{
	int maxi = getMax(arr,n,q);
	int p = 1;
	while(maxi>0){
		//to extract last digit divide
		// by p then %10
		// Store count of occurrences in cnt[]
		int cnt[10]={0};
		
		for(int i=0;i<n;i++)
		{
			cnt[(arr[i][q]/p)%10]++;
		}
		for(int i=1;i<10;i++)
		{
			cnt[i]+=cnt[i-1];
		}
		int ans[n][3];
		for(int i=n-1;i>=0;i--)
		{
			int lastDigit = (arr[i][q]/p)%10;
			
			// Build the output array
			for(int j=0;j<3;j++)
			{
				ans[cnt[lastDigit]-1][j]
				=arr[i][j];
			}
			cnt[lastDigit]--;
		}
		// Copy the output array to arr[],
		// so that arr[] now
		// contains sorted numbers
		// according to current digit
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				arr[i][j] = ans[i][j];
			}
		}
		// update p to get
		// the next digit
		p*=10;
		maxi/=10;
	}
}

// The main function that sorts
// array of dates
// using Radix Sort
void sortDates(int dates[][3], int n)
{
	// First sort by day
	sortDatesUtil(dates, n, 0);

	// Then by month
	sortDatesUtil(dates, n, 1);
	// Finally by year
	sortDatesUtil(dates, n, 2);
}

// A utility function to print an array
void printArr(int arr[][3], int n)
{
for(int i=0;i<n;i++)
{
		for(int j=0;j<3;j++)
		{
			printf("%d  ",arr[i][j]);
		}
		printf("\n");
	}
}

void inputdate(int arr[][3],int n)
{
	int i;
	for(int i =0;i<n;i++)
		{
			printf("enter day  ");
			scanf("%d",&arr[i][0]);
			printf("enter month  ");
			scanf("%d",&arr[i][1]);
			printf("enter year  ");
			scanf("%d",&arr[i][2]);
			printf("\n");
		}
		printf("\n");
	
}

// Driver Code
int main()
{
	int dates[100][3] ;
	int n;
	printf("enter the number of dates you want to enter");
	scanf("%d",&n);
	inputdate (dates,n);
	

	// Function Call
	sortDates(dates,n);
	//cout<<"\nSorted Dates\n";
	printArr(dates,n);
	return 0;
}
