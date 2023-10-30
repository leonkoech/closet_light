
void (*RemoteControl[])(void) = {SetPower, AutoDetect};  

void SetupRemoteControlMapper(){
  RemoteControl[64] = SetPower;
  RemoteControl[11] = AutoDetect;
}

void CallRemote(int button){
  switch(button){
    case 88:
    case 89:
    case 69:
    case 84:
    case 85:
    case 73:
    case 80:
    case 81:
    case 77:
    case 28:
    case 29:
    case 30:
    case 24:
    case 25:
    case 26:
      SetColor(button);
      break;
    case 64:
    case 11:
      RemoteControl[button]();
      break;
    default:
      break;
  }
  
}
