# Zelda Picross Vita

This is a port of Zelda Picross for the PS Vita, based on the original source from here: http://www.zeldaroth.fr/us/dlpicross.php

## Instructions

### For end-users
Just go to the Releases tab, install the .VPK with VitaShell and enjoy.

### For devs
Make sure you have [VitaSDK](https://vitasdk.org/) installed.

Once you do, all you need to do is type in ``make`` and press enter.
Type in ``make clean`` to clean up all of the files that the Makefile produced.

## Controls
-----------------

|             Button             | Action                       |
|:------------------------------:|:--------------               |
| ![joysl] / ![dpadh] / ![dpadv] | Move (Map/Cursor)            |
|            ![cross]            | Confirm/Mark Square as Full  |
|      ![circl] / ![squar]       | Mark Square as Empty         |
|            ![trian]            | Hypothesis                   |
|            ![selec]            | Pause                        |
|            ![start]            | Progress through text        |

## Credits
- [Rinnegatamante](https://github.com/Rinnegatamante/) and [Northfear](https://github.com/Northfear/) for helping me troubleshoot some issues
- [usineur](https://github.com/usineur)'s code used in [Audio](https://github.com/hatoving/zeldapicross_vita/blob/main/src/Audio.cpp) and half of it used in [Input](https://github.com/hatoving/zeldapicross_vita/blob/main/src/Keyboard.cpp)

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
