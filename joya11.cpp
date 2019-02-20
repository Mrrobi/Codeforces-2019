#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100];
queue<int>q;
int color[100], dis[100],par[100];

void bfs(){
    int i,u,v;
while(!q.empty()){
    int v=q.front();
    q.pop();

    for(i=0;i<adj[v].size();i++){
        u=adj[v][i];
        if(color[u]==0){
            color[u]=1;
            dis[u]=dis[v]+1;
            par[u]=v;
            q.push(u);
        }
    }
    color[v]=2;
}
}

int main(){
    int n,node,e,u,v,source,i,flag=0;
for( i=0;i<100;i++){
        color[i]=0;
dis[i]= -1;
par[i]= -1;
}
 scanf("%d%d",&node,&e);
 for(i=0;i<e;i++){
    scanf("%d%d",&u,&v);
    adj[u].push_back(v);
    adj[v].push_back(u);
 }


 scanf("%d",&source);
 color[source]=1;
 dis[source]=0;
 q.push(source);
 bfs();

 for(i=0;i<e;i++){
   if(color[i]!=2){
        flag=1;
   break;
}

 }

if(flag==1){
    printf("not connected");
}

else{
    printf("connected");
}
}
