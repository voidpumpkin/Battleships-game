#include "Ocean.h"

Cell Ocean::getCellAtCoordinates(int x, int y) {
	if (x > 9 ||
		x < 0 ||
		y > 9 ||
		y < 0)
		return Cell::WATER;
	return cells[x][y];
}

bool Ocean::isCellOutOfBounds(int x, int y) {
	if (x > 9 ||
		x < 0 ||
		y > 9 ||
		y < 0)
		return true;
	return false;
}

bool Ocean::isThereAShipAtAndAroundCoordinates(int x, int y) {
	if (getCellAtCoordinates(x - 1, y - 1) == Cell::INTACT_SHIP)
		return true;
	if (getCellAtCoordinates(x, y - 1) == Cell::INTACT_SHIP)
		return true;
	if (getCellAtCoordinates(x + 1, y - 1) == Cell::INTACT_SHIP)
		return true;
	if (getCellAtCoordinates(x - 1, y) == Cell::INTACT_SHIP)
		return true;
	if (getCellAtCoordinates(x, y) == Cell::INTACT_SHIP)
		return true;
	if (getCellAtCoordinates(x + 1, y) == Cell::INTACT_SHIP)
		return true;
	if (getCellAtCoordinates(x - 1, y + 1) == Cell::INTACT_SHIP)
		return true;
	if (getCellAtCoordinates(x, y + 1) == Cell::INTACT_SHIP)
		return true;
	if (getCellAtCoordinates(x + 1, y + 1) == Cell::INTACT_SHIP)
		return true;
	return false;
}

void Ocean::setCellAtCoordinates(int x, int y, Cell cell) {
	cells[x][y] = cell;
}

bool Ocean::isShipAllowedToDeploy(int lenght, int x, int y, Direction direction) {
	switch (direction) {
	case Direction::NORTH:
		for (int i = y; i > y - lenght; i--)
			if (isCellOutOfBounds(x, i) || isThereAShipAtAndAroundCoordinates(x, i))
				return false;
		return true;
	case Direction::EAST:
		for (int j = x; j < x + lenght; j++)
			if (isCellOutOfBounds(j, y) || isThereAShipAtAndAroundCoordinates(j, y))
				return false;
		return true;
	case Direction::SOUTH:
		for (int i = y; i < y + lenght; i++)
			if (isCellOutOfBounds(x, i) || isThereAShipAtAndAroundCoordinates(x, i))
				return false;
		return true;
	case Direction::WEST:
		for (int j = x; j > x - lenght; j--)
			if (isCellOutOfBounds(j, y) || isThereAShipAtAndAroundCoordinates(j, y))
				return false;
		return true;
	}
}
void Ocean::deployShip(int lenght, int x, int y, Direction direction) {
	switch (direction) {
	case Direction::NORTH:
		for (int i = y; i > y - lenght; i--) {
			setCellAtCoordinates(x, i, Cell::INTACT_SHIP);
		}
		return;
	case Direction::EAST:
		for (int j = x; j < x + lenght; j++) {
			setCellAtCoordinates(j, y, Cell::INTACT_SHIP);
		}
		return;
	case Direction::SOUTH:
		for (int i = y; i < y + lenght; i++) {
			setCellAtCoordinates(x, i, Cell::INTACT_SHIP);
		}
		return;
	case Direction::WEST:
		for (int j = x; j > x - lenght; j--) {
			setCellAtCoordinates(j, y, Cell::INTACT_SHIP);
		}
		return;
	}
}

void Ocean::deployShip(int x, int y) {
	setCellAtCoordinates(x, y, Cell::INTACT_SHIP);
}

bool Ocean::equals(Ocean ocean) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (this->getCellAtCoordinates(i, j) != ocean.getCellAtCoordinates(i, j)) {
				return false;
			}
		}
	}
	return true;
}

Ocean::Ocean() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			this->cells[i][j] = Cell::WATER;
		}
	}
}


Ocean::~Ocean() {

}
