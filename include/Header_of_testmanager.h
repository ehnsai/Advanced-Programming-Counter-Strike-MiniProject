#ifndef TESTMANAGER_H
#define TESTMANAGER_H

class TestManager 
{
public:
    void testCalcuteDamage();
    void testStartFight();
    void testInvalidInput();

    void testPlayerHealth();
    void testPlayerArmor();
    void testPlayerName();
    void testPlayerEquality();

    void testTerroristBombStatus();
    void testTerroristPlantingBomb();
    void testTerroristEquality();

    void testCTKitStatus();
    void testCTDisposalBomb();
    void testCTEquality();

    void runAllTests();
};

#endif
