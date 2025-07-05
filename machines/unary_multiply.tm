# unary_add.tm

start: q0
accept: ACCEPT
reject: REJECT

q0 1 -> q1 _ R
q1 1 -> q1 1 R
q1 0 -> q2 0 R
q2 1 -> q3 X R
q3 1 -> q3 1 R
q3 0 -> q4 0 R
q4 _ -> q5 1 L
q4 1 -> q4 1 R
q5 1 -> q5 1 L
q5 0 -> q6 0 L
q6 1 -> q6 1 L
q6 X -> q2 X R
q2 0 -> q7 0 L
q7 X -> q7 1 L
q7 0 -> q8 0 L
q8 1 -> q8 1 L
q8 _ -> q0 _ R
q0 0 -> q9 _ R
q9 1 -> q9 _ R
q9 0 -> ACCEPT _ R
