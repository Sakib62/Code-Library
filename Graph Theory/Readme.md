Graph in grid

Traversing

Shortest Path

Cycle

Component

Tree

MST

Common Ancestor

Max Flow






# 0-1 Knapsack 

```c++
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int p[] = {0,1,2,5,6};
    int wt[] = {0,2,3,4,5};
    int v[5][9];

    int m = 8, n = 4;

    for(int i=0; i<=n; i++){
        for(int w=0; w<=m; w++)
        {
            if(i==0 || w==0){
                v[i][w]=0;
            }
            else if(wt[i]<=w){
                v[i][w] = max(v[i-1][w], v[i-1][w-wt[i]]+p[i]);
            }
            else{
                v[i][w] = v[i-1][w];
            }
        }
    }

    cout<<v[n][m]<<endl;

    return 0;
}

``` 

# LCS
```c++
#include<bits/stdc++.h>

using namespace std;

int lcs(string s1, string s2, int n, int m)
{
    if(n==0 || m==0){
        return 0;
    }
    if(s1[n-1]==s2[m-1]){
        return 1+lcs(s1,s2,n-1,m-1);
    }
    else {
        return max(lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1));
    }
}

int main() {
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.size();
    int m = s2.size();
    cout<<lcs(s1,s2,n,m)<<endl;

    return 0;
}

```   

# Travelling Salesman

```c++
#include <iostream>
using namespace std;
// there are four nodes in example graph (graph is 1-based)
const int n = 4;
// give appropriate maximum to avoid overflow
const int MAX = 1000000;
// dist[i][j] represents shortest distance to go from i to j
// this matrix can be calculated for any given graph using
// all-pair shortest path algorithms
int dist[n + 1][n + 1] = {
	{ 0, 0, 0, 0, 0 }, { 0, 0, 10, 15, 20 },
	{ 0, 10, 0, 25, 25 }, { 0, 15, 25, 0, 30 },
	{ 0, 20, 25, 30, 0 },
};
// memoization for top down recursion
int memo[n + 1][1 << (n + 1)];
int fun(int i, int mask) {
	// base case
	// if only ith bit and 1st bit is set in our mask,
	// it implies we have visited all other nodes already
	if (mask == ((1 << i) | 3))
		return dist[1][i];
	// memoization
	if (memo[i][mask] != 0)
		return memo[i][mask];

	int res = MAX; // result of this sub-problem
	// we have to travel all nodes j in mask and end the
	// path at ith node so for every node j in mask,
	// recursively calculate cost of travelling all nodes in
	// mask except i and then travel back from node j to
	// node i taking the shortest path take the minimum of// all possible j nodes

	for (int j = 1; j <= n; j++)
		if ((mask & (1 << j)) && j != i && j != 1)
			res = std::min(res, fun(j, mask & (~(1 << i)))
									+ dist[j][i]);
	return memo[i][mask] = res;
}
// Driver program to test above logic
int main() {
	int ans = MAX;
	for (int i = 1; i <= n; i++)
		// try to go from node 1 visiting all nodes in
		// between to i then return from i taking the
		// shortest route to 1
		ans = std::min(ans, fun(i, (1 << (n + 1)) - 1)
								+ dist[i][1]);

	printf("The cost of most efficient tour = %d", ans);
	return 0;
}
```

# Coin Change

```c++
#include <bits/stdc++.h>
using namespace std;

int count(int coins[], int n, int sum) {
	int i, j, x, y;
	// We need sum+1 rows as the table // is constructed in bottom up
	// manner using the base case 0 // value case (sum = 0)
	int table[sum + 1][n];

	// Fill the entries for 0// value case (sum = 0)
	for (i = 0; i < n; i++)
		table[0][i] = 1;

	// Fill rest of the table entries// in bottom up manner
	for (i = 1; i < sum + 1; i++) {
		for (j = 0; j < n; j++) {
			// Count of solutions including coins[j]
			x = (i - coins[j] >= 0) ? table[i - coins[j]][j]
									: 0;

			// Count of solutions excluding coins[j]
			y = (j >= 1) ? table[i][j - 1] : 0;
			// total count
			table[i][j] = x + y;
		}
	}
	return table[sum][n - 1];
}
int main() {
	int coins[] = { 1, 2, 3 };
	int n = sizeof(coins) / sizeof(coins[0]);
	int sum = 4;
	cout << count(coins, n, sum);
	return 0;
}

//M*sum
```
