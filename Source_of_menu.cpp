#include "Header_of_menu.h"
#include <thread>
#include <chrono>
#include <fstream>

menu::menu()
{
    numberOfMap = 0;
    NumberOfctPlayer = 0;
    NumberOfTerroristPlayer = 0;
    MoneyOfctPlayer = 0;
    MoneyOfterroristPlayer = 0;
    flag = 0;
}

vector <user> menu::loaduser()
{
    vector <user> users;
    string username;
    string nickname;
    string password;
    fstream file1("users.txt", ios::in);
    while (file1 >> username >> nickname >> password)
    {
        users.push_back(user(username, nickname, password));
    }
    file1.close();
    return users;
}

bool menu::CheckUsername(string inputusername)
{
    vector <user> users = loaduser();
    for (int i = 0;users.size() > i;++i)
    {
        if (users[i].get_username() == inputusername)
        {
            return false;
        }
    }
    return true;
}

bool menu::CheckPassword(string inputpassword)
{
    vector <user> users = loaduser();
    for (int i = 0;users.size() > i;++i)
    {
        if (users[i].get_password() == inputpassword)
        {
            return false;
        }
    }
    return true;
}

bool menu::Checkrepeatpass(string pass1,string pass2)
{
    if (pass1 == pass2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool menu::CheckNickname(string inputnickname)
{
    vector <user> users = loaduser();
    for (int i = 0;users.size() > i;++i)
    {
        if (users[i].get_nickname() == inputnickname)
        {
            return false;
        }
    }
    return true;
}

bool menu::startmenu()
{
    int choice;
    cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t1:SIGN IN" << endl;
    cout << "\n\n\n\t\t\t\t\t\t\t2:SIGN UP" << endl;
    cin >> choice;
    if (choice == 1)
    {
        return this->signin();
    }
    else
    {
        this->signup();
        return false;
    }
}

bool menu::signin()
{
    vector <user> users = loaduser();

    string inputusername;
    string inputnickname;
    string inputpassword;

    system("cls");
    cout << "\n\n\n\n\n\n\t\t\t\t\tPlease enter your username." << endl;
    cin >> inputusername;
    system("cls");
    cout << "\n\n\n\n\n\n\t\t\t\t\tPlease enter your nickname." << endl;
    cin >> inputnickname;
    system("cls");
    cout << "\n\n\n\n\n\n\t\t\t\t\tPlease enter your password." << endl;
    cin >> inputpassword;
    string passhashinput = hash(inputpassword);

    for (int i = 0;users.size() > i;++i)
    {
        if (users[i].get_username() == inputusername && users[i].get_nickname() == inputnickname && users[i].get_password() == passhashinput)
        {
            system("cls");
            cout << "\n\n\n\n\n\t\t\t\t\t\tLOGIN SUCCESSFUL." << endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
            sett_nameuser(inputusername);
            return true;
        }
    }
    system("cls");
    cout << "\n\n\n\n\n\t\t\t\t\tIncorrect credentials! Please wait..." << endl;
    return false;
}

void menu::signup()
{
    fstream file1("users.txt", ios::app);

    string usern;
    string nickn;
    string pass;
    string repeatpass;
    system("cls");
    cout << "\n\n\n\n\n\n\t\t\t\t\tPlease enter your username." << endl;
    cin >> usern;
    while (!this->CheckUsername(usern))
    {
        system("cls");
        cout << "\n\n\n\n\n\n\t\t\t\t\tYour Username already exist.Please try egain." << endl;
        cin >> usern;
    }
    system("cls");
    cout << "\n\n\n\n\n\n\t\t\t\t\tPlease enter your nickname." << endl;
    cin >> nickn;
    while (!this->CheckNickname(nickn))
    {
        system("cls");
        cout << "\n\n\n\n\n\n\t\t\t\t\tYour Nickname already exist.Please try egain." << endl;
        cin >> nickn;
    }
    bool temp = false;
    while (!temp)
    {
        system("cls");
        cout << "\n\n\n\n\n\n\t\t\t\t\tPlease enter your password." << endl;
        cin >> pass;
        while (!this->CheckPassword(pass))
        {
            system("cls");
            cout << "\n\n\n\n\n\n\t\t\t\t\tYour Password already exist.Please try egain." << endl;
            cin >> pass;
        }
        system("cls");
        cout << "\n\n\n\n\n\n\t\t\t\t\tPlease re-enter your password." << endl;
        cin >> repeatpass;
        temp = Checkrepeatpass(pass, repeatpass);
        if (!temp)
        {
            system("cls");
            cout << "\n\n\n\n\n\n\t\t\t\t\tThe password and its repetition did not match.Please try again." << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
        }
    }
    string passhash = hash(pass);
    user newuser(usern, nickn, passhash);
    file1 << newuser.get_username() << " " << newuser.get_nickname() << " " << newuser.get_password() << endl;
    file1.close();

    system("cls");
    cout << "\n\n\n\n\n\n\t\t\t\t\tSIGNUP WAS SUCCESSFULLY. Please wait..." << endl;
}

void menu::showMainMenu()
{
    while (!this->startmenu())
    {
        this_thread::sleep_for(chrono::milliseconds(4000));
        system("cls");
        continue;
    }
    system("cls");
    cout << "\n\n\n\n\n\t\t\t\t\t\tPlease wait..." << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));
    int choice;
    do {
        system("cls");
        cout << "\n\n\n\n\t\t\t\t\t----------- Main Menu -----------" << endl;
        cout << "\n\t\t\t\t\t1. Start Game" << endl;
        cout << "\n\t\t\t\t\t2. Settings" << endl;
        cout << "\n\t\t\t\t\t3. History" << endl;
        cout << "\n\t\t\t\t\t4. Information of player" << endl;
        cout << "\n\t\t\t\t\t0. Exit" << endl;
        //cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            startGame();
            break;
        case 2:
            showSettings();
            break;
        case 3:
            showHistory();
            break;
        case 4:
            showInformation();
            break;
        case 0:
            cout << "Exiting the program..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            pause();
        }
    } while (choice != 0);
}

