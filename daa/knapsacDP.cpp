#include<iostream>

int max(int a, int b){
    return (a>b)?a:b;
}
int knapsack(int W,int v[],int wt[],int n){
    int k[n+1][W+1];
    int i,w;
    for ( i = 0; i <= n; i++)
    {
        for ( w = 0; w <= W; w++)
        {   
            if(i==0 || w==0){
                k[i][w]=0;
            }
            else if(wt[i-1]<=w){
                k[i][w]=max(v[i-1]+k[i-1][w-wt[i-1]],k[i-1][w]);
            }
            else{
                k[i][w]=k[i-1][w];
            }
        }
    }
    for ( i = 0; i <= n; i++)
    {
        for ( w = 0; w <= W; w++)
        {   
            std::cout<<k[i][w]<<" ";
        }
        std::cout<<"\n";
        
    }
    return k[n][W];

}
int main(){
    int value[] = {25,24,15,10};
    int weight[] ={18,15,10,5};
    int size = 20;
    int n=4;
    std::cout<<knapsack(size,value,weight,n)<<"\n";
    return 0;

}