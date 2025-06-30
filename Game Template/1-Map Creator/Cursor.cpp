#include "Cursor.h"
#include "Terrain.h"
#include "AssetsList.h"

#include "rlgl.h"
#include "raymath.h"
#include <algorithm>

using std::to_string;

int currentTexture{ 0 };
int layer{ 0 };
int rotation{ 0 };

Cursor::Cursor(){
}

Cursor::~Cursor(){
}

void Cursor::Update(Vector2* scroll){
	//Move
	if (IsMouseButtonDown(2)) {
		*scroll = Vector2Subtract(*scroll, GetMouseDelta());
	}

	scroll->x -= GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X) * scrollSpeed.x * GetFrameTime();
	scroll->y -= GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y) * scrollSpeed.y * GetFrameTime();

	//Rotation + Layer change
	if (IsKeyPressed(KEY_UP) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_UP)) {
		if (layer == Terrain::maxLayer - 1) layer = 0;
		else layer++;
	}
	if (IsKeyPressed(KEY_DOWN) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN)) {
		if (layer == 0) layer = Terrain::maxLayer - 1;
		else layer--;
	}
	if (IsKeyPressed(KEY_Q) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) {
		if (rotation == 0) rotation = 270;
		else rotation -= 90;
	}
	if (IsKeyPressed(KEY_E) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) {
		if (rotation == 270) rotation = 0;
		else rotation += 90;
	}

	//Tiles placement
	Vector2 mPos{ (int)floor((scroll->x + GetMouseX()) / Terrain::tileSize.x), (int)floor((scroll->y + GetMouseY()) / Terrain::tileSize.y) };
	if (IsMouseButtonPressed(0)) {
		vector<Actor*> actors = GetAllActorsInCollisionVector2(GetMousePosition());
		if (actors.size() > 0) {
			for (int i = 0; i < actors.size(); i++) {
				if (actors[i]->type == ActorType::UI) {
					actors[0]->Clicked();
					break;
				}
			}
		}
		else Terrain::AddNewTile(layer, rotation, mPos, AssetList::GetNameAtPosition(currentTexture));
	}
	if (IsMouseButtonPressed(1)) Terrain::RemoveTile(layer, mPos);
	Vector2 cPos{ (int)floor((scroll->x + GetScreenWidth() * 0.5f) / Terrain::tileSize.x), (int)floor((scroll->y + Terrain::tileSize.y * 0.5f + GetScreenWidth() * 0.5f) / Terrain::tileSize.y) };
	if (IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) Terrain::AddNewTile(layer, rotation, cPos, AssetList::GetNameAtPosition(currentTexture));
	if (IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)) Terrain::RemoveTile(layer, cPos);

	//Save / Load
	if ((IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_S)) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_MIDDLE_RIGHT))Terrain::SaveMap("TowerPath");
	if ((IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_O)) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_MIDDLE_LEFT))Terrain::LoadMap("TowerPath");
}

void Cursor::Draw(Vector2* scroll) {
	rlPushMatrix();
	rlTranslatef(0 - scroll->x, 25 * 50 - scroll->y, 0);
	rlRotatef(90, 1, 0, 0);
	DrawGrid(100, 50);
	rlPopMatrix();

	DrawText(("X. " + to_string((scroll->x - GetMouseX()) / Terrain::tileSize.x)).c_str(), 10, 10, 20, GRAY);
	DrawText(("Y. " + to_string((scroll->y - GetMouseY()) / Terrain::tileSize.y)).c_str(), 10, 30, 20, GRAY);
	DrawText(("Current Sprite:  " + AssetList::GetNameAtPosition(currentTexture)).c_str(), 10, 50, 20, ORANGE);
	DrawText(("Current Layer:  " + to_string(layer)).c_str(), 10, 70, 20, ORANGE);
	DrawText(("Current Rotation:  " + to_string(rotation)).c_str(), 10, 90, 20, ORANGE);

	Texture2D* sprite = &AssetList::SpriteList[AssetList::GetNameAtPosition(currentTexture)];
	DrawTexturePro(*sprite,
		Rectangle{ 0, 0, (float)sprite->width, (float)sprite->height },
		Rectangle{ 500, 50, 80, 80 },
		Vector2{ 40,40 },
		rotation,
		WHITE);

	if (GetFrameTime() != 0)
	{
		DrawText(TextFormat("CURRENT FPS: %i", (int)(1.0f / GetFrameTime())), 10, GetScreenHeight() - 30, 20, BLACK);
	}

	DrawRectangle(GetScreenWidth() * 0.5f - 5, GetScreenHeight() * 0.5f - 5, 10, 10, BLACK);
}