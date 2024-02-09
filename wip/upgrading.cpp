#include <iostream>
#include "materials.cpp" // Include the materials.cpp file containing the Material class
#include "itemtype.cpp" // Include the itemtype.cpp file containing the ItemType enum

using namespace std;

// Define an Upgrading class
class Upgrading {
public:
    // Constructor
    Upgrading() {}

    // Function to upgrade an item using materials
    void upgradeItem(const Material& material, ItemType itemType) {
        cout << "Upgrading an item of type: " << itemTypeToString(itemType) << endl;
        cout << "Using material: " << material.getName() << " (Grade: " << material.gradeToString() << ")" << endl;
        // Add upgrading logic here
    }
};

int main() {
    // Create an instance of the Upgrading class
    Upgrading upgrading;

    // Create an instance of a material
    Material material("Upgrade Material", MaterialGrade::EPIC);

    // Upgrade an item using the material
    upgrading.upgradeItem(material, ItemType::WEAPON);

    return 0;
}
