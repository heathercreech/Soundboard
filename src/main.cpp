#include "scapplication.h"
#include "soundboard.h"

int main(int argc, char* argv[]){
	Application app;
	app.init();
	
	ObjectRenderer sb_renderer;
	SoundBoardLogic sb_logic(&app);
	ApplicationObject sb_object(&app, &sb_renderer, &sb_logic);
	app.addObject(&sb_object);
	
	app.loop();
	return 0;
}