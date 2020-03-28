#include <bits/stdc++.h>

using namespace std;

// function to find all the new unvisited squares by the Knight
set<pair<int, int>> knight_jump(int i, int j, int n, set<pair<int, int>> old_moves, vector<vector<bool>>& visited){

    set<pair<int, int>> new_moves;

    auto it=old_moves.begin();
    while(it!=old_moves.end()){

        int x=it->first, y=it->second;

        // top left diagonals
        if (((x-i)>=0) && ((y-j)>=0))
            if (!visited[x-i][y-j]){
                new_moves.insert(make_pair(x-i, y-j));
                visited[x-i][y-j]=true;
            }

        if (((x-j)>=0) && ((y-i)>=0))
            if (!visited[x-j][y-i]){
                new_moves.insert(make_pair(x-j, y-i));
                visited[x-j][y-i]=true;
            }

        //  top right diagonals
        if (((x-i)>=0) && ((y+j)<n))
            if (!visited[x-i][y+j]){
                new_moves.insert(make_pair(x-i, y+j));
                visited[x-i][y+j]=true;
            }
        
        if (((x-j)>=0) && ((y+i)<n))
            if (!visited[x-j][y+i]){
                new_moves.insert(make_pair(x-j, y+i));
                visited[x-j][y+i]=true;
            }

        // bottom left diagonals
        if (((x+i)<n) && ((y-j)>=0))
            if (!visited[x+i][y-j]){
                new_moves.insert(make_pair(x+i, y-j));
                visited[x+i][y-j]=true;
            }

        if (((x+j)<n) && ((y-i)>=0))
            if (!visited[x+j][y-i]){
                new_moves.insert(make_pair(x+j, y-i));
                visited[x+j][y-i]=true;
            }
        
        // bottom right diagonals
        if (((x+i)<n) && ((y+j)<n))
            if (!visited[x+i][y+j]){
                new_moves.insert(make_pair(x+i, y+j));
                visited[x+i][y+j]=true;
            }
        
        if (((x+j)<n) && ((y+i)<n))
            if (!visited[x+j][y+i]){
                new_moves.insert(make_pair(x+j, y+i));
                visited[x+j][y+i]=true;
            }
        it++;
    }

    return new_moves;
}

// Complete the knightlOnAChessboard function below.
vector<vector<int>> knightlOnAChessboard(int n) {

    // initialize result matrix as zeros
    vector<vector<int>> res(n-1, vector<int> (n-1, 0));

    // loop for matrix
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){

            // if the position has not yet been calculated
            if (!res[j-1][i-1]){

                // vector to store visit information
                vector<vector<bool>> visited(n, vector<bool> (n, false));

                visited[0][0]=true; // starting square
                
                // set to store the squares of moves
                set<pair<int,int>> moves; 
                moves.insert(make_pair(0, 0));

                int n_moves=0;

                while(moves.size()!=0){

                    // update moves
                    moves = knight_jump(i, j, n, moves, visited);
                    n_moves++;

                    // end if the last sqare is reached
                    if (moves.find(make_pair(n-1, n-1))!=moves.end()) break;

                }

                // update result
                if (moves.size()!=0) res[i-1][j-1]=n_moves;
                else res[i-1][j-1]=-1;
                
            }
            else
                // copy result 
                res[i-1][j-1]=res[j-1][i-1];
        }
    }

    return res;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> result = knightlOnAChessboard(n);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}