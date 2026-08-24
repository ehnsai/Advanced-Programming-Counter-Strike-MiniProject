//#include <iostream>
//using namespace std;
//
//// ˜áÇÓ Ñå ÈÑÇ? á?ÓÊ ÏæØÑÝå
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
//// ˜áÇÓ á?ÓÊ ÏæØÑÝå ÑÎÔ?
//class DoublyCircularLinkedList {
//private:
//    WeaponNode* head;
//    WeaponNode* current; // ÇÔÇÑåÑ Èå ÓáÇÍ ÝÚá?
//
//public:
//    DoublyCircularLinkedList() : head(nullptr), current(nullptr) {}
//
//    // ÇÖÇÝå ˜ÑÏä ÓáÇÍ ÌÏ?Ï
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
//    // ÍÑ˜Ê Èå ÓáÇÍ ÈÚÏ?
//    void nextWeapon() {
//        if (current) {
//            current = current->next;
//        }
//    }
//
//    // ÍÑ˜Ê Èå ÓáÇÍ ÞÈá?
//    void prevWeapon() {
//        if (current) {
//            current = current->prev;
//        }
//    }
//
//    // ÏÑ?ÇÝÊ ÓáÇÍ ÝÚá?
//    WeaponNode* getCurrentWeapon() {
//        return current;
//    }
//
//    // äãÇ?Ô ÊãÇã ÓáÇÍåÇ
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
//// ˜áÇÓ ÈÇÒ?˜ä
//class Player {
//private:
//    DoublyCircularLinkedList weapons;
//    WeaponNode* equippedWeapon;
//
//public:
//    Player() : equippedWeapon(nullptr) {
//        // ãÞÏÇÑÏå? Çæá?å ÓáÇÍåÇ
//        weapons.addWeapon(1, "Knife");
//        weapons.addWeapon(2, "Pistol");
//        weapons.addWeapon(3, "AK-47");
//        weapons.addWeapon(4, "AWP");
//
//        equippedWeapon = weapons.getCurrentWeapon();
//    }
//
//    // ÊÛ??Ñ ÓáÇÍ Èå ÈÚÏ?
//    void switchToNextWeapon() {
//        weapons.nextWeapon();
//        equippedWeapon = weapons.getCurrentWeapon();
//        cout << "Switched to: " << equippedWeapon->weaponName << endl;
//    }
//
//    // ÊÛ??Ñ ÓáÇÍ Èå ÞÈá?
//    void switchToPrevWeapon() {
//        weapons.prevWeapon();
//        equippedWeapon = weapons.getCurrentWeapon();
//        cout << "Switched to: " << equippedWeapon->weaponName << endl;
//    }
//
//    // äãÇ?Ô ÓáÇÍ ÝÚá?
//    void displayCurrentWeapon() {
//        if (equippedWeapon) {
//            cout << "Current Weapon: " << equippedWeapon->weaponName
//                << " (ID: " << equippedWeapon->weaponID << ")" << endl;
//        }
//    }
//
//    // äãÇ?Ô ÊãÇã ÓáÇÍåÇ
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
