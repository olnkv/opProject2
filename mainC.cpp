#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

const int MAX_VALUE = 10;

struct User
{
    string name;          // vardas
    string surname;       // pavarde
    int hwRes[MAX_VALUE]; // namu darbu rezultatai
    int hwCount;          // namu darbu rezultatu skaicius
    int exRes;            // egzamino rezultatai
};

void Read(User stud[], int &count);  // skaitymo funkcija
void Result(User stud[], int count); // rezultatu isvedimo i ekrana funkcija
double Average(User stud);           // galutinio vidurkio skaiciavimo funkcija
double Median(User stud);            // galutines medianos skaiciavimo funkcija

int main()
{
    User stud[MAX_VALUE];
    int count;

    Read(stud, count);
    Result(stud, count);

    return 0;
}

void Read(User stud[], int &count)
{
    string name, surname;
    int hwRes[MAX_VALUE];
    int exRes, hw;
    count = 0;
    while (count < MAX_VALUE)
    {
        stud[count].hwCount = 0;
        cout << "Vardas (\"exit\", kad uzbaigti): ";
        cin >> name;
        if (name == "exit")
            break;
        cout << "Pavarde: ";
        cin >> surname;
        while (stud[count].hwCount < MAX_VALUE)
        {
            cout << "Namu darbu pazymys (\"-1\", kad uzbaigti): ";
            cin >> hw;
            if (hw == -1)
                break;
            hwRes[stud[count].hwCount] = hw;
            stud[count].hwCount++;
        }
        cout << "Egzamino pazymys: ";
        cin >> exRes;
        stud[count].name = name;
        stud[count].surname = surname;
        copy(begin(hwRes), end(hwRes), begin(stud[count].hwRes));
        stud[count].exRes = exRes;
        count++;
    }
}

void Result(User stud[], int count)
{
    cout << "Pavarde    Vardas       Galutinis (Vid.)   /   Galutinis (Med.)" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << fixed << setprecision(2);
    for (int i = 0; i < count; i++)
        cout << stud[i].name << setw(15) << right << stud[i].surname << setw(15) << right
             << Average(stud[i]) << setw(20) << right << Median(stud[i]) << endl;
}

double Average(User stud)
{
    double avg;
    for (int i = 0; i < stud.hwCount; i++)
        avg += stud.hwRes[i];
    avg = avg / stud.hwCount;
    return 0.4 * avg + 0.6 * stud.exRes;
}

double Median(User stud)
{
    double med;
    sort(stud.hwRes, stud.hwRes + stud.hwCount);
    if (stud.hwCount % 2 != 0)
        med = (double)stud.hwRes[stud.hwCount / 2];
    med = (double)(stud.hwRes[(stud.hwCount - 1) / 2] + stud.hwRes[stud.hwCount / 2]) / 2.0;
    return 0.4 * med + 0.6 * stud.exRes;
}