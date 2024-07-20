#include <iostream>
#include <algorithm>
using namespace std;

struct Job
{
	int start, finish, profit;
};

bool compareJobs(Job a, Job b)
{
	return (a.finish < b.finish);
}

int findLatestNonConflict(Job arr[], int i)
{
	for (int j = i - 1; j >= 0; j--)
	{
		if (arr[j].finish <= arr[i].start)
			return j;
	}
	return -1;
}

int calculateMaxProfitRec(Job arr[], int n)
{
	if (n == 1) return arr[n - 1].profit;

	int includeProfit = arr[n - 1].profit;
	int i = findLatestNonConflict(arr, n - 1);
	if (i != -1)
		includeProfit += calculateMaxProfitRec(arr, i + 1);

	int excludeProfit = calculateMaxProfitRec(arr, n - 1);

	return max(includeProfit, excludeProfit);
}

int calculateMaxProfit(Job arr[], int n)
{
	sort(arr, arr + n, compareJobs);

	return calculateMaxProfitRec(arr, n);
}

int main()
{
	Job jobs[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
	int n = sizeof(jobs) / sizeof(jobs[0]);
	cout << "The optimal profit is " << calculateMaxProfit(jobs, n);
	return 0;
}
