#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void searchByAtomicNumber(FILE *fp);
void searchByAtomicSymbol(FILE *fp);
void searchByAtomicName(FILE *fp);
void searchByAtomicWeight(FILE *fp);

int main(void) {
    FILE *fp;
    int option;
    // Open the file for reading
    fp = fopen("elements.txt","r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    do {
        // Display menu options
     
        printf("\n\n\n\t\t\t    Modern Element Finder\n\n");
        printf("\n\t\t\t1. Search by Atomic Number\n");
        printf("\t\t\t2. Search by Atomic Symbol\n");
        printf("\t\t\t3. Search by Atomic Name\n");
        printf("\t\t\t4. Search by Atomic Weight\n");
        printf("\t\t\t5. Quit\n");
        printf("\t\t\tEnter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                searchByAtomicNumber(fp);
                  	getchar(); system("cls");
                break;
            case 2:
                searchByAtomicSymbol(fp);
                getchar(); system("cls");
                break;
            case 3:
                searchByAtomicName(fp);
                getchar(); system("cls");
                break;
            case 4:
                searchByAtomicWeight(fp);
                getchar(); system("cls");
                break;
            case 5:
                printf("\n\t\t\tExiting...\n");
                break;
            default:
                printf("\t\t\tInvalid choice. Please try again.\n");
				getchar();
				getchar();
				system("cls");
        }
    } while (option != 5);

    // Close the file
    fclose(fp);
    return 0;
}

void searchByAtomicNumber(FILE *fp) {
    int atomicNumber;
    char line[1000];
    system("cls");
    printf("\n\t\t\tEnter atomic number: ");
    scanf("%d", &atomicNumber);
    fseek(fp, 0, SEEK_SET); // Rewind to the beginning of the file
    while (fgets(line, sizeof(line), fp) != NULL) {
        int currentAtomicNumber;
        sscanf(line, "%d", &currentAtomicNumber);
        if (currentAtomicNumber == atomicNumber) {
           printf("\n\t\t\tElement found: \n\n\t\t\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\n\n\t\tAtomic number, Name, Symbol, Weight,Subgroup, Properties\n\n\t\t\t%s\n\n", line);
		    getchar();
			return;
        }
    }
    printf("Element not found.\n");
}

void searchByAtomicSymbol(FILE *fp) {
    char name[50];
    char line[1000];
    system("cls");
    printf("\t\t\tEnter atomic Symbol: ");
    scanf("%s", name);

    // Open the atname file for reading
    FILE *atname_fp = fopen("atsymbol.txt", "r");
    if (atname_fp == NULL) {
        printf("Error opening atsymbol.txt.\n");
        return;
    }
    int lineNumber = 1; // Initialize line number counter
    int found = 0; // Flag to indicate if the name is found
    // Loop through the atname file to find the given name and count the line number
    while (fgets(line, sizeof(line), atname_fp) != NULL) {
        if (strstr(line, name) != NULL) {
            found = 1;
            break;
        }
        lineNumber++;
    }

    // Close the atname file
    fclose(atname_fp);

    // If the name is found, open the elements file and retrieve the corresponding line
    if (found) {
        fseek(fp, 0, SEEK_SET); // Rewind to the beginning of the elements file
        int currentLine = 1;
        while (fgets(line, sizeof(line), fp) != NULL) {
            if (currentLine == lineNumber) {
                          printf("\n\t\t\tElement found: \n\n\t\t\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\n\n\t\tAtomic number, Name, Symbol, Weight,Subgroup, Properties\n\n\t\t\t%s\n\n", line);
		    getchar();
			return;
            }
            currentLine++;
        }
    } else {
        printf("Element not found.\n");
    }
}

void searchByAtomicName(FILE *fp) {
        char name[50];
    char line[1000];
    system("cls");
    printf("\t\t\tEnter atomic name: ");
    scanf("%s", name);

    // Open the atname file for reading
    FILE *atname_fp = fopen("atname.txt", "r");
    if (atname_fp == NULL) {
        printf("Error opening atname.txt.\n");
        return;
    }

    int lineNumber = 1; // Initialize line number counter
    int found = 0; // Flag to indicate if the name is found

    // Loop through the atname file to find the given name and count the line number
    while (fgets(line, sizeof(line), atname_fp) != NULL) {
        if (strstr(line, name) != NULL) {
            found = 1;
            break;
        }
        lineNumber++;
    }

    // Close the atname file
    fclose(atname_fp);

    // If the name is found, open the elements file and retrieve the corresponding line
    if (found) {
        fseek(fp, 0, SEEK_SET); // Rewind to the beginning of the elements file
        int currentLine = 1;
        while (fgets(line, sizeof(line), fp) != NULL) {
            if (currentLine == lineNumber) {
                          printf("\n\t\t\tElement found: \n\n\t\t\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\n\n\t\tAtomic number, Name, Symbol, Weight,Subgroup, Properties\n\n\t\t\t%s\n\n", line);
		    getchar();
			return;
            }
            currentLine++;
        }
    } else {
        printf("Element not found.\n");
    }
}

void searchByAtomicWeight(FILE *fp) {
    double weight;
    char line[1000];
    system("cls");
    printf("\t\t\tEnter atomic weight: ");
    scanf("%lf", &weight);
    fseek(fp, 0, SEEK_SET); // Rewind to the beginning of the file
    while (fgets(line, sizeof(line), fp) != NULL) {
        double currentWeight;
        sscanf(line, "%*d, %*[^,], %*[^,], %lf", &currentWeight);
        if (currentWeight == weight) {
                      printf("\n\t\t\tElement found: \n\n\t\t\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\t\xdb\n\n\t\tAtomic number, Name, Symbol, Weight,Subgroup, Properties\n\n\t\t\t%s\n\n", line);
		    getchar();
			return;
        }
    }
    printf("Element not found.\n");
}
