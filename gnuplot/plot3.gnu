set datafile separator ","

set terminal pngcairo size 1800,1000 enhanced font "Arial,12"
set output "results/plot_n2.png"

set title "Comparaison des Algorithmes O(n²)"
set xlabel "Taille du tableau"
set ylabel "Temps (secondes)"
set key outside
set grid

set logscale x

plot \
"results/timings.csv" using 1:2 with lines lw 3 title "Bubble", \
"results/timings.csv" using 1:3 with lines lw 3 title "Insertion", \
"results/timings.csv" using 1:4 with lines lw 3 title "Selection"