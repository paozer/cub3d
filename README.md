This project aims at introducing students to using a graphics library by creating a very simple Wolfenstein 3D clone.

### Rules
Using the raycasting techniques students have to create a first-person 3D representation of the inside of a maze. Only a few simple functions are allowed. Students have to use the minilibx, a graphics library provided by the school. The maze is displayed using the 2D map specified as an argument to the executable. The map file also determines the window size, textures for every direction and the colors for the sky and floor. Sprites also have to be displayed and configured using the file.

### Usage
To build and launch the binary with a map run `make && ./cub3D [path/to/map.cub]` in your terminal. If you append the `--save` option - instead of opening a window for playing - a screenshot of the first view will be saved to the current folder. Examples of (non)-valid maps can be found in the maps directory.

You can move the view using W, A, S, D and the arrow keys. The program can be stopped using the ESC key or by clicking on the red cross in the corner of the window.

### Ressources
* [install minilibx](https://achedeuzot.me/2014/12/20/installer-la-minilibx/)
* [raycasting](https://lodev.org/cgtutor/raycasting.html)
* [raycasting](http://www.playfuljs.com/a-first-person-engine-in-265-lines/)
* [minilibx documentation](https://github.com/qst0/ft_libgfx)
* [bmp images](https://stackoverflow.com/questions/2654480/writing-bmp-image-in-pure-c-c-without-other-libraries)

### To-Do
* parse map first as a linked list of char * and then as a char * * to avoid realloc
* move map extension check to main to avoid unecessary initialisations

![](example.gif)
