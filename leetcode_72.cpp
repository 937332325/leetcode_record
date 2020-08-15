//
// Created by 陈海斌 on 2020-07-23.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        int m = word1.size(), n = word2.size();
        for (int i=0; i<m+1;i++)
            dp[i][0] = i;
        for (int i=0; i<n+1;i++)
            dp[0][i] = i;
        for (int i=1; i<m+1;i++)
            for (int j=1; j<n+1;j++)
            {
                if (dp[i-1] == dp[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j]))+1;
            }
        return dp[m][n];
    }
};

/*
// O(n) space fast methods
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int pre = 0;
        vector<int> dp(word2.size()+1);
        for (int i=0; i<n+1;i++)
            dp[i] = i;
        for (int i=1; i<m+1;i++)
        {
            pre = dp[0];
            dp[0] = i;
            for (int j = 1; j <= n; j++)
            {
                int tmp = dp[j];
                if (word1[i - 1] == word2[j - 1])
                    dp[j] = pre;
                else
                    dp[j] = min(pre, min(dp[j - 1], dp[j])) + 1;
                pre = tmp;
            }
        }
        return dp[n];
    }
};
*/

/*
int main()
{
    Solution s;
    cout << s.minDistance("a", "b");
}
*/

/*
#include<iostream>
#include<queue>
using namespace std;
struct point{
    int x,y,s;
};
int a[105][105],n,m,x1,y1,x2,y2,v[105][105];
queue<point> q;

int kkkk(){
    int t; cin>>t;
    while(t--){
        cin>>m>>n>>y1>>x1>>y2>>x2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
                v[i][j]=0;
            }
        }
        while(!q.empty()) q.pop();
        if(x1==x2&&y1==y2){
            cout<<"1"<<endl; continue;
        }
        point p;
        p.x=x1; p.y=y1; p.s=1;
        q.push(p);
        bool flag=false;
        while(!q.empty()){
            p=q.front();
            q.pop();
            if(p.x<0||p.x>=n||p.y<0||p.y>=m) continue;
            if(v[p.x][p.y]||a[p.x][p.y]) continue;
            //cout<<p.x<<" "<<p.y<<endl;
            if(p.x==x2&&p.y==y2){
                flag=true;
                cout<<p.s<<endl;
                break;
            }
            v[p.x][p.y]=1;
            point p1; p1.x=p.x+1; p1.y=p.y; p1.s=p.s+1; q.push(p1);
            point p2; p2.x=p.x-1; p2.y=p.y; p2.s=p.s+1; q.push(p2);
            point p3; p3.x=p.x; p3.y=p.y+1; p3.s=p.s+1; q.push(p3);
            point p4; p4.x=p.x; p4.y=p.y-1; p4.s=p.s+1; q.push(p4);
        }
        if(!flag) cout<<-1<<endl;
    }
}


#include<iostream>
using namespace std;
int jjjj(){
    long long t,m,n,ans=0;
    cin>>t;
    while(t--){
        cin>>n>>m;
        if(n%(m+1)!=0) ans++;
    }
    cout<<ans;
}

vector<int> e[200005];
int n,a[200005],v[200005],ans=1,k[200005];
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
void f(int i,int now,int p){
    v[i]=1;
    if(now>ans) ans=now;
    for(int j=0;j<e[i].size();j++){
        if(!v[e[i][j]]&&k[e[i][j]]){
            int pp=gcd(p,gcd(a[i],a[e[i][j]]));
            if(pp>1) f(e[i][j],now+1,pp);
            else f(e[i][j],1,a[e[i][j]]);
        }
    }
}
int oooo(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        k[i]=0;
    }
    for(int i=0;i<n-1;i++){
        int x,y; cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<e[i].size();j++){
            if(gcd(a[i],a[e[i][j]])>1){
                k[i]=1; k[e[i][j]]=1;
                break;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) v[j]=0;
        if(k[i]&&e[i].size()==1) f(i,1,a[i]);
    }
    if(ans==1) cout<<0;
    else cout<<ans;
}
*/