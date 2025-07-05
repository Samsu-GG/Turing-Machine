start: q0
accept: ACCEPT
reject: REJECT

q0 0 -> q0 1 R 
q0 1 -> q0 0 R
q0 _ -> ACCEPT _ R 