#!/usr/bin/gnuplot
set termoption enhanced
set terminal png size 800, 600 font "Arial, 12"
set output "data_ex4.png"

set style line 1 lc rgb "0xDC143C" lt 1 lw 4 pt 9 ps 1
set style line 2 lc rgb "0x6495ED" lt 1 lw 4 pt 7 ps 1 

set border lw 2
set grid
set key top left

set xlabel "Количество элементов в словаре"
set ylabel "Время поиска элементов, с" rotate by 90
set xtics 20000
set mxtics
set format x "%6.0f"
set format y "%.9f"

plot "ex4_data.txt" using 1:2 title "Average case bstree_min" with linespoints ls 1, \
"ex4_data.txt" using 1:3 title "Worst case bstree_min" with linespoints ls 2