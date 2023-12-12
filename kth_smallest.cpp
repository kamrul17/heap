#include <bits/stdc++.h>
using namespace std;
int kthSmallest(int arr[], int l, int r, int k)
{

    priority_queue<int> maxheap;
    for (int i = 0; i < k; i++)
    {
        maxheap.push(arr[i]);
    }
    int n = r - l + 1;
    for (int i = k; i < n; i++)
    {
        if (arr[i] < maxheap.top())
        {
            maxheap.pop();
            maxheap.push(arr[i]);
        }
    }
    return maxheap.top();
}
int main()
{
    int arr[] = {7, 10, 4, 20, 15};
    int size = sizeof(arr) / sizeof(int);
    int l = 0;
    int r = size - 1;
    int k = 4;
    int ans = kthSmallest(arr, l, r, k);
    cout << ans;
    return 0;
}