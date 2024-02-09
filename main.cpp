#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

const int N = 1;
const int H = 3;

struct User
{
    string name;
    string surname;
    int hwRes[H];
    int exRes;
};

void Read(User stud[]);
void Result(User stud[]);
double Average(User stud);
double Median(User stud);

int main()
{
    User stud[N];

    Read(stud);
    Result(stud);

    return 0;
}

void Read(User stud[])
{
    for (int i = 0; i < N; i++)
    {
        cin >> stud[i].name >> stud[i].surname;
        for (int j = 0; j < H; j++)
            cin >> stud[i].hwRes[j];
        cin >> stud[i].exRes;
    }
}

void Result(User stud[])
{
    cout << "Pavarde    Vardas       Galutinis (Vid.)      Galutinis (Med.)" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << fixed << setprecision(2);
    for (int i = 0; i < N; i++)
        cout << stud[i].name << setw(15) << right << stud[i].surname << setw(15) << right
             << Average(stud[i]) << setw(15) << right << Median(stud[i]) << endl;
}

double Average(User stud)
{
    double avg;
    for (int i = 0; i < H; i++)
        avg += stud.hwRes[i];
    avg = avg / H;
    return 0.4 * avg + 0.6 * stud.exRes;
}

double Median(User stud)
{
    double med;
    sort(stud.hwRes, stud.hwRes + H);
    if (H % 2 != 0)
        med = (double)stud.hwRes[H / 2];
    med = (double)(stud.hwRes[(H - 1) / 2] + stud.hwRes[H / 2]) / 2.0;
    return 0.4 * med + 0.6 * stud.exRes;
}