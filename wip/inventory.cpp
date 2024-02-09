#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <itemtype.cpp>

using namespace std;

// Define the ItemType enum
enum class ItemType { ITEM, MATERIAL, WEAPON, ARMOR, CONSUMABLE, KEY };

// Define the Item class
class Item {
public:
    Item(string name, ItemType type, int quantity = 1) : name(name), type(type), quantity(quantity) {}

    string getName() const { return name; }
    ItemType getType() const { return type; }
    int getQuantity() const { return quantity; }

    void setQuantity(int newQuantity) { quantity = newQuantity; }

    bool operator==(const Item& other) const {
        return name == other.name && type == other.type;
    }

private:
    string name;
    ItemType type;
    int quantity;
};

// Define the Inventory class
class Inventory {
public:
    // Function to add an item to the inventory
    void addItem(const Item& item) {
        if (item.getType() == ItemType::WEAPON || item.getType() == ItemType::ARMOR) {
            // Weapons and armors don't stack, so add them directly
            items.push_back(item);
        } else {
            // Check if the item stacks with existing items
            bool stacked = false;
            for (Item& existingItem : items) {
                if (existingItem == item) {
                    existingItem.setQuantity(existingItem.getQuantity() + item.getQuantity());
                    stacked = true;
                    break;
                }
            }
            // If the item doesn't stack, add it to the inventory
            if (!stacked) {
                items.push_back(item);
            }
        }
    }

    // Function to display the inventory
    void displayInventory() const {
        cout << "Inventory:" << endl;
        for (const Item& item : items) {
            cout << "Name: " << item.getName() << ", Type: " << itemTypeToString(item.getType()) << ", Quantity: " << item.getQuantity() << endl;
        }
    }

private:
    vector<Item> items;

    // Helper function to convert ItemType enum to string
    string itemTypeToString(ItemType type) const {
        switch (type) {
            case ItemType::ITEM:
                return "Item";
            case ItemType::MATERIAL:
                return "Material";
            case ItemType::WEAPON:
                return "Weapon";
            case ItemType::ARMOR:
                return "Armor";
            case ItemType::CONSUMABLE:
                return "Consumable";
            case ItemType::KEY:
                return "Key";
            default:
                return "Unknown";
        }
    }
};

int main() {
    // Create an inventory object
    Inventory inventory;

    // Add some items to the inventory
    inventory.addItem(Item("Sword", ItemType::WEAPON));
    inventory.addItem(Item("Bow", ItemType::WEAPON));
    inventory.addItem(Item("Helmet", ItemType::ARMOR));
    inventory.addItem(Item("Gold", ItemType::ITEM, 100));
    inventory.addItem(Item("Iron Ingot", ItemType::MATERIAL, 10));
    inventory.addItem(Item("Gold Ingot", ItemType::MATERIAL, 5));
    inventory.addItem(Item("Health Potion", ItemType::CONSUMABLE, 3));
    inventory.addItem(Item("Key to Dungeon", ItemType::KEY));

    // Display the inventory
    inventory.displayInventory();

    return 0;
}
