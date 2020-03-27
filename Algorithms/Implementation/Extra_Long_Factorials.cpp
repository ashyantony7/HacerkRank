#include <bits/stdc++.h>

using namespace std;

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {

    map<long, long> results;
    
    results[1]=1;  // default result is 1

    /* number of digits in the reesult. Starts at 1 digit
         but increases as result gets bigger
    */
    int results_digits=1; 

    // loop over n
    for(int i=n;n>1;n--){

        // first multiply all values
        for(int j=1;j<=results_digits;j++)
            results[j] *= n;

        // adjust carry (push carry value to next digit)
        int k=1;
        while((k<=results_digits)){ 
            // do this in loop so that all carry is pushed
            if (results[k]/10){
                results[k+1] += results[k]/10;
                results[k] = results[k]%10;

                if (k==results_digits)
                    results_digits++;
            }
            k++;
        }

    }

    // Print out results digit by digit
    for(int i=results_digits;i>=1;i--)
        std::cout << results[i];

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
