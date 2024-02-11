#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib> // For rand()

using namespace std;

// Define the Skill class
class Skill {
public:
    // Constructor to initialize skill name, damage, and effect
    Skill(string name, int damage, string effect, bool isPassive = false) {
        this->name = name;
        this->damage = damage;
        this->effect = effect;
        this->isPassive = isPassive;
    }

    // Function to apply the skill
    void apply(class Health& target, bool swordAuraActive, int swordMasteryLevel, bool motivationActive, bool isActive) {
        if (!isActive) return; // Exit if the skill is not active

        // Check if the skill is affected by the sword aura
        if (swordAuraActive && hasStatusEffect()) {
            // Apply the skill with reduced effectiveness based on Sword Mastery level
            int reducedDamage = static_cast<int>(damage * (1.0 - (swordMasteryLevel * 0.05))); // Reduce negative effect by 5% per level
            target.applyStatusEffect(effect);
            target.health -= reducedDamage;
            cout << "You used " << name << " with reduced effectiveness due to Sword Aura and Sword Mastery level " << swordMasteryLevel << "!" << endl;
        } else if (name == "Axis Personality") {
            // Apply the Axis Personality debuff
            int debuff = 200; // Base debuff value
            if (motivationActive) {
                // Modify debuff based on motivation
                debuff /= 2; // Half the debuff if motivation is active
            }
            target.applyStatusEffect(effect);
            target.health -= debuff;
            cout << "You used " << name << " and debuffed the player by " << debuff << " times!" << endl;
        } else if (name == "Pain Split") {
            // Apply Pain Split
            float selfDamagePercentage = 0.2f; // Base self damage percentage
            if (motivationActive) {
                selfDamagePercentage *= 0.8f; // Reduce self damage by 20% if motivation is active
            }
            float totalDamage = damage * 1.5f; // Deal 50% more damage
            float selfDamage = min(totalDamage * selfDamagePercentage, 0.5f * target.health); // Cap self damage to 50% of current health
            target.applyStatusEffect(effect);
            target.health -= selfDamage;
            cout << "You used " << name << " and dealt " << totalDamage << " damage, taking " << selfDamage << " as self damage!" << endl;
        } else if (name == "Sharp Edge") {
            // Apply Sharp Edge
            float totalDamage = damage * 1.4f; // Increase damage by 40%
            target.applyStatusEffect(effect);
            target.health -= totalDamage;
            cout << "You used " << name << " and dealt " << totalDamage << " damage!" << endl;
        } else if (name == "Pyromaniac") {
            // Apply Pyromaniac
            float totalDamage = damage * 1.2f; // Increase fire damage by 20%
            if (rand() % 100 < 5 && !motivationActive) { // 5% chance to self ignite if motivation is not active
                target.applyStatusEffect("self_ignite");
                cout << "You used " << name << " and self-ignited due to the Pyromaniac effect!" << endl;
            }
            target.applyStatusEffect(effect);
            target.health -= totalDamage;
            cout << "You used " << name << " and dealt " << totalDamage << " fire damage!" << endl;
        } else if (name == "Kings Regression") {
            // Apply Kings Regression
            float selfDamage = target.health * 0.3f; // Take 30% of current health as self damage
            target.applyStatusEffect("bleeding");
            target.health -= selfDamage;
            cout << "You used " << name << " and took " << selfDamage << " damage, inflicting bleeding status!" << endl;
        } else if (name == "Unholy Crown") {
            // Apply Unholy Crown
            float totalDamage = damage * 1.4f; // Increase damage by 40%
            target.applyStatusEffect("strong_bleed");
            target.health -= totalDamage;
            cout << "You used " << name << " and dealt " << totalDamage << " damage with strong bleed effect!" << endl;
        } else if (name == "Sadistic") {
            // Apply Sadistic
            float increasedDamage = damage * (attackCounter * 0.01f); // Increase damage based on attack count
            target.applyStatusEffect(effect);
            target.health -= increasedDamage;
            cout << "You used " << name << " and dealt " << increasedDamage << " damage!" << endl;
        } else if (name == "Roots Of Hell") {
            // Apply Roots Of Hell
            // Delay before activation
            cout << "Charging " << name << "... (5s)" << endl;
            this_thread::sleep_for(chrono::seconds(5));

            // Check if the skill is on cooldown
            if (cooldownTimer > 0) {
                cout << name << " is on cooldown! Remaining cooldown: " << cooldownTimer << "s" << endl;
                return;
            }

            // Apply the skill effects
            // Assuming the player is at position (0, 0) and enemies are represented as (x, y) coordinates
            const float radius1 = 10.0f; // 10 meters radius
            const float radius2 = 15.0f; // 5 meters outside the main radius
            const float radius3 = 20.0f; // 5 meters outside the secondary radius

            // Simulate enemies in a vector
            vector<pair<float, float>> enemies = { {1.0f, 2.0f}, {5.0f, 6.0f}, {11.0f, 12.0f}, {16.0f, 17.0f}, {20.0f, 21.0f} };

            for (auto& enemy : enemies) {
                float distance = sqrt(pow(enemy.first, 2) + pow(enemy.second, 2)); // Calculate distance from player
                if (distance <= radius1) {
                    target.applyStatusEffect("burning");
                    cout << "Enemy at (" << enemy.first << ", " << enemy.second << ") is consumed by the " << name << " within the main radius!" << endl;
                } else if (distance <= radius2) {
                    target.applyStatusEffect("heavy_burning");
                    cout << "Enemy at (" << enemy.first << ", " << enemy.second << ") is affected by heavy burning from the " << name << "!" << endl;
                } else if (distance <= radius3) {
                    target.applyStatusEffect("normal_burning");
                    cout << "Enemy at (" << enemy.first << ", " << enemy.second << ") is affected by normal burning from the " << name << "!" << endl;
                } else {
                    target.applyStatusEffect("weak_burning");
                    cout << "Enemy at (" << enemy.first << ", " << enemy.second << ") is affected by weak burning from the " << name << "!" << endl;
                }
            }

            // Start cooldown timer
            cooldownTimer = 300; // 5 minutes cooldown
        } else {
            // Apply the skill normally based on Sword Mastery level
            int modifiedDamage = damage + (swordMasteryLevel * 3); // Increase flat damage by 3 per level
            target.applyStatusEffect(effect);
            target.health -= modifiedDamage;
            cout << "You used " << name << " and triggered the " << effect << " effect with Sword Mastery level " << swordMasteryLevel << "!" << endl;
        }
    }

