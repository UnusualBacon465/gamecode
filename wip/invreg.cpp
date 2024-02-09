// ! reg for inv WIP

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath> // For absolute value

using namespace std;

// Define an ItemType enum
enum class ItemType {
    WEAPON,
    ARMOR,
    CONSUMABLE,
    MATERIAL,
    KEY
};

// Define an Item class representing items
class Item {
public:
    Item(ItemType type, const string& name, int stat, int tier, string rarity) : type(type), name(name), stat(stat), tier(tier), rarity(rarity) {}

    // Getter for item type
    ItemType getType() const { return type; }

    // Getter for item name
    string getName() const { return name; }

    // Getter for item stat
    int getStat() const { return stat; }

    // Getter for item tier
    int getTier() const { return tier; }

    // Getter for item rarity
    string getRarity() const { return rarity; }

private:
    ItemType type;
    string name;
    int stat;
    int tier;
    string rarity;
};

// Define an Inventory class representing the player's inventory
class Inventory {
public:
    // Function to add an item to the inventory
    void addItem(const Item& item) {
        items.push_back(item);
    }

    // Function to display the inventory
    void displayInventory() const {
        cout << "Inventory:" << endl;
        for (const auto& item : items) {
            cout << "Type: " << itemTypeToString(item.getType()) << ", Name: " << item.getName() << ", Stat: " << item.getStat() << ", Tier: " << item.getTier() << ", Rarity: " << item.getRarity() << endl;
        }
    }

private:
    vector<Item> items;

    // Function to convert ItemType enum to string
    string itemTypeToString(ItemType type) const {
        switch (type) {
            case ItemType::WEAPON:
                return "Weapon";
            case ItemType::ARMOR:
                return "Armor";
            case ItemType::CONSUMABLE:
                return "Consumable";
            case ItemType::MATERIAL:
                return "Material";
            case ItemType::KEY:
                return "Key";
            default:
                return "Unknown";
        }
    }
};

// Define a Registry class to dynamically add items to the inventory registry
class Registry {
public:
    // Function to add an item to the registry
    void addItem(const Item& item) {
        // Find or create a group for the item based on its stat, tier, and rarity
        int groupKey = findOrCreateGroup(item.getStat(), item.getTier(), item.getRarity());
        // Add the item to the corresponding group
        registry[groupKey].push_back(item);
    }

    // Function to display the registry
    void displayRegistry() const {
        cout << "Registry:" << endl;
        for (const auto& pair : registry) {
            cout << "Group: " << pair.first << endl;
            for (const auto& item : pair.second) {
                cout << "Type: " << itemTypeToString(item.getType()) << ", Name: " << item.getName() << ", Stat: " << item.getStat() << ", Tier: " << item.getTier() << ", Rarity: " << item.getRarity() << endl;
            }
        }
    }

private:
    unordered_map<int, vector<Item>> registry;

    // Function to find or create a group for an item based on its stat, tier, and rarity
    int findOrCreateGroup(int stat, int tier, const string& rarity) {
        // Calculate a unique key based on stat, tier, and rarity
        int groupKey = (stat << 16) | (tier << 8) | rarity[0]; // Assuming rarity is a single character
        return groupKey;
    }

    // Function to convert ItemType enum to string
    string itemTypeToString(ItemType type) const {
        switch (type) {
            case ItemType::WEAPON:
                return "Weapon";
            case ItemType::ARMOR:
                return "Armor";
            case ItemType::CONSUMABLE:
                return "Consumable";
            case ItemType::MATERIAL:
                return "Material";
            case ItemType::KEY:
                return "Key";
            default:
                return "Unknown";
        }
    }
};

int main() {
    // Create an instance of the Inventory class
    Inventory inventory;

    // Create an instance of the Registry class
    Registry registry;

    // Add some items to the registry
    registry.addItem(Item(ItemType::WEAPON, "Sword", 100, 1, "Common"));
    registry.addItem(Item(ItemType::WEAPON, "Axe", 95, 2, "Rare"));
    registry.addItem(Item(ItemType::WEAPON, "Bow", 110, 1, "Common"));
    registry.addItem(Item(ItemType::WEAPON, "Staff", 105, 2, "Rare"));

    // Add some more items to the registry
    registry.addItem(Item(ItemType::ARMOR, "Helmet", 50, 1, "Common"));
    registry.addItem(Item(ItemType::ARMOR, "Chestplate", 45, 2, "Rare"));
    registry.addItem(Item(ItemType::ARMOR, "Leggings", 55, 1, "Common"));

    // Display the registry
    registry.displayRegistry();

    return 0;
}