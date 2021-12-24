
# 3rd Person Multiplayer Prototype
![404](screenshot.PNG)

The game adds the following features to Unreal 4 Third Person game mode:
* Main menu
* In-game menu (press ESC)
* Volume triggered door
* replicated cube platform
* replicated phyisics football
* Xmas tree model from [Wordofcurse](https://sketchfab.com/Wordofcurse)
* Sergio model from [Tio_de_rojo](https://gamebanana.com/members/1587288)
* Feliz navidad audio by Jose Feliciano

Download executable [here](https://kikizana.itch.io/garden)

# Install instructions

To play unzip the client file of your OS and run Garden.exe on windows or cd into the directory and run on Linux:

```
./Garden.sh
```

You can host a dedicated server on linux by unzipping the server file and running in the relevant directory `chmod +x GardenServer.sh` and then:

```
./GardenServer.sh
```

To host games, either as client by clicking host or per the dedicated server executable, you need to have port `7777` open.

You don't have to append the port to the IP Address of a server, i.e.the following addresses are correct examples:

* Local host: `127.0.0.1`
* Sample local IP Address: `192.168.1.10`
* Domain name address: `kpan.nl`

# Controls
Use WASD to move, the mouse to aim and `Escape` button to display the in-game menu.

# Development
* Engine UE_4.27.2 (compiled from source code)
* Client configuration: shipping for Windows and Development for Linux
* Server configuration: development for Linux (can only be packaged from source compiled engine)
* Tutorials used:
  * GameDev.tv tutorials on udemy 
  * Flopperam videos to [Build Unreal Engine from Source](https://www.youtube.com/watch?v=MRJUWC90aJM) and to [Package a Dedicated Server executable](https://www.youtube.com/watch?v=zNUxzl8Dcb4)