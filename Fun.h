#include"Library.h"

void text_add(FILE* f, fpos_t* end) {
	printf("Enter your numbers please:\n");
	char bufer;
	fsetpos(f, &end);
	while (1) {

		scanf("%c", &bufer);
		if (bufer == '\n') {
			fprintf(f, "%c", ' ');
			fgetpos(f, &end);
			break;
		}
		fprintf(f, "%c", bufer);

	}
	fgetpos(f, &end);
}
int bin_add(FILE* f) {
	int amount, i, num;
	printf("Enter the amount of numbers please:\n");
	while (1) {
		rewind(stdin);
		if (!(scanf("%d", &amount)) || amount < 1)
			printf("Wrong number!\n"); else break;
	}
	printf("Please,enter numbers:\n");
	for (i = 0; i < amount; i++) {
		rewind(stdin);
		scanf("%d", &num);
		fwrite(&num, sizeof(num), 1, f);
	}
	return amount;
}
void text_add_1(FILE* f, fpos_t* end, int k, char* arr) {
	while (1) {
		rewind(stdin);
		if ((f = fopen(arr, "a+")) == NULL){
			printf("Open error\n");
			return 0;
	}
          else break;
	}
	fseek(f, 0, 2);
	while (k > 0) {
		fprintf(f, "%c", ' ');
		k--;
	}
	fgetpos(f, &end);
	fclose(f);
}
void text_matches(FILE* f) {
	int num, num1;
	int kol = 0;
	printf("Please,enter a number for match:\n");
	rewind(stdin);
	scanf_s("%d", &num);
	rewind(stdin);
	while (!feof(f)) {

		fscanf(f, "%d", &num1);
		if (feof(f)) {
			rewind(stdin);
			break;
		}
		if (num1 == num)
			kol++;
	}
	rewind(stdin);
	printf("Amount of matches:%d\n", kol);
}
void bin_matches(FILE* f) {
	int num, num1;
	int kol = 0;
	printf("Please,enter a number for match:\n");
	rewind(stdin);
	scanf_s("%d", &num);
	rewind(stdin);
	fseek(f, 0, 0);
	while (!feof(f)) {

		fread(&num1, sizeof(int), 1, f);
		if (feof(f)) {
			rewind(stdin);
			break;
		}
		if (num1 == num)
			kol++;
	}
	rewind(stdin);
	printf("Amount of matches:%d\n", kol);
}
void text_out(FILE* f, char arr) {
	char w;
	printf("Your file's content:\n");
	rewind(stdin);
	fseek(f, 0, 0);
	while (!feof(f)) {
		fscanf(f, "%c", &w);
		if (feof(f))
			break;
		printf("%c", w);
	}
	rewind(stdin);

}
void bin_out(FILE* f) {
	int w;
	fpos_t cur;
	printf("Your file's content:\n");
	rewind(stdin);
	fseek(f, 0, 0);
	while (!feof(f)) {
		fread(&w, sizeof(int), 1, f);
		if (feof(f)) {
			rewind(stdin);
			break;
		}
		fgetpos(f, &cur);
		printf("%d ", w);
	}
	rewind(stdin);
	printf("\n");
}
void textShift(FILE* f, fpos_t end, fpos_t current, int k, char* arr) {
	char space = ' ';
	char cur;
	int amount = 0;
	int first;//number in the end
	char sym;
	int num,num1;//for the end of shifting
	current = 0;

	while (1) {
		rewind(stdin);
		if ((f = fopen(arr, "r+")) == NULL) {
			printf("Open error\n");
			return 0;
		}
		else break;
	}
	while (k > 0) {
		fseek(f, -2, 2);
		fgetpos(f, &end);
		num = end;
		num1 = num;
		while (end != 0) {

			fscanf(f, "%c", &cur);
			amount++;
			end--;

			if (cur == space) {
				end += 2;
				amount--;
				fsetpos(f, &end);
				fscanf(f, "%d", &first);

				break;
			}
			fsetpos(f, &end);
		}
		end--;
		fsetpos(f, &end);

		current = end - 1;
		num = num - current + 1;

		while (num > 0) {
			fprintf(f, "%c", space);
			num--;
		}

		end = num1;
		while (current >= 0) {
			fsetpos(f, &current);
			fscanf(f, "%c", &sym);
			current--;
			fsetpos(f, &end);
			fprintf(f, "%c", sym);
			end--;
			rewind(stdin);

		}
		fseek(f, 0, 0);
		fprintf(f, "%d", first);
		fprintf(f, "%c", space);
		k--;
	}
	fclose(f);
}

void text_shift(FILE* f, fpos_t end, fpos_t cur, int k, char* arr) {
	char sym;
	char sym1, sym2;
	int position = 1;
	int num;
	while (1) {
		rewind(stdin);
		if ((f = fopen(arr, "r+")) == NULL){
			printf("Open error\n");
			return 0;
	}
            else break;
	}
	fseek(f, 0, 2);
	fgetpos(f, &end);
	num = end - k;
	cur = (end - k - 1);
	end--;

	/*printf("Cur==");
	fsetpos(f, &cur);
	fscanf(f, "%c", &sym1);
	printf("%c", sym1);
								 //for checking start numbers:current and end(the last one)
	printf("\nEnd==");
	fsetpos(f, &end);
	fscanf(f, "%c", &sym2);
	printf("%c\n", sym2);*/

	fseek(f, 0, 2);
	while (num > 0) {
		fsetpos(f, &cur);
		fscanf(f, "%c", &sym);
		cur--;
		fsetpos(f, &end);
		fprintf(f, "%c", sym);
		end--;
		num--;
		/*printf("%d try:\n", position++); //for checking during the transformation
		text_out(f, arr);
		printf("\n");*/
		rewind(stdin);
	}

	char space = ' ';//i wanna put spaces(==k) in the beginning of the string after the shift
	int num1 = k;
	rewind(stdin);
	fseek(f, 0, 0);
	while (num1 > 0) {
		fprintf(f, "%c", space);
		num1--;
	}
	fclose(f);
}
int bin_max(FILE* f) {
	int max, current;
	rewind(stdin);
	fread(&max, sizeof(max), 1, f);
	while (!feof(f)) {
		fread(&current, sizeof(int), 1, f);
		if (current > max)
			max = current;
	}
	rewind(stdin);
	return max;
}
void bin_replace(FILE* f, int max, int amount) {
	int current;
	int choice;
	int kol = 0;
	fpos_t cur = 0;
	printf("Please,enter a number for change to max one:\n");
	while (1) {
		rewind(stdin);
		if (!scanf("%d", &choice))
			printf("Try again\n"); else break;
	}
	rewind(stdin);
	fseek(f, 0, 0);
	while (amount > 0) {
		fsetpos(f, &cur);
		fread(&current, sizeof(int), 1, f);
		if (current == choice) {
			fsetpos(f, &cur);
			fwrite(&max, sizeof(max), 1, f);
			rewind(stdin);
			kol++;
		}
		cur += 4;
		amount--;
	}
	if (kol == 0)
		printf("No matches in file for your numbers\n");

}
