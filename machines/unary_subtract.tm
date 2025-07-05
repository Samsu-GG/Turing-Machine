start: q0
accept: ACCEPT
reject: REJECT

q0 1 -> q1 _ R
q1 1 -> q1 1 R
q1 - -> q1 - R
q1 _ -> q2 _ L
q1 _ -> q2 _ L
q2 - -> ACCEPT 1 R
q2 1 -> q3 _ L
q3 1 -> q3 1 L
q3 - -> q3 - L
q3 _ -> q0 _ R
q0 - -> ACCEPT _ R
q5 1 -> ACCEPT _ R
