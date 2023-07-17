#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
using namespace std;

int hp = 1800;
int hpDragon = 32430;
int dmgHero, dmgLord;
char options[6];
bool loop = true;
int attackRound = 1;

void decoration() {
    cout << "------------------------------------------\n";
}

void decoration2() {
    cout << "==========================================\n";
}

void damageDragon() {
    hp -= 1750;
    if (hp < 0) {
        hp = 0;
    }
}

void skill(int dmgHero) {
    hpDragon -= dmgHero;
    if (hpDragon < 0) {
      hpDragon = 0;
    }
}

void addHp(int jmltambah) {
    hp += jmltambah;
    if (hp > 4500) {
        hp = 4500;
    }
}

int randomgen(int max, int min) {
    int random = min + (rand() % (max - min + 1));

    return random;
}

bool digit_check(char key[]) {
    for(int i = 0; i < strlen(key); i++) {
        if(isdigit(key[i])==0) {
            return false;
        }
    }
    return true;
}

int main() {
    srand(time(NULL));
    decoration();
    cout << " -- 'Welcome to Dragon's Lair, Chief!' --\n";
    cout << "  Slay the Giant Dragon to get the flag\n";
    decoration();
    do {
        int cheat = randomgen(99999, 1000); 
        decoration2();
        cout << "\t  ===== Serangan Dragon ke-" << attackRound << " =====\n";
        decoration2();
        cout << "=\tHero : Baby Dragon\t\n";
        cout << "=\tHp   : " << hp << "/1800\t\n";
        cout << "=\t     ------\t\t\n";
        cout << "=\t     | VS |\t\t\n";
        cout << "=\t     ------\t\t\n";
        cout << "=\t* Giant Dragon *\t\n";
        cout << "=\tHp   : " << hpDragon << "/32430\t\n";
        decoration2();
        cout << "Available options\n";
        cout << "[1] Frezze Spell\n";
        cout << "[2] Poison Spell\n";
        cout << "[3] Lightning Spell\n";
        cout << "[4] Healing Spell\n";
        cout << "[0] End Battle\n";
        cout << "Your choice [type numbers only]: ";
        cin >> options;
        decoration();
        if (!digit_check(options)) {
            attackRound = attackRound;
            cout << "Hey Chief, type numbers only!\n";
        } else {
            if (hp <= 0) {
                cout << "--------------------------------------------------------\n";
                cout << "| Let's review our strategy for the next battle Chief! |\n";
                cout << "--------------------------------------------------------\n";
                sleep(3);
                system("clear");
            } else if (hpDragon <= 0) {
               ifstream myfile;
                string flag;
                cout << "------------------------------------------\n";
                cout << "| Congratulations on your victory Chief! |\n";
                cout << "------------------------------------------\n";
                myfile.open("flag.txt");
                getline(myfile, flag);
                cout << "This flag is for you: \n";
                cout << flag << endl;
                loop = false;
            } else {
                if(stoi(options) == cheat) { 
                    cout << "You dropping 10 Electro Dragon(+4500 Hp)\n";
                    addHp(4500);
                    decoration();
                    cout << "Damage : 3243\n"; 
                    skill(3243); 
                    cout << "Damage Dragon : 1750\n";
                    damageDragon();
                
                } else {
                        switch (stoi(options)) {
                            case 0:
                                cout << "The battle is over...\n";
                                loop = false;
                                break;
                            case 1:
                                cout << "Damage skill : 450\n";
                                skill(450);
                                damageDragon();
                                cout << "Damage Dragon : 1750\n";
                                break;
                            case 2:
                                cout << "Damage skill : 650\n";
                                skill(650);
                                damageDragon();
                                cout << "Damage Dragon : 1750\n";
                                break;
                            case 3:
                                cout << "Damage spell : 560\n";
                                skill(560);
                                damageDragon();
                                cout << "Damage Dragon : 1750\n";
                                break;
                            case 4:
                                addHp(1800);
                                cout << "Total troop heal : 1800\n";
                                damageDragon();
                                cout << "Damage Dragon : 1750\n";
                                break;
                            default:
                                attackRound -= 1;
                                cout << "The option you chose isn't available\n";
                        }
                }
            }
        attackRound += 1;
        }
        cout << endl;
    } while (loop);

    return 0;
}
