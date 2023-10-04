#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
using namespace std;

int hp = 1800;
int dragon_hp = 32430;
int freeze_spell = 30;
int healing_spell = 20;
int poison_spell = 10;
int dmg_spell;
char options[6];
bool loop = true;
int dragon_breath = 1;
bool pattern1 = false;
bool pattern2 = false;
bool pattern3 = false;


void decoration() {
    cout << "\n-----------------------------------------\n\n";
}

void decoration2() {
    cout << "=========================================\n";
}

void damage_dragon() {
    hp -= 1750;
    if (hp < 0) {
        hp = 0;
    }
}

void spell(int dmg_spell) {
    dragon_hp -= dmg_spell;
    if (dragon_hp < 0) {
      dragon_hp = 0;
    }
}

void add_hp(int total_add) {
    hp += total_add;
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
        cout << "=\t   HP    : " << dragon_hp << "/32430\t\t=\n";
        decoration2();
        cout << "Available options\n";
        cout << "[1] Freeze Spell [x" << freeze_spell << "]\n";
        cout << "[2] Poison Spell [x" << poison_spell << "]\n";
        cout << "[3] Healing Spell [x" << healing_spell << "]\n";
        cout << "[0] End Battle\n";
        cout << "Your choice [type numbers only]: ";
        cin >> options;
        decoration();
        if (!digit_check(options)) {
            dragon_breath = dragon_breath;
            cout << "Hey Chief, type numbers only!\n";
        } else {
            if (hp <= 0) {
                cout << "--------------------------------------------------------\n";
                cout << "| Let's review our strategy for the next battle Chief! |\n";
                cout << "--------------------------------------------------------\n";
                loop = false;
            } else if (dragon_hp <= 0) {
                ifstream myfile;
                string flag;
                cout << "------------------------------------------\n";
                cout << "| Congratulations on your victory Chief! |\n";
                cout << "------------------------------------------\n";
                myfile.open("flag.txt");
                getline(myfile, flag);

                int key = randomgen(90, 9);
                for (int i = 0; (i < flag.length() && flag[i] != '\0'); i++) {
                    flag[i] = flag[i] ^ key;
                }
                cout << "flag: " << flag << endl;
                loop = false;
            } else if (freeze_spell == 0 & poison_spell == 0 & healing_spell == 0) {
                cout << "No spells left\n";
                loop = false;
            } else {
                if (dragon_breath % 1 == 0 && options[0]-'0' == 1) {
                    pattern1 = true;
                }
                if (dragon_breath % 2 == 0 && options[0]-'0' == 2) {
                    pattern2 = true;
                }
                if (dragon_breath % 3 == 0 && options[0]-'0' == 3) {
                    pattern3 = true;
                }
                if(stoi(options) == cheat) {
                    if (pattern1 && pattern2 && pattern3) {
                        cout << "You're dropping 8 Electro Dragon (+3600 HP)\n";
                        add_hp(3600);
                        decoration();
                        cout << "Total Damage : 3243\n";
                        spell(3243);
                        cout << "Damage Dragon : 1750\n";
                        damage_dragon();

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
                            if (freeze_spell <= 0) {
                                cout << "Select a different spell\n";
                            } else {
                                freeze_spell -= 1;
                                cout << "Damage Spell  : 0\n";

                                cout << "Damage Dragon : 0\n";
                            }
                            break;
                        case 2:
                            if (poison_spell <= 0) {
                               cout << "Select a different spell\n";
                            } else {
                                poison_spell -= 1;
                                cout << "Damage Spell  : 280\n";
                                spell(280);
                                cout << "Damage Dragon : 1750\n";
                                damage_dragon();
                            }
                            break;
                        case 3:
                            if (healing_spell <= 0) {
                                cout << "Select a different spell\n";
                            } else {
                                healing_spell -= 1;
                                if(hp >= 1800) {
                                    hp = hp;
                                } else {
                                    add_hp(1800);
                                    cout << "Total Healing : 1800\n";
                                }
                                cout << "Damage Dragon : 1750\n";
                                damage_dragon();
                            }
                            break;
                        default:
                            dragon_breath -= 1;
                            cout << "The option you chose isn't available\n";
                    }
                }
            }
        dragon_breath += 1;
        }
        cout << endl;
    } while (loop);

    return 0;
}
