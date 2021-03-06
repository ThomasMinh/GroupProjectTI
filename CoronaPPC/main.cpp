#include <iostream>
#include "CoronaFunctions.h"
using namespace std;
 
void StartGame() {
    srand(time(NULL));  // rand() zal hierdoor steeds een andere selectie van getallen genereren
    int choice;
    bool validChoice;
    bool keepPlaying;
    
    do {
        keepPlaying = true;
        cout << "Welcome to Kill The Corona." << endl;
        cout << "1) Play Game" << endl;
        cout << "2) instructions" << endl;
        cout << "3) Computer Play game" << endl;
        cout << "4) Quit" << endl;
        
        do{
          validChoice = true;
          cout << "Please make a selection: ";
          try
          {
              cin >> choice;
              switch (choice)
              {
                  case 1:
                      PlayGame();
                      break;
                  case 2:
                      instructions();
                      break;
                  case 3:
                      PlayGameComputer();
                      break;
                  case 4:
                      cout << "Quitting." << endl;
                      keepPlaying = false;
                      break;
                  default:
                      validChoice = false;
                      cout << "Invalid choice. Please try again." << endl;
                      cin.clear();
                      cin.ignore(10000, '\n');
                      break;
              }
          }
          catch (...)
          {
              validChoice = false;
              cout << "Invalid choice. Please try again." << endl;
              cin.clear();
              cin.ignore(10000, '\n');
          }
 
      } while (validChoice == false);
  } while (keepPlaying);
}
 
int main() {
    StartGame();
}


