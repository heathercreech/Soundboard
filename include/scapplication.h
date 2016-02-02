#ifndef SCAPPLICATION_H
#define SCAPPLICATION_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <vector>
#include <map>
#include <memory>
#include <stdio.h>
#include "scinput.h"
#include "scobject.h"
#include "scaudio.h"
#include "debug.h"

class ApplicationObject;
class AudioManager;

//handles initiation and clean up
class Application{
public:
	Application();
	~Application();
	
	int init();
	void handleInput();
	void loop();
	void update();
	void render();
	void stop();
	
	bool canRun();
	void addObject(ApplicationObject*);
	
	ApplicationDebug getDebug();
	void setDebug(bool);
	void log_info(const char*);
	void log_error(const char*);
	
	Input* getInput();
	
	SDL_Window* getWindow();
	SDL_Renderer* getRenderer();
	
	AudioManager* getAudioManager();
	
private:
	std::vector<ApplicationObject*> objs;
	
	std::unique_ptr<AudioManager> audio_manager;
	
	bool can_run = false;
	
	Input input;
	
	ApplicationDebug debug;
	
	SDL_Window* app_window = NULL;
	SDL_Renderer* app_renderer = NULL;
};

#endif