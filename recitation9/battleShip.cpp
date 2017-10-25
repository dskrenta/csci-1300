#include "battleShip.h"

battleShip::battleShip(string shipName) {
    name = shipName;
}

battleShip::~battleShip() {
    // letting compiler handle deconstruction of the class
}

void battleShip::setShipName(string shipName) {
    name = shipName;
}

string battleShip::getShipName() {
    return name;
}

void battleShip::setSize(int shipSize) {
    size = shipSize;
}

int battleShip::getSize() {
    return size;
}

void battleShip::recordHit() {
    hits++;
}

bool battleShip::isSunk() {
    return hits >= size ? true : false;
}
