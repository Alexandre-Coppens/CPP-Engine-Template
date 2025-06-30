#include "UI_TilesMenu.h"

UI_TilesMenu::UI_TilesMenu(){
	type = ActorType::UI;
	position = Vector2{ 0, GetScreenHeight() * 0.375f };
	size = Vector2{ 30, GetScreenHeight() * 0.250f };
}

UI_TilesMenu::~UI_TilesMenu(){
}

void UI_TilesMenu::Update(Vector2* scroll){
}

void UI_TilesMenu::Draw(Vector2* scroll){
	Rectangle interactibleBar{ position.x, position.y, size.x, size.y };
	Rectangle menuBackground{ 0, GetScreenHeight() - GetScreenHeight() * 0.95f, 300, GetScreenHeight() * 0.9f };
	DrawRectanglePro(interactibleBar, Vector2Zero(), 0, BLACK);
	if (open) {
		DrawRectanglePro(menuBackground, Vector2Zero(), 0, LIGHTGRAY);
	}
}

void  UI_TilesMenu::Clicked(){
	open = !open;
	if(open) position = position = Vector2{ 300, GetScreenHeight() * 0.375f };
	else position = position = Vector2{ 0, GetScreenHeight() * 0.375f };
}

void UI_TilesMenu::OpenTilesTab(){
}
