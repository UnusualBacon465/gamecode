// ! rarity module

#include <iostream>
#include <string>
#include <random>

// Define the rarity levels
const std::string rarities[] = {
    "common", "uncommon", "rare", "epic", "legendary", "mythical", "divine", "demonic", "artifact"
};

// Define the bonus percentages of each rarity
const double rarityBonuses[] = {
    0.0, 0.05, 0.15, 0.30, 0.45, 0.60, 1.0, 2.50, 10.0
};

// Function to generate a random weapon or equipment
void generateItem(int level, std::string rarity) {
    // Generate a random name for the item
    std::string name = "Item " + std::to_string(rand() % 1000 + 1);

    // Generate the item's base stats
    int attack = rand() % 10 + 1;
    int defense = rand() % 10 + 1;
    int health = rand() % 10 + 1;

    // Apply the rarity bonus to the stats
    double rarityBonus = rarityBonuses[0]; // Default to common rarity
    for (int i = 1; i < sizeof(rarities) / sizeof(rarities[0]); i++) {
        if (rarities[i] == rarity) {
            rarityBonus = rarityBonuses[i];
            break;
        }
    }
    attack += attack * rarityBonus;
    defense += defense * rarityBonus;
    health += health * rarityBonus;

    // Print the item's name, rarity, and stats
    std::cout << "Item: " << name << std::endl;
    std::cout << "Rarity: " << rarity << std::endl;
    std::cout << "Stats: Attack=" << attack << ", Defense=" << defense << ", Health=" << health << std::endl;
}

int main() {
    // Set the random seed
    srand(time(0));

    // Generate a random weapon or equipment for a player of level 20 with rarity "legendary"
    int playerLevel = 20;
    std::string playerRarity = "legendary";
    generateItem(playerLevel, playerRarity);

    return 0;
}