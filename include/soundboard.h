#ifndef SOUNDBOARD_H
#define SOUNDBOARD_H

#include "scapplication.h"
#include <fstream>
#include <map>
#include <string>

class SoundBoardLogic : public ObjectLogic{
public:
	SoundBoardLogic(Application*);
	~SoundBoardLogic();
	
	void update();
	
private:
	int loadSettings(); //load the key config and filenames from the settings file
	std::map<SDL_Keycode, std::string> key_to_sound; //contains the designated keycodes and the sounds that are to be played when pressing them
};


#endif