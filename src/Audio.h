/*

    Zelda Picross

    Copyright (C) 2010  Vincent Jouillat

    Please send bugreports with examples or suggestions to www.zeldaroth.fr

*/

#ifndef __AUDIO_H__
#define __AUDIO_H__

#include <vitasdk.h>
#include "vita/os_vita.h"
#include "vita/sound_vita.h"

class Audio {
    public :
        static Audio* getInstance();
        void playSound(int id, int chl = FSOUND_FREE);
        void playMusic(int id);
        void stopMusic();
        void replayMusic();
        void setVolume(int vol);
        void setVolson(int volson);
    private :
        Audio();
        ~Audio();
        static Audio instance;
        void loadSounds();
        void freeSounds();
        FMUSIC_MODULE* choixMusique(int id);
        
        bool SOUND;
        int previous_volume;
        int previous_volson;
        int volume;
        int musiqueId;
        bool playing;
        FSOUND_SAMPLE** sons;
        FMUSIC_MODULE* music;

};

#endif  // Audio.h
