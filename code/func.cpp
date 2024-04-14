#include "func.h"

const vector<string> nameList{"Nojus", "Domas", "Arvydas", "Rokas", "Vytautas", "Aurimas", "Joris", "Ramunas", "Povilas", "Mindaugas"};
const vector<string> surnameList{"Vaicekauskas", "Kateiva", "Kardauskas", "Zalionis", "Norkus", "Ozelis", "Stasiunas", "Oginskas", "Petrauskas", "Pakuckas"};
int paz, st; // generuojamu pazymiu ir studentu skaicius
string file; // failo pavadinimas
auto start = high_resolution_clock::now();
auto stop = high_resolution_clock::now();
duration<double> cElapsed = duration<double>::zero();

void SortChoice(vector<User> &stud)
{
    int choice;
    cout << "Rusiavimo pasirinikimas - (\"1\" - pagal varda; \"2\" - pagal pavarde; \n\"3\" - pagal vidurkio galutini; \"4\" - pagal medianos galutini): ";
    cin >> choice;
    auto start = high_resolution_clock::now();
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
    auto stop = high_resolution_clock::now();
    duration<double> elapsed = stop - start;
    cout << "Duomenu rusiavimo laikas: " << elapsed.count() << " sekundes" << endl;
    cElapsed += elapsed;
}

void SortChoiceList(list<listUser> &stud)
{
    int choice;
    cout << "Rusiavimo pasirinikimas - (\"1\" - pagal varda; \"2\" - pagal pavarde; \"3\" - pagal vidurkio galutini): ";
    cin >> choice;
    auto start = high_resolution_clock::now();
    if (choice == 1)
        stud.sort([](const listUser &a, const listUser &b)
                  { return a.name < b.name; });
    if (choice == 2)
        stud.sort([](const listUser &a, const listUser &b)
                  { return a.surname < b.surname; });
    if (choice == 3)
        stud.sort([](const listUser &a, const listUser &b)
                  { return AverageList(a) < AverageList(b); });
    auto stop = high_resolution_clock::now();
    duration<double> elapsed = stop - start;
    cout << "Duomenu rusiavimo laikas: " << elapsed.count() << " sekundes" << endl;
    cElapsed += elapsed;
}

void SortChoiceDq(deque<dqUser> &stud)
{
    int choice;
    cout << "Rusiavimo pasirinikimas - (\"1\" - pagal varda; \"2\" - pagal pavarde; \"3\" - pagal vidurkio galutini): ";
    cin >> choice;
    auto start = high_resolution_clock::now();
    if (choice == 1)
        sort(stud.begin(), stud.end(), [](const dqUser &a, const dqUser &b)
             { return a.name < b.name; });
    if (choice == 2)
        sort(stud.begin(), stud.end(), [](const dqUser &a, const dqUser &b)
             { return a.surname < b.surname; });
    if (choice == 3)
        sort(stud.begin(), stud.end(), [](const dqUser &a, const dqUser &b)
             { return AverageDq(a) < AverageDq(b); });
    auto stop = high_resolution_clock::now();
    duration<double> elapsed = stop - start;
    cout << "Duomenu rusiavimo laikas: " << elapsed.count() << " sekundes" << endl;
    cElapsed += elapsed;
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
            ifstream rd(file);
        }
    }

    string line;
    int grade;
    rd.ignore(1000, '\n');
    auto start = high_resolution_clock::now();
    while (getline(rd, line))
    {
        istringstream iss(line);
        User temp;
        iss >> temp.name >> temp.surname;
        while (iss >> grade)
            temp.hwRes.push_back(grade);
        temp.exRes = temp.hwRes.back();
        temp.hwRes.pop_back();
        stud.push_back(temp);
    }
    rd.close();
    auto stop = high_resolution_clock::now();
    duration<double> elapsed = stop - start;
    cout << "Failo nuskaitymo laikas: " << elapsed.count() << " sekundes" << endl;
    cElapsed = elapsed;
}

