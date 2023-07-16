#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
using namespace std;

int hp = 4500;
int mp = 2500;
int hpLord = 1000000;
int dmgHero, dmgLord;
char options[6];
bool loop = true;
int attackRound = 1;

void decoration() {
    cout << "---------------------------------------------------\n";
}

void decoration2() {
    cout << "===================================================\n";
}

void damageLord(int dmgLord) {
    hp -= dmgLord;
    if (hp < 0) {
        hp = 0;
    }
}

void skill(int dmgHero, int mc) {
    hpLord -= dmgHero;
    mp -= mc;
    if (hpLord < 0) {
        hpLord = 0;
    }
    if (mp < 0) {
        mp = 0;
    }
}

void tambahHp(int jmltambah) {
    hp += jmltambah;
    if (hp > 4500) {
        hp = 4500;
    }
}

void thunder_strike() {
    damageLord(1000);
    cout << "Damage Thunder Strike Lord : 1000\n";
}

void recall() {
    attackRound = 0;
    hp = 4500;
    mp = 2500;
    hpLord = 1000000;
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
    cout << "\t-- 'Welcome to Dragon's Lair, Chief!' --\n";
    cout << "\t Slay the Giant Dragon to get the flag\n";
    decoration();
    do {
        int cheat = randomgen(99991, 1000); 
        cout << cheat << endl; // testing
        decoration2();
        cout << "\t  ===== Serangan Lord ke-" << attackRound << " =====\n";
        decoration2();
        cout << "=\t\tHero : Baby Dragon\t\t  =\n";
        cout << "=\t\tHp   : " << hp << "/4500\t\t  =\n";
        cout << "=\t\tMp   : " << mp << "/2500\t\t  =\n";
        cout << "=\t\t   ------\t\t\t  =\n";
        cout << "=\t\t   | VS |\t\t\t  =\n";
        cout << "=\t\t   ------\t\t\t  =\n";
        cout << "=\t\t=== Giant Dragon ===\t\t  =\n";
        cout << "=\t\tHp   : " << hpLord << "/1000000\t\t  =\n";
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
                // for(int r = 30; r >= 0; r--) {
                //     system("clear");
                //     cout << "\n{Resurrecting in " << r << "s}\n";
                //     sleep(1);
                // }
                recall();
                system("clear");
            } else if (hpLord <= 0) {
                ifstream myfile;
                string flag;
                cout << "-------------\n";
                cout << "| {Victory} |\n";
                cout << "-------------\n";
                myfile.open("flag.txt");
                getline(myfile, flag);
                cout << flag << endl;
                loop = false;
            } else {
                if(stoi(options) == cheat) { 
                    if (mp <= 0) {
                        attackRound -= 1;
                        cout << "'Mana' habis, silahkan recall dulu\n";
                    } else {
                        cout << "Anda telah menekan tombol 'Gather' rekan tim anda\nMiya dan Roger datang membantu\n";
                        decoration();
                        cout << "Damage bersama : 50000\n"; 
                        skill(50000, 10); 
                        if(attackRound % 3 == 0) {
                            thunder_strike();
                        } else {
                            cout << "Damage Lord : 500\n";
                            damageLord(500);
                        }
                    }
                } else {
                        switch (stoi(options)) {
                            case 0:
                                cout << "The battle is over...\n";
                                loop = false;
                                break;
                            case 1:
                                if (mp <= 0) {
                                    attackRound -= 1;
                                    cout << "'Mana' habis, silahkan recall dulu\n";
                                } else {
                                    cout << "Damage skill : 450\n";
                                    skill(450, 90);
                                    if(attackRound % 3 == 0) {
                                        thunder_strike();
                                    } else {
                                        damageLord(500);
                                        cout << "Damage Lord : 500\n";
                                    }
                                }
                                break;
                            case 2:
                                if (mp <= 0) {
                                    attackRound -= 1;
                                    cout << "'Mana' habis, silahkan recall dulu\n";
                                } else {
                                    cout << "Damage skill : 650\n";
                                    skill(650, 110);
                                    if(attackRound % 3 == 0) {
                                        thunder_strike();
                                    } else {
                                        damageLord(500);
                                        cout << "Damage Lord : 500\n";
                                    }
                                }
                                break;
                            case 3:
                                if (mp <= 0) {
                                    attackRound -= 1;
                                    cout << "'Mana' habis, silahkan recall dulu\n";
                                } else {
                                    cout << "Damage skill : 840\n";
                                    skill(840, 180);
                                    if(attackRound % 3 == 0) {
                                        thunder_strike();
                                    } else {
                                        damageLord(500);
                                        cout << "Damage Lord : 500\n";
                                    }
                                }
                                break;
                            case 4:
                                attackRound -= 1;
                                if(hp == 4500) {
                                    cout << "Hp sudah penuh\n";
                                } else {
                                    tambahHp(300);
                                    cout << "Regen Hp : 300\n";
                                }
                                break;
                            case 5:
                                if(hp == 4500) {
                                    cout << "Hp sudah penuh\n";
                                } else {
                                    tambahHp(1000);
                                    cout << "Regen Hp : 1000\n";
                                }
                                if(attackRound % 3 == 0) {
                                    thunder_strike();
                                } else {
                                    damageLord(500);
                                    cout << "Damage Lord : 500\n";
                                }
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
