#include "PremiumUser.h"
#include "ArtistUser.h"

int main(){
    char x[3] = {'a', 'b', 'c'}; 
    User user(x);

    char s[] = "edbert";
    user.setName(s);

    user.viewMusicList();
    char song[] = "I wanna live forever";
    user.addFavouriteMusic(song);
    user.viewMusicList();

    PremiumUser pu(x);
    pu.viewMusicList();
}