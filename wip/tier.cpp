// ! tier module

#include <iostream>
#include <string>
#include <random>

// Define the tier levels
const int numTiers = 5;
const int tierBonuses[numTiers] = {0, 50, 100, 150, 200};

// Define the special materials required for each tier
const std::string specialMaterials[numTiers] = {
    "iron ore",
    "steel ingot",
    "mithril bar",
    "adamantine ingot",
    "dragon scale" // * current materials are to be changed
};

// Function to generate a random weapon or equipment
void generateItem(int level, int tier) {
    // Generate a random name for the item
    std::string name = "Item " + std::to_string(rand() % 1000 + 1);

    // Generate the item's base stats
    int attack = rand() % 10 + 1;
    int defense = rand() % 10 + 1;
    int health = rand() % 10 + 1;

    // Apply the tier bonus to the stats
    attack += attack * tierBonuses[tier] / 100;
    defense += defense * tierBonuses[tier] / 100;
    health += health * tierBonuses[tier] / 100;

    // Print the item's name, tier, and stats
    std::cout << "Item: " << name << std::endl;
    std::cout << "Tier: " << tier << std::endl;
    std::cout << "Stats: Attack=" << attack << ", Defense=" << defense << ", Health=" << health << std::endl;
}

int main() {
    // Set the random seed
    srand(time(0));

    // Generate a random weapon or equipment for a player of level 20, tier 3
    int playerLevel = 20;
    int playerTier = 3;
    generateItem(playerLevel, playerTier);

    return 0;
}