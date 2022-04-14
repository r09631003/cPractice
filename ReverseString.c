#include<stdio.h>

void strcpy(const char *, char *);
int strlen(const char *);

void reverseString(char *, int);

void swapChar(char *, char *);
void swapInt(int *, int *);

void reverseWordsInString(char *);
void reverseWordsInStringII(char *);

int main(){
    char s[] = "I am a boy";
    reverseWordsInString(s);
    printf("%s\n", s);

    return 0;
}

void reverseWordsInString(char *s){
    int len = strlen(s);

    /* reverse the whole string first */
    reverseString(s, len);

    int i = 0;

    while(i < len){
        if(s[i] == ' ') i++;
        else{
            int j = i;

            /* j should move to the ' ' and '\0' */
            while(s[j] != ' ' && s[j] != '\0')
                j++;


            for(int k = 0; k < (j - i) / 2; k++){
                swapChar(&s[i + k], &s[j - 1 - k]);
            }

            /* move i to j which is ' ' and '\0' */
            i = j;
        }

    }
}

void reverseWordsInStringII(char *s){
    int len = strlen(s);


    int i = 0;

    while(i < len){
        if(s[i] == ' ') i++;
        else{
            int j = i;

            while(s[j] != ' ' && s[j] != '\0')
                j++;


            for(int k = 0; k < (j - i) / 2; k++){
                swapChar(&s[i + k], &s[j - 1 - k]);
            }

            i = j;
        }

    }
}


void reverseArray(int *arr, int len){
    for(int i = 0; i < len/2; i++){
        swapInt(&arr[i], &arr[len-i-1]);
    }
}

int strlen(const char *from){
    int len = 0;
    while(*(from++)){
        len++;
    }

    return len;
}

void strcpy(const char *from, char *to){

    while(*(from)){
        *(to++) = *(from++);
    }

    return;
}

void reverseString(char * str, int len){
   for(int i = 0; i < len; i++){
        swapChar(&str[i], &str[len - i - 1]);
   }
}

void swapChar(char *a, char *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void swapInt(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
