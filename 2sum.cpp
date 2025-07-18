
//T-n and s=1
//two pointer(only for sorted array)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[5] = {2,5,6,8,11};
    int t =8;
    int i=0;
    int j=4;
    while(i!=j && j>=0 && i<5 )
    {
       if(a[i]+a[j]==t)
       {
        cout<<i<<","<<j;
        break;
       }
       else if(a[i]+a[j]<t)
       {
        i++;
       }
       else
       {
        j--;
       }
    }
}
