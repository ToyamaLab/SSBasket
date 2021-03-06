<<<<<<< HEAD
## ---- include = FALSE----------------------------------------------------
=======
## ---- include = FALSE---------------------------------------------------------
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
library(haven)
knitr::opts_chunk$set(
  collapse = TRUE,
  comment = "#>"
)

<<<<<<< HEAD
## ------------------------------------------------------------------------
=======
## -----------------------------------------------------------------------------
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
x1 <- labelled(
  sample(1:5), 
  c(Good = 1, Bad = 5)
)
x1

x2 <- labelled(
  c("M", "F", "F", "F", "M"), 
  c(Male = "M", Female = "F")
)
x2

<<<<<<< HEAD
## ------------------------------------------------------------------------
=======
## -----------------------------------------------------------------------------
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
as_factor(x1)
zap_labels(x1)

as_factor(x2)
zap_labels(x2)

<<<<<<< HEAD
## ------------------------------------------------------------------------
=======
## -----------------------------------------------------------------------------
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
df <- tibble::data_frame(x1, x2, z = 1:5)
df

zap_labels(df)
as_factor(df)

<<<<<<< HEAD
## ------------------------------------------------------------------------
x <- c(1:3, tagged_na("a", "z"), 3:1)
x

## ------------------------------------------------------------------------
print_tagged_na(x)

## ------------------------------------------------------------------------
=======
## -----------------------------------------------------------------------------
x <- c(1:3, tagged_na("a", "z"), 3:1)
x

## -----------------------------------------------------------------------------
print_tagged_na(x)

## -----------------------------------------------------------------------------
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
is_tagged_na(x)
is_tagged_na(x, "a")

na_tag(x)

<<<<<<< HEAD
## ------------------------------------------------------------------------
=======
## -----------------------------------------------------------------------------
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
y <- labelled(x, c("Not home" = tagged_na("a"), "Refused" = tagged_na("z")))
y

as_factor(y)

<<<<<<< HEAD
## ------------------------------------------------------------------------
=======
## -----------------------------------------------------------------------------
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
x1 <- labelled_spss(c(1:10, 99), c(Missing = 99), na_value = 99)
x2 <- labelled_spss(c(1:10, 99), c(Missing = 99), na_range = c(90, Inf))

x1
x2

<<<<<<< HEAD
## ------------------------------------------------------------------------
mean(x1)

## ------------------------------------------------------------------------
is.na(x1)

## ------------------------------------------------------------------------
mean(x1, na.rm = TRUE)

## ------------------------------------------------------------------------
=======
## -----------------------------------------------------------------------------
mean(x1)

## -----------------------------------------------------------------------------
is.na(x1)

## -----------------------------------------------------------------------------
mean(x1, na.rm = TRUE)

## -----------------------------------------------------------------------------
>>>>>>> ddff10c8c1a385735ed59fadb33c4b79e43db9ce
as_factor(x1)
zap_missing(x1)
zap_labels(x1)

