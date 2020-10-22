// BUILD, UPDATE ,QUERY BINARY INDEXED TREE OR FENWICK TREE
#include <iostream>
using namespace std;
int a[1000];
int BIT[1000] = {0};
// Update Operation - We will use update to build BIT
void update(int i, int val, int N) {
    while (i <= N) {
        BIT[i] = max(val, BIT[i]);
        i += i & (-i);    // Moving in set bits of i
    }
}
// Build is to update every index that is initialy holding value 0 with new value in array
void buildBIT(int N) {
    for (int i = 1; i <= N; i++) {
        update(i, a[i], N);
    }
}
// Query the BIT
int query(int i) {
    int m = INT_MIN;
    while (i > 0) {
        m = max(m, BIT[i]);
        i -= (i & (-i));
    }
    return m;
}
int main() {
    int n, q;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    buildBIT(n);
    for (int i = 1; i <= n; i++) {
        cout << BIT[i] << ",";
    }
    cout << endl;
    update(1, 9, n);
    for (int i = 1; i <= n; i++) {
        cout << BIT[i] << ",";
    }
    cout << endl;
    cin >> q;
    while (q--) {
        int index;
        cin >> index;
        cout << query(index) << endl;
    }
    return 0;
}
