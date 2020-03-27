#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {

    int sea_level=0, sea_level_old = 0;
    bool valley_start = false;
    int valleys=0;

    for(int it=0; it < s.size(); it++){

        if (s.compare(it, 1, "D")==0) sea_level--;
        else sea_level++;

        if (!valley_start){
            if ((sea_level_old >=0) && (sea_level<0))
                valley_start = true;
        }else{
            if ((sea_level_old <0) && (sea_level>=0)){
                valley_start = false;
                valleys++;
            }
        }

        sea_level_old = sea_level;
    }

    return valleys;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
