# PICO-MTG-damage-health-counter

This project was used to learn how to setup a project for the RPI Pico W in combination with the Pico Display Pack from Pimoroni. The goal was discovering how to write text on the display and how to use the buttons on the screen to manipulate the text.

## Installation

Download the project on your pc and run the following commands when you cloned it from GitHub:

```bash
git submodule init
git submodule update
```
## Usage
Connect the RPI Pico W (with the Pico Display Pack attached to it) to your computer while pressing the `BOOTSEL` button on the board.

Run the project in Visual Studio Code with the Raspberry Pi Pico extension enabled and click on the Run button in the bottom right corner. The project should now be compiled and moved to the Pico.

You should see `0/0` on the screen. Press `A | B` to increase or decrease the damage counter on the screen. Press `X | Y` to increase or decrease the health counter on the screen.

## Contributing

Since this repository was purely made for educational purposes, I do not accept any contributions to it.

## License

[MIT](https://choosealicense.com/licenses/mit/)