#include<bits/stdc++.h>
using namespace std;
int n,m;
bool check(int x,int y)
{
    if(x <= 0 || x>n || y<=0 || y>m)
        return false;
    return true;
}
int dx[]={-1,-2,-2,-1,1,2,2,1};
int dy[]={2,1,-1,-2,2,1,-1,-2};
//int n,m;
pair<int,int>src,des;
typedef pair<int,pair<int,int> > ipair;
int steps()
{
    queue<ipair>pq;
    bool visited[25][25]={{false}};
    visited[src.first][src.second]=true;
    pq.push({0,src});
    while(!pq.empty())
    {
        int distance=pq.front().first;
     //   cout<<distance<<endl;
        int sx=pq.front().second.first;
     //   cout<<"sx"<<sx<<endl;
        int sy=pq.front().second.second;
       // cout<<"sy"<<sy<<endl;
        pq.pop();
        if(des.first==sx && des.second==sy)
            return distance;
        for(int i=0;i<8;i++)
        {
            if(check(sx+dx[i],sy+dy[i]) && visited[sx+dx[i]][sy+dy[i]]==false)
            {
                pq.push({distance+1,{sx+dx[i],sy+dy[i]}});
                visited[sx+dx[i]][sy+dy[i]]=true;
            }
        }
    }
    return -1;

}
int main()
{
    int t,s1,s2,d1,d2;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cin>>s1>>s2>>d1>>d2;
        src={s1,s2};
        des={d1,d2};
        cout<<steps()<<endl;


    }
}
