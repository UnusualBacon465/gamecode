#include <iostream>
#include <string>
#include <vector>

// ! to make sure code runs.

int main() {
    std::cout << "Hello World!";
    return 0;
}

// * health func.
{
using namespace std;

// * Define the Health class
class Health {
public:
    // Constructor to initialize health and status effects
    Health(int initialHealth, vector<string> statusEffects) {
        health = initialHealth;
        this->statusEffects = statusEffects;
    }

    // ! Function to apply status effects
    void applyStatusEffects() {
        // Iterate through each status effect
        for (string statusEffect : statusEffects) {
            // ! Apply the status effect
            if (statusEffect == "burning") {
                health -= 2; // 2% DoT
            } else if (statusEffect == "bleeding") {
                health -= 3.5; // 3.5% DoT
            } else if (statusEffect == "frostbitten") {
                // Slow the player by 65%
                cout << "You are slowed by 65% due to frostbite!" << endl;
            }
        }
    }

    // ! Function to print the health
    void printHealth() {
        cout << "Health: " << health << endl;
    }

private:
    int health;
    vector<string> statusEffects;
};

int main() {
    // * Initialize health and status effects
    int initialHealth = 100;
    vector<string> statusEffects = {"burning", "bleeding"};

    // * Create a Health object
    Health playerHealth(initialHealth, statusEffects);

    // * Apply status effects
    playerHealth.applyStatusEffects();

    // * Print the health
    playerHealth.printHealth();

}

// ! damage func.

using namespace std;

// * Define the Damage function
int damage(int baseDamage) {
    // Calculate the damage
    int damageDealt = baseDamage;

    // Apply any modifiers (e.g., critical hits, resistances)

    // Return the damage dealt
    return damageDealt;
}

int main() {
    // Initialize the player's and enemy's health
    int playerHealth = 100;
    int enemyHealth = 100;

    // Get the player's and enemy's attack power
    int playerAttackPower = 5;
    int enemyAttackPower = 5;

    // Calculate the damage dealt by the player and enemy
    int playerDamage = damage(playerAttackPower);
    int enemyDamage = damage(enemyAttackPower);

    // Apply the damage to the player and enemy
    playerHealth -= playerDamage;
    enemyHealth -= enemyDamage;

    // Print the player's and enemy's health
    cout << "Player health: " << playerHealth << endl;
    cout << "Enemy health: " << enemyHealth << endl;

    return 0;
}
}