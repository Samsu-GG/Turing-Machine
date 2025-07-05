start: q0
accept: ACCEPT
reject: REJECT

q0 0 -> q0 0 R 
q0 1 -> q0 1 R 
q0 _ -> q1 _ L
q1 0 -> q1 0 L
q1 1 -> q2 1 L 
q2 0 -> q2 1 L
q2 1 -> q2 0 L 
q2 _ -> ACCEPT _ R 
q1 _ -> ACCEPT _ R 