all: game

game:
	g++ --std=c++2a -g -Wall -o snakegame snake_game.cpp snake.cpp grid.cpp cell.cpp direction.cpp state_singleton.cpp state_game.cpp state_menu.cpp -I/usr/local/Cellar/sfml/2.5.1_2/include -L/usr/local/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system

clean: 
	$(RM) snakegame