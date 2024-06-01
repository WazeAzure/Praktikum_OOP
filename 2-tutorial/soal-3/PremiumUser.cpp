#include <iostream>
#include <cstring>
#include "User.h"
#include "PremiumUser.h"
using namespace std;

//ctor, active = true, parameter: nama pengguna
PremiumUser::PremiumUser(char* nama) : User(nama) {
    this->active = true;
    this->num_of_music_downloaded = 0;
}

// cctor
PremiumUser::PremiumUser(const PremiumUser& premuser) : User(premuser) {
    this->active = premuser.active;
    this->num_of_music_downloaded = premuser.num_of_music_downloaded;
}

// dtor; implementasikan jika diperlukan
PremiumUser::~PremiumUser() {}
// jika tidak diperlukan, hapus dtor
// jika diperlukan
// selain implementasi, print juga "Premium user <nama user> deleted<endl>"
// Contoh:
// Premium user A deleted

// print kata-kata sbg. berikut: "Music Downloaded: <judul><endl>"
// Contoh: 
// Music Downloaded: Loyal - Chris Brown, Lil Wayne, Tyga
//
// Jika akun premium tidak aktif, print: "Activate premium account to download music<endl>"
void PremiumUser::downloadMusic(char* judul) {
    if (this->active) {
        cout << "Music Downloaded: " << judul << endl;
        this->num_of_music_downloaded++;
    } else {
        cout << "Activate premium account to download music" << endl;
    }
}

void PremiumUser::inactivatePremium() {
    this->active = false;
}

void PremiumUser::activatePremium() {
    this->active = true;
}

int PremiumUser::getNumOfMusicDownloaded() const {
    return this->num_of_music_downloaded;
}

// mengembalikan nilai active
bool PremiumUser::getPremiumStatus() const {
    return this->active;
}