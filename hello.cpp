#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "monster.h"
#include "weapon.h"
// using namespace std;

int monster_hit(Monster target, Weapon w)
{

    return 0;
}

int main()
{
    double true_raw = 0; // the weapons raw dmg
    double element = 0;  // the weapons elemental dmg
    double shm = 0;      // sharpness mod
    double mv = 0;       // motion value
    double ma = 0;       // monster armor
    double rm = 0;       // rage mod
    double affinity = 0; // crit chance
    double amod = 1.25;  // affinity mod

    double truedmg = true_raw * shm * mv * ma * rm;

    double eledmg = element / 10 * shm * mv * ma * rm;
    // setup
    vector<double> dmgMod{5.2, 4.2, 3.5, 4.8, 3.6, 3.3, 3.1, 2.3, 2.3, 1.5, 1.4, 1.3, 1.2};

    vector<string> weapons{"Hammer", "Horn", "Switch Axe", "Great Sword", "Charge Blade", "Long Sword", "Insect Glaive", "Lance", "Gunlance", "Heavy Bowgun", "Dual Blades", "Light Bowgun", " Bow"};

    int i = 0;

    vector<vector<double>> sh{{1.39, 1.25}, {1.32, 1.125}, {1.20, 1.0625}, {1.05, 1.00}, {1.00, 0.75}, {0.50, 0.25}};
    vector<string> shcolor{"Purple", "White", "Blue", "Green", "Yellow", "Orange", "Red"};
    unordered_map<string, double> dmgMap;
    unordered_map<string, vector<double>> sharpness;

    for (const auto &g : sh)
    {
        sharpness[shcolor[i]] = g;
        i++;
    }
    i = 0;
    for (const auto &n : weapons)
    {
        dmgMap[n] = dmgMod[i];
        i++;
    }
    vector<string> parts{"Head", "Neck", "Throat", "Back", "Body", "Forelegs", "Hindlegs", "Tail"};
    vector<int> monstorAR{};
    // end of setup

    Weapon great_sword;
    great_sword.set_val(1500, 360, sharpness["Green"], 1, 1, 1, dmgMap["Great Sword"], 20, "Great Sword");
    std::cout << "The total Damage dealt by the Great Sword is: " << (int)great_sword.totalDmg() << endl;

    std::cout << "The elem Damage dealt by the Great Sword is: " << great_sword.eledmg() << endl
              << "The raw Damage dealt by the Great Sword is: " << (int)great_sword.getTrueDmg();
    // great_sword.set_val(1000, 300);
    // for (const auto &word : dmgMap)
    // {
    //     cout << word.first << " " << word.second << " ";
    // }
    // cout << endl
    //      << endl;
    // for (const auto &word : sharpness)
    // {
    //     cout << word.first << " " << word.second[0] << " " << word.second[1] << " ";
    // }
    std::cout
        << endl;
}