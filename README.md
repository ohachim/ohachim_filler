# ohachim_filler
Filler project 1337 [42 cursus]

The goal of this project is to create a player/bot who will compete against other bots/players, in a virtual arena.
the games is a similar to tic-tac-toe.

# GAMEPLAY

1. The virutal machine inputs in turns the state of the board as well as a token to each of the players.
2. The players then output the coordinates they chose.
3. The game ends when both players can't play anymore.
4. The player with most points win.

![](https://github.com/ThatKstho/ohachim_filler/blob/master/board_example)

# ALORITHM

1. The program scores the board, the closer the spot is to the enemy pieces to better it is.
2. The program then tries to choose a spot with the best possible score.
3. The program rescores the board after every turn.
For a spot to be valid, the token must crush at least and at most 1 of the program's own pieces.

Board scoring example:

![](https://github.com/ThatKstho/ohachim_filler/blob/master/algo_example)

3. This helps the program navigate closer to the enemy wich gives of the effect of the program circling the enemy pieces.

Mid fight example:

![](https://github.com/ThatKstho/ohachim_filler/blob/master/mid_algo)

# LAUNCH

The VM (filler_vm), extra players and maps are provided in the folder resources.

* make\
  will compile ohachim.filler executable, and visualisator (visu_filler) in folder visu.
* make re\
  will recompile ohachim.filler executable.
* make bothr\
  will recompile both visualisator and executable.
  
Launch:

./filler_vm -f maps/map00 -p1 ./ohachim.filler -p2 players/carli.filler
This will launch a battle between ohachim.filler and carli.filler in the smallest map.

# VISUALISATOR
Made using sdl2

P: pause
space: resume
arrow_up: speed up
arrow_down: speed down
esc/q: quit

Examples:

![](https://github.com/ThatKstho/ohachim_filler/blob/master/visu1)

![](https://github.com/ThatKstho/ohachim_filler/blob/master/visu1)
