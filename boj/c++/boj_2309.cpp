#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> dwarf;

int main(){
    for(int i = 0; i<9; i++)
    {
        int height;
        cin>>height;
        dwarf.push_back(height);
    }

    sort(dwarf.begin(),dwarf.end());

    int sum = 0;
    for(int i = 0; i<9; i++)
        sum += dwarf[i];
    
    int find_sum = sum-100;
    

    for(int i = 0; i<8; i++)
    {
        for(int j = i+1; j<9; j++)
        {
            if(dwarf[i]+dwarf[j] == find_sum){
                dwarf.erase(dwarf.begin()+i);
                dwarf.erase(dwarf.begin()+j-1);
                break;
            }
        }
    }

    for(int i = 0; i<dwarf.size(); i++)
        cout<<dwarf[i]<<endl;
}