void menu::startGame()
{
    if (flag == 0)
    {
        system("cls");
        cout << "\n\n\n\n\t\t\t\t\tPlease enter the game settings first." << endl;
        pauseWithReturn();
        return;
    }
    system("cls");
    random r;
    cout << "\n\n\n\n\n\t\t\t\tStarting game..." << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));
    system("cls");

    Gun g1, g2, g3, g4, g5, g6, g7, g8, g9, g10, g11, g12, g13, g14, g15, g16, g17, g18, g19, g20;

    vector <Gun> guns = { g1, g2, g3, g4, g5, g6, g7, g8, g9, g10, g11, g12, g13, g14, g15, g16, g17, g18, g19, g20 };

    srand(time(0));

    for (int i = 0;guns.size() > i;++i)
    {
        guns[i].set_ammo(r.random_ammocountOfGun());
        guns[i].set_ID(r.random_idOfGun());
        guns[i].set_name(r.random_nameOfGun());
        guns[i].set_power(r.random_powerOfGun());
        //guns[i].set_price(r.random_priceOfGun());
    }

    vector<int> manualPrices = { 1200, 1500, 1800, 1000, 2500, 2000, 3000, 1100, 2700, 1400,
                             1600, 1900, 2300, 1300, 2100, 2400, 1700, 2600, 2200, 2800 };

    for (int i = 0; i < guns.size(); ++i) {
        guns[i].set_price(manualPrices[i]);
    }


    r.sett_availableGuns(guns);

    vector <ct> vectorOfCtPlayer;
    vector <terrorist> vectorOfTerroristPlayer;

    vector <string> v1;
    vector <int> v2;



    for (int i = 0;NumberOfctPlayer > i;++i)
    {
        ct new_ct;
        int money = MoneyOfctPlayer;
        int rand_GunCount = r.random_GunCount();
        for (int j = 0; j < rand_GunCount; ++j)
        {
            Gun temp = r.random_gun_based_on_money(money);
            if (money >= temp.get_price()) {
                money -= temp.get_price();
                new_ct.AddGun(temp);
                v1.push_back(temp.get_name());
                v2.push_back(temp.get_Id());
            }
        }
        new_ct.sett_nameOFplayer(r.random_nameOfplayer());
        new_ct.sett_idOFGun(v2);
        new_ct.sett_nameOFGun(v1);
        new_ct.sett_Health(r.random_Health());
        new_ct.sett_Armor(r.random_Armor());
        new_ct.sett_Alive(true);
        new_ct.sett_Bot(r.random_bool());
        new_ct.sett_money(MoneyOfctPlayer);
        new_ct.sett_GunCount(rand_GunCount);
        new_ct.sett_has_kit(r.random_bool());
        new_ct.sett_disposalBomb(false);
        vectorOfCtPlayer.push_back(new_ct);
        v1.clear();
        v2.clear();
    }

    for (int i = 0;NumberOfTerroristPlayer > i;++i)
    {
        terrorist new_t;
        int money = MoneyOfterroristPlayer;
        int rand_GunCount = r.random_GunCount();
        for (int j = 0; j < rand_GunCount; ++j)
        {
            Gun temp = r.random_gun_based_on_money(money);
            if (money >= temp.get_price()) {
                money -= temp.get_price();
                new_t.AddGun(temp);
                v1.push_back(temp.get_name());
                v2.push_back(temp.get_Id());
            }
        }
        new_t.sett_nameOFplayer(r.random_nameOfplayer());
        new_t.sett_idOFGun(v2);
        new_t.sett_nameOFGun(v1);
        new_t.sett_Health(r.random_Health());
        new_t.sett_Armor(r.random_Armor());
        new_t.sett_Alive(true);
        new_t.sett_Bot(r.random_bool());
        new_t.sett_money(MoneyOfterroristPlayer);
        new_t.sett_GunCount(rand_GunCount);
        new_t.sett_hasBomb(r.random_bool());
        new_t.sett_plantingBomb(false);
        vectorOfTerroristPlayer.push_back(new_t);
        v1.clear();
        v2.clear();
    }
    gamemanager* manageGame = gamemanager::get_ins();
    manageGame->reset();
    manageGame->sett_vec_ct(vectorOfCtPlayer);
    manageGame->sett_vec_terrorist(vectorOfTerroristPlayer);
    for (int i = 0;maps.size() > i;++i)
    {
        if (numberOfMap - 1 == i)
        {
            maps[i].sett_night(r.random_bool());
            maps[i].sett_snow(r.random_bool());
            manageGame->sett_map_of_game(maps[i]);
        }
    }
    manageGame->startfight();

    sett_NumOfResualt(manageGame->get_resualt());
    saveresualt();

    pauseWithReturn();
}

