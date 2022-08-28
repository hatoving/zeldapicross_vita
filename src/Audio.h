/*

    Zelda Picross

    Copyright (C) 2010  Vincent Jouillat

    Please send bugreports with examples or suggestions to www.zeldaroth.fr

*/

#ifndef __AUDIO_H__
#define __AUDIO_H__

#include <vitasdk.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

class Audio {
    public :
        static Audio* getInstance();
        void playSound(int id, int chl = -1);
        void playMusic(int id);
        void stopMusic();
        void replayMusic();
        void setVolume(int vol);
        void setVolson(int volson);
    private :
        Audio();
        ~Audio();
        static Audio instance;
        Mix_Chunk* getSound(const char* son);
        Mix_Music* getMusic(const char* zik);
        void loadSounds();
        void freeSounds();
        void freeMusic();
        Mix_Music* choixMusique(int id);
        
        bool SOUND;
        int previous_volume;
        int previous_volson;
        int volume;
        int musiqueId;
        bool playing;
        Mix_Chunk** sons;
        Mix_Music* music;
#ifdef __vita__
        char* mem;
        FILE* f;
#endif

};

#endif  // Audio.h
