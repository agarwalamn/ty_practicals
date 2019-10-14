#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter number of vertices!"<<endl;
    int v,e,t;
    cin>>v;
    cout<<"Enter number of edges!"<<endl;
    cin>>e;
    cout<<"Enter the type of your graph"<<endl;
    cout<<"Enter 1 for undirected graph"<<endl;
    cout<<"Enter 2 for directed graph"<<endl;
    cout<<"Enter 3 for weighted undirected graph"<<endl;
    cout<<"Enter 4 for weighted directed graph"<<endl;
    cin>>t;
    int arr[v][v];
     for (int i = 0; i < v; i++){
        for (int j = 0; j < v; j++){
            arr[i][j]=0;
        }
    }
    if(t==3 || t==4){
        for(int i=0;i<e;i++){
            int x,y,weight;
            cin>>x>>y>>weight;
            arr[x-1][y-1]=weight;
            // cout<<"edge value"<<e<<endl;
        }
    }
    else{
        for(int i=0;i<e;i++){
            int x,y;
            cin>>x>>y;
            arr[x-1][y-1]=1;
        }
    }
    if(t==1 || t==3){
        for (int i = 0; i < v; i++){
            for (int j = i+1; j < v; j++){
                arr[j][i]=arr[i][j];
            }
        }
    }
    for (int i = 0; i < v; i++){
        for (int j = 0; j < v; j++){
            cout<<arr[i][j]<<" ";
        }
    cout<<endl;
    }
    return 0;
}
