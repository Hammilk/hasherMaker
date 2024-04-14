#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<ctype.h>

void print_usage(const char * app){
  fprintf(stderr, "usage: [-h] [-s size] [-k key] [-t type]\n");
  fprintf(stderr, "   size indicates how many characters/numbers to hash\n");
  fprintf(stderr, "   key indicates hashmap value\n");
  fprintf(stderr, "   type indicates numeric or alphabetic (0 or 1)\n");
}

int main(int argc, char *argv[])
{
  const char optstr[] = "hs:k:t:";
  char opt;
  int hashKey = 3; //defaults
  int arrSize = 5; //defaults
  int type = 0; //default numeric
  while((opt = getopt(argc, argv, optstr))!= -1){
    switch(opt){
      case 'h':
        print_usage(argv[0]);
        return(EXIT_SUCCESS);
      case 's':
        arrSize = atoi(optarg); 
        break;
      case 'k':
        hashKey = atoi(optarg);
        break;
      case 't':
        type = atoi(optarg);
        break;
      default:
        printf("Invalid options %c\n", optopt);
        print_usage(argv[0]);
        return(EXIT_FAILURE);
    } 
  }
  printf("hashkey: %d\n", hashKey);
  int* arr = (int *)malloc(arrSize * sizeof(int));

  for(int i = 0; i < arrSize; i++){
    char temp = '1';
    int tempInt;
    arr[i] = 0;
    printf("Enter value[%d]: ", i);
    if(type == 1){
      scanf("%c", &temp);
      getchar();
    }
    else{
      scanf("%d", &tempInt);
    }
    if(type == 1 && temp > 96){
      arr[i] = (temp - 96) % hashKey;
    }
    else if(type == 1){
      arr[i] = (temp - 64) % hashKey; 
    }
    else{
      arr[i] = (tempInt % hashKey);
    }
  }
  for(int i = 0; i < arrSize; i++){
    printf("%d\n", arr[i]);
  } 
  free(arr);

  return 0;
  }
