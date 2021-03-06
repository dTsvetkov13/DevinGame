#pragma once

#include <vector>
#include <cmath>
#include <utility>
#include "Player.h"
#include "Cell.h"
#include "Common.h"

class Game
{
public:
	Game();
	~Game();

	void load(string configFile);

	void draw();
	void update();

	void initSession(int size);

	bool offBounds(const coordinates&);
	bool isEmptyCell(const coordinates& coor);
	void placeElimination(const coordinates&);
	bool checkForMove(coordinates start, coordinates end, int index);

	void addPlayer(string configFile);
	SDL_Rect syncCoor(coordinates coor);
	coordinates screenCoorToLogical(coordinates coor);
	coordinates logicalToScreen(coordinates coor);
	bool m_moved;
	std::vector <std::vector<Cell*>> m_cells;
	unsigned short m_playerOnTurn;
	pair<bool, Player*> checkForWin();

private:
	std::vector<Player*> m_players;
	unsigned short m_boardSize;
	SDL_Texture* m_whiteCellTexture;
	SDL_Texture* m_blackCellTexture;
	SDL_Texture* m_crossTexture;

	unsigned short m_boardWidth;
	unsigned short m_startOfBoard;
	unsigned short m_topMargin;
	unsigned short m_cellWidth;

	SDL_Rect buffRect;

	SDL_Texture* m_player1Turn;
	SDL_Texture* m_player2Turn;
	SDL_Texture* m_player1Wins;
	SDL_Texture* m_player2Wins;
	SDL_Texture* m_selectCellToMove;
	SDL_Texture* m_selectCellToEliminate;

	SDL_Rect m_screenTextRect;

	bool m_gameOver;
	unsigned short m_winner;
};