void ReadFileList(list<listUser> &stud)
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
            ifstream rd(file);
        }
    }

    string line;
    int grade;
    rd.ignore(1000, '\n');
    auto start = high_resolution_clock::now();
    while (getline(rd, line))
    {
        istringstream iss(line);
        listUser temp;
        iss >> temp.name >> temp.surname;
        while (iss >> grade)
            temp.hwRes.push_back(grade);
        temp.exRes = temp.hwRes.back();
        temp.hwRes.pop_back();
        stud.push_back(temp);
    }
    rd.close();
    auto stop = high_resolution_clock::now();
    duration<double> elapsed = stop - start;
    cout << "Failo nuskaitymo laikas: " << elapsed.count() << " sekundes" << endl;
    cElapsed = elapsed;
}

void ReadFileDq(deque<dqUser> &stud)
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
            ifstream rd(file);
        }
    }

    string line;
    int grade;
    rd.ignore(1000, '\n');
    auto start = high_resolution_clock::now();
    while (getline(rd, line))
    {
        istringstream iss(line);
        dqUser temp;
        iss >> temp.name >> temp.surname;
        while (iss >> grade)
            temp.hwRes.push_back(grade);
        temp.exRes = temp.hwRes.back();
        temp.hwRes.pop_back();
        stud.push_back(temp);
    }
    rd.close();
    auto stop = high_resolution_clock::now();
    duration<double> elapsed = stop - start;
    cout << "Failo nuskaitymo laikas: " << elapsed.count() << " sekundes" << endl;
    cElapsed = elapsed;
}

void ReadUser(vector<User> &stud)
{
    int hw;
    int choice;
    cout << "Programos eigos pasirinkimas - (\"1\" - ivedimas ranka; \"2\" - generuoti pazymius; \"3\" - generuoti pazymius, bei studentu vardus; \"4\" - baigti darba): ";
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
            cout << "Programos eigos pasirinkimas - (\"1\" - ivedimas ranka; \"2\" - generuoti pazymius; \"3\" - generuoti pazymius, bei studentu vardus; \"4\" - baigti darba): ";
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
        while (true)
        {
            try
            {
                cin >> st;
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
                cout << "Studentu skaicius: ";
            }
        }
        cout << "Namu darbu payzmiu skaicius: ";
        while (true)
        {
            try
            {
                cin >> paz;
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
                cout << "Namu darbu payzmiu skaicius: ";
            }
        }
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
                while (true)
                {
                    try
                    {
                        cin >> paz;
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
                        cout << "Namu darbu payzmiu skaicius: ";
                    }
                }
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
    if (stud.size() < 1)
    {
        cout << "Nera duomenu vektoriaus masyve :(" << endl;
    }
    else
    {
        cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Vid.)" << setw(15) << "Galutinis (Med.)" << endl;
        cout << "------------------------------------------------------------------" << endl;
        cout << fixed << setprecision(2);
        for (const auto &i : stud)
            cout << left << setw(15) << i.surname << setw(15) << i.name << setw(20) << Average(i) << setw(15) << Median(i) << endl;
    }

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
    double avg = 0.0;
    avg = accumulate(stud.hwRes.begin(), stud.hwRes.end(), 0.0);
    avg /= stud.hwRes.size();
    return 0.4 * avg + 0.6 * stud.exRes;
}

double AverageList(listUser stud)
{
    double avg = 0.0;
    avg = accumulate(stud.hwRes.begin(), stud.hwRes.end(), 0.0);
    avg /= stud.hwRes.size();
    return 0.4 * avg + 0.6 * stud.exRes;
}

