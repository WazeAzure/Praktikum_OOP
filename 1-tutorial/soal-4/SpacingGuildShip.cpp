#include "SpacingGuildShip.hpp"

float SpacingGuildShip::totalGuildTravel = 0;
int SpacingGuildShip::producedShips = 0;

SpacingGuildShip::SpacingGuildShip(): serialNum(producedShips + 1), guildNavigatorCount(3), maxPassengerCap(50){
    this->passengerCount = 0;
    this->operatingGuildNavigator = 3;
    this->spiceStock = 50;
    SpacingGuildShip::producedShips++;
}

SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock): serialNum(producedShips + 1), guildNavigatorCount(guildNavigatorCount), maxPassengerCap(maxPassengerCap){
    this->passengerCount = 0;
    this->operatingGuildNavigator = guildNavigatorCount;
    this->spiceStock = spiceStock;
    SpacingGuildShip::producedShips++;
}

SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip& s): serialNum(producedShips + 1), guildNavigatorCount(s.guildNavigatorCount), maxPassengerCap(s.maxPassengerCap){
    this->passengerCount = s.passengerCount;
    this->operatingGuildNavigator = s.operatingGuildNavigator;
    this->spiceStock = s.spiceStock;
    SpacingGuildShip::producedShips++;
}

SpacingGuildShip::~SpacingGuildShip(){

}

int SpacingGuildShip::getShipSerialNum() const {
    return this->serialNum;
}

int SpacingGuildShip::getPassengerCount() const {
    return this->passengerCount;
}

void SpacingGuildShip::travel(float distance) {
    if(this->operatingGuildNavigator > 0){
        SpacingGuildShip::totalGuildTravel += (distance / (E * E * this->operatingGuildNavigator));
        this->operatingGuildNavigator--;
    }
}

void SpacingGuildShip::boarding(int addedPassengers){
    this->passengerCount += addedPassengers;
    if(this->passengerCount > this->maxPassengerCap){
        this->passengerCount = this->maxPassengerCap;
    }
}

void SpacingGuildShip::dropOff(int droppedPassengers){
    this->passengerCount -= droppedPassengers;
    if(this->passengerCount < 0){
        this->passengerCount = 0;
    }
}

void SpacingGuildShip::refreshNavigator(int n){
    // find max possible amount of operator based on spice
    int max_n_spice = this->spiceStock / GUILD_NAVIGATOR_SPICE_DOSE;
    if(n < max_n_spice){
        max_n_spice = n;
    }

    // possible add
    if(this->operatingGuildNavigator + max_n_spice > this->guildNavigatorCount){
        max_n_spice = (this->operatingGuildNavigator + max_n_spice) - this->guildNavigatorCount;
    }

    this->operatingGuildNavigator += max_n_spice;
    this->spiceStock -= max_n_spice * GUILD_NAVIGATOR_SPICE_DOSE;
}

void SpacingGuildShip::transitToArrakis(int addedSpice){
    this->spiceStock += addedSpice;
}
