#include <iostream>
#include "materials.cpp" // Include the materials.cpp file containing the Material class
#include "itemtype.cpp" // Include the itemtype.cpp file containing the ItemType enum

using namespace std;

// Define a Crafting class
class Crafting {
public:
    // Constructor
    Crafting() {}

    // Function to craft an item using materials
    void craftItem(const Material& material1, const Material& material2) {
        cout << "Crafting an item using materials:" << endl;
        cout << "Material 1: " << material1.getName() << " (Grade: " << material1.gradeToString() << ")" << endl;
        cout << "Material 2: " << material2.getName() << " (Grade: " << material2.gradeToString() << ")" << endl;
        // Add crafting logic here
    }
};

int main() {
    // Create an instance of the Crafting class
    Crafting crafting;

    // Create instances of materials
    Material material1("Material 1", MaterialGrade::COMMON);
    Material material2("Material 2", MaterialGrade::RARE);

    // Craft an item using the materials
    crafting.craftItem(material1, material2);

    return 0;
}
