// ! level func.

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

    // Function to level up the skill
    void levelUp() {
        damage += 5; // Increase damage by 5 upon leveling up
        cout << "Your skill " << name << " has leveled up! Damage increased to " << damage << "." << endl;
    }

private:
    string name;
    int damage;
    string effect;
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

class Player {
public:
    // Constructor to initialize player
    Player() {
        level = 1;
        exp = 0;
    }

    // Function to gain experience points
    void gainExp(int expPoints) {
        exp += expPoints;
        cout << "You gained " << expPoints << " experience points!" << endl;

        // Check if the player levels up
        while (exp >= expRequired) {
            levelUp();
        }
    }

    // Function to level up the player
    void levelUp() {
        level++;
        exp -= expRequired;
        expRequired = static_cast<int>(expRequired * 1.15); // Increase required exp by 15% per level

        cout << "Congratulations! You leveled up to level " << level << "!" << endl;

        // Randomly choose to gain a new skill or level up an existing skill
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 1);
        int choice = dis(gen);

        if (choice == 0) {
            // Gain a new skill
            cout << "You gained a new skill!" << endl;
            // Code to add a new skill goes here
        } else {
            // Level up an existing skill
            cout << "One of your skills has leveled up!" << endl;
            // Code to level up a random skill goes here
        }
    }

private:
    int level;
    int exp;
    int expRequired = 5;
};

int main() {
    // Initialize health
    int initialHealth = 100;
    Health playerHealth(initialHealth);

    // Create a player
    Player player;

    // Simulate gaining experience points
    player.gainExp(10); // Example: Gain 10 exp
    player.gainExp(20); // Example: Gain 20 exp

    // Print the player's level and experience
    cout << "Player Level: " << player.getLevel() << endl;
    cout << "Experience Points: " << player.getExp() << endl;

    // Print the player's health
    playerHealth.printHealth();

    return 0;
}