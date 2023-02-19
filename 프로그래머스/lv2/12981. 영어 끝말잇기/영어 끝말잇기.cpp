#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0,0};
    set<string> st;
    
    st.insert(words[0]);
    for(int i = 1; i<words.size(); i++){
        string cur = words[i];
        string prev = words[i-1];
        if(cur.size() == 1 || st.count(cur) || cur[0] != prev[prev.size()-1]){
            answer[0] = i%n+1;
            answer[1] = i/n+1;
            break;
        }
        else st.insert(cur);
    }

    return answer;
}