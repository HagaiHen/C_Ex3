#include <stdio.h>
#include <string.h>

#define TXT 1024
#define WORD 30

int Anagram() {
    char word[WORD] = "bee";
    char copy[WORD] = "";
    strcpy(copy, word);
    char ch[TXT] = "I’m bringing home my baby bumble bee Won’t my Mommy be so proud of me I’m bringing home my baby bumble bee    – OUCH!! It stung me!!~";
    int space = 0;
    int bool = 0;
    int enter = 0;
    int first = 0;
    int size = sizeof(ch) / sizeof(char);
    for (int i = 0; i < size && i < TXT - 1; i++) {
        enter = 0;
        for (int j = 0; j < strlen(copy) + space && j < WORD - 1; j++) {
            if (ch[i] == copy[j]) {
                bool++;
                enter = 1;
                copy[j] = "";
                break;
            } else {
                if (ch[i] == ' ') {
                    space++;
                    break;
                }
            }
            if ((space != 0 || bool != 0) && enter == 0 && j+1 == strlen(copy)) {
                bool = 0;
                space = 0;
                strcpy(copy, word);
            }
        }
        if (bool == strlen(word)) {
            first++;
            if (first > 1) {
                printf("~");
            }
            for (int k = i - space - bool + 1; k <= i; k++) {
                printf("%c", ch[k]);

            }
            i = i - 2;
            strcpy(copy, word);
            space = 0;
            bool = 0;
        }
    }
    return 0;
}

int main() {
    /*
    char word[WORD] = "abcd";
    char ch[TXT] = "AbcdaBcf74'dsGs6ab Dc4";
    int target = 0;
    int size = sizeof(word) / sizeof(char);
    for (int i = 0; i < size; i++) {
        if ((int) word[i] >= 65 && (int) word[i] <= 90) {
            target = target + ((int) word[i] - 64);
        } else {
            if ((int) word[i] >= 97 && (int) word[i] <= 122) {
                target = target + ((int) word[i] - 96);
            }
        }
    }
    int tmp = 0;
    int counter = 0;
    size = sizeof(ch) / sizeof(char);
    int last_indx = 0;
    //int wordSize = sizeof(word) / sizeof(char);
    for (int i = 0; i < size && i < TXT - 1; i++) {
        tmp = 0;
        for (int j = i; j < WORD - 1; j++) {
            if (tmp == target &&
                (((int) ch[i] >= 65 && (int) ch[j] <= 90) || ((int) ch[i] >= 97 && (int) ch[j] <= 122))) {
                if (counter >= 1) {
                    printf("~");
                }
                counter++;
                for (int k = i; k <= last_indx; k++) {
                    printf("%c", ch[k]);
                }
                break;
            }
            if (ch[j] == '~') {
                break;
            } else {
                if ((int) ch[j] >= 65 && (int) ch[j] <= 90) {
                    if (tmp < target) {
                        tmp = tmp + ((int) ch[j] - 64);
                        last_indx = j;
                    } else {
                        break;
                    }
                } else {
                    if ((int) ch[j] >= 97 && (int) ch[j] <= 122) {
                        if (tmp < target) {
                            tmp = tmp + ((int) ch[j] - 96);
                            last_indx = j;
                        }
                    }
                }
            }
        }
    }


     */
    Anagram();

    return 0;

}