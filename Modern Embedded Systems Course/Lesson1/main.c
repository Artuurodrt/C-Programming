/* Lesson 1
*
*  Created by Arturo de los Rios on 04/01/22.
*
* C code of how computers count.
*/
int main()
{
  int count = 0;
  ++count; // count == 0
  ++count; //count == 1
  
  ++count; //count == 0x7FFFFFFF -> 2'147'483'647 (Modified with debugger)
  ++count; //count == 0x8000000  -> -2'147'483'648
  ++count;
  ++count;
  ++count;
  return 0;
}
