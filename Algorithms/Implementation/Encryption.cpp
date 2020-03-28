#include <bits/c++config.h>
#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {

    string res;

    size_t l = s.size();

    // row and col of grid
    int r = floor(sqrt(l));
    int c = r+1;

    // adjust the size if smaller
    if (r*r == l) c=r;
    else if ((r*c) < l) r++;

    // implement the encryption algorithm
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            if ((j*c +i) < l)
                res.push_back(s[j*c +i]);
        }

        res.push_back(' ');
    }

    return res;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}