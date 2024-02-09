#include <iostream>

using namespace std;

const int N = 2;
const int H = 10;

struct User{
    string name;
    string surname;
    int hwRes[H];
    int exRes;
};

void Read(User person[]);

int main()
{
    User person[N];

    return 0;
}

void Read(User person[])
{
    for(int i = 0; i < N; i++)
    {
        cin>>person[i].name>>person[i].surname;
        for(int j = 0; j < H; j++)
            cin>>person[i].hwRes[j];
        cin>>person[i].exRes;
    }
}