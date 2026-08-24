//#include <iostream>
//using namespace std;
//
//// ò·«” ê—Â »—«? ·?”  œÊÿ—›Â
//class WeaponNode {
//public:
//    int weaponID;
//    string weaponName;
//    WeaponNode* prev;
//    WeaponNode* next;
//
//    WeaponNode(int id, string name)
//        : weaponID(id), weaponName(name), prev(nullptr), next(nullptr) {
//    }
//};
//
//// ò·«” ·?”  œÊÿ—›Â ç—Œ‘?
//class DoublyCircularLinkedList {
//private:
//    WeaponNode* head;
//    WeaponNode* current; // «‘«—Âùê— »Â ”·«Õ ›⁄·?
//
//public:
//    DoublyCircularLinkedList() : head(nullptr), current(nullptr) {}
//
//    // «÷«›Â ò—œ‰ ”·«Õ Ãœ?œ
//    void addWeapon(int id, string name) {
//        WeaponNode* newNode = new WeaponNode(id, name);
//
//        if (!head) {
//            head = newNode;
//            head->next = head;
//            head->prev = head;
//            current = head;
//        }
//        else {
//            WeaponNode* last = head->prev;
//
//            last->next = newNode;
//            newNode->prev = last;
//            newNode->next = head;
//            head->prev = newNode;
//        }
//    }
//
//    // Õ—ò  »Â ”·«Õ »⁄œ?
//    void nextWeapon() {
//        if (current) {
//            current = current->next;
//        }
//    }
//
//    // Õ—ò  »Â ”·«Õ ﬁ»·?
//    void prevWeapon() {
//        if (current) {
//            current = current->prev;
//        }
//    }
//
//    // œ—?«›  ”·«Õ ›⁄·?
//    WeaponNode* getCurrentWeapon() {
//        return current;
//    }
//
//    // ‰„«?‘  „«„ ”·«ÕùÂ«
//    void displayAll() {
//        if (!head) return;
//
//        WeaponNode* temp = head;
//        do {
//            cout << "ID: " << temp->weaponID << ", Name: " << temp->weaponName;
//            if (temp == current) cout << " (Current)";
//            cout << endl;
//            temp = temp->next;
//        } while (temp != head);
//    }
//};
//
//// ò·«” »«“?ò‰
//class Player {
//private:
//    DoublyCircularLinkedList weapons;
//    WeaponNode* equippedWeapon;
//
//public:
//    Player() : equippedWeapon(nullptr) {
//        // „ﬁœ«—œÂ? «Ê·?Â ”·«ÕùÂ«
//        weapons.addWeapon(1, "Knife");
//        weapons.addWeapon(2, "Pistol");
//        weapons.addWeapon(3, "AK-47");
//        weapons.addWeapon(4, "AWP");
//
//        equippedWeapon = weapons.getCurrentWeapon();
//    }
//
//    //  €??— ”·«Õ »Â »⁄œ?
//    void switchToNextWeapon() {
//        weapons.nextWeapon();
//        equippedWeapon = weapons.getCurrentWeapon();
//        cout << "Switched to: " << equippedWeapon->weaponName << endl;
//    }
//
//    //  €??— ”·«Õ »Â ﬁ»·?
//    void switchToPrevWeapon() {
//        weapons.prevWeapon();
//        equippedWeapon = weapons.getCurrentWeapon();
//        cout << "Switched to: " << equippedWeapon->weaponName << endl;
//    }
//
//    // ‰„«?‘ ”·«Õ ›⁄·?
//    void displayCurrentWeapon() {
//        if (equippedWeapon) {
//            cout << "Current Weapon: " << equippedWeapon->weaponName
//                << " (ID: " << equippedWeapon->weaponID << ")" << endl;
//        }
//    }
//
//    // ‰„«?‘  „«„ ”·«ÕùÂ«
//    void displayAllWeapons() {
//        weapons.displayAll();
//    }
//};
//
//int main() {
//    Player player;
//
//    cout << "Initial weapons:" << endl;
//    player.displayAllWeapons();
//    cout << endl;
//
//    player.displayCurrentWeapon();
//    cout << endl;
//
//    cout << "Switching weapons:" << endl;
//    player.switchToNextWeapon();
//    player.switchToNextWeapon();
//    player.switchToPrevWeapon();
//
//    return 0;
//}