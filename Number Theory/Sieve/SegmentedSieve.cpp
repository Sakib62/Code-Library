#include <bits/stdc++.h>
using namespace std;

vector <int> prime;
bool isComposite[100001];

void sieveOfEratosthenes(long long n) {
	isComposite[0] = isComposite[1] = 1;
	long long i, j;

	for(i = 4; i <= n; i += 2) {
		isComposite[i] = 1;
    }

	prime.push_back(2);

	for(i = 3; i <= n; i += 2) {
		if(isComposite[i] == 0) {
			prime.push_back(i);
			for(j = i*i; j <= n; j += 2*i) {
				isComposite[j] = 1;
			}
		}
	}
}

vector <int> segPrime;
void segmentedSieve(long long l, long long r) {
	bool isComposite[r-l+1] = {0};
	if(l == 1) isComposite[0] = 1;

	long long i, j;
	for(i = 0; prime[i]*prime[i] <= r; i++) {
		long long base = prime[i]*prime[i];
		if(base < l) base = ((l+prime[i]-1) / prime[i]) * prime[i];
		for(j = base; j <= r; j += prime[i]) {
			isComposite[j-l] = 1;
		}
	}
	for(i = 0; i <= r-l; i++) {
		if(isComposite[i] == 0) {
			segPrime.push_back(l+i);
        }
	}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); int testCase = 1;
    //cin >> testCase;
    while(testCase--) {

    	sieveOfEratosthenes(100000);//it would be root of r

        long long l, r;
        cin >> l >> r;
        segmentedSieve(l, r);

        for(auto i:segPrime) {
        	cout<<i<<"\n";
        }
    }
}