

bool CheckPower(){
  return is_power_on;
}

void SetPower(){
  Serial.println("power clicked");
  is_power_on = !is_power_on;
}
 
