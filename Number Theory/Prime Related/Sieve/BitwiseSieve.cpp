#include <bits/stdc++.h>
using namespace std;

vector <int> prime;
int isComposite[100000/32 + 2];

bool checkBit(int n, int pos) {
	return (bool) (n&(1<<pos));
}

int setBit(int n, int pos) {
	return n|=(1<<pos);
}

void bitwiseSieve(int n) {
	if(n>=2) prime.push_back(2);
	long long i, j;
	for(i = 3; i <= n; i += 2) {
		if(checkBit(isComposite[i/32], i%32) == 0) {
//if(checkBit(isComposite[i>>5], i&31) == 0) Works same. as i%32 = i&31
			prime.push_back(i);
			for(j = i*i; j <= n; j += 2*i) {
				isComposite[j/32] = setBit(isComposite[j/32], j%32);
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); int testCase = 1;
    //cin >> testCase;
    while(testCase--) {
        int n;
        cin >> n;
        bitwiseSieve(n);

        for(auto i:prime) {
        	cout << i << "\n";
        }
    }
}