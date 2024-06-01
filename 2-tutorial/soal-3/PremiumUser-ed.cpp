#include "PremiumUser.h"
#include <iostream>
#include <cstring>

using namespace std;

PremiumUser::PremiumUser(char* name): User(name) {
    this->active = true;
    this->num_of_music_downloaded = 0;
}

PremiumUser::PremiumUser(const PremiumUser& pu): User(pu) {
    cout << "Premium User Copied" << endl;
    this->active = pu.active;
    this->num_of_music_downloaded = pu.num_of_music_downloaded;
}

PremiumUser::~PremiumUser(){}

void PremiumUser::downloadMusic(char * title){
    if(!this->active){
        cout << "Active premium account to download music" << endl;
        return;
    }

    cout << "Music Downloaded: " << title << endl;
    this->num_of_music_downloaded++;
}

void PremiumUser::inactivatePremium(){
    this->active = false;
}

void PremiumUser::activatePremium(){
    this->active = true;
}

int PremiumUser::getNumOfMusicDownloaded() const {
    return this->num_of_music_downloaded;
}

bool PremiumUser::getPremiumStatus() const {
    return this->active;
}