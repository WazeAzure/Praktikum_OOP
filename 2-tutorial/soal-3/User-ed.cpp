#include "User.h"
#include <iostream>
#include <cstring>

using namespace std;

int User::n_user = 0;

User::User(char* name){
    this->name = new char[strlen(name)];
    strcpy(this->name, name);

    this->num_of_favourite_music = 0;
    this->music_list = new char*[this->num_of_favourite_music];
    User::n_user++;
}

User::User(const User& u){
    this->name = new char[strlen(u.name)];
    strcpy(this->name, u.name);

    this->num_of_favourite_music = u.num_of_favourite_music;
    this->music_list = new char*[u.num_of_favourite_music];

    int i=0;
    for(i=0; i < this->num_of_favourite_music; i++){
        this->music_list[i] = new char(strlen(u.music_list[i]));
        strcpy(this->music_list[i], u.music_list[i]);
    }
    User::n_user++;
}

User::~User(){
    cout << "User " << this->name << " deleted" << endl;
    delete this->name;
    for (int i = 0; i < this->num_of_favourite_music; i++) {
        delete [] music_list[i];
    }
    delete [] this->music_list;
    User::n_user--;
}

void User::addFavouriteMusic(char* title){
    char** temp_list = new char*[this->num_of_favourite_music + 1];
    int i = 0;

    for(int i=0; i<this->num_of_favourite_music; i++){
        temp_list[i] = new char[strlen(this->music_list[i])];
        strcpy(temp_list[i], this->music_list[i]);
    }
    temp_list[i] = new char[strlen(title)];
    strcpy(temp_list[i], title);

    delete [] this->music_list;

    this->num_of_favourite_music++;
    this->music_list = new char*[this->num_of_favourite_music];

    for(i=0; i<this->num_of_favourite_music; i++){
        this->music_list[i] = new char[strlen(temp_list[i])];
        strcpy(this->music_list[i], temp_list[i]);
        delete [] temp_list[i];
    }

    delete [] temp_list;
}

void User::deleteFavouriteMusic(char* title){
    char** temp_list = new char*[this->num_of_favourite_music - 1];
    int i = 0, counter = 0;

    for(int i=0; i<this->num_of_favourite_music; i++){
        if(strcmp(title, this->music_list[i])){
            temp_list[counter] = new char[strlen(this->music_list[i])];
            strcpy(temp_list[counter], this->music_list[i]);
            counter++;
        }
    }

    delete [] this->music_list;
    this->num_of_favourite_music--;
    this->music_list = new char*[this->num_of_favourite_music];

    for(i=0; i<this->num_of_favourite_music; i++){
        this->music_list[i] = new char[strlen(temp_list[i])];
        strcpy(this->music_list[i], temp_list[i]);
        delete [] temp_list[i];
    }

    delete [] temp_list;
}

void User::setName(char* name){
    delete [] this->name;
    this->name = new char[strlen(name)];
    strcpy(this->name, name);
}

char* User::getName() const {
    return this->name;
}

int User::getNumOfFavouriteMusic() const {
    return this->num_of_favourite_music;
}

void User::viewMusicList() const {
    int n = this->num_of_favourite_music;

    if(n == 0){
        cout << "No music in your favourite list\n";
        return ;
    }

    int i = 0;
    for(i=0; i<this->num_of_favourite_music; i++){
        cout << i+1 << " " << this->music_list[i] << endl;
    }
}

int User::getNumOfUser(){
    return User::n_user;
}