float ultra(){
  long duration;
  int distance;

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
 
  duration = pulseIn(echo, HIGH);
 
  distance= duration*0.034/2;

  Serial.print("Distance: ");
  Serial.println(distance);
  
  return distance;
  
  }
