#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

struct User
{
    string name;    // vardas
    string surname; // pavarde
    vector<int> hwRes;   // namu darbu rezultatai
    int exRes;      // egzamino rezultatai
};

void Read(vector<User>& stud);    // skaitymo funkcija
// void Result(User stud[]);  // rezultatu isvedimo i ekrana funkcija
// double Average(User stud); // galutinio vidurkio skaiciavimo funkcija
// double Median(User stud);  // galutines medianos skaiciavimo funkcija

int main()
{
    vector<User> stud;
    

    Read(stud);
    for(const auto &i : stud)
    {
        cout<<i.name<<" "<<i.surname<<" "<<i.exRes;
        for(int value : i.hwRes)
            cout<<value;
    }

    return 0;
}

void Read(vector<User>& stud)
{
    string name, surname;
    int exRes, hw;
    vector<int> hwRes;
    while(true)
    {
        cout<<"name: ";
        cin>>name;
        if(name == "exit")
            break;
        cout<<"surname: ";
        cin>>surname;
        while(true)
        {
            cout<<"hwRes: ";
            cin>>hw;
            if(hw == -1)
            break;
            hwRes.push_back(hw);
        }
        cout<<"exRes: ";
        cin>>exRes;
        User temp;
        temp.name = name;
        temp.surname = surname;
        temp.hwRes = hwRes;
        temp.exRes = exRes;
        stud.push_back(temp);
    }
}

// void Result(User stud[])
// {
//     cout << "Pavarde    Vardas       Galutinis (Vid.)   /   Galutinis (Med.)" << endl;
//     cout << "--------------------------------------------------------------" << endl;
//     cout << fixed << setprecision(2);
//     for (int i = 0; i < N; i++)
//         cout << stud[i].name << setw(15) << right << stud[i].surname << setw(15) << right
//              << Average(stud[i]) << setw(15) << right << Median(stud[i]) << endl;
// }

// double Average(User stud)
// {
//     double avg;
//     for (int i = 0; i < H; i++)
//         avg += stud.hwRes[i];
//     avg = avg / H;
//     return 0.4 * avg + 0.6 * stud.exRes;
// }

// double Median(User stud)
// {
//     double med;
//     sort(stud.hwRes, stud.hwRes + H);
//     if (H % 2 != 0)
//         med = (double)stud.hwRes[H / 2];
//     med = (double)(stud.hwRes[(H - 1) / 2] + stud.hwRes[H / 2]) / 2.0;
//     return 0.4 * med + 0.6 * stud.exRes;
// }