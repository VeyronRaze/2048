#include "Board.h"
#include <cmath>
#include <random>

Board::Board(){
	InitSpawn();
}

void Board::Draw(Graphics &gfx, Font ft){
	for(auto &i : cells )
		for(auto &j : i)
			j.Draw(gfx, ft, pos);
}

void Board::InitSpawn(){
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> uid(0, 11);
	for(int y = 0; y < height; y++){
		cells.push_back({});
		for(int x = 0; x < width; x++)
			cells[y].push_back({{x, y}, (int)exp2(uid(rng))});
	}
}

void Board::Cell::Draw(Graphics &gfx, Font ft, Vei2 boardPos){
	Vei2 drawPos = pos * cellSize + boardPos;
	if(value != 0){
		int nSymbols = 0, temp = value;
		while(temp > 0){
			nSymbols++;
			temp /= 10;
		}
		gfx.DrawFilledRectBorder(drawPos, {cellSize, cellSize}, Colors::MakeRGB(220, 220 - 10 * (int)log(value), 0), Colors::LightGray);
		ft.DrawText(std::to_string(value), drawPos + Vei2(50 - 8 * nSymbols, 36), Colors::White, gfx);
	}
	else
		gfx.DrawFilledRectBorder(drawPos, {cellSize, cellSize}, Colors::Gray, Colors::LightGray);
}

Board::Cell::Cell(Vei2 _pos, int _value) : 
	pos(_pos), value(_value)
{}
