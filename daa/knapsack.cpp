#include<iostream>

int max(int a, int b){
    return (a>b)?a:b;
}
int knapsack(int W,int v[],int w[],int n){
    //exit condition
    if(W==0 || n==0){
        return 0;
    }
    if(w[n-1]>W){
        return knapsack(W,v,w,n-1);
    }
    else{
        return max(v[n-1]+knapsack(W-w[n-1],v,w,n-1),knapsack(W,v,w,n-1));
    }

}
int main(){
    int value[] = {25,24,15,10};
    int weight[] ={18,15,10,5};
    int size = 20;
    int n=4;
    std::cout<<knapsack(size,value,weight,n)<<"\n";
    return 0;

}