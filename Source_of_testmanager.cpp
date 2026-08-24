#include "Header_of_testmanager.h"
#include "Header_of_gamemanager.h"
#include "Header_of_player.h"
#include "Header_of_terrorist.h"
#include "Header_of_ct.h"
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

void TestManager::testCalcuteDamage() {
    gamemanager* manager = gamemanager::get_ins();

    assert(manager->calcute_damage(100, true, true) == 70);
    assert(manager->calcute_damage(100, true, false) == 80);
    assert(manager->calcute_damage(100, false, true) == 90);
    assert(manager->calcute_damage(100, false, false) == 100);

    cout << "testCalcuteDamage: pass" << endl;
}

void TestManager::testStartFight() {
    gamemanager* manager = gamemanager::get_ins();

    vector<int> ct_guns_id = { 1, 2 };
    vector<string> ct_guns_name = { "AK-47", "M4A1" };
    ct ct_player("CT Player", ct_guns_id, ct_guns_name, 100, 50, true, false, 1000, 2, false, false);

    vector<int> t_guns_id = { 3, 4 };
    vector<string> t_guns_name = { "AWP", "P90" };
    terrorist t_player("Terrorist Player", t_guns_id, t_guns_name, 100, 50, true, false, 1000, 2, false, false);

    manager->sett_vec_ct({ ct_player });
    manager->sett_vec_terrorist({ t_player });

    map m;
    m.sett_nameOFmap("Test Map");
    m.sett_snow(false);
    m.sett_night(false);
    manager->sett_map_of_game(m);

    manager->startfight();
    int result = manager->get_resualt();
    assert(result == 0 || result == 1 || result == 2);

    cout << "testStartFight: pass" << endl;
}

void TestManager::testInvalidInput() {
    gamemanager* manager = gamemanager::get_ins();

    vector<int> ct_guns_id = { 1, 2 };
    vector<string> ct_guns_name = { "AK-47", "M4A1" };
    ct ct_player("CT Player", ct_guns_id, ct_guns_name, 100, 50, false, false, 1000, 2, false, false);

    vector<int> t_guns_id = { 3, 4 };
    vector<string> t_guns_name = { "AWP", "P90" };
    terrorist t_player("Terrorist Player", t_guns_id, t_guns_name, 100, 50, true, false, 1000, 2, false, false);

    manager->sett_vec_ct({ ct_player });
    manager->sett_vec_terrorist({ t_player });

    map m;
    m.sett_nameOFmap("Test Map");
    m.sett_snow(false);
    m.sett_night(false);
    manager->sett_map_of_game(m);

    manager->startfight();
    int result = manager->get_resualt();
    assert(result == 0 || result == 1 || result == 2);

    cout << "testInvalidInput: (Expected logical fail — dead player)" << endl;
}

void TestManager::testPlayerHealth() {
    vector<int> ids = { 1 };
    vector<string> names = { "AK" };
    player p("P1", ids, names, 100, 50, true, false, 1000, 2);
    p.sett_Health(120);
    assert(p.get_Health() == 120);
    cout << "testPlayerHealth: pass" << endl;
}

void TestManager::testPlayerArmor() {
    vector<int> ids = { 1 };
    vector<string> names = { "AK" };
    player p("P1", ids, names, 100, 50, true, false, 1000, 2);
    p.sett_Armor(75);
    assert(p.get_Armor() == 75);
    cout << "testPlayerArmor: pass" << endl;
}

void TestManager::testPlayerName() {
    vector<int> ids = { 1 };
    vector<string> names = { "AK" };
    player p("P1", ids, names, 100, 50, true, false, 1000, 2);
    p.sett_nameOFplayer("NewPlayer");
    assert(p.get_nameOFplayer() == "NewPlayer");
    cout << "testPlayerName: pass" << endl;
}

void TestManager::testPlayerEquality() {
    vector<int> ids = { 1 };
    vector<string> names = { "AK" };
    player p1("P1", ids, names, 100, 50, true, false, 1000, 2);
    player p2 = p1;
    assert(p1 == p2);
    cout << "testPlayerEquality: pass" << endl;
}

void TestManager::testTerroristBombStatus() {
    terrorist t("T", { 1 }, { "AK" }, 100, 50, true, false, 1000, 2, false, false);
    t.sett_hasBomb(true);
    assert(t.get_hasBomb() == true);
    cout << "testTerroristBombStatus: pass" << endl;
}

void TestManager::testTerroristPlantingBomb() {
    terrorist t("T", { 1 }, { "AK" }, 100, 50, true, false, 1000, 2, false, false);
    t.sett_plantingBomb(true);
    assert(t.get_plantingBomb() == true);
    cout << "testTerroristPlantingBomb: pass" << endl;
}

void TestManager::testTerroristEquality() {
    terrorist t1("T", { 1 }, { "AK" }, 100, 50, true, false, 1000, 2, true, true);
    terrorist t2 = t1;
    assert(t1 == t2);
    cout << "testTerroristEquality: pass" << endl;
}

void TestManager::testCTKitStatus() {
    ct c("C", { 1 }, { "AK" }, 100, 50, true, false, 1000, 2, false, false);
    c.sett_has_kit(true);
    assert(c.get_has_kit() == true);
    cout << "testCTKitStatus: pass" << endl;
}

void TestManager::testCTDisposalBomb() {
    ct c("C", { 1 }, { "AK" }, 100, 50, true, false, 1000, 2, false, false);
    c.sett_disposalBomb(true);
    assert(c.get_disposalBomb() == true);
    cout << "testCTDisposalBomb: pass" << endl;
}

void TestManager::testCTEquality() {
    ct c1("C", { 1 }, { "AK" }, 100, 50, true, false, 1000, 2, true, true);
    ct c2 = c1;
    assert(c1 == c2);
    cout << "testCTEquality: pass" << endl;
}

void TestManager::runAllTests() {
    testCalcuteDamage();
    testStartFight();
    testInvalidInput();

    testPlayerHealth();
    testPlayerArmor();
    testPlayerName();
    testPlayerEquality();

    testTerroristBombStatus();
    testTerroristPlantingBomb();
    testTerroristEquality();

    testCTKitStatus();
    testCTDisposalBomb();
    testCTEquality();
}
