#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the bfs function below.
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {

    // Initialize results with -1
    vector<int> res(n, -1);
    
    // vector to store the current edges 
    vector<vector<int>> edges_curr;

    // vector to store the current nodes
    vector<int> nodes_curr;
    nodes_curr.push_back(s);

    // vector to store visited information
    vector<bool> visited(n, false);
    visited[s-1]=true;


    int step=1;
    do{
        edges_curr.clear(); // clear the currene edges
        
        // add edges connected to the current nodes
        for(int& si: nodes_curr)
            copy_if(edges.begin(), edges.end(), inserter(edges_curr, edges_curr.end()), [visited, si](auto& v){
                return ((!visited[v[1]-1] && v[0]==si) || (!visited[v[0]-1] && v[1]==si));
            });

        nodes_curr.clear(); // clear nodes
        for(auto& x: edges_curr){
            
            // add new unvisited nodes from the edges
            if (!visited[x[0]-1]){
                nodes_curr.push_back(x[0]);

                visited[x[0]-1]=true;

                res[x[0]-1]=step*6;
            }else if (!visited[x[1]-1]){
                nodes_curr.push_back(x[1]);

                visited[x[1]-1]=true;

                res[x[1]-1]=step*6;
            }
        }

        step++;

    }while(!edges_curr.empty()); // loop untill new edges are available

    // remove result corresponding to starting position
    res.erase(res.begin()+(s-1));

    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = bfs(n, m, edges, s);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

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