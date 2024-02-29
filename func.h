#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct User
{
    string name;       // vardas
    string surname;    // pavarde
    vector<int> hwRes; // namu darbu rezultatai
    int exRes;         // egzamino rezultatai
};

const vector<string> nameList{"Nojus", "Domas", "Arvydas", "Rokas", "Vytautas", "Aurimas", "Joris", "Ramunas", "Povilas", "Mindaugas"};
const vector<string> surnameList{"Vaicekauskas", "Kateiva", "Kardauskas", "Zalionis", "Norkus", "Ozelis", "Stasiunas", "Oginskas", "Petrauskas", "Pakuckas"};
int paz, st; // generuojamu pazymiu ir studentu skaicius
string file; // failo pavadinimas

void SortChoice(vector<User> &stud);
int RandNumber();
void ReadFile(vector<User> &stud);
void ReadUser(vector<User> &stud);
void Result(vector<User> &stud);
double Average(User stud);
double Median(User stud);

void SortChoice(vector<User> &stud)
{
    int choice;
    cout << "Rusiavimo pasirinikimas - (\"1\" - pagal varda; \"2\" - pagal pavarde; \n\"3\" - pagal vidurkio galutini; \"4\" - pagal medianos galutini): ";
    cin >> choice;
    if (choice == 1)
        sort(stud.begin(), stud.end(), [](const User &a, const User &b)
             { return a.name < b.name; });
    if (choice == 2)
        sort(stud.begin(), stud.end(), [](const User &a, const User &b)
             { return a.surname < b.surname; });
    if (choice == 3)
        sort(stud.begin(), stud.end(), [](const User &a, const User &b)
             { return Average(a) < Average(b); });
    if (choice == 4)
        sort(stud.begin(), stud.end(), [](const User &a, const User &b)
             { return Median(a) < Median(b); });
}

int RandNumber()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);
    return dis(gen);
}

void ReadFile(vector<User> &stud)
{
    cout << "Irasykite failo varda (\"exit\", kad baigti darba): ";
    cin >> file;
    if (file == "exit")
        exit(0);
    ifstream rd(file);
    while (true)
    {
        try
        {
            if (!rd.is_open())
                throw runtime_error("Nepavyko atidaryti failo.");
            else
            {
                ifstream rd(file);
                break;
            }            
        }
        catch (const runtime_error &e)
        {
            cout << e.what() << endl;
            cout << "Irasykite failo varda (\"exit\", kad baigti darba): ";
            cin >> file;
            if (file == "exit")
                exit(0);
        }
    }

    string line;
    int grade;
    int num = 0;
    rd.ignore(1000, '\n');

    auto start = high_resolution_clock::now();
    while (getline(rd, line))
    {
        istringstream iss(line);
        User temp;
        iss >> temp.name >> temp.surname;
        while (iss >> grade)
        {
            if (iss.peek() == ' ')
                temp.hwRes.push_back(grade);
            else
                temp.exRes = grade;
        }
        stud.push_back(temp);
    }
    rd.close();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Nuskaitymo laikas: "
         << duration.count() << " mikrosekundes" << endl;
}

void ReadUser(vector<User> &stud)
{
    int hw;
    int choice;
    cout << "Programos eigos pasirinkimas -  (\"1\" - ivedimas ranka; \"2\" - generuoti pazymius; \"3\" - generuoti pazymius, bei studentu vardus; \"4\" - baigti darba): ";
    while (true)
    {
        try
        {
            cin >> choice;
            if (cin.fail())
                throw invalid_argument("Klaidinga ivestis");
            else
                break;
        }
        catch (const invalid_argument &ia)
        {
            cerr << ia.what() << '\n';
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Programos eigos pasirinkimas -  (\"1\" - ivedimas ranka; \"2\" - generuoti pazymius; \"3\" - generuoti pazymius, bei studentu vardus; \"4\" - baigti darba): ";
        }
    }

    if (choice == 4)
    {
        cout << "Programos uzdarymas" << endl;
        exit(0);
    }

    if (choice == 3)
    {
        cout << "Studentu skaicius: ";
        cin >> st;
        cout << "Namu darbu payzmiu skaicius: ";
        cin >> paz;
        for (int i = 0; i < st; i++)
        {
            User temp;
            temp.name = nameList[RandNumber() - 1];
            temp.surname = surnameList[RandNumber() - 1];
            for (int i = 0; i < paz; i++)
                temp.hwRes.push_back(RandNumber());
            temp.exRes = RandNumber();
            stud.push_back(temp);
        }
    }

    if (choice == 1 || choice == 2)
    {
        while (true)
        {
            User temp;
            cout << "Vardas (\"exit\", kad uzbaigti): ";
            cin >> temp.name;
            if (temp.name == "exit")
                break;
            cout << "Pavarde: ";
            cin >> temp.surname;

            if (choice == 2)
            {
                cout << "Namu darbu payzmiu skaicius: ";
                cin >> paz;
                for (int i = 0; i < paz; i++)
                    temp.hwRes.push_back(RandNumber());
                temp.exRes = RandNumber();
            }
            else
            {
                while (true)
                {
                    cout << "Namu darbu pazymys (\"-1\", kad uzbaigti): ";
                    cin >> hw;
                    if (hw == -1)
                        break;
                    temp.hwRes.push_back(hw);
                }
                cout << "Egzamino pazymys: ";
                cin >> temp.exRes;
            }
            stud.push_back(temp);
        }
    }
}

void Result(vector<User> &stud)
{
    cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Vid.)" << setw(15) << "Galutinis (Med.)" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << fixed << setprecision(2);
    for (const auto &i : stud)
        cout << left << setw(15) << i.surname << setw(15) << i.name << setw(20) << Average(i) << setw(15) << Median(i) << endl;
    // Ivesties patikrinimui
    // for (const auto &i : stud)
    // {
    //     cout << i.name << " " << i.surname << " ";
    //     for (int result : i.hwRes)
    //         cout << result << " ";
    //     cout << i.exRes << endl;
    // }
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

#endif
