#include <bits/stdc++.h>
using namespace std;

int rangeMinQuery(int segment[], int qlow, int qhigh, int low, int high, int pos){
    if(qlow <= low && qhigh >= high)
        return segment[pos];
    if(qlow > high || qhigh < low)
        return INT_MAX;
    int mid = (low + high)/2;
    return min(rangeMinQuery(segment, qlow, qhigh, low, mid, 2*pos + 1), rangeMinQuery(segment, qlow, qhigh, mid+1, high, 2*pos + 1));
}

void constructTree(int input[], int segment[], int low, int high, int pos){
    if(low == high){
        segment[pos] = input[low];
        return;
    }
    int mid = (low + high)/2;
    constructTree(input, segment, low, mid, 2*pos + 1);
    constructTree(input, segment, mid, high, 2*pos + 2);
    segment[pos] = min(segment[2*pos + 1], segment[2*pos + 2]);
}

int main(){
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i < n; i++){
        cin >> input[i];
    }
    int i = 0;
    while(true){
        if(n == pow(2, i))
            break;
        else if(n < pow(2, i))
            break;
        i++;
    }
    int nn = (pow(2, i)*2)-1;
    int segment[nn];
    cout << nn << "\n";
    for(i = 0;i < nn; i++){
        segment[i] = INT_MAX;
    }
    constructTree(input, segment, 0, n-1, 0);
    for(i = 0;i < nn; i++){
        cout << segment[i] << "\n";
    }
}
/*
4
-1  2  4  0
*/