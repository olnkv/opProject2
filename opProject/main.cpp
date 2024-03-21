#include "func.h"

int main()
{
    cout << "Sveiki!" << endl;
    vector<User> stud;
    list<listUser> listStud;
    int choice;
    while (true)
    {
        cout << "Programos eigos pasirinkimas - (\"1\" - skaitymas is failu; \"2\" - duomenu isvedimas i ekrana; \"3\" - duomenu rusiavimas \"4\" - ivedimas ranka / generavimas; \"5\" - generuoti faila; \"6\" - rusiuoti faila; \"7\" - baigti darba): ";
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
                cout << "Programos eigos pasirinkimas - (\"1\" - skaitymas is failu; \"2\" - duomenu isvedimas i ekrana; \"3\" - duomenu rusiavimas \"4\" - ivedimas ranka / generavimas; \"5\" - generuoti faila; \"6\" - rusiuoti faila; \"7\" - baigti darba): ";
            }
        }

        if (choice == 7)
            exit(0);
        if (choice == 6)
            SortFile(stud);
        if (choice == 5)
            CreateFile();
        if (choice == 4)
            ReadUser(stud);
        if (choice == 3)
        {
            cout << "Konteinerio tipo pasirinikimas - (\"1\" - vector; \"2\" - list; \"3\" - deque): ";
            cin >> choice;
            if (choice == 1)
                SortChoice(stud);
            if (choice == 2)
                SortChoiceList(listStud);
        }
            SortChoice(stud);
        if (choice == 2)
            Result(stud);
        if (choice == 1)
        {
            cout << "Konteinerio tipo pasirinikimas - (\"1\" - vector; \"2\" - list; \"3\" - deque): ";
            cin >> choice;
            if (choice == 1)
                ReadFile(stud);
            if (choice == 2)
                ReadFileList(listStud);
        }
    }

    return 0;
}
