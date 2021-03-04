#pragma once
#include "Graphics.h"
#include "Font.h"
#include "Vec2.h"
#include <vector>

class Board{
public:
	Board();
	void Draw(Graphics &gfx, Font ft);

	const static int width = 4, height = 4;
	const static int cellSize = 100;
private:
	void InitSpawn();
	void SpawnCell();
	void CheckCells();

	class Cell{
	public:
		void Draw(Graphics &gfx, Font ft, Vei2 boardPos);
		Cell(Vei2 _pos, int _value);
		int value;
		Vei2 pos;
	};

	bool cellsAvalible = true;
	std::vector<std::vector<Cell>> cells;
	Vei2 pos = {200, 100};
};