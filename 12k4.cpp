#include <iostream>
using namespace std;

//Compiler version g++ 6.3.0

int main()
{
    cout << "Hello, Dcoder!";
}
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Character {
private:
    string name;
    int health;
    int attackPower;

public:
    Character(string n, int h, int a) {
        name = n;
        health = h;
        attackPower = a;
    }

    string getName() {
        return name;
    }

    int getHealth() {
        return health;
    }

    void takeDamage(int damage) {
        health -= damage;
    }

    int getAttackPower() {
        return attackPower;
    }
};

void battle(Character& player, Character& enemy) {
    srand(time(0)); // To generate random numbers
    while (player.getHealth() > 0 && enemy.getHealth() > 0) {
        // Player attacks
        int playerAttack = rand() % player.getAttackPower();
        enemy.takeDamage(playerAttack);
        cout << player.getName() << " attacks! Enemy Health: " << enemy.getHealth() << endl;

        if (enemy.getHealth() > 0) {
            // Enemy attacks
            int enemyAttack = rand() % enemy.getAttackPower();
            player.takeDamage(enemyAttack);
            cout << enemy.getName() << " attacks! Player Health: " << player.getHealth() << endl;
        }

        if (player.getHealth() <= 0) {
            cout << player.getName() << " is defeated. Try Again." << endl;
            break;
        }
        else if (enemy.getHealth() <= 0) {
            cout << player.getName() << " wins! 12k4" << endl;
            break;
        }
    }
}

int main() {
    string playerName, enemyName;
    int playerAttack, enemyAttack;

    // Input for player
    cout << "Enter Player Name: ";
    cin >> playerName;
    cout << "Enter Player Attack Power: ";
    cin >> playerAttack;

    // Input for enemy
    cout << "Enter Enemy Name: ";
    cin >> enemyName;
    cout << "Enter Enemy Attack Power: ";
    cin >> enemyAttack;

    // Create Player and Enemy objects
    Character player(playerName, 100, playerAttack);
    Character enemy(enemyName, 80, enemyAttack);

    // Start the battle
    battle(player, enemy);

    return 0;
}