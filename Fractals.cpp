#include <iostream>
#include <pthread.h>

#define NUM_THREADS 4 // Number of threads for parallel computation
const int SIZE = 40;
int globalArray[SIZE][SIZE] = {{0}};


// Function to compute fractal values for a portion of the image
void* computeFractal1(void* threadId) {
    long tid = (long)threadId;
    // Compute fractal values for the assigned portion of the image
    // This could involve iterating over a portion of the complex plane
    // and calculating the fractal values for each point
    // Example: Mandelbrot set computation
    // ...
    pthread_exit(NULL);
}

void* computeFractal2(void* threadId) {
    long tid = (long)threadId;
    // Compute fractal values for the assigned portion of the image
    // This could involve iterating over a portion of the complex plane
    // and calculating the fractal values for each point
    // Example: Mandelbrot set computation
    // ...
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    int threadArray = [1,2,3,4]; // Thread IDs
    
    for (int i = 0; i < NUM_THREADS; i++) {
        if (i < 2) {
            rc = pthread_create(&threads[i], NULL, computeFractal1, (void*)threadArray[i]);
        } else {
            rc = pthread_create(&threads[i], NULL, computeFractal2, (void*)threadArray[i]);
        }
        if (rc) {
            std::cerr << "Error: Unable to create thread, " << rc << std::endl;
            exit(-1);
        }
    }

    // Wait for all threads to complete
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    return 0;
}