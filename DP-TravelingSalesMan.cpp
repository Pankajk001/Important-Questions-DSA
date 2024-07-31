#include<bits/stdc++.h>
#define int long long
using namespace std;

int n = 4;

//making DP array as dp[2^n][n];
int dp[16][4];

//Adj matrix which defines the graph
int dist[10][10] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}
};

//if al cities have been visited
int visited_mask = (1<<n) - 1;

int tsp(int mask, int pos){

    //base case --- when all the cities are visited
    if(mask == visited_mask) return dist[pos][1];
    
    if(dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INT_MAX;

    //try to go to an unvisited city
    for(int city = 0; city < n; city++){
        //check is this city is visited or not using mask
        if((mask & (1 << city)) == 0){
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);

            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int_fast32_t main(){

    for(int i = 0; i<(1<<n); i++){
        for(int j = 0; j<n; j++){
            dp[i][j] = -1;
        }
    }

    cout<<"Min weight hamiltonian path cost = "<<tsp(2, 1)<< endl;


    return 0;
}