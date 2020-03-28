#include <bits/stdc++.h>

using namespace std;

// 8 way connectivity
void add_connectivity(int i, int j, int r, int w, const vector<vector<int>>& matrix, set<pair<int, int>>& children){

    // top
    if (i>0)
        if (matrix[i-1][j]) children.insert(make_pair(i-1, j));

    // bottom
    if (i<(r-1))
        if (matrix[i+1][j]) children.insert(make_pair(i+1, j));

    // left
    if (j>0)
        if (matrix[i][j-1]) children.insert(make_pair(i, j-1));

    // right
    if (j<(w-1))
        if (matrix[i][j+1]) children.insert(make_pair(i, j+1));

    // top left
    if ((i>0) && (j>0))
        if (matrix[i-1][j-1]) children.insert(make_pair(i-1, j-1));

    // top right
    if ((i>0) && (j<(w-1)))
        if (matrix[i-1][j+1]) children.insert(make_pair(i-1, j+1));

    // bottom left
    if ((i<(r-1)) && (j>0))
        if (matrix[i+1][j-1]) children.insert(make_pair(i+1, j-1));

    // bottom right
    if ((i<(r-1)) && (j<(w-1)))
        if (matrix[i+1][j+1]) children.insert(make_pair(i+1, j+1));
}

// Complete the connectedCell function below.
int connectedCell(vector<vector<int>> matrix) {

    // length and width of the matrix
    size_t r=matrix.size();
    size_t w=matrix[0].size();

    // visited matrix
    vector<bool> v(r, false);
    vector<vector<bool>> visited(r, v);

    // set to store neighboring nodes of a node
    set<pair<int, int>> children;

    int max_conn=0; // result

    for(int i=0;i<r;i++){
        for(int j=0;j<w;j++){

            // if
            if ((!visited[i][j]) && (matrix[i][j]!=0)){
                children.insert(make_pair(i, j));

                // connectivity
                auto it=children.begin();
                while(it!=children.end()){

                    visited[it->first][it->second] = true;

                    add_connectivity(it->first, it->second, r, w, matrix, children);
                    it++;
                }

            }

            if (max_conn < children.size()) max_conn = children.size();

            children.clear();
        }
    }

    return max_conn;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> matrix(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = connectedCell(matrix);

    fout << result << "\n";

    fout.close();

    return 0;
}