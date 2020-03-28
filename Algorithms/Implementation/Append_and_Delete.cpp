#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {

    string output="No"; // initialize output with No

    int s_len = s.size(); // size of inital string
    int t_len = t.size(); // size of desired string

    // find position where mismatch occurs
    int pos=mismatch(s.begin(), s.end(), t.begin()).first - s.begin();

    if (pos==s_len){  // need to add string
        if (t_len >= s_len){

            // only insertion calculate extra actions
            int actions = k - (t_len-s_len);

            if ((actions >=0) && (actions%2==0)) output="Yes";
        }

    }else if(pos<s_len){

        // now we need to delete and then insert
        int actions = k - 2*(s_len-pos) - (t_len-s_len);


        if ((actions >=0) && (actions%2==0)) output="Yes";
    }

    // check possibile delete entire word and rewrite
    if (k >= (s_len + t_len)) output="Yes";

    return output;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}