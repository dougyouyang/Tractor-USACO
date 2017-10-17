//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
pii haybale[50001];
int step[1002][1002];

int finish(int n)
{
     for(int i=0;i<=1001;i++){
         if(step[0][i]>0){
             cout << step[0][i]-1 << endl;
             return 0;
         }
         if(step[1001][i]>0){
             cout << step[1001][i]-1 << endl;
             return 0;
         }
         if(step[i][0]>0){
             cout << step[i][0]-1 << endl;
             return 0;
         }
         if(step[i][1001]>0){
             cout << step[i][1001]-1 << endl;
             return 0;
        }
     }
    return 1;
}

int check(int n)
{
    int i, re=0;
    for(i=1;i<=n;i++){
        if(step[haybale[i].first][haybale[i].second+1]>0)
            step[haybale[i].first][haybale[i].second]=0, re=i;
        if(step[haybale[i].first][haybale[i].second-1]>0)
            step[haybale[i].first][haybale[i].second]=0, re=i;
        if(step[haybale[i].first+1][haybale[i].second]>0)
            step[haybale[i].first][haybale[i].second]=0, re=i;
        if(step[haybale[i].first-1][haybale[i].second]>0)
            step[haybale[i].first][haybale[i].second]=0, re=i;
    }
    return re;
}

void floodfill(int x, int y, int steps, int n)
{
    queue<int> pox, poy;
    pox.push(x), poy.push(y);
    step[x][y]=steps;
    while(!pox.empty()){
        int curx=pox.front(), cury=poy.front();
        pox.pop(), poy.pop();
        step[curx][cury]=steps;
        if(curx<1 || cury<1 || curx>1000 || cury>1000)
            continue;
        if(step[curx][cury+1]==0)
            pox.push(curx), poy.push(cury+1), step[curx][cury+1]=steps;
        if(step[curx][cury-1]==0)
            pox.push(curx), poy.push(cury-1), step[curx][cury-1]=steps;
        if(step[curx+1][cury]==0)
            pox.push(curx+1), poy.push(cury), step[curx+1][cury]=steps;
        if(step[curx-1][cury]==0)
            pox.push(curx-1), poy.push(cury), step[curx-1][cury]=steps;
    }
}

int main()
{
    int n, x, y;
    int i, cnt=1;
    
    cin >> n >> x >> y;
    for(i=1;i<=n;i++)
        cin >> haybale[i].first >> haybale[i].second, step[haybale[i].first][haybale[i].second]=-1;
    
    floodfill(x, y, cnt, n);
    while(finish(n)){
        int po=check(n);
        floodfill(haybale[po].first, haybale[po].second, ++cnt, n);
    }
    
    return 0;
}
