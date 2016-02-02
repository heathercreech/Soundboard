#include "soundboard.h"

//load settings
SoundBoardLogic::SoundBoardLogic(Application* application) : ObjectLogic(application, NULL){
	if(loadSettings() != 0){
		app->getDebug().log("error", "SoundBoardLogic was unable to load the settings file. Please make sure the file \"settings.txt\" is in the executable's directory and correctly formatted.");
	}
}


//
SoundBoardLogic::~SoundBoardLogic(){
	
}


//
void SoundBoardLogic::update(){
	for(std::map<SDL_Keycode, std::string>::iterator it = key_to_sound.begin(); it != key_to_sound.end(); it++){
		if(app->getInput()->getKeyDown(it->first)){
			app->getAudioManager()->playSound(it->second);
		}
	}
}


//loads the keys and sounds
int SoundBoardLogic::loadSettings(){
	std::ifstream s_file("settings.txt");
	int counter = 1;
	
	if(!s_file.good()){
		app->getDebug().log("error", "Unable to open \"settings.txt\"");
		return -1;
	}
	
	while(!s_file.eof()){
		std::string line;
		getline(s_file, line);
		
		
		//allow comments in the file
		if(line.substr(0, 2) != "//" && line.length() != 0){
		
			if(line.find(":") == std::string::npos){
				app->getDebug().log("error", "(Settings Line: %d) unable to parse input. ", counter);
			}
		
			//delimit string by ':'
			int delimiter_position = line.find(":");
			std::string key_name = line.substr(0, delimiter_position);
			std::string file_name = line.substr(delimiter_position+1);
			
			SDL_Keycode key = SDL_GetKeyFromName(key_name.c_str());
			if(key == SDLK_UNKNOWN){
				app->getDebug().log("error", "(Settings Line: %d) loadSettings was unable to find the key %s. ", counter, key_name.c_str());
				return -1;
			}

			app->getAudioManager()->loadSound(file_name, file_name);
			
			key_to_sound[key] = file_name;
		}
		
		counter++;
	}
	
	return 0;
}