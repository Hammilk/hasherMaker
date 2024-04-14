#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

void print_usage(const char * app){
  fprintf(stderr, "usage: [-h] [-s size] [-k key]");
  fprintf(stderr, "   size indicates how many characters/numbers to hash");
  fprintf(stderr, "   key indicates hashmap value");
}

int main(int argc, char *argv[])
{
  const char optstr[] = "hs:k";
  char opt;
  int hashKey = 3;
  int arrSize = 5;
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
      default:
        printf("Invalid options %c\n", optopt);
        print_usage(argv[0]);
        return(EXIT_FAILURE);
    } 
  }

  int* arr = (int *)malloc(arrSize * sizeof(int));

  for(int i = 0; i < arrSize; i++){
    char temp;
    printf("Enter value[%d]: ", i);
    scanf("%c", &temp);
    arr[i] = temp % hashKey;
  }
  for(int i = 0; i < arrSize; i++){
    printf("%d", arr[i]);
  } 


  return 0;
  }
