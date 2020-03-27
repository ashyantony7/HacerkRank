#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int n) {

    for(int i=0;i<n; i++){
        for (int j=1; j <=n; j++){
            if (i <(n-j)) std::cout << " ";
            else std::cout << "#";
        }

        std::cout << std::endl;

    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
