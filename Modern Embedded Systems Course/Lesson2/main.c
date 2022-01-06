/* Lesson 2
*
*  Created by Arturo de los Rios on 04/01/22.
*
* C code of how processor handles control flow.
*/
int main()
{
  int count = 0;
 
/*see the control flow and assembly instructions with debugger */
  
  while(count < 21){
    ++count; 
    if((count & 1) != 0){
      /*Do something when the counter is odd*/
    }
    else{
      /*Do something when the counter is even*/    
    }
    
  }
  

  return 0;
}
