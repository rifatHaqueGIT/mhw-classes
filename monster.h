using namespace std;
#include <vector>
#include <string>
#include <unordered_map>

class Monster
{
private:
    double mv = 0;
    unordered_map<string, double> ma = {};
    double rm = 0;
    float health;
    unordered_map<string, int> part_armour;

public:
    void set_val(double move, unordered_map<string, double> armour, double rage)
    {
        mv = move;
        ma = armour;
        rm = rage;
    }
    string hitLocation(string, string);
    int hitDamage(int, int);
};

class MonsterVarient : public Monster
{
};
