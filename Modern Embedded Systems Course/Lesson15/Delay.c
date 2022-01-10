void delay(int iter);

void delay(int iter){

int volatile counter = 0; /*Prevents compiler optimizations*/
    counter = 0;
  
  while(counter < iter){
    counter++;
  }
}