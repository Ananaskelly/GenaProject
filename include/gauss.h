#include "vector"
#include "iostream"
using namespace std;
#define MIN_ROOT -100
#define MAX_ROOT 100
bool Gauss(vector<vector<double> > v,int n,int m,vector<double>& res)
{
    vector<pair<double,double> > mains;
    res.assign(n,0);
    int t=0,j=0;
    for(j=0;j<m&&t<n;t++)
    {
        double main_el=0;
        int cur=-1;
        for(int i=j;i<m;i++)
            if(abs(v[i][t])>main_el)
        {
            main_el=abs(v[i][t]);
            cur=i;
        }
            if(cur!=-1)
            swap(v[cur],v[t]);
            else
            {
                res[t]=MIN_ROOT+rand()%(MAX_ROOT-MIN_ROOT);
                continue;
            }
            mains.push_back(make_pair(j,t));
            for(int i=j+1;i<m;i++)
                for(int k=n;k>=j;k--)
                {
                    v[i][k]-=v[j][k]*(v[i][t]/v[j][t]);
                }
            j++;
    }
    for(int i=m;i<n;i++)
        res[i]=MIN_ROOT+rand()%(MAX_ROOT-MIN_ROOT);
    for(int i=mains.size()-1;i>=0;i--)
    {
        double r=v[mains[i].first][n];
        for(int j=mains[i].second+1;j<n;j++)
            r-=v[mains[i].first][j]*res[j];
        res[mains[i].second]=r/v[mains[i].first][mains[i].second];
    }
    for(int i=mains[mains.size()-1].first+1;i<m;i++)
    {
        double r=0;
        for(int j=0;j<n;j++)
            r+=v[i][j]*res[j];
        if(r!=v[i][n])
            return 0;
    }
return 1;
}
