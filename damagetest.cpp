#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Enum to represent different status effects
enum StatusEffect {
    HEAVY_BURNING,
    BURNING,
    WEAK_BURNING,
    FROSTBITE,
    CURSED,
    POISON,
    BLEEDING
};

// Define the Skill class
class Skill {
public:
    Skill(string name) : name(name) {}

    string getName() const {
        return name;
    }

private:
    string name;
};

int main() {
    // List of owned skills
    vector<Skill> ownedSkills = {
        Skill("Icy bite"),  // Example: Skill("Icy bite") is owned
        Skill("Fire"),      // Example: Skill("Fire") is owned
        Skill("Bloodletting"),  // Example: Skill("Bloodletting") is owned
        Skill("Poison Drops")   // Example: Skill("Poison Drops") is owned
        // Add other owned skills here
    };

    // Flag to track if Roots of Hell is activated
    bool rootsOfHellActivated = false;

    // Check owned skills to apply status effects
    for (const Skill& skill : ownedSkills) {
        if (skill.getName() == "Icy bite") {
            // Apply Frostbite status effect
            cout << "Frostbite applied due to skill: " << skill.getName() << endl;
            // You can implement the logic to apply the status effect here
        } else if (skill.getName() == "Fire") {
            // Apply Burning status effect
            cout << "Burning applied due to skill: " << skill.getName() << endl;
            // You can implement the logic to apply the status effect here
        } else if (skill.getName() == "Bloodletting") {
            // Apply Bleeding status effect
            cout << "Bleeding applied due to skill: " << skill.getName() << endl;
            // You can implement the logic to apply the status effect here
        } else if (skill.getName() == "Poison Drops") {
            // Apply Poison status effect
            cout << "Poison applied due to skill: " << skill.getName() << endl;
            // You can implement the logic to apply the status effect here
        } else if (skill.getName() == "Roots of Hell") {
            // Activate Roots of Hell and apply all status effects
            cout << "Roots of Hell activated!" << endl;
            rootsOfHellActivated = true;
        }
    }

    // If Roots of Hell is activated, apply all status effects
    if (rootsOfHellActivated) {
        cout << "All status effects applied due to Roots of Hell!" << endl;
        // You can implement the logic to apply all status effects here
    }

    return 0;
}