eea <- function(x,y) {
  r <- x%%y;
  return(ifelse(r, eea(y, r), y))
}

eea(128, 134)
eea(331, 337)
eea(991, 997)
