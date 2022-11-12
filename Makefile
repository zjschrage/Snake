CC = g++ --std=c++2a -g -Wall
G_INC = -Iinclude $(CPPFLAGS)

all: game

game:
	$(CC) $(G_INC) -o snakegame snake_game.cpp snake.cpp grid.cpp cell.cpp direction.cpp state_singleton.cpp state_game.cpp state_menu.cpp button/button.cpp button/button_play.cpp button/button_settings.cpp button/button_help.cpp -I/usr/local/Cellar/sfml/2.5.1_2/include -L/usr/local/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system

clean: 
	$(RM) snakegame