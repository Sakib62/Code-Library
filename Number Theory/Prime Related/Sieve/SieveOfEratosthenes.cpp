#include <bits/stdc++.h>
using namespace std;

vector <int> prime;
bool isComposite[100001];

void sieveOfEratosthenes(int n) {
	isComposite[0] = isComposite[1] = 1;
	long long i, j;

	for(i = 4; i <= n; i += 2) {
		isComposite[i] = 1;
    }
	for(i = 3; i*i <= n; i+=2) {
		if(isComposite[i] == 0) {
			for(j = i*i; j <= n; j += 2*i) {
				isComposite[j] = 1;
            }
		}
	}
	if(n >= 2) prime.push_back(2);
	for(i = 3; i <= n; i+=2) {
		if(isComposite[i] == 0) {
			prime.push_back(i);
        }
	}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); int testCase = 1;
    //cin >> testCase;
    while(testCase--) {
        int n;
        cin >> n;
        sieveOfEratosthenes(n);
        for(auto i : prime) {
        	cout << i << "\n";
        }
    }
}