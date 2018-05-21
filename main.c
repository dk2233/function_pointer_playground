//
//  main.c
//  function_pointer_test
//
//  Created by Daniel Kucharski on 20.05.2018.
//  Copyright © 2018 code masterss. All rights reserved.
//

#include <stdio.h>




char *tab1="dane ze struktuty 1";
char *tab2="dane ze struktury 2";
char *tab3 =(char *)"dane dane uwaga ";

typedef enum
{
    FIRST_DATA,
    SECOND_DATA,
    THIRD_DATA,
}EnumType;


typedef enum
{
    PRIMER,
    DUO,
    TRZECI,
}EnumType2;


typedef  struct
{
    uint8_t  data1;
    uint16_t data2;
    char     *tab;
    
}struct1_type;


typedef  struct
{
    uint8_t  data1;
    uint16_t data2;
    char     *tab;
    
}struct2_type;

typedef struct{
    struct1_type  TypeOfArg1;
    struct2_type TypeOfArg2;
}EntryArguments;



typedef struct
{
    uint8_t  WhatAreTheNumber;
    void (*function_pf)(uint8_t inputData_as_Enum, EntryArguments typeOfDataTobeGiven);
    
}TestStruct;

void functionWrapper(uint8_t arg_u8,struct1_type *arg_struct1, struct2_type *arg_struct2 );




void function1(EnumType arg_enum, struct1_type Arg_struct);
void function2(EnumType2 arg_enum, struct2_type StrukturaWejsciowa);

void function1(EnumType arg_enum, struct1_type Arg_struct)
{
    printf(" \n warning this is function of first type \n");
    printf(" %d <-< enum ",arg_enum );
    printf(" %s ",Arg_struct.tab);
}

void functionWrapper(uint8_t arg_u8,struct1_type *arg_struct1, struct2_type *arg_struct2 )
{
    if (NULL != arg_struct1)
        function1((EnumType)arg_u8, *arg_struct1);
}


struct {
    uint8_t  DataInput;
    struct1_type *struct1_input;
    struct2_type *struct2_input;
    void (*functionWrapper_pointer)(uint8_t arg_u8,struct1_type *arg_struct1, struct2_type *arg_struct2  );
    
} tab_iteracyjna[]={
    {(uint8_t)FIRST_DATA, &(struct1_type){7U, 0U, (char *)"aaaa"},NULL, &functionWrapper}
};

//((uint8_t) FIRST_DATA,

int main(int argc, const char * argv[])
{
    // insert code here...
    printf("Hello, World!\n");
    
    tab_iteracyjna[0].functionWrapper_pointer(tab_iteracyjna[0].DataInput, tab_iteracyjna[0].struct1_input, tab_iteracyjna[0].struct2_input);
    
    return 0;
}
