// Kompiliavimo komanda mac'ui: clang++ -std=c++11 -stdlib=libc++ -o prog main.cpp
// Neveikia g++ -g main.cpp -o main -lm
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include "func.h"

using namespace std;
using namespace std::chrono;

int main()
{
    vector<User> stud;
    int choice;
    cout << "Sveiki!\nProgramos eigos pasirinkimas - (\"1\" - skaitymas is failu; \"2\" - ivedimas ranka / generavimas; \"3\" - baigti darba): ";
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
            cout << "Sveiki!\nProgramos eigos pasirinkimas - (\"1\" - skaitymas is failu; \"2\" - ivedimas ranka / generavimas; \"3\" - baigti darba): ";
        }
    }

    if (choice == 3)
        exit(0);
    if (choice == 2)
    {
        ReadUser(stud);
        SortChoice(stud);
        Result(stud);
    }
    if (choice == 1)
    {
        string fileName;
        ReadFile(stud);
        SortChoice(stud);
        Result(stud);
    }

    return 0;
}
