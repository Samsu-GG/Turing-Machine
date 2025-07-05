start: q0
accept: ACCEPT
reject: REJECT

q0 0 -> q1 _ R
q1 0 -> q1 0 R
q1 1 -> q1 1 R
q1 _ -> q2 _ L
q2 _ -> ACCEPT _ R
q2 0 -> q3 _ L
q3 1 -> q3 1 L
q3 0 -> q3 0 L
q3 _ -> q0 _ R
q0 1 -> q4 _ R
q4 0 -> q4 0 R
q4 1 -> q4 1 R
q4 _ -> q5 _ L
q5 _ -> ACCEPT _ R
q5 1 -> q6 _ L
q6 0 -> q6 0 L
q6 1 -> q6 1 L
q6 _ -> q0 _ R
q0 _ -> ACCEPT _ R
