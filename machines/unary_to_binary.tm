start: q0
accept: ACCEPT
reject: REJECT

q0 1 -> q1 _ R 
q1 1 -> q1 1 R 
q1 # -> q2 # R 
q2 0 -> q2 0 R 
q2 # -> q3 # L
q2 1 -> q2 1 R 
q3 1 -> q3 0 L 
q3 0 -> q4 1 L 
q4 0 -> q4 0 L 
q4 1 -> q4 1 L 
q4 # -> q4 # L
q4 _ -> q0 _ R 
q0 # -> q5 _ R 
q5 1 -> q5 1 R
q5 0 -> q5 0 R  
q5 # -> ACCEPT B R 
