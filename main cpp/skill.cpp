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
        return (effect == "burning" || effect == "bleeding" || effect == "frostbite" || effect == "poisoned" );
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
    skills.push_back(Skill("Poison Drops", 5, "poison"));
    skills.push_back(Skill("Motivation", 0,"Motivation")); // ! Special buffing skill

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


}