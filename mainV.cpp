#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

struct User
{
    string name;       // vardas
    string surname;    // pavarde
    vector<int> hwRes; // namu darbu rezultatai
    int exRes;         // egzamino rezultatai
};

void Read(vector<User> &stud);   // skaitymo funkcija
void Result(vector<User> &stud); // rezultatu isvedimo i ekrana funkcija
double Average(User stud);       // galutinio vidurkio skaiciavimo funkcija
double Median(User stud);        // galutines medianos skaiciavimo funkcija

int main()
{
    vector<User> stud;

    Read(stud);
    Result(stud);

    return 0;
}

void Read(vector<User> &stud)
{
    string name, surname;
    int exRes, hw;
    vector<int> hwRes;
    while (true)
    {
        cout << "Vardas (\"exit\", kad uzbaigti): ";
        cin >> name;
        if (name == "exit")
            break;
        cout << "Pavarde: ";
        cin >> surname;
        while (true)
        {
            cout << "Namu darbu pazymys (\"-1\", kad uzbaigti): ";
            cin >> hw;
            if (hw == -1)
                break;
            hwRes.push_back(hw);
        }
        cout << "Egzamino pazymys: ";
        cin >> exRes;
        User temp;
        temp.name = name;
        temp.surname = surname;
        temp.hwRes = hwRes;
        temp.exRes = exRes;
        stud.push_back(temp);
    }
}

void Result(vector<User> &stud)
{
    cout << "Pavarde    Vardas       Galutinis (Vid.)   /   Galutinis (Med.)" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << fixed << setprecision(2);
    for (const auto &i : stud)
        cout << i.name << setw(15) << right << i.surname << setw(15) << right
             << Average(i) << setw(20) << right << Median(i) << endl;
}

double Average(User stud)
{
    double avg;
    for (const double &value : stud.hwRes)
        avg += value;
    avg = avg / stud.hwRes.size();
    return 0.4 * avg + 0.6 * stud.exRes;
}

double Median(User stud)
{
    double med;
    sort(stud.hwRes.begin(), stud.hwRes.end());
    if (stud.hwRes.size() % 2 != 0)
        med = (double)stud.hwRes[stud.hwRes.size() / 2];
    med = (double)(stud.hwRes[(stud.hwRes.size() - 1) / 2] + stud.hwRes[stud.hwRes.size() / 2]) / 2.0;
    return 0.4 * med + 0.6 * stud.exRes;
}