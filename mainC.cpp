#include <iostream>
#include <iomanip>
#include <algorithm>
#include <random>

using namespace std;

const int MAX_VALUE = 100;
const string nameList[] = {"Nojus", "Domas", "Arvydas", "Rokas", "Vytautas", "Aurimas", "Joris", "Ramunas", "Povilas", "Mindaugas"};
const string surnameList[] = {"Vaicekauskas", "Kateiva", "Kardauskas", "Zalionis", "Norkus", "Ozelis", "Stasiunas", "Oginskas", "Petrauskas", "Pakuckas"};
const int paz = 5; // pazymiu skaicius
const int st = 10; // generuojamu studentu skaicius

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
int RandNumber();                    // atstiktinio skaiciaus 1-10 generavimas

int main()
{
    User stud[MAX_VALUE];
    int count;

    Read(stud, count);
    Result(stud, count);

    return 0;
}

int RandNumber()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);
    return dis(gen);
}

void Read(User stud[], int &count)
{
    string name, surname;
    int hwRes[MAX_VALUE];
    int exRes, hw;

    int choice;
    cout << "Programos eigos pasirinkimas -  (\"1\" - ivedimas ranka; \"2\" - generuoti pazymius;\n\"3\" - generuoti pazymius, bei studentu vardus; \"4\" - baigti darba): ";
    cin >> choice;

    if (choice == 4)
    {
        cout << "Programos uzdarymas" << endl;
        exit(0);
    }

    if (choice == 3)
    {
        count = 0;
        for (int i = 0; i < st; i++)
        {
            name = nameList[RandNumber() - 1];
            surname = surnameList[RandNumber() - 1];
            for (int i = 0; i < paz; i++)
            {
                hwRes[i] = RandNumber();
                stud[count].hwCount++;
            }
            exRes = RandNumber();
            stud[count].name = name;
            stud[count].surname = surname;
            copy(begin(hwRes), end(hwRes), begin(stud[count].hwRes));
            stud[count].exRes = exRes;
            count++;
        }
    }

    if (choice == 1 || choice == 2)
    {
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
            if (choice == 2)
            {
                for (int i = 0; i < paz; i++)
                {
                    hwRes[i] = RandNumber();
                    stud[count].hwCount++;
                }
                exRes = RandNumber();
            }
            else
            {
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
            }

            stud[count].name = name;
            stud[count].surname = surname;
            copy(begin(hwRes), end(hwRes), begin(stud[count].hwRes));
            stud[count].exRes = exRes;
            count++;
        }
    }
}

void Result(User stud[], int count)
{
    cout << "Pavarde        Vardas    Galutinis (Vid.)   /   Galutinis (Med.)" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << fixed << setprecision(2);
    for (int i = 0; i < count; i++)
        cout << left << setw(15) << stud[i].surname << setw(15) << stud[i].name << setw(15) << Average(stud[i]) << setw(15) << Median(stud[i]) << endl;
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