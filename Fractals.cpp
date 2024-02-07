#include <cmath>
#include <iostream>
#include <pthread.h>

#define NUM_THREADS 4 // Number of threads for parallel computation
const int SIZE = 40;
int globalArray[SIZE][SIZE] = {{0}};


int fractalValueAtPoint(int x, int y) {
    // Calculate the distance of the point (x, y) from the center of the image
    int centerX = SIZE / 2;
    int centerY = SIZE / 2;
    double distance = std::sqrt(std::pow(x - centerX, 2) + std::pow(y - centerY, 2));

    // Define the radius of the rings
    double ringRadius = SIZE / 4; // Adjust this value as needed for desired ring thickness

    // Determine whether the point falls within a ring of 0s or 1s using a sine pattern
    if (std::sin(distance / ringRadius * M_PI) > 0) {
        return 1; // Inside the ring of 1s
    } else {
        return 0; // Outside the ring of 1s (inside the ring of 0s)
    }
}

// Function to compute fractal values for a portion of the image
void* computeFractal1(void* threadId) {
    int arg = *static_cast<int*>(threadId);
    if (arg == 1) {
        //top left
        for (int i = 0; i < SIZE/2; i++) {
            for (int j = 0; j < SIZE/2; j++) {
                globalArray[i][j] = fractalValueAtPoint(i, j);
            }
        }
    }

    if (arg = 2) {
        //top right
        for (int i = 0; i < SIZE/2; i++) {
            for (int j = SIZE/2; j < SIZE; j++) {
                globalArray[i][j] = fractalValueAtPoint(i, j);
            }
        }
    }
    pthread_exit(NULL);
}

void* computeFractal2(void* threadId) {
    int arg = *static_cast<int*>(threadId);
    if (arg == 3)
    {
        //bottom right?
        for (int y = SIZE / 2; y < SIZE; y++)
        {
            for (int x = SIZE / 2; x < SIZE; x++)
            {
                globalArray[x][y] = fractalValueAtPoint(x, y);
            }
        }
    }
    if (arg == 4)
    {
        //bottom left
        for (int y = 0; y < SIZE / 2; y++)
        {
            for (int x = SIZE / 2; x < SIZE; x++)
            {
                globalArray[x][y] = fractalValueAtPoint(x, y);
            }
        }
    }
    pthread_exit(NULL);
}


int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    int threadArray[] = {1,2,3,4}; // Thread IDs
    
    for (int i = 0; i < NUM_THREADS; i++) {
        if (i < 2) {
            rc = pthread_create(&threads[i], NULL, computeFractal1, (void*)&threadArray[i]);
        } else {
            rc = pthread_create(&threads[i], NULL, computeFractal2, (void*)&threadArray[i]);
        }
        if (rc) {
            std::cerr << "Error: Unable to create thread, " << rc << std::endl;
            exit(-1);
        }
    }

    for (int t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cout << globalArray[i][j] << " ";
        }
        std::cout << '\n';
    }

    return 0;
}