#include<iostream>
#include<vector>
using namespace std;

int k;
vector<int> S;
vector<int> picked;

void print()
{
    for(int i = 0; i<6; i++)
    {
        cout<<S[picked[i]]<<" ";
    }
    cout<<endl;
}

void pick(int start, int idx)
{
    if(idx==6)
    {
        print();
        return;
    }
    else
    {
        int smallest = picked.empty() ? 0 : picked.back() + 1;
        for(int next = smallest ; next<k; ++next)
        {
            picked.push_back(next);
            pick(start+1, idx+1);
            picked.pop_back();
        }
    }
}

int main(){
    int input;
    while(cin>>k && k)
    {
        S.clear();
        for(int i = 0; i<k; i++)
        { 
            cin>>input;
            S.push_back(input);
        }
        pick(0,0);
        cout<<endl;
    }
}