void menu::showSettings()
{
    system("cls");
    cout << "\n\n\n\n\t\t\t\t\t\t--- Settings ---" << endl;

    random r;

    map map1("VertexForge", "de_sandrift", r.random_bool(), r.random_bool());
    map map2("DustPixel", "de_rustline", r.random_bool(), r.random_bool());
    map map3("Mapitect", "de_vanguard", r.random_bool(), r.random_bool());
    map map4("GeoSmith", "de_ashport", r.random_bool(), r.random_bool());
    map map5("SectorZero Studios", "de_fort1848", r.random_bool(), r.random_bool());
    maps.push_back(map1);
    maps.push_back(map2);
    maps.push_back(map3);
    maps.push_back(map4);
    maps.push_back(map5);
    
    cout << "\n\t\t\t\t\tPlease Enter Number Of Map." << endl;
    cout << "\n\t\t\t\t\t1.name of Map Number 1: " << map1.get_nameOFmap() << "\n\n\t\t\t\t\t2.name of Map Number 2 : " << map2.get_nameOFmap()
        << "\n\n\t\t\t\t\t3.name of Map Number 3 : "<< map3.get_nameOFmap() << "\n\n\t\t\t\t\t4.name of Map Number 4 : " << map4.get_nameOFmap()
        << "\n\n\t\t\t\t\t5.name of Map Number 5 : " << map5.get_nameOFmap() << endl;
    cin >> numberOfMap;
    system("cls");
    cout << "\n\n\n\n\t\t\t\t\t\t--- Settings ---" << endl;
    cout << "\n\t\t\t\t\tPlease Enter Money Of CT player." << endl;
    cin >> MoneyOfctPlayer;
    system("cls");
    cout << "\n\n\n\n\t\t\t\t\t\t--- Settings ---" << endl;
    cout << "\n\t\t\t\t\tPlease Enter Money Of terrorist player." << endl;
    cin >> MoneyOfterroristPlayer;
    system("cls");
    cout << "\n\n\n\n\t\t\t\t\t\t--- Settings ---" << endl;
    cout << "\n\t\t\t\t\tPlease Enter Number Of terrorist player." << endl;
    cin >> NumberOfTerroristPlayer;
    system("cls");
    cout << "\n\n\n\n\t\t\t\t\t\t--- Settings ---" << endl;
    cout << "\n\t\t\t\t\tPlease Enter Number Of ct player." << endl;
    cin >> NumberOfctPlayer;
    flag = 1;
    pauseWithReturn();
}

