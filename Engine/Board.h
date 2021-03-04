#pragma once
#include "Graphics.h"
#include "Font.h"
#include "Vec2.h"
#include <vector>

enum class Directions{
	RIGHT, LEFT, UP, DOWN
};

class Board{
private:
	class Cell{
	public:
		void Draw(Graphics &gfx, Font ft, Vei2 boardPos);
		Cell(Vei2 _pos, int _value);
		int value;
		Vei2 pos;
		Vei2 oldPos;
		bool finishedAnimation = true;
	};
public:
	Board();
	void Draw(Graphics &gfx, Font ft);
	void MoveAllCells(Directions dir);

	const static int width = 4, height = 4;
	const static int cellSize = 100;
private:
	void InitSpawn();
	void SpawnCell();
	void CheckCells();
	size_t GetClosestCell(Cell &movable, Directions dir);
	void MoveCell(Cell &original, Cell &destination);
	void MergeCells(Cell & destination, Cell & donor);

	bool cellsAvalible = true;
	std::vector<std::vector<Cell>> cells;
	Vei2 pos = {200, 100};
};