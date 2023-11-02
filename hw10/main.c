#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_NAME_LENGTH 100

typedef struct Book {
    char isbn[14];
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int publication_year;
    char reserved[10];
    struct Book *next;
} Book;

typedef struct Student {
    char name[MAX_NAME_LENGTH];
    int id;
    Book *borrowed_books;
    struct Student *next;
} Student;

void addBook(char* isbn, char* title, char* author, int publicationYear, int method, Book **head) {
    Book *new_book = (Book*)malloc(sizeof(Book));
    strcpy(new_book->isbn, isbn);
    strcpy(new_book->title, title);
    strcpy(new_book->author, author);
    new_book->publication_year = publicationYear;
    strcpy(new_book->reserved, "Available");
    new_book->next = NULL;

    if (*head == NULL) {
        *head = new_book;
    } else {
        if (method == 0) {
            // FIFO
            Book *temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_book;
        } else {
            // LIFO
            new_book->next = *head;
            *head = new_book;
        }
    }

    FILE *fp = fopen("books.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(fp, "ISBN: %s\n", isbn);
    fprintf(fp, "Title: %s\n", title);
    fprintf(fp, "Author: %s\n", author);
    fprintf(fp, "Publication Year: %d\n", publicationYear);
    fprintf(fp, "Available: %s\n", new_book->reserved);
    fprintf(fp, "\n");

    fclose(fp);
}

void deleteBook(char* isbn, Book **head) {
    Book *temp = *head;
    Book *prev = NULL;

    while (temp != NULL) {
        if (strcmp(temp->isbn, isbn) == 0) {
            if (prev == NULL) {
                *head = temp->next;
            } else {
                prev->next = temp->next;
            }

            FILE *fp = fopen("books.txt", "r");
            if (fp == NULL) {
                printf("Error opening file!\n");
                exit(1);
            }

            FILE *fp_temp = fopen("temp.txt", "w");
            if (fp_temp == NULL) {
                printf("Error opening file!\n");
                exit(1);
            }

            char line[256];
            int found = 0;

            while (fgets(line, sizeof(line), fp)) {
                if (strstr(line, isbn)) {
                    found = 1;
                } else if (found && strcmp(line, "\n") == 0) {
                    found = 0;
                } else if (!found) {
                    fputs(line, fp_temp);
                }
            }

            fclose(fp);
            fclose(fp_temp);

            remove("books.txt");
            rename("temp.txt", "books.txt");

            free(temp);
            printf("Book deleted successfully.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Book not found.\n");
}

void updateBook(char* isbn, char* feature, char* value, Book *head) {
    Book *temp = head;
    int validFeature = 0;

    if (strcmp(feature, "title") == 0 || strcmp(feature, "author") == 0 || strcmp(feature, "publication year") == 0) {
        validFeature = 1;
    } else {
        printf("Invalid feature. Please enter a valid feature (title, author, or publication year).\n");
        return;
    }

    while (temp != NULL) {
        if (strcmp(temp->isbn, isbn) == 0) {
            if (strcmp(feature, "title") == 0) {
                strcpy(temp->title, value);
            } else if (strcmp(feature, "author") == 0) {
                strcpy(temp->author, value);
            } else if (strcmp(feature, "publication year") == 0) {
                temp->publication_year = atoi(value);
            }

            FILE *fp = fopen("temp.txt", "w");
            if (fp == NULL) {
                printf("Error opening file!\n");
                exit(1);
            }

            temp = head;
            while (temp != NULL) {
                fprintf(fp, "ISBN: %s\n", temp->isbn);
                fprintf(fp, "Title: %s\n", temp->title);
                fprintf(fp, "Author: %s\n", temp->author);
                fprintf(fp, "Publication Year: %d\n", temp->publication_year);
                fprintf(fp, "Reserved: %s\n", temp->reserved);
                fprintf(fp, "\n");
                temp = temp->next;
            }

            fclose(fp);

            remove("books.txt");
            rename("temp.txt", "books.txt");

            printf("Book updated successfully.\n");
            return;
        }
        temp = temp->next;
    }

    printf("Book not found.\n");
}

int compareBooks(Book *a, Book *b, int sortChoice) {
    if (sortChoice == 0) {
        return strcmp(a->title, b->title);
    } else if (sortChoice == 1) {
        return strcmp(a->author, b->author);
    } else {
        return a->publication_year - b->publication_year;
    }
}

void swapBooks(Book *a, Book *b) {
    char temp_isbn[14];
    char temp_title[MAX_TITLE_LENGTH];
    char temp_author[MAX_AUTHOR_LENGTH];
    int temp_publication_year;
    char temp_reserved[10];

    strcpy(temp_isbn, a->isbn);
    strcpy(temp_title, a->title);
    strcpy(temp_author, a->author);
    temp_publication_year = a->publication_year;
    strcpy(temp_reserved, a->reserved);

    strcpy(a->isbn, b->isbn);
    strcpy(a->title, b->title);
    strcpy(a->author, b->author);
    a->publication_year = b->publication_year;
    strcpy(a->reserved, b->reserved);

    strcpy(b->isbn, temp_isbn);
    strcpy(b->title, temp_title);
    strcpy(b->author, temp_author);
    b->publication_year = temp_publication_year;
    strcpy(b->reserved, temp_reserved);
}

void sortBooks(Book *head, int sortChoice) {
    int swapped;
    Book *ptr1;
    Book *lptr = NULL;

    if (head == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (compareBooks(ptr1, ptr1->next, sortChoice) > 0) {
                swapBooks(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void filterAndSortBooks(int filterChoice, char* filter, int sortChoice, Book *head) {
    Book *temp = head;

    while (temp != NULL) {
        if ((filterChoice == 0 && strcmp(temp->author, filter) == 0) || (filterChoice == 1 && temp->publication_year == atoi(filter))) {
            printf("ISBN: %s\n", temp->isbn);
            printf("Title: %s\n", temp->title);
            printf("Author: %s\n", temp->author);
            printf("Publication Year: %d\n", temp->publication_year);
            printf("Available: %s\n", temp->reserved);
            printf("\n");
        }
        temp = temp->next;
    }

    sortBooks(head, sortChoice);
}

void reverseBookList(Book **head) {
    Book *prev = NULL;
    Book *current = *head;
    Book *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;

    Book *temp = *head;

    while (temp != NULL) {
        printf("ISBN: %s\n", temp->isbn);
        printf("Title: %s\n", temp->title);
        printf("Author: %s\n", temp->author);
        printf("Publication Year: %d\n", temp->publication_year);
        printf("Available: %s\n", temp->reserved);
        printf("\n");
        temp = temp->next;
    }
}

void searchBooks(int searchChoice, char* searchValue, Book *head) {
    Book *temp = head;
    int found = 0;

    while (temp != NULL) {
        if ((searchChoice == 0 && strcmp(temp->isbn, searchValue) == 0) || (searchChoice == 1 && strcmp(temp->author, searchValue) == 0) || (searchChoice == 2 && strcmp(temp->title, searchValue) == 0)) {
            printf("ISBN: %s\n", temp->isbn);
            printf("Title: %s\n", temp->title);
            printf("Author: %s\n", temp->author);
            printf("Publication Year: %d\n", temp->publication_year);
            printf("Available: %s\n", temp->reserved);
            printf("\n");
            found = 1;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

void returnBook(char* isbn, Book *head, Student **studentHead, Student *student) {
    Book *temp = head;
    Student *currentStudent = *studentHead;
    int studentFound = 0;

   while (currentStudent != NULL) {
        if (currentStudent->id == student->id) {
            studentFound = 1;
            break;
        }
        currentStudent = currentStudent->next;
    }

    if (!studentFound) {
        printf("Student not found.\n");
        return;
    }

    while (temp != NULL) {
        if (strcmp(temp->isbn, isbn) == 0) {
            if (strcmp(temp->reserved, "Borrowed") == 0) {
                strcpy(temp->reserved, "Available");

                Book *prev = NULL;
                Book *curr = currentStudent->borrowed_books;

                while (curr != NULL) {
                    if (strcmp(curr->isbn, isbn) == 0) {
                        if (prev == NULL) {
                            currentStudent->borrowed_books = curr->next;
                        } else {
                            prev->next = curr->next;
                        }
                        free(curr);
                        break;
                    }
                    prev = curr;
                    curr = curr->next;
                }

                FILE *fp = fopen("temp.txt", "w");
                if (fp == NULL) {
                    printf("Error opening file!\n");
                    exit(1);
                }

                temp = head;
                while (temp != NULL) {
                    fprintf(fp, "ISBN: %s\n", temp->isbn);
                    fprintf(fp, "Title: %s\n", temp->title);
                    fprintf(fp, "Author: %s\n", temp->author);
                    fprintf(fp, "Publication Year: %d\n", temp->publication_year);
                    fprintf(fp, "Reserved: Available\n");
                    fprintf(fp, "\n");
                    temp = temp->next;
                }

                fclose(fp);

                remove("books.txt");
                rename("temp.txt", "books.txt");

                printf("Book returned successfully.\n");
            } else {
                printf("Book is not borrowed.\n");
            }
            return;
        }
        temp = temp->next;
    }

    printf("Book not found.\n");
}

void borrowBook(char* isbn, Book *head, Student **studentHead, Student *student) {
    Book *temp = head;
    Student *currentStudent = *studentHead;
    int studentFound = 0;

    while (currentStudent != NULL) {
        if (currentStudent->id == student->id) {
            studentFound = 1;
            break;
        }
        currentStudent = currentStudent->next;
    }

    if (!studentFound) {
        Student *newStudent = (Student*)malloc(sizeof(Student));
        strcpy(newStudent->name, student->name);
        newStudent->id = student->id;
        newStudent->borrowed_books = NULL;
        newStudent->next = *studentHead;
        *studentHead = newStudent;
        currentStudent = newStudent;
    }

    while (temp != NULL) {
        if (strcmp(temp->isbn, isbn) == 0) {
            if (strcmp(temp->reserved, "Available") == 0) {
                strcpy(temp->reserved, "Borrowed");

                Book *new_book = (Book*)malloc(sizeof(Book));
                strcpy(new_book->isbn, temp->isbn);
                strcpy(new_book->title, temp->title);
                strcpy(new_book->author, temp->author);
                new_book->publication_year = temp->publication_year;
                strcpy(new_book->reserved, temp->reserved);
                new_book->next = currentStudent->borrowed_books;
                currentStudent->borrowed_books = new_book;

                FILE *fp = fopen("students.txt", "a");
                if (fp == NULL) {
                    printf("Error opening file!\n");
                    exit(1);
                }

                fprintf(fp, "Name: %s\n", student->name);
                fprintf(fp, "ID: %d\n", student->id);
                fprintf(fp, "ISBN: %s\n", temp->isbn);
                fprintf(fp, "Title: %s\n", temp->title);
                fprintf(fp, "Author: %s\n", temp->author);
                fprintf(fp, "Publication Year: %d\n", temp->publication_year);
                fprintf(fp, "\n");

                fclose(fp);

                fp = fopen("books.txt", "r");
                if (fp == NULL) {
                    printf("Error opening file!\n");
                    exit(1);
                }

                FILE *fp_temp = fopen("temp.txt", "w");
                if (fp_temp == NULL) {
                    printf("Error opening file!\n");
                    exit(1);
                }

                char line[256];
                int found = 0;

                while (fgets(line, sizeof(line), fp)) {
                    if (strstr(line, isbn)) {
                        found = 1;
                    } else if (found && strcmp(line, "\n") == 0) {
                        found = 0;
                    }

                    if (found && strstr(line, "Available")) {
                        fprintf(fp_temp, "Reserved: %s\n", temp->reserved);
                    } else {
                        fputs(line, fp_temp);
                    }
                }

                fclose(fp);
                fclose(fp_temp);

                remove("books.txt");
                rename("temp.txt", "books.txt");

                 printf("Book borrowed successfully.\n");
            } else {
                 printf("Book is not available.\n");
            }
            return;
        }
        temp = temp->next;
    }

     printf("Book not found.\n");
}

void displayBorrowedBooks(int studentID, Student *head) {
    Student *current = head;
    while (current != NULL) {
        if (current->id == studentID) {
            printf("Student Name: %s\n", current->name);
            printf("Student ID: %d\n", current->id);
            printf("Borrowed Books:\n");
            Book *book = current->borrowed_books;
            while (book != NULL) {
                printf("ISBN: %s\n", book->isbn);
                printf("Title: %s\n", book->title);
                printf("Author: %s\n", book->author);
                printf("Publication Year: %d\n", book->publication_year);
                book = book->next;
            }
            break;
        }
        current = current->next;
    }
}

int main() {
    Book *head = NULL;
    Student *studentHead = NULL;
    Student student;

    while (1) {
        printf("Library Book Management System\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Update Book\n");
        printf("4. Filter and Sort Books\n");
        printf("5. Reverse Book List\n");
        printf("6. Search Books\n");
        printf("7. Borrow Book\n");
        printf("8. Return Book\n");
        printf("9. Display Borrowed Books\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            char isbn[14];
            char title[MAX_TITLE_LENGTH];
            char author[MAX_AUTHOR_LENGTH];
            int publicationYear;
            int method;

            printf("Enter ISBN: ");
            scanf("%s", isbn);
            printf("Enter Title: ");
            scanf("%s", title);
            printf("Enter Author: ");
            scanf("%s", author);
            printf("Enter Publication Year: ");
            scanf("%d", &publicationYear);
            printf("Enter Method (0 for FIFO, 1 for LIFO): ");
            scanf("%d", &method);

            addBook(isbn, title, author, publicationYear, method, &head);
        } else if (choice == 2) {
            char isbn[14];

            printf("Enter ISBN: ");
            scanf("%s", isbn);

            deleteBook(isbn, &head);
        } else if (choice == 3) {
            char isbn[14];
            char feature[20];
            char value[100];

            printf("Enter ISBN: ");
            scanf("%s", isbn);
            printf("Enter Feature: ");
            scanf("%s", feature);
            printf("Enter Value: ");
            scanf("%s", value);

            updateBook(isbn, feature, value, head);
        } else if (choice == 4) {
            int filterChoice;
            char filter[100];
            int sortChoice;

            printf("Enter Filter Choice (0 for author, 1 for publication year): ");
            scanf("%d", &filterChoice);
            printf("Enter Filter: ");
            scanf("%s", filter);
            printf("Enter Sort Choice (0 for title, 1 for author, 2 for publication year): ");
            scanf("%d", &sortChoice);

            filterAndSortBooks(filterChoice, filter, sortChoice, head);
        } else if (choice == 5) {
            reverseBookList(&head);
        } else if (choice == 6) {
            int searchChoice;
            char searchValue[100];

            printf("Enter Search Choice (0 for ISBN, 1 for author, 2 for title): ");
            scanf("%d", &searchChoice);
            printf("Enter Search Value: ");
            scanf("%s", searchValue);

            searchBooks(searchChoice, searchValue, head);
        } else if (choice == 7) {
            char isbn[14];

            printf("Enter Student Name: ");
            scanf("%s", student.name);
            printf("Enter Student ID: ");
            scanf("%d", &student.id);
            printf("Enter ISBN: ");
            scanf("%s", isbn);

            borrowBook(isbn, head, &studentHead, &student);
        } else if (choice == 8) {
            char isbn[14];

            printf("Enter ISBN: ");
            scanf("%s", isbn);

            returnBook(isbn, head, &studentHead, &student);
        } else if (choice == 9) {
            int studentID;

            printf("Enter Student ID: ");
            scanf("%d", &studentID);

            displayBorrowedBooks(studentID, studentHead);
        } else if (choice == 10) {
            break;
        }
    }

    return 0;
}
