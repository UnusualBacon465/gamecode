#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define the Health class
class Health {
public:
    // Constructor to initialize health and status effects
    Health(int initialHealth, vector<string> statusEffects) {
        health = initialHealth;
        this->statusEffects = statusEffects;
    }

    // Function to apply status effects
    void applyStatusEffects(vector<string>& ownedSkills) {
        // Check if the player has the Axis Personality skill
        bool hasAxisPersonality = false;
        for (string skill : ownedSkills) {
            if (skill == "Axis Personality") {
                hasAxisPersonality = true;
                break;
            }
        }

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
            } else if (statusEffect == "cursed" && hasAxisPersonality) {
                // Apply curse effect if the player has Axis Personality skill
                cout << "You are cursed and deal 200% less damage due to Axis Personality!" << endl;
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

    // Player's owned skills
    vector<string> ownedSkills = {"Axis Personality"};

    // Apply status effects
    playerHealth.applyStatusEffects(ownedSkills);

    // Print the health
    playerHealth.printHealth();

    return 0;
}