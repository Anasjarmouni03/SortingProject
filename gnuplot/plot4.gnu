set datafile separator ","
set terminal pngcairo size 1800,1000 enhanced font "Arial,12"
set output "results/plot_heatmap_limited2.png"

set title "Heatmap des temps d'exécution (Limité)"
set xlabel "Taille du tableau"
set ylabel "Algorithme"
set xtics rotate by -45
set ytics ("Bubble" 1, "Insertion" 2, "Selection" 3, "Quick" 4, "Merge" 5, \
           "Heap" 6, "Shell" 7, "Comb" 8, "Counting" 9, "Radix" 10, "Intro" 11)
set cblabel "Temps (s)"
set palette defined (0 "blue", 1 "green", 2 "yellow", 3 "red")
set pm3d map
set grid

# Plot pseudo-heatmap using for loop and columns
splot for [i=2:12] "results/timings.csv" using 1:(i-1):i with pm3d notitle