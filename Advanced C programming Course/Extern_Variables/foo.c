

extern int i; //extern i variable declaration

extern int count; //extern count variable declaration

void foo(void){
    i = 100;
}

void write_extern(void){
    printf("Count is %d\n", count);
}
