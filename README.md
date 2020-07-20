# QuickUI
## What is QuickUI?
*QuickUI* is a C++ library that allows you to build any application or game very quickly. You have two way to build your app: 
- Develop it with built-in QuickUI methods and class. 
- Write it with an XML/JSON like syntax very easy to master then call the methods to load your app files and it will interpreted by QuickUI.

**But wait, you're just reproducing *Qt* library?**
Not exactly... For two reasons:
- Unlike Qt, QuickUI allows you two build 2D games (with Behaviors, Trajectories etc...)
- You can create your own Components from existing Components from your app files (exactly like React framework for Javascript).

**Sample:**
```
App: {
    name: "myLittleGame"
    screens: {
        $MainMenuScreen,
        $gameScreen
    }
    currentScreen: "MainMenuScreen"
    state: RUN
}

Screen: {
    name: "gameScreen"
}

Screen: {
    name: "MainMenuScreen"
    layers: {
        $buttonsLayer,
        $backgroundPicture
    }
}

Layout: {
    name: "buttonsLayer"
    width: SCREEN_WIDTH
    height: SCREEN_HEIGHT
    x: 0,
    y: 0,
    cols: 24
    rows: 18
    objects: {
        $gameLogo,
        $playButton,
        $optionButton,
        $quitButton
    }
}

Object: {
    name: "gameLogo",
    x: CENTER,
    y: 2,
    height: 3,
    width: 18,
}

 ```
This is a sample of app you can write with the easy QuickUI syntax. These few lines just create a game main menu without the buttons.

## How to install?
The library is not available for now...

## How to use?
I'm gona write a wiki about the QuickUI library. This wiki will be avalaible in the wiki menu from the Github repository.
