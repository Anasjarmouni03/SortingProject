# Sorting Algorithms Benchmark in C

## Overview
This project implements and benchmarks several classical and advanced sorting algorithms in the C programming language.
The goal is to evaluate the real execution time of each algorithm over a wide range of input sizes and visualize their performance using GNUPlot.

The implemented algorithms include:

- Bubble Sort  
- Insertion Sort  
- Selection Sort  
- Quick Sort  
- Merge Sort  
- Heap Sort  
- Shell Sort  
- radix Sort
- Comb Sort
- Counting Sort
- Intro Sort 

The program measures the execution time of each algorithm on arrays of sizes:

1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000, 256000, 512000, 1000000, 10000000, 20000000

Results are exported to `results/timings.csv` and plotted using GNUPlot.

----------

## Project Structure

SortingProject/
│
├── src/                      # Sorting algorithms + main benchmark file
│   ├── bubble.c              # Bubble Sort
│   ├── insertion.c           # Insertion Sort
│   ├── selection.c           # Selection Sort
│   ├── quick.c               # Quick Sort
│   ├── merge.c               # Merge Sort
│   ├── heap.c                # Heap Sort
│   ├── shell.c               # Shell Sort
│   ├── radix.c               # Radix Sort
│   ├── counting.c            # Counting Sort
│   ├── comb.c                # Comb Sort
│   ├── intro.c               # Intro Sort
│   │
│   ├── sorting.h             # Header file with all prototypes
│   └── main.c                # Benchmark driver (time measurement)
│
├── results/                  
│   ├── timings.csv           # Execution time results
│   ├── plot1.png             # Output plot from plot.gnu
│   ├── plot2.png             # Output plot from plot2.gnu
│   └── plot3.png             # Output plot from plot3.gnu
│
├── gnuplot/
│   ├── plot.gnu              # Plot of all algorithms
│   ├── plot2.gnu             # Plot of O(n²) weak algorithms
│   └── plot3.gnu             # Plot of detailed comparison of all algorithms
│
├── Makefile                  # Build + clean commands
└── README.md                 # Project documentation

----------

## Compilation 
To compile the project, simply run: make

This will produce an executable located at: ./sorting

To clean all compiled files: make clean

----------

## Running the Benchmark
After compilation, run: ./sorting

The program will:
-  Generate random arrays for each size
- Run all sorting algorithms
- Measure execution times using clock()
- Save data to results/timings.csv

----------

## Plotting Results (GNUPlot)
The project includes three plotting scripts.

- Plot all algorithms : gnuplot gnuplot/plot.gnu
- Plot of O(n²) weak algorithms (Bubble, Insertion, Selection) : gnuplot gnuplot/plot2.gnu
- Plot of detailed comparison of all algorithms : gnuplot gnuplot/plot3.gnu

----------

## Learning Outcomes
Through this project, you gain hands-on experience with:
- Algorithm complexity in real-world execution
- Time measurement in C
- Benchmarking methodology
- Memory management and pointer manipulation
- Large-scale data handling
- Automating data plots through GNUPlot
- Performance comparison across algorithms

----------

## License
This project is fully open-source.
You are free to use, modify, or distribute it for educational or research purposes.