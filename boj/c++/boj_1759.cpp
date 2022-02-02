#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int L,C;
vector<char> word;
vector<int> picked;

void printPicked()
{
    int vowel = 0; int con = 0;
    int idx;
    for(int i = 0; i<L; i++)
    {
        idx = picked[i];
        char c = word[idx];
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vowel++;
        else con++;
    }
    if(vowel>=1 && con>=2)
    {
        for(int i = 0; i<L; i++)
        {
            idx = picked[i];
            cout<<word[idx];
        }
        cout<<endl;
    }
}

void pick(int toPick)
{
    if(toPick==0) {printPicked(); return;} //�� �� ���Ұ� ������ ���
    else
    {
        int smallest = picked.empty() ? 0 : picked.back() + 1;
        for(int next = smallest ; next<C; ++next)
        {
            picked.push_back(next);
            pick(toPick-1);
            picked.pop_back();
        }
    }
}

int main()
{
    cin>>L>>C; //L:��ȣ���� C:��������

    char w;
    for(int i = 0; i<C; i++)
    {
        cin>>w;
        word.push_back(w);
    }
    sort(word.begin(),word.end());

    pick(L);
}