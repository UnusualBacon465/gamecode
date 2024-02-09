#include <iostream>
#include <string>

using namespace std;

// Enum representing the grades of materials
enum class MaterialGrade { COMMON, RARE, EPIC, LEGENDARY, MYTHICAL, ANCIENT, UNKNOWN };

// Class to represent a material
class Material {
public:
    Material(string name, MaterialGrade grade) : name(name), grade(grade) {}

    string getName() const { return name; }
    MaterialGrade getGrade() const { return grade; }

    // Function to convert MaterialGrade enum to string
    string gradeToString() const {
        switch (grade) {
            case MaterialGrade::COMMON:
                return "Common";
            case MaterialGrade::RARE:
                return "Rare";
            case MaterialGrade::EPIC:
                return "Epic";
            case MaterialGrade::LEGENDARY:
                return "Legendary";
            case MaterialGrade::MYTHICAL:
                return "Mythical";
            case MaterialGrade::ANCIENT:
                return "Ancient";
            case MaterialGrade::UNKNOWN:
                return "Unknown";
            default:
                return "Unknown";
        }
    }

private:
    string name;
    MaterialGrade grade;
};

int main() {
    // Create instances of materials
    Material impureDemonsBlood("Impure Demon's Blood", MaterialGrade::RARE);
    Material pureDemonsBlood("Pure Demon's Blood", MaterialGrade::LEGENDARY);
    Material royalDemonsBlood("Royal Demon's Blood", MaterialGrade::MYTHICAL);
    Material fragmentOfTheSun("Fragment of the Sun", MaterialGrade::EPIC);
    Material shardOfTheSun("Shard of the Sun", MaterialGrade::LEGENDARY);
    Material tinyStar("Tiny Star", MaterialGrade::MYTHICAL);
    Material miniStar("Mini Star", MaterialGrade::ANCIENT);
    Material miniBlackhole("Mini Blackhole", MaterialGrade::UNKNOWN);
    Material kingsHolySigil("King's Holy Sigil", MaterialGrade::LEGENDARY);
    Material bottleOfCurses("Bottle of Curses", MaterialGrade::RARE);
    Material mythril("Mythril", MaterialGrade::MYTHICAL);
    Material divineSteel("Divine Steel", MaterialGrade::LEGENDARY);
    Material divineLeather("Divine Leather", MaterialGrade::LEGENDARY);
    Material brokenBlade("Broken Blade", MaterialGrade::COMMON);
    Material demonicSteel("Demonic Steel", MaterialGrade::MYTHICAL);
    Material whetstone("Whetstone", MaterialGrade::COMMON);
    Material glowingWhetstone("Glowing Whetstone", MaterialGrade::RARE);
    Material runeOfEndurance("Rune of Endurance", MaterialGrade::RARE);
    Material goldenWhetstone("Golden Whetstone", MaterialGrade::EPIC);
    Material mastersWhetstone("Master's Whetstone", MaterialGrade::LEGENDARY);

    // Display information about the materials
    cout << impureDemonsBlood.getName() << " - Grade: " << impureDemonsBlood.gradeToString() << endl;
    cout << pureDemonsBlood.getName() << " - Grade: " << pureDemonsBlood.gradeToString() << endl;
    cout << royalDemonsBlood.getName() << " - Grade: " << royalDemonsBlood.gradeToString() << endl;
    cout << fragmentOfTheSun.getName() << " - Grade: " << fragmentOfTheSun.gradeToString() << endl;
    cout << shardOfTheSun.getName() << " - Grade: " << shardOfTheSun.gradeToString() << endl;
    cout << tinyStar.getName() << " - Grade: " << tinyStar.gradeToString() << endl;
    cout << miniStar.getName() << " - Grade: " << miniStar.gradeToString() << endl;
    cout << miniBlackhole.getName() << " - Grade: " << miniBlackhole.gradeToString() << endl;
    cout << kingsHolySigil.getName() << " - Grade: " << kingsHolySigil.gradeToString() << endl;
    cout << bottleOfCurses.getName() << " - Grade: " << bottleOfCurses.gradeToString() << endl;
    cout << mythril.getName() << " - Grade: " << mythril.gradeToString() << endl;
    cout << divineSteel.getName() << " - Grade: " << divineSteel.gradeToString() << endl;
    cout << divineLeather.getName() << " - Grade: " << divineLeather.gradeToString() << endl;
    cout << brokenBlade.getName() << " - Grade: " << brokenBlade.gradeToString() << endl;
    cout << demonicSteel.getName() << " - Grade: " << demonicSteel.gradeToString() << endl;
    cout << whetstone.getName() << " - Grade: " << whetstone.gradeToString() << endl;
    cout << glowingWhetstone.getName() << " - Grade: " << glowingWhetstone.gradeToString() << endl;
    cout << runeOfEndurance.getName() << " - Grade: " << runeOfEndurance.gradeToString() << endl;
    cout << goldenWhetstone.getName() << " - Grade: " << goldenWhetstone.gradeToString() << endl;
    cout << mastersWhetstone.getName() << " - Grade: " << mastersWhetstone.gradeToString() << endl;

    return 0;
}