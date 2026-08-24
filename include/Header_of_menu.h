#ifndef MENU_H
#define MENU_H

#include "Header_of_ct.h"
#include "Header_of_terrorist.h"
#include "Header_of_random.h"
#include "Header_of_gamemanager.h"
#include "Header_of_user.h"
#include "Header_of_map.h"

using namespace std;

class menu 
{
private:
    int numberOfMap;
    int NumberOfctPlayer;
    int NumberOfTerroristPlayer;
    int MoneyOfctPlayer;
    int MoneyOfterroristPlayer;
    vector <ct> cts;
    vector <terrorist> terrorists;
    vector <map> maps;

    string nameuser;

    int NumOfResualt;

    int ctwin;
    int twin;

    int flag;

public:
    menu();
    void showMainMenu();
    void startGame();
    void showSettings();
    void showHistory();
    void showInformation();
    void pause();
    void pauseWithReturn();

    int get_numberOfMap();
    int get_NumberOfctPlayer();
    int get_NumberOfTerroristPlayer();
    int get_MoneyOfctPlayer();
    int get_MoneyOfterroristPlayer();
    void sett_numberOfMap(int n);
    void sett_NumberOfctPlayer(int n);
    void sett_NumberOfTerroristPlayer(int n);
    void sett_MoneyOfctPlayer(int n);
    void sett_MoneyOfterroristPlayer(int n);
    string get_nameuser();
    void sett_nameuser(string nameuser_);
    int get_NumOfResualt();
    void sett_NumOfResualt(int Num);
    int get_ctwin();
    int get_twin();
    void sett_ctwin(int c);
    void sett_twin(int t);
    int get_flag();
    void sett_flag(int f);
    void sett_cts(vector <ct>& c);
    void sett_terrorists(vector <terrorist>& t);
    vector<ct>& get_cts();
    vector<terrorist>& get_terrorists();
    void sett_maps(vector<map>& m);
    vector<map>& get_maps();

    void count_win();
    bool startmenu();
    bool signin();
    void signup();

    bool CheckUsername(string inputusername);
    bool CheckNickname(string inputnickname);
    bool CheckPassword(string inputpassword);
    bool Checkrepeatpass(string pass1,string pass2);
    vector<user> loaduser();
    void saveresualt();
    string hash(string pass);
};


#endif
