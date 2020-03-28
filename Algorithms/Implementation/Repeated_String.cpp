#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {

    // number of 'a' in the string
    int a_in_string=count(s.begin(), s.end(), 'a');

    // (number of times full string in repeated) * number of a's
    long ans=(n/s.size())*a_in_string;

    // add number of 'a' s in the parital string
    ans += count(s.begin(), s.begin() + (n%s.size()), 'a');

    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}