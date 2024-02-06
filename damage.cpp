// ! damage func.

using namespace std;

// * Define the Damage function
int damage(int baseDamage) {
    // Calculate the damage
    int damageDealt = baseDamage;

    // Apply any modifiers (e.g., critical hits, resistances)

    // Return the damage dealt
    return damageDealt;
}

/// @brief 
/// @return 
int main() {
    // Initialize the player's and enemy's health
    int playerHealth = 100;
    int enemyHealth = 100;

    // Get the player's and enemy's attack power
    int playerAttackPower = 5;
    int enemyAttackPower = 5;

    // Calculate the damage dealt by the player and enemy
    int playerDamage = damage(playerAttackPower);
    int enemyDamage = damage(enemyAttackPower);

    // Apply the damage to the player and enemy
    playerHealth -= playerDamage;
    enemyHealth -= enemyDamage;

    // Print the player's and enemy's health
    cout << "Player health: " << playerHealth << endl;
    cout << "Enemy health: " << enemyHealth << endl;


}