# fractol

A program coded in C that generates 3 types of fractal : the famous Mandelbrot set, the Julia set with the possibility of choosing the complex parameter c at the start, and the Burning Ship.

If you want to try it, you can do as follow:
- Use a Linux distribution and check that you have the necessary packages (cf. README in the minilibx-linux directory)
- Clone this repository
- Use `make bonus` inside the repository
- Then use:
  - `./fractol -m` for the Mandelbrot set
  - `./fractol -j re im` for the Julia set - let `re` and `im` be float numbers in the interval [-4 ; 4]
  - `./fractol --bonus` for the Burning Ship

Feel free to navigate through the fractal by `zooming` with your mouse wheel and/or `moving` with your arrow keys.

You can also change the `color` by using your space bar at any moment.

Fractol is a 42 project made with the minilibx (linux version only for this repository).
