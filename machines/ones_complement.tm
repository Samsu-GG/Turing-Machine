# ones_complement.tm
# This Turing Machine computes the 1's complement of a binary number
# It flips 0 -> 1 and 1 -> 0, then accepts when blank is reached

start: q0
accept: ACCEPT
reject: REJECT

q0 0 -> q0 1 R
q0 1 -> q0 0 R
q0 _ -> ACCEPT _ R