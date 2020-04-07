#include "WumpusFunctions.h"

void instructions(){
    char back;
    cout << " Welcome to Kill The Corona " << endl;
    cout << " The Corona floats in a cave of 20 rooms. Each room has 3 tunnels leading to" << endl;
    cout << " other rooms. (The room has a form like a dodecahedron, maybe this will help you" << endl;
    cout << " to kill the Corona). \n" << endl;
    cout << " Hazards: \n" << endl;
    cout << " quarantine zones - two rooms are quarantine zones. If you go there, you " << endl;
    cout << " are in quarantine and you won't be able to go anywhere (you lose). \n" << endl;
    cout << " Police Officers - two other rooms have police officers.  If you go there, an officer grabs you" << endl;
    cout << " and takes you to some other room at random. (Which may be troublesome). Once the" << endl;
    cout << " officer has moved you, that officer moves to another random location on the map.\n\n" << endl;
 
    cout << " Corona" << endl;
    cout << " The Corona is not bothered by hazards (it's just air and police officers can't " << endl;
    cout << " risk to get Corona).  Usually it stays put.  Two things can happen to the Corona: you shooting a" << endl;
    cout << " spray or you entering it's room. If you spray the room but it isn't there, there will be a chance " << endl;
    cout << " it moves to a neighbouring room or it stays. After that, if it is where you are, it infects you and you lose!\n" << endl;
 
    cout << " You \n" << endl;
    cout << " Each turn you may move, quit or shoot a spray using the commands move, quit & shoot." << endl;
    cout << " Moving: you can move one room (thru one tunnel)." << endl;
    cout << " Sprays: you have 5 sprays. You lose when you run out. You aim by telling the" << endl;
    cout << " computer the rooms you want the spray to go to.  If the spray can't go that way" << endl;
    cout << " (if no tunnel), the spray will not fire." << endl;
 
    cout << " Warnings" << endl;
    cout << " If one room away from a hazard, the computer says:" << endl;
 
    cout << " Bat: 'Bats nearby'" << endl;
    cout << " Pit: 'I feel a draft'" << endl;
    cout << " If you are two rooms away from the wumpus, the game says:" << endl;
    cout << " Wumpus: 'I smell a wumpus'" << endl;
 
    cout << endl;
    cout << "Press any button to return to menu" << endl;
    cin >> back;
}