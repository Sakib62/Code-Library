//LowerBound of x:: returns the iterator of first value that is >= x
//UpperBound of x:: returns the iterator of first value that is > x

//data structure needs to be sorted

#include <bits/stdc++.h>
using namespace std;

int main() {

//Array//
    int a[6] = {2, 3, 4, 7, 11, 23};

    int* ptr1 = lower_bound(a, a + 6, 7);
    int* ptr2 = upper_bound(a, a + 6, 7);

    cout << *ptr1 << "\n"; //prints 7 
    cout << *ptr2 << "\n"; //prints 11

//Vector//
    vector <int> v = {2, 3, 4, 11, 15, 24};

    auto ptr3 = lower_bound(v.begin(), v.end(), 11);
    auto ptr4 = upper_bound(v.begin(), v.end(), 11);

    cout << *ptr3 << "\n"; //prints 11
    cout << *ptr4 << "\n"; //prints 15

//Map//
    map <int, int> mp = {{1, 2}, {3, 2}, {5, 11}};

    auto ptr5 = mp.lower_bound(1);
    auto ptr6 = mp.upper_bound(3);
    //same syntax also for set

    cout << ptr5->first << " " << ptr5->second << "\n"; // 1 2
    cout << ptr6->first << " " << ptr6->second << "\n"; // 5 11

//Set//
    set <int> s = {1, 2, 7, 14};

    auto ptr7 = s.lower_bound(2);
    auto ptr8 = s.upper_bound(2); 

    cout << *ptr7 << "\n"; // prints 2
    cout << *ptr8 << "\n"; // prints 7

/*
Syntax for map & set is same. Search based in key only. It works in logn
If we use the 'Syntax of vector' for map and set, that will work in O(n).

We can't customize search range in set or map as they are not indexed.
They are continous in nature, trees internally, not arrays.

For pair, there is no iterator, no lower bound & upper bound.
*/
}