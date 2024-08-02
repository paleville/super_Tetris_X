#include<iostream>
#include"windowManager.h"
#include"actualGame.h"

//[15]	
int main()
{
	srand(actualGame::time);
	

	windowManager::getinstance().initialize();
	windowManager::getinstance().loadFile();
	//windowManager::getinstance().update();
	//windowManager::getinstance().draw();
	//is.loadFile();
	

	

	return 22;
}