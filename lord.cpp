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
char pilihan[6];
bool loop = true;
int attackRound = 1;

void hiasan1() {
    cout << "---------------------------------------------------\n";
}

void hiasan2() {
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

// int randomgen(int max, int min) {
//     int random = rand() % max + min;

//     return random;
// }
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
    hiasan1();
    cout << "\t-- 'Welcome to Legenda Seluler' --\n";
    cout << "\tKalahkan Lord untuk mendapatkan flag\n";
    hiasan1();
    cout << "\t   Note: Lord mengeluarkan skill\n";
    cout << "\tThunder Strike setiap serangan ke-3\n";
    do {
        int cheat = randomgen(99999, 1000); 
        hiasan2();
        cout << "\t  ===== Serangan Lord ke-" << attackRound << " =====\n";
        hiasan2();
        cout << "=\t\tHero : Eudora\t\t\t  =\n";
        cout << "=\t\tHp   : " << hp << "/4500\t\t  =\n";
        cout << "=\t\tMp   : " << mp << "/2500\t\t  =\n";
        cout << "=\t\t   ------\t\t\t  =\n";
        cout << "=\t\t   | VS |\t\t\t  =\n";
        cout << "=\t\t   ------\t\t\t  =\n";
        cout << "=\t\t=== Lord ===\t\t\t  =\n";
        cout << "=\t\tHp   : " << hpLord << "/1000000\t\t  =\n";
        hiasan2();
        cout << "Pilihan yang tersedia\n";
        cout << "[1] Ball Lightning\n";
        cout << "[2] Forked Lightning\n";
        cout << "[3] Thunder's Wrath\n";
        cout << "[4] Regen\n";
        cout << "[5] Revitalize\n";
        cout << "[6] Recall\n";
        cout << "[0] AFK\n";
        cout << "Pilihan anda [ketik angka saja]: ";
        cin >> pilihan;
        hiasan1();
        if (!digit_check(pilihan)) {
            attackRound = attackRound;
            cout << "Wahai anak senja, masukan angka saja\n";
        } else {
            if (hp <= 0) {
                cout << "------------\n";
                cout << "| {Defeat} |\n";
                cout << "------------\n";
                sleep(2);
                for(int r = 30; r >= 0; r--) {
                    system("clear");
                    cout << "\n{Resurrecting in " << r << "s}\n";
                    sleep(1);
                }
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
                if(stoi(pilihan) == cheat) { 
                    if (mp <= 0) {
                        attackRound -= 1;
                        cout << "'Mana' habis, silahkan recall dulu\n";
                    } else {
                        cout << "Anda telah menekan tombol 'Gather' rekan tim anda\nMiya dan Roger datang membantu\n";
                        hiasan1();
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
                        switch (stoi(pilihan)) {
                            case 0:
                                cout << "Anda meninggalkan permainan...\n";
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
                            case 6:
                                cout << "Tasss...tasss...tasss...\n";
                                recall();
                                break;
                            default:
                                attackRound -= 1;
                                cout << "Pilihan tidak tersedia\n";
                        }
                }
            }
        attackRound += 1;
        }
        cout << endl;
    } while (loop);

    return 0;
}