#include "ArtistUser.h"
#include <iostream>
#include <cstring>

using namespace std;

int ArtistUser::num_of_artist = 0;

ArtistUser::ArtistUser(char* name) : User(name) {
    this->num_of_music_uploaded = 0;
    this->uploaded_music_list = new char*[this->num_of_music_uploaded];
    ArtistUser::num_of_artist++;
}

ArtistUser::ArtistUser(const ArtistUser& au) : User(au) {
    this->num_of_music_uploaded = au.num_of_music_uploaded;
    this->uploaded_music_list = new char*[this->num_of_music_uploaded];

    int i=au.num_of_music_uploaded;
    while(i--){
        this->uploaded_music_list[i-1] = new char[strlen(au.uploaded_music_list[i-1])];
        strcpy(this->uploaded_music_list[i-1], au.uploaded_music_list[i-1]);
    }
    ArtistUser::num_of_artist++;
}

ArtistUser::~ArtistUser(){
    cout << "Artist user " << this->name << " deleted" << endl;
    delete [] this->uploaded_music_list;
    this->num_of_music_uploaded = 0;
}

void ArtistUser::uploadMusic(char* title){
    char** temp_list = new char*[this->num_of_music_uploaded + 1];
    int i = 0;

    temp_list[this->num_of_music_uploaded] = new char[strlen(title)];
    strcpy(temp_list[this->num_of_music_uploaded], title);

    for(int i=0; i<this->num_of_music_uploaded; i++){
        temp_list[i] = new char[strlen(this->music_list[i])];
        strcpy(temp_list[i], this->music_list[i]);
    }

    delete [] this->uploaded_music_list;
    this->uploaded_music_list = temp_list;
    this->num_of_music_uploaded++;
}

void ArtistUser::deleteUploadedMusic(char* title){
    char** temp_list = new char*[this->num_of_music_uploaded - 1];
    int i = 0, counter = 0;

    for(int i=0; i<this->num_of_music_uploaded; i++){
        if(strcmp(title, this->uploaded_music_list[i])){
            temp_list[counter] = new char[strlen(this->uploaded_music_list[i])];
            strcpy(temp_list[counter], this->uploaded_music_list[i]);
            counter++;
        }
    }

    delete [] this->uploaded_music_list;
    this->uploaded_music_list = temp_list;
    this->num_of_music_uploaded--;
}

void ArtistUser::viewUploadedMusicList() const {
    int i=0;
    for(i=0; i<this->num_of_music_uploaded; i++){
        cout << i+1 << ". " << this->uploaded_music_list[i] << endl;
    }
}

int ArtistUser::getNumOfMusicUploaded() const {
    return this->num_of_music_uploaded;
}

int ArtistUser::getNumOfArtist(){
    return ArtistUser::num_of_artist;
}
