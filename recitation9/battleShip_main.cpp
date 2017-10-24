#include <iostream>
#include "battleShip.h"

using namespace std;

int main(){
	//TODO: Declare 3 instances of the battleship class: Destroyer Carrier Cruiser
	battleShip ship_one ("Destroyer");
	battleShip ship_two ("Carrier");
	battleShip ship_three ("Cruiser");


	//TOD0: Give the ships a size: Destroyer-3 Carrier-5 Cruiser-2
	// you will need to call the appropriate methods
	ship_one.setSize(3);
	ship_two.setSize(5);
	ship_three.setSize(2);


	// Once you have this running for one, expand this while loop to include the other
	// two instances. Have the while loop end when all three ships have been sunk
	while(ship_one.isSunk() == false && ship_two.isSunk() == false && ship_three.isSunk() == false){
		ship_one.recordHit();
		ship_two.recordHit();
		ship_three.recordHit();
	}
}
