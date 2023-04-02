//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << '>' << #x << " : " << x << "\n";
#define all(c) c.begin(), c.end()
#define F first
#define S second

typedef unsigned long long ull;
typedef long long ll;


//Counting Sort - Linear Complexity. Not a comparison based sorting algo.
//Stable Sorting Algorithm - Important if number is associated with something

//Stability of sorting algorithm simply means that the relative ordering of elements with same keys will
//remain same before & after the sorting.

void countSort(int *a, int n) {
    int mx = *max_element(a, a+n); //to determine range of freq array
    int freq[mx + 1] = {0}, ans[n];

    for(int j = 0; j < n; j++) { //frequency array
        freq[a[j]]++;
    }
    for(int j = 1; j < mx + 1; j++) { //prefix sum
        freq[j]+=freq[j-1]; //can complete sorting in this point though won't be stable
    }
    //from last to make stable sorting
    for(int i = n - 1; i >= 0; i--) {
         ans[freq[a[i]] - 1] = a[i];//-1 to fit in 0 based indexing. a[i] is freq[a[i]]th element if sorted
         freq[a[i]]--;//already placed this one, hence decrement
    }
    //copy into original array
    for(int i = 0; i < n; i++) {
        a[i] = ans[i];
    }
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    countSort(a, n);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); int testCase = 1;
    //cin >> testCase;
    while(testCase--) {
        solve();
    }
}