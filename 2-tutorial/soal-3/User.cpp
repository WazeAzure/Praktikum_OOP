#include <iostream>
#include <cstring>
#include "User.h"
using namespace std;

int User::n_user = 0;

// ctor, parameter: nama pengguna
User::User(char* nama) {
    this->name = new char[strlen(nama)];
    strcpy(this->name, nama);
    this->num_of_favourite_music = 0;
    this->music_list = new char* [this->num_of_favourite_music];
    User::n_user++;
}

// cctor
User::User(const User& user) {
    this->name = new char[strlen(user.name)];
    strcpy(this->name, user.name);
    this->num_of_favourite_music = user.num_of_favourite_music;
    this->music_list = new char*[this->num_of_favourite_music];
    for (int i = 0; i < this->num_of_favourite_music; i++) {
        this->music_list[i] = new char[strlen(user.music_list[i])];
        strcpy(this->music_list[i], user.music_list[i]);
    }
    User::n_user++;
}

// dtor
// selain implementasi, print juga "User <nama user> deleted<endl>"
// Contoh:
// User A deleted
//
User::~User() {
    cout << "User " << this->name << " deleted" << endl;
    delete [] this->name;
    for (int i = 0; i < this->num_of_favourite_music; i++) {
        delete [] music_list[i];
    }
    delete [] this->music_list;
    User::n_user--;
}

// Asumsi: musik unik, parameter: judul musik
void User::addFavouriteMusic(char* judul) {
    // bikin temp
    char** temp = new char*[this->num_of_favourite_music];
    // nyalin ke temp
    for (int i = 0; i < this->num_of_favourite_music; i++) {
        temp[i] = new char[strlen(this->music_list[i])];
        strcpy(temp[i], this->music_list[i]);
        delete[] music_list[i];
    }
    
    // alokasi ulang dengan ukuran + 1
    delete [] this->music_list;

    this->num_of_favourite_music++; // jangan lupa
    this->music_list = new char*[this->num_of_favourite_music];
    // balikin dari temp
    for (int i = 0; i < this->num_of_favourite_music-1; i++) {
        this->music_list[i] = new char[strlen(temp[i])];
        strcpy(this->music_list[i], temp[i]);
        delete [] temp[i];
    }
    // nambahin judul baru
    this->music_list[this->num_of_favourite_music-1] = new char[strlen(judul)];
    strcpy(this->music_list[this->num_of_favourite_music-1], judul);
    delete [] temp;
}

void User::deleteFavouriteMusic(char* judul) {
    // cek dulu yang mau didelete ada apa ga
    bool found = false;
    int p = 0;

    while (!found && p < this->num_of_favourite_music) {
        if (strcmp(this->music_list[p], judul) == 0) {
            found = true;
        } else {
            p++;
        }
    }
    // kalo ketemu
    if (found) {
        // bikin temp
        char** temp = new char*[this->num_of_favourite_music];
        // nyalin ke temp
        for (int i = 0; i < this->num_of_favourite_music; i++) {
            temp[i] = new char[strlen(this->music_list[i])];
            strcpy(temp[i], this->music_list[i]);
            delete[] this->music_list[i];
        }
        // alokasi ulang dengan ukuran - 1
        delete [] this->music_list;

        int count = 0;

        this->music_list = new char*[this->num_of_favourite_music-1];
        // balikin dari temp
        for (int i = 0; i < this->num_of_favourite_music; i++) {
            if (strcmp(temp[i], judul) != 0) {
                this->music_list[count] = new char[strlen(temp[i])];
                strcpy(this->music_list[count], temp[i]);
                count++;
                delete [] temp[i];
            }
        }
        // nambahin judul baru
        delete [] temp;
        this->num_of_favourite_music--; // jangan lupa
    }
}

void User::setName(char* namabaru) {
    delete [] name;
    this->name = new char[strlen(namabaru)];
    strcpy(this->name, namabaru);
}

char* User::getName() const {
    return this->name;
}

int User::getNumOfFavouriteMusic() const {
    return this->num_of_favourite_music;
}

// format print:
// <No>. <Judul musik><endl>
// contoh:
// 1. Starship - Nicki Minaj
// 2. To Be Human - Sia, Labrinth
//
// jika tidak ada musik, print: "No music in your favourite list<endl>"
void User::viewMusicList() const {
    if (this->num_of_favourite_music == 0) {
        cout << "No music in your favourite list" << endl;
    } 
    else {
        for (int i = 0; i < this->num_of_favourite_music; i++) {
            cout << i+1 << ". " << this->music_list[i] << endl;
        }
    }
}

int User::getNumOfUser() {
    return User::n_user;
}