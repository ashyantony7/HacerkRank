#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the dayOfProgrammer function below.
string dayOfProgrammer(int year) {

    vector<int> months ={31, 28, 31, 30, 31, 30, 31, 31, 30};

    if (year < 1918){ // Julian
        if ((year%4)==0) months[2]++;

    }else if (year==1918){ // change
        months[2]=18;

    }else{ // Gregorian
        if (((year%400)==0) || 
                (((year%4)==0) && ((year%100)!=0)) )
            months[2]++;
    }

    int day=1, month=1, days=256;
    
    for(int i=0; i<months.size(); i++){
        if ((days-months[i]) > 0){
            month++;
            days -= months[i];
        }else{
            day=days;
            break;
        }
    }

    string day_str= to_string(day);
    string month_str= to_string(month);

    if (day < 10) day_str.insert(0, string("0"));

    if (month < 10) month_str.insert(0, string("0"));

    return string(day_str + "." + month_str + "." + to_string(year));
    

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
