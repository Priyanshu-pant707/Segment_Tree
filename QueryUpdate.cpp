#include <bits/stdc++.h>

using namespace std;

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

void updateTREE(vector<int> &segmentTree, int index, int val, int i, int left, int right)
{
    // index is the index of rth
    if (left == right)
    {
        segmentTree[i] = val;
        return;
    }
    int mid = (left + right) / 2;

    if (index <= mid)
    {
        updateTREE(segmentTree, index, val, 2 * i + 1, left, mid);
    }
    else
    {
        updateTREE(segmentTree, index, val, 2 * i + 2, mid + 1, right);
    }
    segmentTree[i] = segmentTree[2 * i + 1] + segmentTree[2 * i + 2];
}

int main()
{
    int n;
    cout << "enter the size of the array :";
    cin >> n;

    vector<int> arr(n);
    cout << "enter the elements  of the array : " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> segmentTree(n+(n-1), 0);

    cout << "Calling the build segment tree function ....." << endl;
    buildTree(arr, 0, 0, n - 1, segmentTree);

    cout << "Your segment tree is ready to use ..." << endl;


    cout<<"before updating : ";
    for(auto it:segmentTree)
    cout<<it<<" ";
    cout<<endl;
    cout << "Now enter you query for updating (index and value) :";
    int idx, val;
    cin >> idx >> val;

    cout << "Updating the Segment tree......." << endl;
    updateTREE(segmentTree, idx, val, 0, 0, n - 1);
    cout<<"updation done..."<<endl;

        cout<<"after updating : ";
    for(auto it:segmentTree)
    cout<<it<<" ";
}