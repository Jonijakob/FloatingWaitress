struct package
{
  int id=1;
  float temperature = 18.3;
  char  text[100] = "Text to be transmitted";
};
typedef struct package Package;
Package data;




float nrf(){
 myRadio.write(&data, sizeof(data)); 

  /*Serial.print("\nPackage:");
  Serial.print(data.id);
  Serial.print("\n");
  Serial.println(data.temperature);
  Serial.println(data.text);*/
  data.id = data.id + 1;
  data.temperature = data.temperature+0.1;
 
  
  }
