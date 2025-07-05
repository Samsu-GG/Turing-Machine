# unary_add.tm


start: q0
accept: ACCEPT
reject: REJECT

q0 1 -> q0 1 R
q0 + -> q1 1 R
q1 1 -> q1 1 R 
q1 _ -> q2 _ L
q2 1 -> ACCEPT _ R