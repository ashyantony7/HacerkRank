#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {

    size_t l = w.size(); // length of string

    // start with last character
    char start_c = w.back();

    bool possible= false;
    size_t pos_to_swap=l-1;

    // find the first character that can be swapped
    // starting from the penultimate character
    for(size_t it=l-2;it>=0;it--){

        if(w[it] < start_c){
            pos_to_swap=it;
            break;
        }
        start_c=w[it];
    }

    // starting from last char till the position to swap
    // check the first bigger char    
    for(int i=l-1;i>pos_to_swap;i--){
        if(w[i] > w[pos_to_swap]){

            // change possibility to true
            possible=true;

            // swap the characters
            swap(w[pos_to_swap], w[i]);

            break;
        }
    }

    if (possible){

        // sort characters after the swapped postion
        if ((w.begin()+pos_to_swap+1)<w.end())
            sort(w.begin()+pos_to_swap+1, w.end());

        return w;
    }
    else
        return string("no answer");
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
