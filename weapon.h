using namespace std;
#include <vector>
#include <string>
#include <unordered_map>

class Weapon
{
private:
    double true_raw = 0;
    double element = 0;
    string weaponName; // NEEED TO ADD TO SETTER
    vector<double> shm = {};
    double mv = 0; // should move
    double ma = 0; // should move
    double rm = 0; // should move
    double weapon_mod;
    double affinity = 0;
    double amod = 1.25;

public:
    void set_val(double tr, double e, vector<double> s, double move, double marmor, double rage, double weamod, double af, string name)
    {
        true_raw = tr;
        element = e;
        shm = s;
        mv = move;
        ma = marmor;
        rm = rage;
        weapon_mod = weamod;
        affinity = af;
        weaponName = name;
    }
    void set_amod(double a) { amod = a; }
    double getTrueDmg()
    {
        return true_raw / weapon_mod * shm[0] * mv * ma * rm;
    }
    double eledmg()
    {
        return element / 10 * shm[1] * mv * ma * rm;
    }
    double totalDmg()
    {
        return getTrueDmg() + eledmg();
    }
};