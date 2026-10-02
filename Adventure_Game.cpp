#include <iostream>
#include <string>

int main() {
    char choice1, choice2;

    std::cout << "--- 🌲 THE MYSTERIOUS FOREST 🌲 ---\n\n";
    std::cout << "You wake up at a dark crossroads in an ancient forest.\n";
    std::cout << "To your left, you hear the sound of rushing water.\n";
    std::cout << "To your right, you see a faint, flickering light through the trees.\n\n";
    
    // First Choice
    std::cout << "Which path do you choose? (L for Left / R for Right): ";
    std::cin >> choice1;
    std::cout << "\n-----------------------------------------\n\n";

    // Path Left: Rushing Water
    if (choice1 == 'L' || choice1 == 'l') {
        std::cout << "You walk toward the sound of water and find a massive, roaring river.\n";
        std::cout << "There is an old, rickety wooden bridge crossing it.\n";
        std::cout << "You can try to cross the bridge, or swim across the river.\n\n";
        
        std::cout << "What do you do? (C for Cross / S for Swim): ";
        std::cin >> choice2;
        std::cout << "\n-----------------------------------------\n\n";
        
        if (choice2 == 'C' || choice2 == 'c') {
            std::cout << "💨 A plank breaks under your feet, but you scramble to the other side safely!\n";
            std::cout << "You find a chest full of gold. 🎉 YOU WIN! 🎉\n";
        } else if (choice2 == 'S' || choice2 == 's') {
            std::cout << "🌊 The current is too strong! It sweeps you away downriver.\n";
            std::cout << "💀 GAME OVER 💀\n";
        } else {
            std::cout << "❌ You hesitated for too long and a wild beast caught you. 💀 GAME OVER 💀\n";
        }
    } 
    // Path Right: Flickering Light
    else if (choice1 == 'R' || choice1 == 'r') {
        std::cout << "You creep toward the light and discover a small, cozy log cabin.\n";
        std::cout << "The door is unlocked. You hear a strange humming sound from inside.\n";
        std::cout << "Do you enter the cabin, or knock politely?\n\n";
        
        std::cout << "What do you do? (E for Enter / K for Knock): ";
        std::cin >> choice2;
        std::cout << "\n-----------------------------------------\n\n";
        
        if (choice2 == 'E' || choice2 == 'e') {
            std::cout << "🧙‍♂️ Inside, a friendly wizard is brewing a potion! He welcomes you in.\n";
            std::cout << "He gives you a magical amulet. 🎉 YOU WIN! 🎉\n";
        } else if (choice2 == 'K' || choice2 == 'k') {
            std::cout << "🧟 The humming stops. A giant ogre opens the door and chases you away!\n";
            std::cout << "💀 GAME OVER 💀\n";
        } else {
            std::cout << "❌ Invalid choice. The cabin disappears into thin air, leaving you lost forever. 💀\n";
        }
    } 
    // Invalid First Choice
    else {
        std::cout << "❌ You stood still and got lost in the shadows forever. 💀 GAME OVER 💀\n";
    }

    return 0;
}
