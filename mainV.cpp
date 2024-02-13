#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <random>

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
int RandNumber();                // atstiktinio skaiciaus 1-10 generavimas

int main()
{
    vector<User> stud;

    Read(stud);
    Result(stud);

    return 0;
}

int RandNumber()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);
    return dis(gen);
}

void Read(vector<User> &stud)
{
    string name, surname;
    int exRes, hw;
    vector<int> hwRes;

    int choice;
    cout << "Programos eigos pasirinkimas -  (\"1\" - ivedimas ranka; \"2\" - generuoti pazymius;\n\"3\" - generuoti ir pazymius ir studentu vardus; \"4\" - baigti darba): ";
    cin >> choice;

    if (choice == 4)
    {
        cout<<"Programos uzdarymas"<<endl;
        exit(0);
    }
        
    if (choice == 3)
    {
        //Nebuvo uzduotyje
        exit(0);
    }

    while (true)
    {
        cout << "Vardas (\"exit\", kad uzbaigti): ";
        cin >> name;
        if (name == "exit")
            break;
        cout << "Pavarde: ";
        cin >> surname;

        if (choice == 2)
        {
            int n = 5; // pazymiu skaicius
            for (int i = 0; i < 5; i++)
                hwRes.push_back(RandNumber());
            exRes = RandNumber();
        }
        else
        {
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
        }

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