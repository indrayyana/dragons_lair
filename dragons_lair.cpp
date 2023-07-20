#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
using namespace std;

int hp = 1800;
int dragonHp = 32430;
int dmgSpell;
char options[6];
bool loop = true;
int dragonBreath = 1;
bool pattern1 = false;
bool pattern2 = false;
bool pattern3 = false;


void decoration() {
    cout << "\n-----------------------------------------\n\n";
}

void decoration2() {
    cout << "=========================================\n";
}

void damageDragon() {
    hp -= 1750;
    if (hp < 0) {
        hp = 0;
    }
}

void spell(int dmgSpell) {
    dragonHp -= dmgSpell;
    if (dragonHp < 0) {
      dragonHp = 0;
    }
}

void addHp(int totalAdd) {
    hp += totalAdd;
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
        if(isdigit(key[i]) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    srand(time(NULL));
    decoration();
    cout << "-- 'Welcome to Dragon's Lair, Chief!' --\n";
    cout << " Slay the Giant Dragon to get the flag\n";
    decoration();
    do {
        int cheat = randomgen(99999, 1000); 
        decoration2();
        cout << "=\t   Troop : Baby Dragon\t\t=\n";
        cout << "=\t   HP    : " << hp << "/1800\t\t=\n";
        cout << "=\t         ------\t\t\t=\n";
        cout << "=\t         | VS |\t\t\t=\n";
        cout << "=\t         ------\t\t\t=\n";
        cout << "=\t   ** Giant Dragon **\t\t=\n";
        cout << "=\t   HP    : " << dragonHp << "/32430\t\t=\n";
        decoration2();
        cout << "Available options\n";
        cout << "[1] Freeze Spell\n";
        cout << "[2] Poison Spell\n";
        cout << "[3] Healing Spell\n";
        cout << "[0] End Battle\n";
        cout << "Your choice [type numbers only]: ";
        cin >> options;
        decoration();
        if (!digit_check(options)) {
            dragonBreath = dragonBreath;
            cout << "Hey Chief, type numbers only!\n";
        } else {
            if (hp <= 0) {
                cout << "--------------------------------------------------------\n";
                cout << "| Let's review our strategy for the next battle Chief! |\n";
                cout << "--------------------------------------------------------\n";
                loop = false;
            } else if (dragonHp <= 0) {
                ifstream myfile;
                string flag;
                cout << "------------------------------------------\n";
                cout << "| Congratulations on your victory Chief! |\n";
                cout << "------------------------------------------\n";
                myfile.open("flag.txt");
                getline(myfile, flag);
                cout << "This flag is for you : \n";
                cout << flag << endl;
                loop = false;
            } else {
                if (dragonBreath % 1 == 0 && options[0]-'0' == 1) {
                    pattern1 = true;
                }
                if (dragonBreath % 2 == 0 && options[0]-'0' == 2) {
                    pattern2 = true;
                }
                if (dragonBreath % 3 == 0 && options[0]-'0' == 3) {
                    pattern3 = true;
                } 
                if(stoi(options) == cheat) {
                    if (pattern1 && pattern2 && pattern3) {
                        cout << "You're dropping 10 Electro Dragon (+4500 HP)\n";
                        addHp(4500);
                        decoration();
                        cout << "Total Damage : 3243\n"; 
                        spell(3243); 
                        cout << "Damage Dragon : 1750\n";
                        damageDragon();    

                        pattern1 = false;
                        pattern2 = false;
                        pattern3 = false;
                    } else {
                        cout << "The option you chose isn't available\n";
                    }
                } else {
                    switch (stoi(options)) {
                        case 0:
                            cout << "The battle is over...\n";
                            loop = false;
                            break;
                        case 1:
                            cout << "Damage Spell  : 0\n";
                            cout << "Damage Dragon : 0\n";
                            break;
                        case 2:
                            cout << "Damage Spell  : 280\n";
                            spell(280);
                            cout << "Damage Dragon : 1750\n";
                            damageDragon();
                            break;
                        case 3:
                            if(hp >= 1800) {
                                hp = hp;
                            } else {
                                addHp(1800);
                                cout << "Total Healing : 1800\n";
                            }
                            cout << "Damage Dragon : 1750\n";
                            damageDragon();
                            break;
                        default:
                            dragonBreath -= 1;
                            cout << "The option you chose isn't available\n";
                    }
                }
            }
        dragonBreath += 1;
        }
        cout << endl;
    } while (loop);

    return 0;
}
