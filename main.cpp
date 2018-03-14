#include <iostream>
#include <vector>
#include <random>
#include <time.h>
using std::cout;
using std::vector;
using std::endl;

int main()
{
    vector<int> A;
    std::mt19937 m(time(NULL));
    std::uniform_int_distribution<int> d(0,200);
    int n=d(m)+1;
    for(int i=0; i<n; i++)
    {
        A.push_back(d(m));
    }
    int b=1;
    int a;
    for(int i:A)
    {
        a=1;
        while (i!=0)
        {
            if(i/10>0)
            {
                a++;
            }
            i=i/10;
        }
        if(a>b)
        {
            b=a; //b - didziausias skaitmenu skaicius
        }
    }
    a=1; //a dabar zymes dalikli
    for(int j=0; j<b; j++)
    {
        for(int i=0; i<n-1; i++)
        {
            if(((A[i]/a)%10)>((A[i+1]/a)%10))
            {
                A[i]=A[i]+A[i+1];
                A[i+1]=A[i]-A[i+1];
                A[i]=A[i]-A[i+1];
                i=-1;
            }
        }
        a=a*10;
    }
    for(int i=0; i<n; i++)
    {
        cout<<A[i]<<"\t";
    }
    return 0;
}
