#include <iostream>
#include <vector>
using namespace std;

vector<pair<char, char>> tree[27];

int N;

void preorder(char root)
{
    char left = tree[root - 'A'].front().first;
    char right = tree[root - 'A'].front().second;

    cout << root;
    if (left != '.') preorder(left);
    if (right != '.') preorder(right);
}
void inorder(char root)
{
    char left = tree[root - 'A'].front().first;
    char right = tree[root - 'A'].front().second;

    if (left != '.') inorder(left);
    cout << root;
    if (right != '.') inorder(right);
}
void postorder(char root)
{
    char left = tree[root - 'A'].front().first;
    char right = tree[root - 'A'].front().second;

    if (left != '.') postorder(left);
    if (right != '.') postorder(right);
    cout << root;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char node, lnode, rnode;
        cin >> node >> lnode >> rnode;

        tree[node - 'A'].push_back(make_pair(lnode, rnode));
    }

    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
}