double AverageDq(dqUser stud)
{
    double avg = 0.0;
    avg = accumulate(stud.hwRes.begin(), stud.hwRes.end(), 0.0);
    avg /= stud.hwRes.size();
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

void CreateFile()
{

    cout << "Sukurkite failo pavadinima: ";
    cin >> file;
    cout << "Studentu skaicius: ";
    cin >> st;
    cout << "Pazymiu skaicius: ";
    cin >> paz;
    auto start = high_resolution_clock::now();
    ofstream out(file);
    out << left << setw(25) << "Vardas" << setw(25) << "Pavarde";
    for (int i = 0; i < paz; i++)
        out << left << setw(10) << "ND" + to_string(i) << " ";
    out << left << setw(10) << "Egz." << endl;
    for (int i = 0; i < st; i++)
    {
        out << left << setw(25) << "Vardas" + to_string(i) << setw(25) << "Pavarde" + to_string(i);
        for (int j = 0; j < paz; j++)
            out << left << setw(10) << RandNumber() << " ";
        out << left << setw(10) << RandNumber() << endl;
    }
    out.close();
    auto stop = high_resolution_clock::now();
    duration<double> elapsed = stop - start;
    cout << "Failo sukurimo laikas: "
         << elapsed.count() << " sekundes" << endl;
}

void SortFile(vector<User> &stud)
{
    vector<User> kiet;
    vector<User> varg;
    bool kExist = false;
    bool vExist = false;
    auto fullStart = high_resolution_clock::now();
    auto start = high_resolution_clock::now();

    for (int i = 0; i < stud.size(); i++)
        if (Average(stud[i]) >= 5.0)
        {
            kiet.push_back(stud[i]);
            kExist = true;
        }
    for (int i = 0; i < stud.size(); i++)
        if (Average(stud[i]) < 5.0)
        {
            varg.push_back(stud[i]);
            vExist = true;
        }
    //    for (int i = 0; i < stud.size(); i++)
    //        if (Average(stud[i]) >= 5.0)
    //            {
    //                kiet.push_back(stud[i]);
    //                stud.erase(stud.begin() + i);
    //                kExist = true;
    //            }
    //            else
    //            {
    //                i++;
    //                vExist = true;
    //            }
    //

    auto stop = high_resolution_clock::now();
    duration<double> elapsed = stop - start;
    cout << "Rusiavimo i dvi grupes laikas: "
         << elapsed.count() << " sekundes" << endl;
       start = high_resolution_clock::now();
       ofstream out1("Kietiakai.txt");
       if (kExist)
       {
           out1 << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Vid.)" << setw(15) << "Galutinis (Med.)" << endl;
           out1 << "------------------------------------------------------------------" << endl;
           out1 << fixed << setprecision(2);
           for (int i = 0; i < kiet.size(); i++)
               out1 << left << setw(15) << kiet[i].surname << setw(15) << kiet[i].name << setw(20) << Average(kiet[i]) << setw(15) << Median(kiet[i]) << endl;
       }
       else
           out1 << "Kietiaku nera :(";
       out1.close();
       stop = high_resolution_clock::now();
       elapsed = stop - start;
       cout << "Kietiaku irasymo laikas: "
            << elapsed.count() << " sekundes" << endl;
    
       start = high_resolution_clock::now();
       ofstream out2("Vargsiukai.txt");
       if (vExist)
       {
           out2 << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Vid.)" << setw(15) << "Galutinis (Med.)" << endl;
           out2 << "------------------------------------------------------------------" << endl;
           out2 << fixed << setprecision(2);
           for (int i = 0; i < varg.size(); i++)
               out1 << left << setw(15) << varg[i].surname << setw(15) << varg[i].name << setw(20) << Average(varg[i]) << setw(15) << Median(varg[i]) << endl;
       }
       else
           out2 << "Vargsiuku nera :)";
       out2.close();
       stop = high_resolution_clock::now();
       elapsed = stop - start;
       cout << "Vargsiuku irasymo laikas: "
            << elapsed.count() << " sekundes" << endl;
       auto fullStop = high_resolution_clock::now();
       elapsed = fullStop - fullStart;
       cout << "Testo laikas: "
            << elapsed.count() << " sekundes" << endl;
}

