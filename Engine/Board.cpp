#include "Board.h"
#include <cmath>

Board::Board(){
	InitSpawn();
}

void Board::Draw(Graphics &gfx, Font ft){
	for(auto &i : cells )
		for(auto &j : i)
			j.Draw(gfx, ft, pos);
}

void Board::InitSpawn(){
	for(int y = 0; y < height; y++){
		cells.push_back({});
		for(int x = 0; x < width; x++)
			cells[y].push_back({{x, y}, 2048});
	}
}

void Board::Cell::Draw(Graphics &gfx, Font ft, Vei2 boardPos){
	Vei2 drawPos = pos * cellSize + boardPos;
	int nSymbols = 0, temp = value;
	while(temp > 0){
		nSymbols++;
		temp /= 10;
	}
	gfx.DrawFilledRectBorder(drawPos, {cellSize, cellSize}, Colors::MakeRGB(110 + 5 * (int)log2(value), 110, 0), Colors::LightGray);
	ft.DrawText(std::to_string(value), drawPos + Vei2(50 - 8 * nSymbols, 36), Colors::White, gfx);
}

Board::Cell::Cell(Vei2 _pos, int _value) : 
	pos(_pos), value(_value)
{}
