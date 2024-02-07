# Fractal Visualizations
Use multithreading to more efficiently render a fractal. 

#### Stage 1 
2/7/24 - Final Commit 461e194

* The program generates a fractal pattern by computing values for different portions of a 2D array concurrently using pthreads.

* fractalValueAtPoint() calculates whether a point falls within a ring pattern of 0s or 1s.

* computeFractal1() and computeFractal2() functions compute fractal values for different quadrants of the image array using pthreads.

* The main() function creates threads to compute fractal values for different image quadrants.

* pthread_join() ensures that the main thread waits for all other threads to finish execution before printing the computed fractal array.

* The computed fractal array is printed to the console.

