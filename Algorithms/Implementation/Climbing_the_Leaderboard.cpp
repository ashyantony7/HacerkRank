#include <bits/stdc++.h>
#include <map>
#include <algorithm>

using namespace std;

vector<string> split_string(string);

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {

    //initialize output
    vector<int> rank;
    rank.reserve(alice.size());

    // make another vector which stores the ranks
    vector<int> ranking;
    ranking.reserve(scores.size());

    // Get the Dense ranking for the scores
    int score_old =INT_MAX, rank_old=0;
    for(int x:scores){
        if (x < score_old){
            rank_old++;
            score_old=x;
        }
        ranking.emplace_back(rank_old);
    }

    // known position is the current known position in leaderboard
    int known_pos = scores.size()-1;

    // current rank is the Dense rank corresponding to the position
    int current_rank = ranking[ranking.size()-1] + 1;

    // loop through Alice score and compare it to the leaderboard
    for(int x: alice){
        
        // to save time start from previous known position
        for (int i=known_pos;i>=0;i--){
            if (x < scores[i]){
                known_pos=i;
                break;
            }else{
                current_rank=ranking[i];
            }
        }
        rank.push_back(current_rank);
    }

    return rank;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
