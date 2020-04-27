#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    // get number of queries
    int n, action, val, maxVal = 0;
    cin >> n; 

    stack<int> s;

    for (int i=0; i<n;i++){
        cin >> action;
        switch (action) {
            case 1:
                // push
                cin >> val;
                maxVal = max(maxVal, val);
                s.push(maxVal);
                break;
            case 2:
                // pop
                s.pop();
                if (!s.empty()) maxVal = s.top();
                else maxVal = 0;
                break;
            case 3:
                //print
                cout << s.top() << endl;
        }
    }

    return 0;
}