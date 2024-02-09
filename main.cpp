#include <iostream>
#include <iomanip>

using namespace std;

const int N = 1;
const int H = 3;

struct User{
    string name;
    string surname;
    int hwRes[H];
    int exRes;
};

void Read(User stud[]);
void Result(User stud[]);

int main()
{
    User stud[N];

    Read(stud);
    Result(stud);

    return 0;
}

void Read(User stud[])
{
    for(int i = 0; i < N; i++)
    {
        cin>>stud[i].name>>stud[i].surname;
        for(int j = 0; j < H; j++)
            cin>>stud[i].hwRes[j];
        cin>>stud[i].exRes;
    }
}

void Result(User stud[])
{  
    cout<<"Pavarde    Vardas       Galutinis (Vid.)"<<endl;
    cout<<"----------------------------------------"<<endl;
    for(int i = 0; i < N; i++)
    {
        double avg;
        cout<<stud[i].name<<setw(15)<<right<<stud[i].surname<<setw(15)<<right;
        for(int j = 0; j < H; j++)
            avg += stud[i].hwRes[j];
        avg = avg / H;
        cout<<0.4 * avg + 0.6 * stud[i].exRes<<endl;
    }
}