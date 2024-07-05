#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//Top-Down Approach (Recursive with Memoization)
int solve1(vector<int>& value,vector<int>& weight,int index,int capacity,vector<vector<int>>& memo){
    if(index==0){
        if(weight[0]<=capacity){
        return value[0];
        }
        else
            return 0;
    }
    if(memo[index][capacity]!=-1){
        return memo[index][capacity];
    }
    int include=0;
    if(weight[index]<=capacity){
        include=value[index]+solve1(value,weight,index-1,capacity-weight[index],memo);
    }
    int exclude=0+solve1(value,weight,index-1,capacity,memo);
    memo[index][capacity]=max(include,exclude);
    return memo[index][capacity];
}

//Bottom-Up Approach (Iterative with Tabulation)
int solve2(vector<int>& value,vector<int>& weight,int index,int capacity){
    vector<vector<int>> memo(value.size(),vector<int>(capacity+1,0));
    int n=value.size();
    for(int w=weight[0];w<=capacity;w++){
        if(weight[0]<=capacity){
            memo[0][w]=value[0];
        }
        else{
            memo[0][w]=0;
        }
    }
    int include=0;
    for(int index=1;index<n;index++){
        for(int w=0;w<=capacity;w++){
            if(weight[index]<=w){
                include=value[index]+memo[index-1][w-weight[index]];
            }
            int exclude=0+memo[index-1][w];
            memo[index][w]=max(include,exclude);
        }
    }
    return memo[n-1][capacity];
}

int main(){
    int n,m;
    cin>>n;
    vector<int> weight(n);
    vector<int> value(n);
    for(int i=0;i<n;i++){
        cin>>value[i]>>weight[i];
    }
    int t;
    cin>>t;
    vector<vector<int>> memo(n, vector<int>(t + 1, -1));
    int ans1= solve1(value,weight,n-1,t,memo);//recursive function
    int ans2= solve2(value,weight,n-1,t);//tabulation method
    cout<<ans1<<ans2;  
}