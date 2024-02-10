#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

enum class ItemType {
    WEAPON,
    ARMOR,
    CONSUMABLE,
    MATERIAL,
    KEY
};

class Item {
public:
    Item(ItemType type, string name, int baseStat) : type(type), name(name), baseStat(baseStat) {}

    // Generate a random item
    static Item generateRandomItem() {
        // Seed the random number generator
        srand(time(nullptr));

        // Generate a random type
        ItemType type = static_cast<ItemType>(rand() % 2); // Generates a number between 0 and 1

        // Initialize base stat
        int baseStat = 0;

        // Generate random base stat for weapons and armors
        if (type == ItemType::WEAPON || type == ItemType::ARMOR) {
            baseStat = rand() % 101; // Generates a number between 0 and 100
        }

        // Generate random name based on item type
        string name = generateRandomName(type);

        return Item(type, name, baseStat);
    }

    void display() const {
        cout << "Type: " << static_cast<int>(type) << endl;
        cout << "Name: " << name << endl;
        cout << "Base Stat: " << baseStat << endl;
    }

private:
    ItemType type;
    string name;
    int baseStat;

    // Generate random name based on item type
    static string generateRandomName(ItemType type) {
        vector<string> weaponNames = {"katana", "Wand Of Unholy Remains", "Super Heated Katana", "Broken Blade", "Kings Unholy Blade"};
        vector<string> armorNames = {"Helmet", "Chestplate", "Leggings", "Boots", "Gloves", "Cloak"};
        vector<string> consumableNames = {"Health Potion",};
        vector<string> materialNames = {"Impure Demon's Blood", "Pure Demon's Blood", "Royal Demon's Blood", "Fragment of the Sun", "Shard of the Sun", "Tiny Star", "Mini Star", "Mini Blackhole", "King's Holy Sigil", "Bottle of Curses", "Mythril", "Divine Steel", "Divine Leather", "Demonic Steel", "Whetstone", "Glowing Whetstone", "Rune of Endurance", "Golden Whetstone", "Master's Whetstone"};
        vector<string> keyNames = {"Key to the Castle"};

        switch (type) {
            case ItemType::WEAPON:
                return weaponNames[rand() % weaponNames.size()];
            case ItemType::ARMOR:
                return armorNames[rand() % armorNames.size()];
            case ItemType::CONSUMABLE:
                return consumableNames[rand() % consumableNames.size()];
            case ItemType::MATERIAL:
                return materialNames[rand() % materialNames.size()];
            case ItemType::KEY:
                return keyNames[rand() % keyNames.size()];
            default:
                return "Item";
        }
    }
};

int main() {
    vector<Item> items;

    // Generate random items
    for (int i = 0; i < 5; ++i) {
        items.push_back(Item::generateRandomItem());
    }

    // Display the generated items
    for (const auto& item : items) {
        item.display();
        cout << endl;
    }

    return 0;
}