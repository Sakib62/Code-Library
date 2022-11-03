#include <bits/stdc++.h>
using namespace std;

vector <int> prime;
bool isComposite[100001];

void linearSieve(int n) {
    //fill (isComposite, isComposite + n + 1, false);
	isComposite[0] = isComposite[1] = 1;
	long long i, j;

	for(i = 2; i <= n; i++) {
		if(isComposite[i] == 0) {
			prime.push_back(i);
		}
//q=i*p; q composite, p is smalles prime factor, then i>=p
//no other prime smaller than p divides i
		for(j = 0; j < prime.size() && i*prime[j] <= n; j++) {
			isComposite[i*prime[j]] = 1;
			if(i%prime[j] == 0) break;
		}
	}
}
//the inner loop is executed only once for each composite.
//Hence, the code above performs in O(n) complexity, resulting in its name — the 'linear' sieve.
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); int testCase = 1;
    //cin >> testCase;
    while(testCase--) {
        int n;
        cin >> n;
        linearSieve(n);
        for(auto i : prime) {
        	cout << i << "\n";
        }
    }
}