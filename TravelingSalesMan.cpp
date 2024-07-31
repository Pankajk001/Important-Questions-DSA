#include<bits/stdc++.h>
#define int long long
using namespace std;

int n = 4;
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
    if(mask == visited_mask){
        return dist[pos][0];
    }

    int ans = INT_MAX;

    //try to go to an unvisited city
    for(int city = 0; city < n; city++){
        //check is this city is visited or not using mask
        if((mask & (1 << city)) == 0){
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);

            ans = min(ans, newAns);
        }
    }

    return ans;
}

int_fast32_t main(){
    cout<<tsp(1, 0);
    return 0;
}

//the time complexity of the above code is n! which can be reduced to 2^n * n as mask can have 2^n distinct values and pos can have n different city, so total number of DP stactes can be DP[2^n][n];

