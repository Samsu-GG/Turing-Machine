start: q0
accept: ACCEPT
reject: REJECT

q0 0 -> q1 _ R 
q1 1 -> q1 1 R 
q1 0 -> q1 0 R 
q1 2 -> q2 2 R 
q2 X -> q2 X R 
q2 0 -> q3 X L 
q3 X -> q3 X L
q3 0 -> q3 0 L
q3 1 -> q3 1 L
q3 2 -> q3 2 L
q3 _ -> q0 _ R 
q0 1 -> q4 _ R 
q4 1 -> q4 1 R 
q4 0 -> q4 0 R 
q4 2 -> q5 2 R 
q5 X -> q5 X R 
q5 1 -> q6 X L
q6 X -> q6 X L
q6 0 -> q6 0 L
q6 1 -> q6 1 L
q6 2 -> q6 2 L
q6 _ -> q0 _ R 
q0 2 -> q7 _ R 
q7 X -> q7 _ R 
q7 _ -> ACCEPT _ R



