#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {

    srand(time(NULL));

    cout << "\033[32m";

    int hp = 100;
    int gold = 50;
    int attpwr = 15;
    int lvl = 1;
    int xp = 0;
    int xpthres = 100;
    int choice = 0;
    int sword = 0;
    int swordpwr = 10;
    int potions = 0;
    int goblin = 0;
    int wolf = 0;
    int bandit = 0;
    int maxhp = 0;
    string name;

    cout << "\n====================";
    cout << "\n  THE LOST DUNGEON  ";
    cout << "\n====================";

    cout << "\nEnter your name, warrior!: ";
    cin >> name;
    cout << "\nWelcome, Warrior " << name << '!' << '\n';
    cout << "\nHP: " << hp << '/' << maxhp + 100;
    cout << "\nGold: " << gold;
    cout << "\nAttack: " << attpwr;
    cout << "\nLevel: " << lvl;
    cout << "\nXP: " << xp << "/" << xpthres << '\n';

    do {
        cout << "\n======MAIN MENU======";
        cout << "\n1. Enter Dungeon";
        cout << "\n2. Character Stats";
        cout << "\n3. Shop";
        cout << "\n4. Rest";
        cout << "\n5. Exit";
        cout << "\n\nEnter choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nInvalid choice!\n";
            continue;
        }

        cin.ignore(1000, '\n');

        switch (choice) {

        case 1: {
            int enc = rand() % 6 + 1;
            int choicep1 = 0;

            int enemyhp = rand() % 70 + 1;
            int reward = rand() % 45 + 1;
            int xp1 = rand() % 50 + 1;

            if (enc == 1) {
                do {
                    cout << "\nA wild Goblin appears!";
                    cout << "\n\nYour HP: " << hp;
                    cout << "\nGoblin HP: " << enemyhp;
                    cout << "\n\n1. Attack\n2. Run\n";
                    cout << "\nWhat will you do?: ";
                    cin >> choicep1;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "\nInvalid choice!\n";
                        continue;
                    }

                    cin.ignore(1000, '\n');
                    string attchoice;

                    switch (choicep1) {

                    case 1: {
                        do {
                            int enemyatt = rand() % 15 + 1;
                            int potionenemyatt = rand() % 15 + 1;
                            int p1att = rand() % attpwr + 1;

                            cout << "\n\nYou dealt " << p1att << " damage!";
                            enemyhp -= p1att;

                            if (enemyhp < 0) {
                                enemyhp = 0;
                            }
                            cout << "\n\nGoblin HP: " << enemyhp;

                            if (enemyhp == 0) {
                                cout << "\n\nYou defeated the Goblin!\n";
                                cout << "\n+" << reward << " Gold";
                                cout << "\n+" << xp1 << " XP\n";
                                xp += xp1;
                                gold += reward;
                                goblin++;

                                while (xp >= xpthres) {
                                    cout << "\n==============================\n";
                                    cout << "            LEVEL UP!             ";
                                    cout << "\n==============================\n";
                                    lvl++;
                                    xp -= xpthres;
                                    xpthres += 100;
                                    maxhp += 20;
                                    hp = maxhp + 100;
                                    attpwr += 5;
                                    cout << "\nYou reached Level " << lvl << "!\n";
                                    cout << "\nAttack increased!";
                                    cout << "\nMaximum HP increased!";
                                    cout << "\nHP Restored!\n";
                                }

                            } else {

                                cout << "\n\nGoblin deals " << enemyatt << " damage!";
                                hp -= enemyatt;

                                if (hp < 0) {
                                    hp = 0;
                                }
                                if (hp == 0) {
                                    cout << "\n\nYou have no HP left!";
                                    cout << "\nYou died! X(\n";

                                    cout << "\n====================";
                                    cout << "\n      GAME OVER     ";
                                    cout << "\n====================";
                                    cout << "\n\n" << name << " reached Level " << lvl;
                                    cout << "\nFinal Gold: " << gold;
                                    cout << "\nFinal XP: " << xp << "\n\n";
                                    return 0;
                                }
                                cout << "\n\nYour HP: " << hp;

                                do {
                                    cout << "\n\nAttack again? (A) or Run away? (R) or Use Potions? (P): ";
                                    cin >> attchoice;

                                    if (attchoice == "A" || attchoice == "a") {
                                        cout << "\nYou attack again!";
                                    } else if (attchoice == "R" || attchoice == "r") {
                                        cout << "\nYou ran away! :(\n";
                                    } else if (attchoice == "P" || attchoice == "p") {
                                        if (potions < 1) {
                                            cout << "\nYou don't have any potions!";
                                            attchoice = "";
                                        } else {
                                            cout << "\nYou used a potion! +20 HP restored!\n";
                                            hp += 20;
                                            potions--;

                                            if (hp > maxhp + 100) {
                                                hp = maxhp + 100;
                                            }
                                            cout << "\nThe Goblin attacks while you recover!";
                                            cout << "\n\nGoblin deals " << potionenemyatt << " damage!";
                                            hp -= potionenemyatt;

                                            if (hp < 0) {
                                                hp = 0;
                                            }
                                            if (hp == 0) {
                                                cout << "\n\nYou have no HP left!";
                                                cout << "\nYou died! X(\n";

                                                cout << "\n====================";
                                                cout << "\n      GAME OVER     ";
                                                cout << "\n====================";
                                                cout << "\n\n" << name << " reached Level " << lvl;
                                                cout << "\nFinal Gold: " << gold;
                                                cout << "\nFinal XP: " << xp << "\n\n";
                                                return 0;
                                            }
                                            cout << "\n\nYour HP: " << hp;
                                            attchoice = "";
                                        }
                                    } else {
                                        cout << "\nInvalid choice! Enter only A or R or P.\n";
                                    }
                                } while (attchoice != "A" && attchoice != "a" &&
                                         attchoice != "R" && attchoice != "r" &&
                                         attchoice != "P" && attchoice != "p");
                            }
                        } while (enemyhp != 0 && ((attchoice == "A" || attchoice == "a") ||
                                                   (attchoice == "P" || attchoice == "p")));
                        break;
                    }

                    case 2:
                        cout << "\nYou ran away! :(\n";
                        break;

                    default:
                        cout << "\nInvalid choice!\n";
                        break;
                    }
                } while (choicep1 != 1 && choicep1 != 2);

            } else if (enc == 2) {
                do {
                    cout << "\nA wild Wolf appears!";
                    cout << "\n\nYour HP: " << hp;
                    cout << "\nWolf HP: " << enemyhp;
                    cout << "\n\n1. Attack\n2. Run\n";
                    cout << "\nWhat will you do?: ";
                    cin >> choicep1;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "\nInvalid choice!\n";
                        continue;
                    }

                    cin.ignore(1000, '\n');
                    string attchoice;

                    switch (choicep1) {

                    case 1: {
                        do {
                            int enemyatt = rand() % 15 + 1;
                            int potionenemyatt = rand() % 15 + 1;
                            int p1att = rand() % attpwr + 1;

                            cout << "\n\nYou dealt " << p1att << " damage!";
                            enemyhp -= p1att;

                            if (enemyhp < 0) {
                                enemyhp = 0;
                            }
                            cout << "\n\nWolf HP: " << enemyhp;

                            if (enemyhp == 0) {
                                cout << "\n\nYou defeated the Wolf!\n";
                                cout << "\n+" << reward << " Gold";
                                cout << "\n+" << xp1 << " XP\n";
                                xp += xp1;
                                gold += reward;
                                wolf++;

                                while (xp >= xpthres) {
                                    cout << "\n==============================\n";
                                    cout << "            LEVEL UP!             ";
                                    cout << "\n==============================\n";
                                    lvl++;
                                    xp -= xpthres;
                                    xpthres += 100;
                                    maxhp += 20;
                                    hp = maxhp + 100;
                                    attpwr += 5;
                                    cout << "\nYou reached Level " << lvl << "!\n";
                                    cout << "\nAttack increased!";
                                    cout << "\nMaximum HP increased!";
                                    cout << "\nHP Restored!\n";
                                }

                            } else {

                                cout << "\n\nWolf deals " << enemyatt << " damage!";
                                hp -= enemyatt;

                                if (hp < 0) {
                                    hp = 0;
                                }
                                if (hp == 0) {
                                    cout << "\n\nYou have no HP left!";
                                    cout << "\nYou died! X(\n";

                                    cout << "\n====================";
                                    cout << "\n      GAME OVER     ";
                                    cout << "\n====================";
                                    cout << "\n\n" << name << " reached Level " << lvl;
                                    cout << "\nFinal Gold: " << gold;
                                    cout << "\nFinal XP: " << xp << "\n\n";
                                    return 0;
                                }
                                cout << "\n\nYour HP: " << hp;

                                do {
                                    cout << "\n\nAttack again? (A) or Run away? (R) or Use Potions? (P): ";
                                    cin >> attchoice;

                                    if (attchoice == "A" || attchoice == "a") {
                                        cout << "\nYou attack again!";
                                    } else if (attchoice == "R" || attchoice == "r") {
                                        cout << "\nYou ran away! :(\n";
                                    } else if (attchoice == "P" || attchoice == "p") {
                                        if (potions < 1) {
                                            cout << "\nYou don't have any potions!";
                                            attchoice = "";
                                        } else {
                                            cout << "\nYou used a potion! +20 HP restored!\n";
                                            hp += 20;
                                            potions--;

                                            if (hp > maxhp + 100) {
                                                hp = maxhp + 100;
                                            }
                                            cout << "\nThe Wolf attacks while you recover!";
                                            cout << "\n\nWolf deals " << potionenemyatt << " damage!";
                                            hp -= potionenemyatt;

                                            if (hp < 0) {
                                                hp = 0;
                                            }
                                            if (hp == 0) {
                                                cout << "\n\nYou have no HP left!";
                                                cout << "\nYou died! X(\n";

                                                cout << "\n====================";
                                                cout << "\n      GAME OVER     ";
                                                cout << "\n====================";
                                                cout << "\n\n" << name << " reached Level " << lvl;
                                                cout << "\nFinal Gold: " << gold;
                                                cout << "\nFinal XP: " << xp << "\n\n";
                                                return 0;
                                            }
                                            cout << "\n\nYour HP: " << hp;
                                            attchoice = "";
                                        }
                                    } else {
                                        cout << "\nInvalid choice! Enter only A or R or P.\n";
                                    }
                                } while (attchoice != "A" && attchoice != "a" &&
                                         attchoice != "R" && attchoice != "r" &&
                                         attchoice != "P" && attchoice != "p");
                            }
                        } while (enemyhp != 0 && ((attchoice == "A" || attchoice == "a") ||
                                                   (attchoice == "P" || attchoice == "p")));
                        break;
                    }

                    case 2:
                        cout << "\nYou ran away! :(\n";
                        break;

                    default:
                        cout << "\nInvalid choice!\n";
                        break;
                    }
                } while (choicep1 != 1 && choicep1 != 2);

            } else if (enc == 3) {
                do {
                    cout << "\nA wild Bandit appears!";
                    cout << "\n\nYour HP: " << hp;
                    cout << "\nBandit HP: " << enemyhp;
                    cout << "\n\n1. Attack\n2. Run\n";
                    cout << "\nWhat will you do?: ";
                    cin >> choicep1;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "\nInvalid choice!\n";
                        continue;
                    }

                    cin.ignore(1000, '\n');
                    string attchoice;

                    switch (choicep1) {

                    case 1: {
                        do {
                            int enemyatt = rand() % 15 + 1;
                            int potionenemyatt = rand() % 15 + 1;
                            int p1att = rand() % attpwr + 1;

                            cout << "\n\nYou dealt " << p1att << " damage!";
                            enemyhp -= p1att;

                            if (enemyhp < 0) {
                                enemyhp = 0;
                            }
                            cout << "\n\nBandit HP: " << enemyhp;

                            if (enemyhp == 0) {
                                cout << "\n\nYou defeated the Bandit!\n";
                                cout << "\n+" << reward << " Gold";
                                cout << "\n+" << xp1 << " XP\n";
                                xp += xp1;
                                gold += reward;
                                bandit++;

                                while (xp >= xpthres) {
                                    cout << "\n==============================\n";
                                    cout << "            LEVEL UP!             ";
                                    cout << "\n==============================\n";
                                    lvl++;
                                    xp -= xpthres;
                                    xpthres += 100;
                                    maxhp += 20;
                                    hp = maxhp + 100;
                                    attpwr += 5;
                                    cout << "\nYou reached Level " << lvl << "!\n";
                                    cout << "\nAttack increased!";
                                    cout << "\nMaximum HP increased!";
                                    cout << "\nHP Restored!\n";
                                }

                            } else {

                                cout << "\n\nBandit deals " << enemyatt << " damage!";
                                hp -= enemyatt;

                                if (hp < 0) {
                                    hp = 0;
                                }
                                if (hp == 0) {
                                    cout << "\n\nYou have no HP left!";
                                    cout << "\nYou died! X(\n";

                                    cout << "\n====================";
                                    cout << "\n      GAME OVER     ";
                                    cout << "\n====================";
                                    cout << "\n\n" << name << " reached Level " << lvl;
                                    cout << "\nFinal Gold: " << gold;
                                    cout << "\nFinal XP: " << xp << "\n\n";
                                    return 0;
                                }
                                cout << "\n\nYour HP: " << hp;

                                do {
                                    cout << "\n\nAttack again? (A) or Run away? (R) or Use Potions? (P): ";
                                    cin >> attchoice;

                                    if (attchoice == "A" || attchoice == "a") {
                                        cout << "\nYou attack again!";
                                    } else if (attchoice == "R" || attchoice == "r") {
                                        cout << "\nYou ran away! :(\n";
                                    } else if (attchoice == "P" || attchoice == "p") {
                                        if (potions < 1) {
                                            cout << "\nYou don't have any potions!";
                                            attchoice = "";
                                        } else {
                                            cout << "\nYou used a potion! +20 HP restored!\n";
                                            hp += 20;
                                            potions--;

                                            if (hp > maxhp + 100) {
                                                hp = maxhp + 100;
                                            }
                                            cout << "\nThe Bandit attacks while you recover!";
                                            cout << "\n\nBandit deals " << potionenemyatt << " damage!";
                                            hp -= potionenemyatt;

                                            if (hp < 0) {
                                                hp = 0;
                                            }
                                            if (hp == 0) {
                                                cout << "\n\nYou have no HP left!";
                                                cout << "\nYou died! X(\n";

                                                cout << "\n====================";
                                                cout << "\n      GAME OVER     ";
                                                cout << "\n====================";
                                                cout << "\n\n" << name << " reached Level " << lvl;
                                                cout << "\nFinal Gold: " << gold;
                                                cout << "\nFinal XP: " << xp << "\n\n";
                                                return 0;
                                            }
                                            cout << "\n\nYour HP: " << hp;
                                            attchoice = "";
                                        }
                                    } else {
                                        cout << "\nInvalid choice! Enter only A or R or P.\n";
                                    }
                                } while (attchoice != "A" && attchoice != "a" &&
                                         attchoice != "R" && attchoice != "r" &&
                                         attchoice != "P" && attchoice != "p");
                            }
                        } while (enemyhp != 0 && ((attchoice == "A" || attchoice == "a") ||
                                                   (attchoice == "P" || attchoice == "p")));
                        break;
                    }

                    case 2:
                        cout << "\nYou ran away! :(\n";
                        break;

                    default:
                        cout << "\nInvalid choice!\n";
                        break;
                    }
                } while (choicep1 != 1 && choicep1 != 2);

            } else {
                cout << "\nTry again!\n";
            }
            break;
        }

        case 2:
            cout << "\nName: " << name;
            cout << "\nHP: " << hp << '/' << maxhp + 100;
            cout << "\nGold: " << gold;
            cout << "\nAttack: " << attpwr;
            cout << "\nLevel: " << lvl;
            cout << "\nPotions: " << potions;
            cout << "\nXP: " << xp << '/' << xpthres << '\n';
            cout << "\nTotal enemies slain: " << goblin + wolf + bandit;
            cout << "\nGoblins slain: " << goblin;
            cout << "\nWolves slain: " << wolf;
            cout << "\nBandits slain: " << bandit << '\n';
            break;

        case 3: {
            int shopchoice = 0;
            do {
                cout << "\n========== SHOP ==========\n";
                cout << "\nGold: " << gold << "\n\n";
                cout << "1. Health Potion - 20 Gold";
                cout << "\n2. Sword Upgrade - 100 Gold";
                cout << "\n3. Leave Shop\n\n";
                cout << "Enter choice: ";
                cin >> shopchoice;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "\nInvalid choice!\n";
                    continue;
                }

                cin.ignore(1000, '\n');

                if (shopchoice == 1 && potions == 5) {
                    cout << "\nInventory Full!\n";
                } else if (shopchoice == 3) {
                    cout << "\nThanks for shopping with us!\n";
                } else if (shopchoice == 1 && gold < 20) {
                    cout << "\nGTFO! Poor fellow!\n";
                } else if (shopchoice == 1) {
                    cout << "\nYou bought a Health Potion!\n";
                    gold -= 20;
                    potions++;
                    cout << "\nGold: " << gold << '\n';
                    cout << "\nPotions: " << potions << '\n';
                } else if (shopchoice == 2 && sword == 1) {
                    cout << "\nYou already have the sword!\n";
                } else if (shopchoice == 2 && gold < 100) {
                    cout << "\nGTFO! Poor fellow!\n";
                } else if (shopchoice == 2) {
                    cout << "\nYou bought the sword!\n";
                    cout << "\nAttack Power is now increased by 10!\n";
                    attpwr += swordpwr;
                    sword++;
                    gold -= 100;
                } else {
                    cout << "\nInvalid choice!\n";
                }
            } while (shopchoice != 3);
            break;
        }

        case 4: {
            string inn;

            do {
                cout << "\nGold: " << gold << "\n\n";

                cout << "Rest at the Inn for 15 Gold? (Y/N): ";
                cin >> inn;

                if (inn == "Y" || inn == "y") {
                    if (gold < 15) {
                        cout << "\nInsufficient Gold! Get outta here! Poor fellow..\n";
                    } else {
                        gold -= 15;
                        hp = 100 + maxhp;
                        cout << "\nYour HP is restored to " << hp << " again!\n";
                    }
                } else if (inn == "N" || inn == "n") {
                    cout << "\nWe hope to see you again soon!\n";
                } else {
                    cout << "\nInvalid choice!\n";
                }
            } while (inn != "Y" && inn != "y" && inn != "N" && inn != "n");
            break;
        }

        case 5:
            cout << "\nThanks for playing! We hope to see you again!\n\n";
            return 0;

        default:
            cout << "\nInvalid choice!\n";
            break;
        }

    } while (choice != 5);

    cout << "\033[32m";

    return 0;
}