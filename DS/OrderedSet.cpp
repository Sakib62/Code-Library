
//https://www.youtube.com/watch?v=f88s33eFGDo
//https://codeforces.com/blog/entry/11080

//Policy Based Data Structure

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using ordered_set = tree <T, null_type, less <T>,
							rb_tree_tag, tree_order_statistics_node_update>;

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//only for int

int main() {

	ordered_set<int> s; //similar to other container declaration.

	//ordered_set s; // like int a. all is declared by typedef But for int only.
					// whereas in class template, we can use any type of data type.
	
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.insert(6);

	cout << s.order_of_key(12) << "\n"; //number of items strictly smaller than k.
	cout << *s.find_by_order(4) << "\n"; //k'th element in the set. (0 based)
}