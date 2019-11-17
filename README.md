# 42filler
#### Disclaimer:

For this specific project only those functions were allowed:
read, write, malloc, free, perror. Memory leaks are prohibited, makefile has to be smooth.

Task (CTRL+C CTRL+V):
Create your player program to compete against other students on the
famous (or not) Filler board. The principle is simple: two players take on each other on
a board, and take turns placing the piece that the master of the game (supplied in the
form of a Ruby executable) gives them, earning points. The game stops as soon as a
piece can no longer be placed. Little playful project!

Examples of some pieces that could be given:

<img src="https://i.imgur.com/eIMjnT4.png" width="300" title="Pieces">

#### Approach:

So, in a nutshell, what is asked to do is to continuously parse the data (which player are we, the map, the given piece), which the virtual machine sends to our standard output. Then, with the given information, to think of an algorithm, which will decide as which spot is more suitable to insert our piece into. In order to put a new piece into our existing map it has to be overlapped by one cell of our kind and not to be overlapped by any of enemy's pieces. By the end of the game, the one who managed to occupy more cells is the winner and claims the right to become a shaman king.

#### Algorithm:
The solution that I have come up with was to create a heat map (priority map) every time a new enemy's location is given. It is quite simple: the closer a cell is to an enemy's cell - the higher priority it has for us to insert our piece into. This is done with the purpose of surrounding our enemy, so he wouldn't be able to put any of his pieces anymore.

#### Bonus:
As for the bonus part, it was proposed to create a visualizer for this game.

#### Usage:

Without visualizer:
```shell
make && ./resources/filler_vm -p1 skrabby.filler -p2 resources/players/abanlin.filler -v -f resources/maps/map01
```

With visualizer:
```shell
make visual && ./resources/filler_vm -p1 skrabby.filler -p2 resources/players/abanlin.filler -v -f resources/maps/map01 | visualizer/visualizer
```

Several examples and previews are attached below.

Map01 Preview

<img src="https://i.imgur.com/3Ws0WzB.png" width="700" title="Map01 Preview">

Map02 Preview

<img src="https://i.imgur.com/NE6pSrp.png" width="700" title="Map02 Preview">

#### Heat Map Example

Map

<img src="https://i.imgur.com/4ZRraLA.png" width="350" title="Map Example">

Heat Map (corresponding to the map above)
<img src="https://i.imgur.com/kfkB0eS.png" width="700" title="Heat Map Example">

#### Afterword:

Overall, this project was quite satisfying and fun to do. Even though the algorithm behaviour could be upgraded by analyzing specific circumstances, such as a bigger map, it still tends to be uNbEaTaBlE in the small ones.
