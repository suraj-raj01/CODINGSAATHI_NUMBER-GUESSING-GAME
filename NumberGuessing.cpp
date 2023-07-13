#include <iostream>
#include <string> 
#include <cstdlib>
#include <ctime>
using namespace std;
void rules();
int main()
{
    string playerName;
    int balance; // stores player's balance
    int bettingAmount;
    int guess;
    int dice; // stores the random number
    char choice;
    srand(time(0)); // "Seed" the random generator
    cout << "\n\t\t======== WELCOME TO GAMING WORLD =======\n";
    cout << "\n\t\t Enter Your Name : ";
    getline(cin, playerName);
    cout << "\t\t Enter Some Amount to play Game : $";
    cin >> balance;
    do
    {
        system("cls");
        rules();
        cout << "\n\n\t\tYour current balance is $ " << balance << "\n";
// Get player's betting balance
        do
        {
            cout << "\t\tHello, " << playerName<<", Enter amount to bet : $";
            cin >> bettingAmount;
            if(bettingAmount > balance)
                cout << "\t\tBetting balance is not sufficient to play game!\n"
                       <<"\n\t\tRe-enter balance\n ";
        }while(bettingAmount > balance);
// Get player's numbers
        do
        {
            cout << "\t\tGuess any betting number between 1 & 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "\n\t\tNumber should be between 1 to 10\n"
                    <<"\t\tRe-enter number:\n ";
        }while(guess <= 0 || guess > 10);
        dice = rand()%10 + 1;
        if(dice == guess)
        {
            cout << "\n\nYou are in luck!! You have won Rs." << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
        }
        else
        {
            cout << "\t\tOOPs, better luck in next time !! You lost $ "<< bettingAmount <<"\n";
            balance = balance - bettingAmount;
        }
        cout << "\n\t\tThe winning number was : " << dice;
        cout << "\n\t\t"<<playerName<<", You have balance only $ " << balance << "\n";
        if(balance == 0)
        {
            cout << "\t\tYou have no more money to play again";
            break;
        }
        cout << "\n\n\t\t--> Do you want to play again (y/n)? ";
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    cout << "\t\tThanks for showing your Interest. \n\t\tYour balance is $ " << balance << "\n\n";
    return 0;
}
void rules()
{
    system("cls");
    cout << "\t\t================= GAMING RULES ====================\n";
    cout << "\t\t|| 1) Choose a number between 1 to 10    \t ||\n";
    cout << "\t\t|| 2) Winner gets 10 times of the money bet  \t ||\n";
    cout << "\t\t|| 3) Wrong bet, and you lose the amount you bet ||\n";
    cout<<"\t\t===================================================";
}
