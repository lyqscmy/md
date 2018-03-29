timing
```cpp
#include <chrono>  // for high_resolution_clock

// Record start time
auto start = std::chrono::high_resolution_clock::now();

// Portion of code to be timed

// Record end time
auto finish = std::chrono::high_resolution_clock::now();

std::chrono::duration<double> elapsed = finish - start;
printf("Elapsed time: %f s\n", elapsed.count());
// std::cout << "Elapsed time: " << elapsed.count() << " s\n";
```