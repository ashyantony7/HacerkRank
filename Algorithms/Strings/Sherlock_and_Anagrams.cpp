#include <bits/stdc++.h>

using namespace std;

// number of possible combinations nCr
long nCr(int n, int r) 
{ 
    long den=1;
    for(int i=2;i<=r;i++) den *=i;

    long num=1;
    for(int i=n;i>(n-r);i--) num*=i;

    return num/den;
    
}

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {

    int res=0, l=s.size();

    // create a hashmap
    unordered_map<string, int> count;

    // get all possible substrings and store
    for(int i=1;i<l;i++){ // l of substring

        for(int j=0;j<l;j++){ // positions
            
            if ((j+i) <= l){
                string sub= s.substr(j, i);

                // sorting the substring and storing it
                sort(sub.begin(), sub.end());

                count[sub]++;
            }
        } 
    }
    
    // loop over map
    for(auto it=count.begin();it!=count.end();it++){
        if (it->second ==2)
            res ++;
        else if (it->second >2)
            res += nCr(it->second, 2); // possible combinations
    }

    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}