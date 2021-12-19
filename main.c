#include <stdio.h>
#include <string.h>
#include "function.h"

#define TXT 1024
#define WORD 30

int main() {

    char word[WORD]={0};
    char ch[TXT]={0};
    scanf("%s", word);
    char tmp;
    for (int i = 0; i < TXT; i++) {
        scanf("%c", &tmp);
        if (tmp == '~') {
            break;
        }
        ch[i] = tmp;
    }
    char *ptrCh = &ch[0];
    char *ptrWord = &word[0];
    printf("Gematria Sequences: ");
    Gimetria(ptrCh, ptrWord);
    printf("\n");
    printf("Atbash Sequences: ");
    Atbash(ptrCh, ptrWord);
    printf("\n");
    printf("Anagram Sequences: ");
    Anagram(ptrCh, ptrWord);
    return 0;

}
