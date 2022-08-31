# Zelda Picross Vita

This is a port of Zelda Picross for the PS Vita, based on the original source from here: http://www.zeldaroth.fr/us/dlpicross.php

Save files are located at ``ux0:data/ZeldaPicross/save``

# Known bugs
When playing the game, if for whatever reason every text has double letters at the end of 'em, try to go to ``ux0:data/ZeldaPicross`` in VitaShell, open up ``config.cfg`` and change the value of ``fixText`` to ``1``.

The reason as to why it happens may be because of undefined behaviour, though i'm not sure yet.

## Instructions

### For end-users
Just go to the Releases tab, install the .VPK with VitaShell and enjoy.

### For devs
Make sure you have [VitaSDK](https://vitasdk.org/) and 7Zip (`sudo apt install p7zip-full` if you're on Linux) installed on your terminal.

Once you have it installed, all you need to do is type in ``make`` and press enter. All the files should be in the root of the repo.

Type in ``make clean`` to clean up all of the files that the Makefile produced.

## Controls
-----------------

|             Button             | Action                         |
|:------------------------------:|:------------------------------:|
| ![joysl] / ![dpadh] / ![dpadv] | Move (Map/Game)/Reset sqaure   |
|            ![cross]            | Mark square as full            |
|      ![circl]                  | Mark square as empty           |
|            ![trian]            | Hypothesis                     |
|            ![selec]            | Pause                          |
|            ![start]            | Progress through text/Confirm  |

## Credits
- [Rinnegatamante](https://github.com/Rinnegatamante/) and [Northfear](https://github.com/Northfear/) for helping me troubleshoot some issues
- [usineur](https://github.com/usineur)'s code used in [Audio](https://github.com/hatoving/zeldapicross_vita/blob/main/src/Audio.cpp) and half of it used in [Input](https://github.com/hatoving/zeldapicross_vita/blob/main/src/Keyboard.cpp)
- [gl33twine](https://github.com/v-atamanenko) for those nice looking Vita buttons lmao

[cross]: https://raw.githubusercontent.com/v-atamanenko/sdl2sand/master/img/cross.svg "Cross"
[circl]: https://raw.githubusercontent.com/v-atamanenko/sdl2sand/master/img/circle.svg "Circle"
[squar]: https://raw.githubusercontent.com/v-atamanenko/sdl2sand/master/img/square.svg "Square"
[trian]: https://raw.githubusercontent.com/v-atamanenko/sdl2sand/master/img/triangle.svg "Triangle"
[joysl]: https://raw.githubusercontent.com/v-atamanenko/sdl2sand/master/img/joystick-left.svg "Left Joystick"
[dpadh]: https://raw.githubusercontent.com/v-atamanenko/sdl2sand/master/img/dpad-left-right.svg "D-Pad Left/Right"
[dpadv]: https://raw.githubusercontent.com/v-atamanenko/sdl2sand/master/img/dpad-top-down.svg "D-Pad Up/Down"
[selec]: https://raw.githubusercontent.com/v-atamanenko/sdl2sand/master/img/dpad-select.svg "Select"
[start]: https://raw.githubusercontent.com/v-atamanenko/sdl2sand/master/img/dpad-start.svg "Start"
[trigl]: https://raw.githubusercontent.com/v-atamanenko/sdl2sand/master/img/trigger-left.svg "Left Trigger"
[trigr]: https://raw.githubusercontent.com/v-atamanenko/sdl2sand/master/img/trigger-right.svg "Right Trigger"
