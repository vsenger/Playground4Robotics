void motor_left_Forward(){
  // Move the DC motor forward at maximum speed
  Serial.println("Moving Left Motor Forward");
  digitalWrite(motor1_IA, LOW);
  digitalWrite(motor1_IB, HIGH); 
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
}

void motor_left_Stop(){
  // Stop the DC motor
  Serial.println("Left Motor  stopped");
  digitalWrite(motor1_IA, LOW);
  digitalWrite(motor1_IB, LOW);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
}

void motor_left_Backwards(){
  // Move DC motor backwards at maximum speed
  Serial.println("Moving Left Motor Backwards");
  digitalWrite(motor1_IA, HIGH);
  digitalWrite(motor1_IB, LOW); 
  digitalWrite(led1,LOW);
  digitalWrite(led2,HIGH);
}


void motor_right_Forward(){
  // Move the DC motor forward at maximum speed
  Serial.println("Moving Right Motor Forward");
  digitalWrite(motor2_IA, LOW);
  digitalWrite(motor2_IB, HIGH); 
  digitalWrite(led3,HIGH);
  digitalWrite(led4,LOW);
}

void motor_right_Stop(){
  // Stop the DC motor
  Serial.println("Right Motor stopped");
  digitalWrite(motor2_IA, LOW);
  digitalWrite(motor2_IB, LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
}

void motor_right_Backwards(){
  // Move DC motor backwards at maximum speed
  Serial.println("Moving Right Motor Backwards");
  digitalWrite(motor2_IA, HIGH);
  digitalWrite(motor2_IB, LOW); 
  digitalWrite(led3,LOW);
  digitalWrite(led4,HIGH);
}
