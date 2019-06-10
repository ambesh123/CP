#include <bits/stdc++.h>

using namespace std;

pair<int,int> parent[10][10];
int cnt[10][10];
int mx;

void ini(){
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++){
            parent[i][j].first = i;
            parent[i][j].second= j;
            cnt[i][j]=1;
        }
        mx = 1;
}

pair<int,int> findR(int x, int y){
    if(parent[x][y].first == x && parent[x][y].second == y)return parent[x][y];
    parent[x][y] = findR(parent[x][y].first,parent[x][y].second);
    return parent[x][y];
}

void unn(int x1,int y1, int x2, int y2){
    pair<int,int> r1 = findR(x1,y1);
    pair<int,int> r2 = findR(x2,y2);
    if(r1==r2)return;
    parent[r1.first][r1.second].first = parent[r2.first][r2.second].first;
    parent[r1.first][r1.second].second = parent[r2.first][r2.second].second;
    cnt[r2.first][r2.second] = cnt[r2.first][r2.second] + cnt[r1.first][r1.second];
    if(cnt[r2.first][r2.second] > mx)mx = cnt[r2.first][r2.second];
}

int connectedCell(vector < vector<int> > matrix, int n, int m) {
       for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(matrix[i][j]){
                if(i<n-1 && matrix[i+1][j])unn(i,j,i+1,j);
                if(i<n-1 && j<m-1 && matrix[i+1][j+1])unn(i,j,i+1,j+1);
                if(j<m-1 && matrix[i][j+1])unn(i,j,i,j+1);
                if(i>0 && j<n-1 && matrix[i-1][j+1])unn(i,j,i-1,j+1);
            }
            
        }
    return mx;
}

int main() {
    ini();
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > matrix(n,vector<int>(m));
    for(int matrix_i = 0;matrix_i < n;matrix_i++){
       for(int matrix_j = 0;matrix_j < m;matrix_j++){
          cin >> matrix[matrix_i][matrix_j];
       }
    }
    int result = connectedCell(matrix,n,m);
    cout << result << endl;
    return 0;
}

