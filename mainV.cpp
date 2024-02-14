//Kompiliavimo komanda mac'ui: clang++ -std=c++11 -stdlib=libc++ -o prog mainV.cpp
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

const vector<string> nameList{"Nojus", "Domas", "Arvydas", "Rokas", "Vytautas", "Aurimas", "Joris", "Ramunas", "Povilas", "Mindaugas"};
const vector<string> surnameList{"Vaicekauskas", "Kateiva", "Kardauskas", "Zalionis", "Norkus", "Ozelis", "Stasiunas", "Oginskas", "Petrauskas", "Pakuckas"};
const int paz = 5; // pazymiu skaicius

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
        cout << "Programos uzdarymas" << endl;
        exit(0);
    }

    if (choice == 3)
    {
        for (int i = 0; i < 10; i++)
        {
            name = nameList[RandNumber() - 1];
            surname = surnameList[RandNumber() - 1];
            for (int i = 0; i < paz; i++)
                hwRes.push_back(RandNumber());
            exRes = RandNumber();
            User temp;
            temp.name = name;
            temp.surname = surname;
            temp.hwRes = hwRes;
            temp.exRes = exRes;
            stud.push_back(temp);
        }
    }

    if (choice == 1 || choice == 2)
    {
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
}

void Result(vector<User> &stud)
{
    cout << "Pavarde        Vardas    Galutinis (Vid.)   /   Galutinis (Med.)" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << fixed << setprecision(2);
    for (const auto &i : stud)
        cout<<left<<setw(15)<<i.surname<<setw(15)<<i.name<<setw(15)<<Average(i)<<setw(15)<<Median(i)<<endl;
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