void SortFileList(list<listUser> &stud)
{
    list<listUser> kiet;
    list<listUser> varg;
    bool kExist = false;
    bool vExist = false;
    auto fullStart = high_resolution_clock::now();
    auto start = high_resolution_clock::now();

    for (auto it = stud.begin(); it != stud.end(); ++it)
    {
        if (AverageList(*it) >= 5.0)
        {
            kiet.push_back(*it);
            kExist = true;
        }
        else
        {
            varg.push_back(*it);
            vExist = true;
        }
    }

    auto stop = high_resolution_clock::now();
    duration<double> elapsed = stop - start;
    cout << "Rusiavimo i dvi grupes laikas: "
         << elapsed.count() << " sekundes" << endl;
       start = high_resolution_clock::now();
       ofstream out1("Kietiakai.txt");
       if (kExist)
       {
           out1 << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Vid.)" << setw(15) << "Galutinis (Med.)" << endl;
           out1 << "------------------------------------------------------------------" << endl;
           out1 << fixed << setprecision(2);
           for (const auto& i : kiet) {
               out1 << left << setw(15) << i.surname
               << setw(15) << i.name
               << setw(20) << AverageList(i) <<endl;
           }
       }
       else
           out1 << "Kietiaku nera :(";
       out1.close();
       stop = high_resolution_clock::now();
       elapsed = stop - start;
       cout << "Kietiaku irasymo laikas: "
            << elapsed.count() << " sekundes" << endl;
    
       start = high_resolution_clock::now();
       ofstream out2("Vargsiukai.txt");
       if (vExist)
       {
           out2 << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Vid.)" << setw(15) << "Galutinis (Med.)" << endl;
           out2 << "------------------------------------------------------------------" << endl;
           out2 << fixed << setprecision(2);
           for (const auto& i : varg) {
               out2 << left << setw(15) << i.surname
               << setw(15) << i.name
               << setw(20) << AverageList(i) <<endl;
           }
       }
       else
           out2 << "Vargsiuku nera :)";
       out2.close();
       stop = high_resolution_clock::now();
       elapsed = stop - start;
       cout << "Vargsiuku irasymo laikas: "
            << elapsed.count() << " sekundes" << endl;
       auto fullStop = high_resolution_clock::now();
       elapsed = fullStop - fullStart;
       cout << "Testo laikas: "
            << elapsed.count() << " sekundes" << endl;
}

void SortFileDq(deque<dqUser> &stud)
{
    deque<dqUser> kiet;
    deque<dqUser> varg;
    bool kExist = false;
    bool vExist = false;
    auto fullStart = high_resolution_clock::now();
    auto start = high_resolution_clock::now();

    for (auto it = stud.begin(); it != stud.end(); ++it)
    {
        if (AverageDq(*it) >= 5.0)
        {
            kiet.push_back(*it);
            kExist = true;
        }
        else
        {
            varg.push_back(*it);
            vExist = true;
        }
    }

    auto stop = high_resolution_clock::now();
    duration<double> elapsed = stop - start;
    cout << "Rusiavimo i dvi grupes laikas: "
         << elapsed.count() << " sekundes" << endl;
       start = high_resolution_clock::now();
       ofstream out1("Kietiakai.txt");
       if (kExist)
       {
           out1 << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Vid.)" << setw(15) << "Galutinis (Med.)" << endl;
           out1 << "------------------------------------------------------------------" << endl;
           out1 << fixed << setprecision(2);
           for (const auto& i : kiet) {
               out1 << left << setw(15) << i.surname
               << setw(15) << i.name
               << setw(20) << AverageDq(i) <<endl;
           }
       }
       else
           out1 << "Kietiaku nera :(";
       out1.close();
       stop = high_resolution_clock::now();
       elapsed = stop - start;
       cout << "Kietiaku irasymo laikas: "
            << elapsed.count() << " sekundes" << endl;
    
       start = high_resolution_clock::now();
       ofstream out2("Vargsiukai.txt");
       if (vExist)
       {
           out2 << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(20) << "Galutinis (Vid.)" << setw(15) << "Galutinis (Med.)" << endl;
           out2 << "------------------------------------------------------------------" << endl;
           out2 << fixed << setprecision(2);
           for (const auto& i : varg) {
               out2 << left << setw(15) << i.surname
               << setw(15) << i.name
               << setw(20) << AverageDq(i) <<endl;
           }
       }
       else
           out2 << "Vargsiuku nera :)";
       out2.close();
       stop = high_resolution_clock::now();
       elapsed = stop - start;
       cout << "Vargsiuku irasymo laikas: "
            << elapsed.count() << " sekundes" << endl;
       auto fullStop = high_resolution_clock::now();
       elapsed = fullStop - fullStart;
       cout << "Testo laikas: "
            << elapsed.count() << " sekundes" << endl;
}
