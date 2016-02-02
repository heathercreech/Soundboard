#include "scaudio.h"


AudioManager::AudioManager(Application* application){

	app = application;
	
}


//just call quit
AudioManager::~AudioManager(){
}


//loads music from designated path and gives it a name
void AudioManager::loadMusic(std::string path, std::string name){
	Mix_Music* loaded = Mix_LoadMUS(path.c_str());
	if(loaded == NULL){
		app->getDebug().log("error", "Loading of music failed: %s", Mix_GetError());
	}else{
		music[name] = loaded;
	}
}


//loads a sound from designated path and gives it a name
void AudioManager::loadSound(std::string path, std::string name){
	Mix_Chunk* loaded = Mix_LoadWAV(path.c_str());
	if(loaded == NULL){
		app->getDebug().log("error", "Loading of sound failed: %s", Mix_GetError());
	}else{
		sounds[name] = loaded;
	}
}


//plays the indicated music track
void AudioManager::playMusic(std::string name){
	if(Mix_PlayingMusic() == 0){
		Mix_PlayMusic(music[name], -1);
	}
}


//pauses the music if it currently isn't paused
void AudioManager::pauseMusic(){
	if(Mix_PausedMusic() != 1){
		Mix_PauseMusic();
	}
}


//resumes music if it is paused
void AudioManager::resumeMusic(){
	if(Mix_PausedMusic() == 1){
		Mix_ResumeMusic();
	}
}

//stops all music
void AudioManager::stopMusic(){
	Mix_HaltMusic();
}


//plays the indicated sound effect
void AudioManager::playSound(std::string name){
	Mix_PlayChannel(-1, sounds[name], 0);
}


//helper function for quit(), frees all music
void AudioManager::freeMusic(){
	for(std::map<std::string, Mix_Music*>::iterator it = music.begin(); it != music.end(); it++){
		Mix_FreeMusic(it->second);
	}
}


//helper function for quit(), frees all sounds
void AudioManager::freeSounds(){
	for(std::map<std::string, Mix_Chunk*>::iterator it = sounds.begin(); it != sounds.end(); it++){
		Mix_FreeChunk(it->second);
	}
}


//cleans up everything
void AudioManager::quit(){
	freeMusic();
	freeSounds();
	Mix_Quit();
}