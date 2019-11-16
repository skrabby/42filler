# 42filler
#### Disclaimer:

For this specific project only those functions have been allowed:
read, write, malloc, free, perror

Task (CTRL+C CTRL+V):
Create your player program to compete against other students on the
famous (or not) Filler board. The principle is simple: two players take on each other on
a board, and take turns placing the piece that the master of the game (supplied in the
form of a Ruby executable) gives them, earning points. The game stops as soon as a
piece can no longer be placed. Little playful project!

Examples of pieces that could be given:

<img src="https://i.imgur.com/eIMjnT4.png" width="300" title="Pieces">

Approach:

So, basically, what is asked to do is to continuously parse the data (which player are we, the map, the given piece), which the virtual machine sends to our standard output. Then, with the given information, to think of an algorithm, which will decide as which spot is more suitable to insert our piece. In order to put a new piece into our existing map it has to be overlapped by one cell of our kind and not to be overlapped by any of enemy's pieces. By the end of the game, the one who managed to occupy more cells is the winner and claims the right to become a shaman king.

Algorithm:
The solution that I have come up with was to create a heat map (priority map) every time a new enemys location is given. It is quite simple: the closer a cell is to an enemy's cell - the higher priority it has for us to insert our piece. This is done with the purpose of surrounding him, so he wouldn't be able to put any of his pieces anymore.

Bonus:
As for the bonus part, it was proposed to create a visualizer for this game.

Several examples and previews are attached below.

Map01 Preview

<img src="https://i.imgur.com/3Ws0WzB.png" width="700" title="Map01 Preview">

Map02 Preview

<img src="https://i.imgur.com/NE6pSrp.png" width="700" title="Map02 Preview">

#### Heat Map Example

Map

<img src="https://i.imgur.com/4ZRraLA.png" width="350" title="Map Example">

Heat Map

<img src="https://i.imgur.com/kfkB0eS.png" width="700" title="Heat Map Example">