void menu::showHistory()
{
    system("cls");
    cout << "\n\n\n\n\t\t\t\t\t\t--- History ---" << endl;
    string filename = get_nameuser() + ".txt";
    fstream file1(filename, ios::in);
    int temp;
    while (file1 >> temp)
    {
        switch(temp)
        {
        case 1:
            cout << "\n\t\t\t\t\tCT WIN!" << endl;
            break;
        case 2:
            cout << "\n\t\t\t\t\tTERRORIST WIN!" << endl;
            break;
        case 0:
            cout << "\n\t\t\t\t\tDRAW!" << endl;
            break;
        }
    }
    pauseWithReturn();
}

void menu::showInformation()
{
    count_win();
    system("cls");
    cout << "\n\n\n\n\t\t\t\t\t--- Information ---" << endl;
    cout << "\n\t\t\t\t\tusername : " << get_nameuser() << endl;
    cout << "\n\t\t\t\t\tCt win : " << get_ctwin() << endl;
    cout << "\n\t\t\t\t\tTerrorist win : " << get_twin() << endl;
    
    pauseWithReturn();
}

void menu::pause()
{
    cout << "\nPress any key to continue...";
    cin.ignore();
    cin.get();
}

void menu::pauseWithReturn()
{
    cout << "\nPress any key to return to the main menu...";
    cin.ignore();
    cin.get();
}

int menu::get_numberOfMap()
{
    return numberOfMap;
}

int menu::get_NumberOfctPlayer()
{
    return NumberOfctPlayer;
}

int menu::get_NumberOfTerroristPlayer()
{
    return NumberOfTerroristPlayer;
}

int menu::get_MoneyOfctPlayer()
{
    return MoneyOfctPlayer;
}

int menu::get_MoneyOfterroristPlayer()
{
    return MoneyOfterroristPlayer;
}

void menu::sett_cts(vector <ct>& c)
{
    cts = c;
}

void menu::sett_terrorists(vector <terrorist>& t)
{
    terrorists = t;
}

string menu::get_nameuser()
{
    return nameuser;
}

void menu::sett_nameuser(string nameuser_)
{
    nameuser = nameuser_;
}

int menu::get_NumOfResualt()
{
    return NumOfResualt;
}

void menu::sett_NumOfResualt(int Num)
{
    NumOfResualt = Num;
}

void menu::saveresualt()
{
    string filename = get_nameuser() + ".txt";
    fstream file1(filename, ios::app);
    file1 << get_NumOfResualt() << endl;
    file1.close();
}

int menu::get_ctwin()
{
    return ctwin;
}

int menu::get_twin()
{
    return twin;
}

void menu::count_win()
{
    string filename = get_nameuser() + ".txt";
    fstream file1(filename, ios::in);
    int temp;
    ctwin = 0;
    twin = 0;
    while (file1 >> temp)
    {
        switch (temp)
        {
        case 1:
            ctwin++;
            break;
        case 2 :
            twin++;
            break;
        }
    }
}

string menu::hash(string pass)
{
    for (int i = 0;pass.length() > i;++i)
    {
        pass[i] = pass[i] + 10;
    }
    return pass;
}


void menu::sett_MoneyOfctPlayer(int m)
{
    MoneyOfctPlayer = m;
}

void menu::sett_MoneyOfterroristPlayer(int m)
{
    MoneyOfterroristPlayer = m;
}

void menu::sett_numberOfMap(int n)
{
    numberOfMap = n;
}

void menu::sett_NumberOfctPlayer(int n)
{
    NumberOfctPlayer = n;
}

void menu::sett_NumberOfTerroristPlayer(int n)
{
    NumberOfTerroristPlayer = n;
}

vector<ct>& menu::get_cts()
{
    return cts;
}

vector<terrorist>& menu::get_terrorists()
{
    return terrorists;
}

void menu::sett_maps(vector<map>& m)
{
    maps = m;
}

vector<map>& menu::get_maps()
{
    return maps;
}

void menu::sett_ctwin(int c)
{
    ctwin = c;
}

void menu::sett_twin(int t)
{
    twin = t;
}

int menu::get_flag()
{
    return flag;
}

void menu::sett_flag(int f)
{
    flag = f;
}