#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void appendToFirstLine(const char* filename, const char* word) {
    // Відкриття файлу у режимі дозапису
   FILE* file = fopen(filename, "r+");

    if (file == NULL) {
        printf("Помилка відкриття файлу.\n");
        return;
    }
  
    // Переміщення на початок файлу
    fseek(file, 0, SEEK_SET);

    // Читання першого рядка з файлу
    char buffer[1000];
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        printf("Помилка читання файлу.\n");
        fclose(file);
        return;
    }

    // Додавання слова до першого рядка
    strcat(buffer, word);

    // Повернення на початок файлу
    fseek(file, 0, SEEK_SET);

    // Запис оновленого рядка до файлу
    fputs(buffer, file);


    // Закриття файлу
    fclose(file);
}

int main() {
    const char* filename = "text.txt";
    char word[100];
    setlocale (LC_CTYPE,"ua");

    printf("Введіть слово: ");
    scanf("%s", word);

    appendToFirstLine(filename, word);

    printf("Слово додано до першого рядка файлу.\n");

    return 0;
}
