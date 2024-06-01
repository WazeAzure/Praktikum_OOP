#include <iostream>
#include <cstring>
#include "User.h"
#include "ArtistUser.h"
using namespace std;

int ArtistUser::num_of_artist = 0;

//ctor, parameter: nama pengguna
ArtistUser::ArtistUser(char* nama) : User(nama) {
    this->num_of_music_uploaded = 0;
    this->uploaded_music_list = new char*[this->num_of_music_uploaded];
    ArtistUser::num_of_artist++;
}

// cctor
ArtistUser::ArtistUser(const ArtistUser& artist) : User(artist) {
    this->num_of_music_uploaded = artist.num_of_music_uploaded;
    this->uploaded_music_list = new char* [num_of_music_uploaded];
    for (int i = 0; i < num_of_music_uploaded; i++) {
        this->uploaded_music_list[i] = new char[strlen(artist.uploaded_music_list[i])];
        strcpy(this->uploaded_music_list[i], artist.uploaded_music_list[i]);
    }
    ArtistUser::num_of_artist++;
}

// dtor
// selain implementasi, print juga "Artist user <nama user> deleted"
// Contoh:
// Artist user A deleted
ArtistUser::~ArtistUser() {
    cout << "Artist user " << name << " deleted" << endl;
    for (int i = 0; i < num_of_music_uploaded; i++) {
        delete[] uploaded_music_list[i];
    }
    delete [] uploaded_music_list;
    ArtistUser::num_of_artist--;
}

// Asumsi: musik unik, parameter: judul musik
void ArtistUser::uploadMusic(char* music) {
    // bikin temp
    char** temp = new char*[this->num_of_music_uploaded];
    // nyalin ke temp
    for (int i = 0; i < this->num_of_music_uploaded; i++) {
        temp[i] = new char[strlen(this->uploaded_music_list[i])];
        strcpy(temp[i], this->uploaded_music_list[i]);
        delete[] uploaded_music_list[i];
    }
    delete [] this->uploaded_music_list;

    this->num_of_music_uploaded++; // jangan lupa
    // alokasi ulang dengan ukuran + 1
    this->uploaded_music_list = new char*[this->num_of_music_uploaded];
    // balikin dari temp
    for (int i = 0; i < this->num_of_music_uploaded-1; i++) {
        this->uploaded_music_list[i] = new char[strlen(temp[i])];
        strcpy(this->uploaded_music_list[i], temp[i]);
        delete[] temp[i];
    }
    // nambahin judul baru
    this->uploaded_music_list[this->num_of_music_uploaded-1] = new char[strlen(music)];
    strcpy(this->uploaded_music_list[num_of_music_uploaded-1], music);
    delete [] temp;
}

void ArtistUser::deleteUploadedMusic(char* music) {
    // cek dulu yang mau didelete ada apa ga
    bool found = false;
    int p = 0;

    while (!found && p < this->num_of_music_uploaded) {
        if (strcmp(this->uploaded_music_list[p], music) == 0) {
            found = true;
        } else {
            p++;
        }
    }
    // kalo ketemu

    if (found) {
        // bikin temp
        char** temp = new char*[this->num_of_music_uploaded];
        // nyalin ke temp
        for (int i = 0; i < this->num_of_music_uploaded; i++) {
            temp[i] = new char[strlen(this->uploaded_music_list[i])];
            strcpy(temp[i], this->uploaded_music_list[i]);
            delete [] uploaded_music_list[i];
        }
        // alokasi ulang dengan ukuran - 1
        delete [] this->uploaded_music_list;

        int count = 0;

        this->uploaded_music_list = new char*[this->num_of_music_uploaded-1];
        // balikin dari temp
        for (int i = 0; i < this->num_of_music_uploaded; i++) {
            if (strcmp(temp[i], music) != 0) {
                this->uploaded_music_list[count] = new char[strlen(temp[i])];
                strcpy(this->uploaded_music_list[count], temp[i]);
                count++;
                delete[] temp[i];
            }
        }
        delete [] temp;
        this->num_of_music_uploaded--; // jangan lupa
    }
}

// format print:
// <No>. <Judul musik><endl>
// contoh:
// 1. Starship - Nicki Minaj
// 2. To Be Human - Sia, Labrinth
//
// jika tidak ada musik, print: "No music uploaded<endl>"
void ArtistUser::viewUploadedMusicList() const {
    if (this->num_of_music_uploaded == 0) {
        cout << "No music uploaded" << endl;
    } 
    else {
        for (int i = 0; i < this->num_of_music_uploaded; i++) {
            cout << i+1 << ". " << this->uploaded_music_list[i] << endl;
        }
    }
}

int ArtistUser::getNumOfMusicUploaded() const {
    return this->num_of_music_uploaded;
}

int ArtistUser::getNumOfArtist() {
    return ArtistUser::num_of_artist;
}