#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<ctype.h>

void print_usage(const char * app){
  fprintf(stderr, "usage: [-h] [-s size] [-k key]\n");
  fprintf(stderr, "   size indicates how many characters/numbers to hash\n");
  fprintf(stderr, "   key indicates hashmap value\n");
}

int main(int argc, char *argv[])
{
  const char optstr[] = "hs:k:";
  char opt;
  int hashKey = 3; //defaults
  int arrSize = 5; //defaults
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
    getchar();
    if(isalpha(temp) && temp > 96){
      arr[i] = (temp - 96) % hashKey;
    }
    else if(isalpha(temp)){
      arr[i] = (temp - 64) % hashKey; 
    }
    else arr[i] = (temp % hashKey);
  }
  for(int i = 0; i < arrSize; i++){
    printf("%d\n", arr[i]);
  } 
  free(arr);

  return 0;
  }
