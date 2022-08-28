/*

    Zelda Picross

    Copyright (C) 2010  Vincent Jouillat

    Please send bugreports with examples or suggestions to www.zeldaroth.fr

*/

#include <sstream>
#include <fstream>
#include <iostream>

#include "Audio.h"

#ifdef __vita__
#include <sys/stat.h>
#endif

Audio Audio::instance=Audio();

Audio::Audio() : volume(0), musiqueId(0), playing(false) {
    SOUND = true;
    music = NULL;
#ifdef __vita__
    f = NULL;
    mem = NULL;
#endif
    
    if(SDL_InitSubSystem(SDL_INIT_AUDIO) == -1) SOUND = false;
    
    if (SOUND) {
#ifdef __vita__
        Mix_OpenAudio(22050, AUDIO_S16SYS, 1, 1024);
#else
        Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 2048);
#endif
        previous_volume = Mix_VolumeMusic(32);
        loadSounds();
        setVolson(32);
    }
}

Audio::~Audio() {
    if (SOUND) {
        freeSounds();
        Mix_PauseMusic();
        Mix_VolumeMusic(previous_volume);
        Mix_HaltMusic();
        freeMusic();
        Mix_CloseAudio();
    }
}

Audio* Audio::getInstance() {
    return &instance;
}

void Audio::setVolume(int volume) {
    if (SOUND) Mix_VolumeMusic(volume);
}

void Audio::setVolson(int volson) {
    if (SOUND) for (int i = 0; i < 16; i++) Mix_VolumeChunk(sons[i], volson);
}

void Audio::loadSounds() {
    sceClibPrintf("Loading sounds...\n");
    sons = new Mix_Chunk*[16];
    
    sons[0] = getSound("text"); // lettres
    sons[1] = getSound("menu1"); // menu 1
    sons[2] = getSound("menu2"); // menu 2
    sons[3] = getSound("menu3"); // menu 3
    sons[4] = getSound("surprise"); // surprise
    sons[5] = getSound("monte"); // monte
    sons[6] = getSound("descend"); // descend
    sons[7] = getSound("bomb"); // bombe
    sons[8] = getSound("textnext"); // suite texte
    sons[9] = getSound("textend"); // fin texte
    sons[10] = getSound("happy"); // trouve objet
    sons[11] = getSound("sword"); // �p�e
    sons[12] = getSound("Sword360"); // spin
    sons[13] = getSound("stamp"); // pose bombe
    sons[14] = getSound("danger"); // danger
    sons[15] = getSound("hurt"); // link se blesse
}

Mix_Chunk* Audio::getSound(const char* son) {
    char fSon[512];
#ifdef __vita__
    snprintf(fSon, sizeof(fSon), "%s/%s.ogg", "app0:data/sound", son);
    sceClibPrintf("Loading %s... \n", fSon);
#else
    snprintf(fSon, sizeof(fSon), "%s/%s.ogg", "data/sound", son);
#endif
    return Mix_LoadWAV(fSon);
}

Mix_Music* Audio::getMusic(const char* zik) {
    char fZik[512];
#ifdef __vita__
    struct stat info;
    snprintf(fZik, sizeof(fZik), "%s/%s.ogg", "app0:data/music", zik);
    sceClibPrintf("Loading %s... \n", fZik);
    return Mix_LoadMUS(fZik);
#else
    snprintf(fZik, sizeof(fZik), "/%s.mid", "data/music", zik);
    return Mix_LoadMUS(fZik);
#endif
}

void Audio::freeSounds() {
    if (SOUND) {
        for (int i = 0; i < 16; i++) Mix_FreeChunk(sons[i]);
        delete[] sons;
    }
}

void Audio::freeMusic() {
    Mix_FreeMusic(music);
#ifdef __vita__
    if (mem != NULL) {
        free(mem);
        mem = NULL;
    }
    if (f != NULL) {
        fclose(f);
        f = NULL;
    }
#endif
}

void Audio::playSound(int id, int chl) {
    if (SOUND) Mix_PlayChannel(chl,sons[id],0);
}

void Audio::playMusic(int id) {
    if (SOUND) {
         if (musiqueId != id) {
	        musiqueId = id;            
		    Mix_HaltMusic();
            freeMusic();
		    music = choixMusique(id);
		    Mix_PlayMusic(music,-1);
        }
    }
}

void Audio::stopMusic() {
    if (SOUND) Mix_HaltMusic();
}

void Audio::replayMusic() {
    if (SOUND) Mix_PlayMusic(music,-1);
}

Mix_Music* Audio::choixMusique(int id) {
     sceClibPrintf("Loading music...\n");
    switch (id) {
        case 1 : return getMusic("Plaine");
        case 2 : return getMusic("Home");
        case 3 : return getMusic("Lac");
        case 4 : return getMusic("Cocorico");
        case 5 : return getMusic("Mont");
        case 6 : return getMusic("BoisPerdus");
        case 7 : return getMusic("Jeu");
        case 8 : return getMusic("Chateau");
        case 9 : return getMusic("Boss");
        case 10 : return getMusic("DFinal");
        case 11 : return getMusic("BossF");
        case 12 : return getMusic("Zelda");
        case 190 : return getMusic("Selection");
        case 195 : return getMusic("Magasin");
        case 200 : return getMusic("Titre");
        case 210 : return getMusic("Debut");
        case 220 : return getMusic("Mort");
        case 230 : return getMusic("Fin");
        default : return getMusic("Plaine");
    }
}
