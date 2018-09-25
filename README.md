# monopolyExplore
An exploration of moving around the Monopoly board, NOT a working Monopoly game.

The program models the Monopoly game, using standard movement rules. It is NOT a playable version of the game. Instead, 
it moves many thousands of times, recording where each move landed. At the end, very basic statistics are printed.

Only the final destination is recorded, not the interim steps. For example, take this scenario:  
Land on Chance, draw a "move back 3" card  
That takes you to Community Chest, draw a "move to Go" card  
In that case, the program considers it a +1 for the Go position, not Chance or Community Chest.

Likewise, the "GoToJail" position is never landed on; the program records that as landing on Jail. Also, it's assumed the player always leaves Jail immediately.

The game runs from the command line as Monopoly.exe.
