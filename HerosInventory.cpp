//
//  main.cpp
//  Hero's Inventory
//
//  Created by Dennis Hubley on 2021-02-26.
//

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::distance;

int askNumber(string question, int high, int low);
void displayInventory(const vector<string> &inventory, const vector<int> &stock, const vector<int> &prices);

int main() {

    // TODO

    // 2 of the items the merchant will only have 1 of and will be sold out once purchased
    // items the merchant purchases can just be removed from player - does not need to be added to store

    vector<string> merchantInventory;
    merchantInventory.push_back("sword");
    merchantInventory.push_back("shield");
    merchantInventory.push_back("health potion");
    
    vector<int> merchantStock;
    merchantStock.push_back(1);
    merchantStock.push_back(1);
    merchantStock.push_back(99);
    
    vector<int> merchantPrices;
    merchantPrices.push_back(75);
    merchantPrices.push_back(50);
    merchantPrices.push_back(5);
    
    float merchantBuyBackRate = 0.5;
    
    vector<string> playerInventory;
    playerInventory.push_back("stick");
    playerInventory.push_back("frisbee");
    playerInventory.push_back("empty bottle");
    
    vector<int> playerStock;
    playerStock.push_back(872);
    playerStock.push_back(1);
    playerStock.push_back(1);
    
    vector<int> playerPrices;
    playerPrices.push_back(2);
    playerPrices.push_back(3);
    playerPrices.push_back(0);
    
    int playerGold = 150;
    
    cout << "Welcome to the Hero's Inventory Assignment" << endl << endl;
    
    cout << "In this program, you are given some gold and an initial" << endl;
    cout << "inventory.  You can buy and sell with the merchant until" << endl;
    cout << "you are satisfied, where you can then end the program." << endl << endl;
    
    int choice;
    
    do {
        cout << endl << "Main Menu" << endl << endl;
        cout << "1. Buy from merchant" << endl;
        cout << "2. Sell to merchant" << endl;
        cout << "3. View player inventory" << endl;
        cout << "4. View merchant inventory" << endl;
        cout << "0. Quit" << endl << endl;
       
        cout << "Gold: " << playerGold << "\t";
        choice = askNumber("Your choice? ", 4, 0);
        
        switch (choice) {
            case 1: {
                // code for buying
                
                // view merchant inventory
                cout << endl << "Viewing merchant's inventory" << endl;
                displayInventory(merchantInventory, merchantStock, merchantPrices);
                int choice2 = askNumber("Your choice? ", merchantInventory.size(), 0);
                
                if (!(merchantStock[choice2-1] > 0)) {
                    cout << "I'm sorry, but that item is out of stock!" << endl;
                    break;
                }
                
                if (!(playerGold > merchantPrices[choice2-1])) {
                    cout << "I'm sorry, you don't seem to have enough gold for that!" << endl;
                    break;
                }
                
                playerGold -= merchantPrices[choice2-1];
                merchantStock[choice2-1]--;
                vector<string>::iterator it;

                it = find(playerInventory.begin(), playerInventory.end(), merchantInventory[choice2-1]);
                if (it != playerInventory.end()) {
                    int index = distance( playerInventory.begin(), it );
                    playerStock[index]++;
                }
                else {
                    playerInventory.push_back(merchantInventory[choice2-1]);
                    playerStock.push_back(1);
                    playerPrices.push_back(merchantPrices[choice2-1]);
                }
 
                break;
            }
            case 2: {
                // code for selling
                
                // display list of items for sale (players)
                // ask player what item they would like to sell
                // is item valid? (does it exist)
                //    if so - do transaction
                //      add gold to player
                //      remove stock from player
                //      if player stock == 0 then remove item

                break;
            }
            case 3: {
                // view player inventory
                cout << endl << "Viewing player's inventory" << endl;
                displayInventory(playerInventory, playerStock, playerPrices);
                break;
            }
            case 4:{
                // view merchant inventory
                cout << endl << "Viewing merchant's inventory" << endl;
                displayInventory(merchantInventory, merchantStock, merchantPrices);
                break;
            }
            case 0: {
                cout << "Ok!  Thanks for playing, have a great day!" << endl;
                break;
            }
            default: {
                cout << "ERROR: Invalid choice.  This should never happen." << endl;
                break;
            }
        }
        
        
    } while (choice != 0);
    
    return 0;
}

int askNumber(string question, int high, int low)
{
    int number;
    do
    {
        cout << question << " (" << low << " - " << high << "): ";
        cin >> number;
    } while (number > high || number < low);

    return number;
}

void displayInventory(const vector<string> &inventory, const vector<int> &stock, const vector<int> &prices) {
    
    cout << setw(3) << "#  " << setw(15) << "Item name" << setw(10) << "Stock" << setw(10) << "Price" << endl;
    
    for (int i = 0; i < inventory.size(); i++) {
        cout << i+1 << ". " << setw(15) << inventory[i];
        if (stock[i] != 0) {
            cout << setw(10) << stock[i] << setw(10) << prices[i] << endl;
        } else {
            cout << setw(10) << "Sold Out" << setw(10) << prices[i] << endl;
        }
    }
}
