CC = g++ --std=c++2a -g -Wall
G_INC = -Iinclude $(CPPFLAGS)
O = -o snakegame
DEPS_SFML = -I/usr/local/Cellar/sfml/2.5.1_2/include -L/usr/local/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system
DEPS_GAME = snake_game.cpp game/snake.cpp game/grid.cpp game/cell.cpp game/direction.cpp
DEPS_STATE = state/state_game.cpp state/state_menu.cpp state/state_help.cpp state/state_settings.cpp
DEPS_BUTTON = button/button.cpp button/button_toggle.cpp button/button_selector.cpp button/button_play.cpp button/button_settings.cpp button/button_help.cpp button/button_menu.cpp button/button_audio.cpp button/button_wrap.cpp button/button_gridsize.cpp

all: snake

snake:
	$(CC) $(G_INC) $(O) $(DEPS_GAME) $(DEPS_STATE) $(DEPS_BUTTON) $(DEPS_SFML)

clean: 
	$(RM) snakegame