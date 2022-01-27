#!/bin/sh

R CMD javareconf

R --quiet --vanilla --slave  <<EOF 
install.packages('rJava')
install.packages('tidyverse')
install.packages("plotly")
EOF
