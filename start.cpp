#include <iostream>
#include <string>
#include <vector>

// ! to make sure code runs.

int main() {
    std::cout << "Hello World!";
    return 0;
}

// ! health func.

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


}


// ! skill func.

using namespace std;

// Define the Skill class
class Skill {
public:
    // Constructor to initialize skill name and damage
    Skill(string name, int damage) {
        this->name = name;
        this->damage = damage;
    }

    // Function to apply the skill
    void apply(Health& target, vector<string>& statusEffects) {
        // Check if the target has the required status effects
        bool hasRequiredStatusEffects = true;
        for (string statusEffect : requiredStatusEffects) {
            if (find(statusEffects.begin(), statusEffects.end(), statusEffect) == statusEffects.end()) {
                hasRequiredStatusEffects = false;
                break;
            }
        }

        // If the target has the required status effects, apply the skill
        if (hasRequiredStatusEffects) {
            target.applyStatusEffects(statusEffects);
            target.health -= damage;
            cout << "You used " << name << "!" << endl;
        } else {
            cout << "You don't have the required status effects to use " << name << "!" << endl;
        }
    }

private:
    string name;
    int damage;
    vector<string> requiredStatusEffects;
};

// Define the Health class
class Health {
public:
    // Constructor to initialize health and status effects
    Health(int initialHealth, vector<string> statusEffects) {
        health = initialHealth;
        this->statusEffects = statusEffects;
    }

    // Function to apply status effects
    void applyStatusEffects(vector<string> statusEffects) {
        // Iterate through each status effect
        for (string statusEffect : statusEffects) {
            // Apply the status effect
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

    // Function to print the health
    void printHealth() {
        cout << "Health: " << health << endl;
    }

private:
    int health;
    vector<string> statusEffects;
};

int main() {
    // Initialize health and status effects
    int initialHealth = 100;
    vector<string> statusEffects = {"burning", "bleeding"};

    // Create a Health object
    Health playerHealth(initialHealth, statusEffects);

    // Create a vector of skills
    vector<Skill> skills;
    skills.push_back(Skill("Fireball", 10));
    skills.push_back(Skill("Bloodletting", 15));
    skills.push_back(Skill("Ice Shard", 20));

    // Get the player's input
    string input;
    cout << "Enter the skill you want to use: ";
    cin >> input;

    // Find the skill in the vector
    Skill* skill = nullptr;
    for (Skill& s : skills) {
        if (s.name == input) {
            skill = &s;
            break;
        }
    }

    // If the skill was found, apply it
    if (skill) {
        skill->apply(playerHealth, statusEffects);
    } else {
        cout << "Invalid skill!" << endl;
    }

    // Print the player's health
    playerHealth.printHealth();

    return 0;
}
}