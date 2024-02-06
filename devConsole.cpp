// ! dev console for testing, ignore.

private:

using namespace std;

bool IsDevConsoleOpen = false;
int playerLevel = 1;
int playerExp = 0;

void ProcessDevCommand(const string& command)
{
    // Process the developer command here
    cout << "Developer command executed: " << command << endl;
}

void ToggleDevConsole()
{
    IsDevConsoleOpen = !IsDevConsoleOpen;
    if (IsDevConsoleOpen)
    {
        cout << "Developer console opened" << endl;
    }
    else
    {
        cout << "Developer console closed" << endl;
    }
}

void LevelUp()
{
    playerLevel++;
    cout << "Player leveled up to level " << playerLevel << "!" << endl;
}

void GainExp(int expPoints)
{
    playerExp += expPoints;
    cout << "Player gained " << expPoints << " experience points!" << endl;

    // Check if the player levels up
    if (playerExp >= 5 * playerLevel) {
        LevelUp();
    }
}

int main()
{
    // Game loop
    while (true)
    {
        // Game logic and rendering goes here

        // Check for input to toggle the developer console
        if (IsDevConsoleOpen)
        {
            // Process developer console input
            string input;
            getline(cin, input);
            if (!input.empty())
            {
                if (input == "levelup") {
                    LevelUp();
                }
                else if (input == "Fire") {
                    // Handle Fire action
                    cout << "Fire activated!" << endl;
                }
                else if (input == "Bloodletting") {
                    // Handle Bloodletting action
                    cout << "Bloodletting activated!" << endl;
                }
                else if (input == "Icy bite") {
                    // Handle Icy bite action
                    cout << "Icy bite activated!" << endl;
                }
                else if (input == "Sword Aura") {
                    // Handle Sword Aura action
                    cout << "Sword Aura activated!" << endl;
                }
                else if (input == "Sword Mastery") {
                    // Handle Sword Mastery action
                    cout << "Sword Mastery activated!" << endl;
                }
                else {
                    ProcessDevCommand(input);
                }
            }
        }
        else
        {
            // Check for input to toggle the developer console
            if (GetAsyncKeyState(VK_OEM_3) & 0x8000) // Check for "~" key (OEM_3)
            {
                ToggleDevConsole();
            }
            else if (GetAsyncKeyState(VK_F1) & 0x8000) // Check for F1 key
            {
                ToggleDevConsole();
            }
        }
    }

    return 0;
}