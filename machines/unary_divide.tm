start: q0
accept: ACCEPT
reject: REJECT

q0 1 -> q1 _ R
q1 1 -> q1 1 R
q1 0 -> q2 0 R
q2 X -> q2 X R
q2 1 -> q3 X L
q3 1 -> q3 1 L
q3 X -> q3 X L
q3 0 -> q3 0 L
q3 C -> q3 0 L
q3 _ -> q0 1 R
q0 0 -> q4 0 R
q4 X -> q4 X R
q4 1 -> q4 1 R
q4 0 -> q4 0 R
q4 _ -> q5 1 L
q5 0 -> q5 0 L
q5 1 -> q5 1 L
q5 X -> q5 X L
q5 _ -> q0 _ R
q2 0 -> q6 _ L
q6 1 -> q6 _ L
q6 0 -> q6 _ L
q6 X -> q6 _ L
q6 _ -> ACCEPT _ R
