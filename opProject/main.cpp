#include "func.h"

int main()
{
    cout<<"Sveiki!"<<endl;
    vector<User> stud;
    int choice;
    while (true)
    {
        cout << "Programos eigos pasirinkimas - (\"1\" - skaitymas is failu; \"2\" - ivedimas ranka / generavimas; \"3\" - generuoti faila; \"4\" - rusiuoti faila; \"5\" - baigti darba): ";
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
                cout << "Programos eigos pasirinkimas - (\"1\" - skaitymas is failu; \"2\" - ivedimas ranka / generavimas; \"3\" - generuoti faila; \"4\" - rusiuoti faila; \"5\" - baigti darba): ";
            }
        }
        
        if (choice == 5)
            exit(0);
        if (choice == 4)
            SortFile(stud);
        if (choice == 3)
            CreateFile();
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
