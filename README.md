# cs-internal-hack

Spent a weekend researching and then implementing a CS 1.6 internal hack.
The dll hooks the game's engine function table after it is injected, then gives the player 'no flash' so that flashbangs
don't affect him. It does this by calling the game's GetScreenFade and SetScreenFade functions in an infinite loop.
