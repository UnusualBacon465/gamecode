// ! upgrade WIP

#include <iostream>
#include <vector>
#include <algorithm> // For std::find
#include "materials.cpp" // Include the materials.cpp file containing the Material class
#include "itemtype.cpp" // Include the itemtype.cpp file containing the ItemType enum

using namespace std;

// Define an Item class representing items in the inventory
class Item {
public:
    Item(ItemType type, const string& name) : type(type), name(name) {}

    // Getter for item type
    ItemType getType() const { return type; }

    // Getter for item name
    string getName() const { return name; }

private:
    ItemType type;
    string name;
};

// Define an Inventory class representing the player's inventory
class Inventory {
public:
    // Function to add an item to the inventory
    void addItem(const Item& item) {
        items.push_back(item);
    }

    // Function to remove an item from the inventory
    void removeItem(const Item& item) {
        auto it = find(items.begin(), items.end(), item);
        if (it != items.end()) {
            items.erase(it);
        }
    }

    // Function to check if the inventory contains a specific item
    bool containsItem(const Item& item) const {
        return find(items.begin(), items.end(), item) != items.end();
    }

    // Function to display the inventory
    void displayInventory() const {
        cout << "Inventory:" << endl;
        for (const auto& item : items) {
            cout << "Type: " << itemTypeToString(item.getType()) << ", Name: " << item.getName() << endl;
        }
    }

private:
    vector<Item> items;
};

// Define an Upgrading class
class Upgrading {
public:
    // Constructor
    Upgrading() {}

    // Function to upgrade items in the inventory using materials
    void upgradeItems(Inventory& inventory, const Material& material) {
        cout << "Upgrading items in the inventory using material: " << material.getName() << " (Grade: " << material.gradeToString() << ")" << endl;
        // Iterate through each item in the inventory
        for (auto& item : inventoryItems) {
            // Check if the item can be upgraded (e.g., weapon or armor)
            if (isUpgradeable(item.getType())) {
                // Perform the upgrade
                cout << "Upgrading item: " << item.getName() << endl;
                // Add upgrading logic here

                // Remove the original item from the inventory
                inventory.removeItem(item);
                // Add the upgraded item back to the inventory
                inventory.addItem(item);
            }
        }
    }

private:
    // Function to check if an item type is upgradeable (e.g., weapon or armor)
    bool isUpgradeable(ItemType type) {
        return type == ItemType::WEAPON || type == ItemType::ARMOR;
    }

    vector<Item> inventoryItems; // Store inventory items here
};

int main() {
    // Create an instance of the Inventory class
    Inventory inventory;

    // Populate the inventory with some items (for demonstration)
    inventory.addItem(Item(ItemType::WEAPON, "Sword"));
    inventory.addItem(Item(ItemType::ARMOR, "Helmet"));
    inventory.addItem(Item(ItemType::CONSUMABLE, "Health Potion"));
    inventory.addItem(Item(ItemType::WEAPON, "Axe"));

    // Display the initial inventory
    cout << "Initial Inventory:" << endl;
    inventory.displayInventory();

    // Create an instance of the Upgrading class
    Upgrading upgrading;

    // Create an instance of a material
    Material material("Upgrade Material", MaterialGrade::EPIC);

    // Upgrade items in the inventory using the material
    upgrading.upgradeItems(inventory, material);

    // Display the inventory after upgrading
    cout << "\nInventory after upgrading:" << endl;
    inventory.displayInventory();

    return 0;
}