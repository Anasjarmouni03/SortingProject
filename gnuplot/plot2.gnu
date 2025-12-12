set datafile separator ","

set terminal pngcairo size 1800,1000 enhanced font "Arial,12"
set output "results/plot_nlogn.png"

set title "Comparaison des Algorithmes O(n log n)"
set xlabel "Taille du tableau"
set ylabel "Temps (secondes)"
set key outside
set grid

set logscale x

plot \
"results/timings.csv" using 1:5 with lines lw 3 title "Quick", \
"results/timings.csv" using 1:6 with lines lw 3 title "Merge", \
"results/timings.csv" using 1:7 with lines lw 3 title "Heap", \
"results/timings.csv" using 1:12 with lines lw 3 title "Intro"