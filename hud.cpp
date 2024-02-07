// ! WIP.

#include <iostream>
#include <string>

using namespace std;

// Define the Player class
class Player {
public:
    // Constructor to initialize player's health and level
    Player(int initialHealth, int initialLevel) : health(initialHealth), level(initialLevel) {}

    // Function to update player's health
    void updateHealth(int newHealth) {
        health = newHealth;
    }

    // Function to update player's level
    void updateLevel(int newLevel) {
        level = newLevel;
    }

    // Function to display HUD
    void displayHUD() {
        // Clear the screen
        system("cls"); // For Windows
        //system("clear"); // For Unix/Linux/Mac

        // Display HUD
        cout << "Health: " << health << endl;
        cout << "Level: " << level << endl;
    }

private:
    int health;
    int level;
};

int main() {
    // Create a player object
    Player player(100, 1);

    // Update player's health and level (for demonstration)
    player.updateHealth(80);
    player.updateLevel(2);

    // Display HUD
    player.displayHUD();

    return 0;
}