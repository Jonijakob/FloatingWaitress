void motion_c(float dist){
  digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
   analogWrite(enA, 250);
  
  if(dist<20){
   digitalWrite(in1, LOW);
   digitalWrite(in2, LOW);
   analogWrite(enA, 0);
  
         }
 
  
  }
