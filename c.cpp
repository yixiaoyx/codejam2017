#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char *argv[]) {
    int t, n, k,  max, min, d;
    priority_queue<int> q;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        cin >> k;
        d = n;
        if (k > n/2) {
            cout << "Case #" << i+1 << ": 0 0" << endl;
            continue;
        }
        for (int j = 0; j < k; j++) {
            max = d/2;
            min = d - max - 1;
            q.push(max);
            q.push(min);
            d = q.top();
            q.pop();
        }
        cout << "Case #" << i+1 << ": " << max << " " << min << endl;
    }
    return 0;
} 
