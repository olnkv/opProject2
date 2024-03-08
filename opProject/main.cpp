#include "func.h"

int main()
{
    vector<User> stud;
    int choice;
    while(true)
    {
        cout << "Sveiki!\nProgramos eigos pasirinkimas - (\"1\" - skaitymas is failu; \"2\" - ivedimas ranka / generavimas; \"3\" - generuoti faila;  \"4\" - baigti darba): ";
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
        
        if (choice == 4)
            exit(0);
        if (choice == 3)
        {
            CreateFile();
            SortFile(stud);
        }
        if (choice == 2)
        {
            ReadUser(stud);
            SortChoice(stud);
            Result(stud);
        }
        if (choice == 1)
        {
            ReadFile(stud);
            SortChoice(stud);
            Result(stud);
        }
    }
    
    return 0;
}
