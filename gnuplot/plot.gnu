set datafile separator ","

set terminal pngcairo size 1800,1000 enhanced font "Arial,12"
set output "results/plot_all.png"

set title "Comparaison de Tous les Algorithmes de Tri"
set xlabel "Taille du tableau"
set ylabel "Temps (secondes)"
set key outside
set grid

set logscale x

plot \
"results/timings.csv" using 1:2 with lines lw 2 title "Bubble", \
"results/timings.csv" using 1:3 with lines lw 2 title "Insertion", \
"results/timings.csv" using 1:4 with lines lw 2 title "Selection", \
"results/timings.csv" using 1:5 with lines lw 2 title "Quick", \
"results/timings.csv" using 1:6 with lines lw 2 title "Merge", \
"results/timings.csv" using 1:7 with lines lw 2 title "Heap", \
"results/timings.csv" using 1:8 with lines lw 2 title "Shell", \
"results/timings.csv" using 1:9 with lines lw 2 title "Comb", \
"results/timings.csv" using 1:10 with lines lw 2 title "Counting", \
"results/timings.csv" using 1:11 with lines lw 2 title "Radix", \
"results/timings.csv" using 1:12 with lines lw 2 title "Intro"