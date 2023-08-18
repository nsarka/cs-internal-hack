# cs-internal-hack

I explain how it all works in this blog post:
https://nsarka.com/2019/01/21/CS-1-6-internal-hack/

Spent a weekend researching and then implementing a CS 1.6 internal hack.
The dll hooks the game's engine function table after it is injected, then gives the player 'no flash' so that flashbangs
don't affect him. It does this by calling the game's GetScreenFade and SetScreenFade functions from the table in an infinite loop.

Credit to some people at unknowncheats.me for the dll injector, the hlsdk base, and resources on how to find the offset to the func table.

This project uses mingw.
