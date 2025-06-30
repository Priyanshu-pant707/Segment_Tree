#include <bits/stdc++.h>

using namespace std;

void buildTree(vector<int> &arr, int index, int left, int right, vector<int> &segTree)
{
    if (left == right)
    {
        segTree[index] = arr[right];
        return;
    }

    int mid = (left + right) / 2;

    buildTree(arr, 2 * index + 1, left, mid, segTree);
    buildTree(arr, 2 * index + 2, mid + 1, right, segTree);
    segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
}

int main()
{
    int n;
    cout << "Enter the Size of the Array :";
    cin >> n;

    vector<int> segmentTree(n+(n-1), 0);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    buildTree(arr, 0, 0, n - 1, segmentTree);

    for (auto it : segmentTree)
    {
        cout << it<<" " ;
    }
}