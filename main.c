/*TEXT:
1. С клавиатуры заполнить файл числами. Вывести содержимое файла на экран.
2. Определить, сколько раз в файле встречается число, заданное с клавиатуры.
3. Выполнить циклический сдвиг чисел в файле на k позиций (задаётся с клавиатуры) вправо.

BINARY:
1. С клавиатуры заполнить файл целыми числами.
2. Посчитать, сколько раз встречается заданный элемент.
3. Заменить элементы с заданным значением максимальным элементом.
*/


#include"Fun.h"
int main() {
	FILE* f;
	char* arr;
	char symbol;
	int i = 0, length = 1;
	int num, num1, kol = 0;
	char check;
	int choice;
	int max;
	int Amount;//of numbers
	static flag = 0;
	fpos_t end = 0;
	fpos_t cur = 0;
	arr = (char*)malloc(1 * sizeof(char));
	
	while (1) {
		printf("Please.choose the file type\n1-Text\n2-Binary\n3-End program\n");
		scanf_s("%d", &choice);
		if (choice == 1) {                                                              //TEXT
			printf("Please enter the file name:\n");
			rewind(stdin);
			while (1) {
				scanf("%c", &symbol);
				if (symbol == '\n') {

					if (arr[i - 4] == '.' && arr[i - 3] == 't' && arr[i - 2] == 'x' && arr[i - 1] == 't') {
						arr[i] = '\0';
						break;
					}

					if (arr[i - 1] == '.') {
						length += 3;
						arr = (char*)realloc(arr, length * sizeof(char));
						arr[i] = 't';
						arr[i + 1] = 'x';
						arr[i + 2] = 't';
						arr[i + 3] = '\0';
						break;
					}

					length += 4;
					arr = (char*)realloc(arr, length * sizeof(char));
					arr[i] = '.';
					arr[i + 1] = 't';
					arr[i + 2] = 'x';
					arr[i + 3] = 't';
					arr[i + 4] = '\0';
					break;
				}
				arr[i] = symbol;
				i++;
				length++;
				arr = (char*)realloc(arr, length * sizeof(char));
			}
			rewind(stdin);
			while (1) {
				printf("\nWhat would u like to do?\n1-Add content\n2-See file's content\n3-See matches\n4-Make a shift\n5-End program\n");
				rewind(stdin);
				scanf("%d", &choice);

				switch (choice) {
				case 1: {

					while (1) {
						rewind(stdin);
						if ((f = fopen(arr, "a+")) == NULL){
							printf("Open error\n");
							return 0;
					}
		            else break;

					}

					fsetpos(f, &end);
					text_add(f, end);
					fclose(f);
					break;
				}
				case 2: {
					while (1) {
						rewind(stdin);
						if ((f = fopen(arr, "r")) == NULL){
							printf("Open error\n");
							return 0;
					}
						else break;
					}
					text_out(f, arr);
					fclose(f);
					break;
				}
				case 3: {
					while (1) {
						rewind(stdin);
						if ((f = fopen(arr, "r")) == NULL){
							printf("Open error\n");
							return 0;
					    }
		              else break;
					}

					
					rewind(stdin);
					text_matches(f);
					fclose(f);
					break;
				}

				case 4: {
					int k;
					printf("Please,enter k coefficient\n");
					while (1) {
						rewind(stdin);
						if (!scanf("%d", &k) || k < 0)
							printf("Wrong number!Please,try again\n"); else break;
					}
					while (1) {
						rewind(stdin);
						if ((f = fopen(arr, "a+")) == NULL){
							printf("Open error\n");
							return 0;
					}
		               else break;
					}
					//text_add_1(f, end, k, arr);
					fclose(f);
					while (1) {
						rewind(stdin);
						if ((f = fopen(arr, "r+")) == NULL){
							printf("Open error\n");
							return 0;
					}
		              else break;
					}
					fsetpos(f, &end);

					textShift(f, end, cur, k, arr);
					fclose(f);
					break;
				}
				case 5:  return 0;
				default: printf("Wrong number!Please try again!\n");

				}

			}
		}
		else if (choice == 2) {                                                           //bINARY
		printf("Please enter the file name:\n");
		rewind(stdin);
		while (1) {
			scanf("%c", &symbol);
			if (symbol == '\n') {

				if (arr[i - 4] == '.' && arr[i - 3] == 'b' && arr[i - 2] == 'i' && arr[i - 1] == 'n') {
					arr[i] = '\0';
					break;
				}

				if (arr[i - 1] == '.') {
					length += 3;
					arr = (char*)realloc(arr, length * sizeof(char));
					arr[i] = 'b';
					arr[i + 1] = 'i';
					arr[i + 2] = 'n';
					arr[i + 3] = '\0';
					break;
				}

				length += 4;
				arr = (char*)realloc(arr, length * sizeof(char));
				arr[i] = '.';
				arr[i + 1] = 'b';
				arr[i + 2] = 'i';
				arr[i + 3] = 'n';
				arr[i + 4] = '\0';
				break;
			}
			arr[i] = symbol;
			i++;
			length++;
			arr = (char*)realloc(arr, length * sizeof(char));
		}
			rewind(stdin);
			while (1)
			{
				printf("What would u like to do?\n1-Add content\n2-See content\n3-See matches\n4-Elements change\n5-End program\n");
				rewind(stdin);
				scanf_s("%d", &choice);

				switch (choice) {
				case 1: {

					while (1) {
						rewind(stdin);
						if ((f = fopen(arr, "ab+")) == NULL){
							printf("Open error\n");
							return 0;
					    }
		               else break;

					}

					fsetpos(f, &end);
					Amount=bin_add(f, end);
					fclose(f);
					break;
				}
				case 2: {
					while (1) {
						rewind(stdin);
						if ((f = fopen(arr, "rb")) == NULL){
							printf("Open error\n");
							return 0;
					     }
		              else break;
					}
					bin_out(f, arr);
					fclose(f);
					break;
				}
				case 3: {
					while (1) {
						rewind(stdin);
						if ((f = fopen(arr, "rb")) == NULL){
							printf("Open error\n");
							return 0;
					}
		               else break;
					}
					rewind(stdin);
					bin_matches(f);
					fclose(f);
					
					break;
				}
				case 4: {

					while (1) {
						rewind(stdin);
						if ((f = fopen(arr, "rb+")) == NULL){
							printf("Open error\n");
							return 0;
					    }
		              else break;
					}
					max = bin_max(f);
					bin_replace(f, max,Amount);
					fclose(f);
					break;
				}
				case 5:  return 0;
				default: printf("Wrong number!Please try again!\n");

				}
			}
		}
	
		else if (choice == 3) return 0;
		else {
		printf("Wrong number!\n");
		return 0;
		}
    }
}

