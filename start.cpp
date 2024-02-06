#include <iostream>
#include <string>
#include <vector>
#include <random> // For random number generation

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
    // Constructor to initialize skill name, damage, and effect
    Skill(string name, int damage, string effect) {
        this->name = name;
        this->damage = damage;
        this->effect = effect;
    }

    // Function to apply the skill
    void apply(Health& target, bool swordAuraActive, int swordMasteryLevel) {
        // Check if the skill is affected by the sword aura
        if (swordAuraActive && hasStatusEffect()) {
            // Apply the skill with reduced effectiveness based on Sword Mastery level
            int reducedDamage = static_cast<int>(damage * (1.0 - (swordMasteryLevel * 0.05))); // Reduce negative effect by 5% per level
            target.applyStatusEffect(effect);
            target.health -= reducedDamage;
            cout << "You used " << name << " with reduced effectiveness due to Sword Aura and Sword Mastery level " << swordMasteryLevel << "!" << endl;
        } else {
            // Apply the skill normally based on Sword Mastery level
            int modifiedDamage = damage + (swordMasteryLevel * 3); // Increase flat damage by 3 per level
            target.applyStatusEffect(effect);
            target.health -= modifiedDamage;
            cout << "You used " << name << " and triggered the " << effect << " effect with Sword Mastery level " << swordMasteryLevel << "!" << endl;
        }
    }

private:
    string name;
    int damage;
    string effect;

    // Function to check if the skill has a status effect
    bool hasStatusEffect() {
        return (effect == "burning" || effect == "bleeding" || effect == "frostbite");
    }
};

// Define the Health class
class Health {
public:
    // Constructor to initialize health
    Health(int initialHealth) {
        health = initialHealth;
    }

    // Function to apply a status effect
    void applyStatusEffect(string effect) {
        // Apply the status effect
        // Code to apply the specific effect goes here
        cout << "The " << effect << " effect is applied!" << endl;
    }

    // Function to print the health
    void printHealth() {
        cout << "Health: " << health << endl;
    }

private:
    int health;
};

int main() {
    // Initialize health
    int initialHealth = 100;
    Health playerHealth(initialHealth);

    // Create a vector of skills
    vector<Skill> skills;
    skills.push_back(Skill("Fire", 10, "burning"));
    skills.push_back(Skill("Bloodletting", 15, "bleeding"));
    skills.push_back(Skill("Icy bite", 20, "frostbite"));
    skills.push_back(Skill("Sword Aura", 0, "sword_aura")); // Special skill for Sword Aura
    skills.push_back(Skill("Sword Mastery", 0, "sword_mastery")); // Special skill for Sword Mastery

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
        // Check if Sword Aura is active
        bool swordAuraActive = (input == "Sword Aura");

        // Check if Sword Mastery level is active
        int swordMasteryLevel = 3; // Set the Sword Mastery level here

        // Apply the skill
        skill->apply(playerHealth, swordAuraActive, swordMasteryLevel);
    } else {
        cout << "Invalid skill!" << endl;
    }

    // Print the player's health
    playerHealth.printHealth();

    return 0;
}
}