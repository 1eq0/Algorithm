#include<iostream>
using namespace std;

void star(int size)
{
    if(size == 1) {
        cout<<"*";
    }
    else{
        int third = size/3;
        for(int i = 0; i<third; i++)
        {
            star(third);
        }
        cout<<endl;
        star(third);
        for(int i = 0 ; i<third; i++)
        {
            for(int j = 0; j<third; j++)
            {
                cout<<" ";
            }
            cout<<endl;
        }
        star(third);
        cout<<endl;
        for(int i = 0; i<third; i++)
        {
            star(third);
        }
    }
}

int main()
{
    int n;
    cin>>n;

    star(n);
}