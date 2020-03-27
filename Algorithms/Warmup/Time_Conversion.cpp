#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */

    int hours = stoi(s.substr(0, 2));

    if (s.compare(s.size()-2, 1, "P") == 0){

        if (hours!=12)
            s.replace(0, 2, to_string(hours+12));
    }else{
        if (hours==12)
            s.replace(0, 2, string("00"));
    }

    // delete last two characters
    s.pop_back();
    s.pop_back();

    return s;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