    // Function to update attack count for Sadistic skill
    static void incrementAttackCounter() {
        attackCounter++;
    }

    // Function to reset attack counter
    static void resetAttackCounter() {
        attackCounter = 0;
    }

    // Function to check if the skill has a status effect
    bool hasStatusEffect() {
        return (effect == "burning" || effect == "bleeding" || effect == "frostbite" || effect == "poisoned" || effect == "irradiated");
    }

    // Function to check if the skill is passive
    bool isPassiveSkill() {
        return isPassive;
    }

private:
    string name;
    int damage;
    string effect;
    bool isPassive;
    static int attackCounter;
    static int cooldownTimer; // Cooldown timer in seconds
};

int Skill::attackCounter = 0;
int Skill::cooldownTimer = 0;

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

    // Function to buff health and speed
    void buffHealthAndSpeed(float buffPercentage) {
        health *= (1.0f + buffPercentage); // Increase health by buffPercentage%
        cout << "Health is buffed by " << (buffPercentage * 100) << "%!" << endl;
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
    skills.push_back(Skill("Fire", 10, "burning", true));
    skills.push_back(Skill("Bloodletting", 15, "bleeding", true));
    skills.push_back(Skill("Icy bite", 20, "frostbite", true));
    skills.push_back(Skill("Sword Aura", 0, "sword_aura", true)); // Special skill for Sword Aura
    skills.push_back(Skill("Sword Mastery", 0, "sword_mastery", true)); // Special skill for Sword Mastery
    skills.push_back(Skill("Poison Drops", 5, "poison", true));
    skills.push_back(Skill("Motivation", 0, "Motivation", true)); // ! Special buffing skill
    skills.push_back(Skill("Axis Personality", 0, "axis_personality", true)); // ! Debuffs the player
    skills.push_back(Skill("Pain Split", 0, "pain_split"));
    skills.push_back(Skill("Sharp Edge", 0, "sharp_edge", true)); // ! Adds 40% more damage to all non-elemental attacks
    skills.push_back(Skill("Pyromaniac", 0, "pyro", true)); // ! Deals 20% more damage but has a 5% chance to self ignite
    skills.push_back(Skill("Kings Regression", 0, "kings_regression")); // ! Player stabs self causing 30% health loss and bleed status, but player gains bleed to all attacks and bleed does 60% more damage to enemies, lasting 2 minutes, has a cooldown of 3 minutes.
    skills.push_back(Skill("Unholy Crown", 0, "unholy_crown")); // ! Player loses 20% of hp upon putting on the crown and gets stronger than normal bleeding status, but deals 50% more damage with ALL attacks
    skills.push_back(Skill("Ashen Slash", 15, "radioactive"));
    skills.push_back(Skill("Gunsmith", 0, "gunsmith", true)); // ! Player's firearms deal 15% more damage and found and created weapons have a 27.5% chance to be of a higher tier. 1% chance for an upgrade to skip a tier.
    skills.push_back(Skill("Brawler", 0, "brawler", true)); // ! Player deals 20% more damage with fists and has a 5% chance to bleed enemies, additive with motivation, sharp edge, Kings Regression, and Unholy Crown
    skills.push_back(Skill("Sadistic", 0, "sadist", true)); // ! Deal increasing damage with each attack
    skills.push_back(Skill("Roots Of Hell", 0, "roots_of_hell")); // ! Stab weapon into the ground, causing fiery destruction
    skills.push_back(Skill("Flash Step", 0, "flash_step")); // ! player teleports and can teleport from side to side
    skills.push_back(Skill("Judgement Day", 0, "judgement_day")); // ! player cuts everythings around them in a 20m radius obliterating everything in its radius, has a cooldown of 7m.   

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

        // Check if Motivation is active
        bool motivationActive = false;
        if (input == "Motivation") {
            motivationActive = true;
        }

        // Apply the skill
        bool isActive = true; // Assume the skill is active by default
        if (input == "Sadistic" || input == "Brawler" || input == "Gunsmith" || input == "Fire" || input == "Bloodletting" || input == "Icy bite" || input == "Sword Aura" || input == "Sword Mastery" || input == "Roots Of Hell") {
            isActive = false; // These skills are passive
        }
        skill->apply(playerHealth, swordAuraActive, swordMasteryLevel, motivationActive, isActive);
    } else {
        cout << "Invalid skill!" << endl;
    }

    // Print the player's health
    playerHealth.printHealth();

    return 0;
}