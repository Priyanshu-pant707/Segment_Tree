#include <bits/stdc++.h>

using namespace std;

/*
three conditions
1.out of bound-no contribution return 0.
2.entirely in the query-return value at that node .
3.overlapping -go to left and right both side.


*/

int Query(vector<int> &segmentTree, int start, int end, int i, int left, int right)
{

    if (left > end || right < start)
    {
        return 0;
    }
    if (left >= start && right <= end)
    {
        return segmentTree[i];
    }
    int mid = (left + right) / 2;
    return Query(segmentTree, start, end, 2 * i + 1, left, mid) + Query(segmentTree, start, end, 2 * i + 2, mid + 1, right);
}
void buildTree(vector<int> &arr, int index, int left, int right, vector<int> &segmentTree)
{

    if (left == right)
    {
        segmentTree[index] = arr[left];
        return;
    }
    int mid = (left + right) / 2;

    buildTree(arr, 2 * index + 1, left, mid, segmentTree);
    buildTree(arr, 2 * index + 2, mid + 1, right, segmentTree);
    segmentTree[index] = segmentTree[2 * index + 1] + segmentTree[2 * index + 2];
}

int main()
{
    int n;
    cout << "Enter the Size of the Array :";
    cin >> n;

    vector<int> segmentTree(4 * n, 0);
    vector<int> arr(n);
    cout << "enter the elements in the array :" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    buildTree(arr, 0, 0, n - 1, segmentTree);

    for (auto it : segmentTree)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << "enter the start and end the range sum query  :" ;
    int start, end;
    cin >> start >> end;
    int ans = Query(segmentTree, start, end, 0, 0, n - 1);
    cout << "range sum query : " << ans << endl;
}