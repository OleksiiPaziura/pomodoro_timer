[![Static Badge](https://img.shields.io/badge/Qt-6.5.3-orange)](https://www.qt.io/download) 
[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)
![GitHub forks](https://img.shields.io/github/forks/OleksiiPaziura/pomodoro_timer?label=GitHub%20Forks&logo=github) 
## Installation

You can install this project due setup file or build it on your own:
+ Download [Qt](https://www.qt.io/download). This project was written with `6.5.3` version;
+ Open `Pomodoro.pro` as a project;
+ Build & compile;
+ Move executable file to the folder that you want to be your main one. Drag&Drop .exe to `windeployqt6.exe` in the root folder of Qt. This file located in `"<path_to_qt_root>/<version>/<compiler>/bin/windeployqt6.exe"`.
+ Move folders `"translations", "sounds"` and `"icons"`to your project folder;
+ Enjoy the app!
## Demo


## Features

+ Easy switching rounds with interactive time-picker;
+ Customizability. Settings allows you to do the following things:
  + Select you sound for each round;
  + Select time for each round with saving proportions or without it;
  + You can tray it;
  + Enable/Disable notifications;
  + Languages switcher. Now it supports:
    + English;
    + Ukrainian;
    + Russian.
  + All these settings and some more keep the state so you can reset the settings if you want.
+ Statistics;
+ (advanced) You can enable themes feature from code. 


## Tech Stack

**Language:** C++17

**Framework:** Qt Widgets (6.5.3)


## Usage/Examples

```javascript
import Component from 'my-project'

function App() {
  return <Component />
}
```


## Authors

- [Oleksii Paziura](https://github.com/OleksiiPaziura)


## Feedback

If you have any feedback, please reach out to me at alexeypazyura@gmail.com


## License

[MIT](https://choosealicense.com/licenses/mit/)

