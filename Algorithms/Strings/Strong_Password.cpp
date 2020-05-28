#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    
    // bool values for criteria satisfaction
    bool digit=false, lc=false, uc=false, sp=false;
    int res= 0;

    // check the criteria the passowrd satisfies
    for (auto c: password){
        
        int i = int(c);

        if ((i >= 48) && (i <= 59)) 
            digit = true;
        else if ((i >= 97) && (i <= 122))
            lc = true;
        else if ((i >= 65) && (i <= 90))
            uc = true;
        else if (((i >= 32) && (i <= 47)) ||
                 ((i >= 58) && (i <= 64)) ||
                 ((i >= 123) && (i <= 127))) 
            sp = true;
    }

    // add number of required characters
    if (!digit) res++;
    if (!lc) res++;
    if (!uc) res++;
    if (!sp) res++;

    // minimum password length is 6
    // so add additional characters
    int newPassLen = password.size() + res;
    if (newPassLen< 6) {
        res += 6 - newPassLen;
    }

    return res;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
