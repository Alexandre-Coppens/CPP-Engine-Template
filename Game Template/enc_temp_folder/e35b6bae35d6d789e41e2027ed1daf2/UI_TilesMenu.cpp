#include "UI_TilesMenu.h"

UI_TilesMenu::UI_TilesMenu(){
	interactibleBar = Rectangle{ 0, GetScreenHeight() * 0.375f, 30, GetScreenHeight() * 0.250f};
}

UI_TilesMenu::~UI_TilesMenu(){
}

void UI_TilesMenu::Update(Vector2* scroll){
}

void UI_TilesMenu::Draw(Vector2* scroll){
	if (open) {

	}
	else {
		DrawRectanglePro(interactibleBar, Vector2Zero(), 0, BLACK);
	}
}

void  UI_TilesMenu::Clicked(){
	open = !open;
}

void UI_TilesMenu::OpenTilesTab(){
}
