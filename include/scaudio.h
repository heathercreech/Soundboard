#ifndef SCAUDIO_H
#define SCAUDIO_H

#include "scapplication.h"
#include <map>
#include <string>

class Application;

class AudioManager{
public:
	AudioManager(Application*);
	~AudioManager();
	
	void loadMusic(std::string, std::string);
	void loadSound(std::string, std::string);
	
	void playMusic(std::string);
	void playSound(std::string);
	
	void pauseMusic();
	void resumeMusic();
	void stopMusic();
	
	void quit(); //cleans up everything related to audio

	
private:
	void freeMusic(); //helper function, for clarification. frees all music in map
	void freeSounds();//helper function, for clarification. frees all sounds in map

	std::map<std::string, Mix_Chunk*> sounds;
	std::map<std::string, Mix_Music*> music;
	
	Application* app;
};

#endif