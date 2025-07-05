start: q0
accept: ACCEPT
reject: REJECT

q0 0 -> q1 X R
q1 0 -> q1 0 R 
q1 Y -> q1 Y R 
q1 1 -> q2 Y R 
q2 Z -> q2 Z R 
q2 1 -> q2 1 R 
q2 2 -> q3 Z L
q3 1 -> q3 1 L
q3 Y -> q3 Y L
q3 0 -> q3 0 L
q3 Z -> q3 Z L
q3 X -> q0 X R 
q0 Y -> q4 Y R 
q4 Y -> q4 Y R 
q4 Z -> q4 Z R 
q4 _ -> ACCEPT _ L
