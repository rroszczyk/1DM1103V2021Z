//
// Created by roszczyr on 18.11.2021.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct ListElement {
    int data;
    struct ListElement * previous;
    struct ListElement * next;
} ListElement_type;


void show(ListElement_type *head);
void show_reverse(ListElement_type *head);
int list_size(ListElement_type *head);
void push_front(ListElement_type **head, int number);
void push_back(ListElement_type **head, int number);
void push_by_index(ListElement_type **head, int number, int position);
void pop_front(ListElement_type **head);
void pop_back(ListElement_type **head);
void pop_by_index(ListElement_type **head, int position);

int main()
{
    ListElement_type *head;
    head = (ListElement_type *)malloc(sizeof(ListElement_type));
    head=NULL;


    int option=-1;
    int number=-1;
    int index=-1;

    while(option!=0)
    {

        system("clear");
        printf("\nAktualny stan listy: ");
        show(head);

        printf("\n\nDrogi uzytkowniku! Co chcesz zrobic?\n");
        printf("1. Dodac element na poczatek listy.\n");
        printf("2. Dodac element na koniec listy.\n");
        printf("3. Dodac element zgodnie z wybranym indeksem.\n");
        printf("4. Usunac element z poczatku listy.\n");
        printf("5. Usunac element z konca listy.\n");
        printf("6. Usunac element o wybranym indeksie.\n");
        printf("7. Wyswietlic liste w odwrotnej kolejnosci.\n");
        printf("0. Zakonczyc program.\n");

        scanf("%i", &option);

        switch (option)
        {
            case 0:
                return 0;
                break;
            case 1:
                printf("Wpisz liczbe jaka chcesz dodac: ");
                scanf("%i", &number);
                push_front(&head, number);
                break;
            case 2:
                printf("Wpisz liczbe jaka chcesz dodac: ");
                scanf("%i", &number);
                push_back(&head, number);
                break;
            case 3:
                printf("Wpisz liczbe jaka chcesz dodac: ");
                scanf("%i", &number);
                printf("Wpisz indeks: ");
                scanf("%i", &index);
                push_by_index(&head, number, index);
                break;
            case 4:
                pop_front(&head);
                break;
            case 5:
                pop_back(&head);
                break;

            case 6:
                printf("Wpisz indeks elementu, ktorego chcesz sie pozbyc raz na zawsze: ");
                scanf("%i", &index);
                pop_by_index(&head, index);
                break;

            case 7:
                show_reverse(head);
                break;

            default:
                printf("Podaj wlasciwa opcje.");
                break;

        }

    }


    return 0;
}

void push_front(ListElement_type **head, int number)
{

    if(*head==NULL) {
        *head = (ListElement_type *)malloc(sizeof(ListElement_type));
        (*head)->data = number;
        (*head)->previous=NULL;
        (*head)->next = NULL;
    } else {
        ListElement_type *current;
        current=(ListElement_type *)malloc(sizeof(ListElement_type));
        current->data=number;
        current->previous=NULL;
        current->next=(*head);
        (*head)->previous=current;
        *head=current;
    }

}

void push_back(ListElement_type **head, int number)
{


    if(*head==NULL)
    {
        *head = (ListElement_type *)malloc(sizeof(ListElement_type));
        (*head)->data = number;
        (*head)->previous = NULL;
        (*head)->next = NULL;
    }else
    {
        ListElement_type *current=*head;
        ListElement_type *new_element;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = (ListElement_type *)malloc(sizeof(ListElement_type));
        current->next->data = number;
        current->next->previous=current;
        current->next->next = NULL;
    }



}

void push_by_index(ListElement_type **head, int number, int position)
{
    if(position==0) push_front(head, number);
    else
    {
        if(position==list_size(*head)) push_back(head, number);
        else
        {
            ListElement_type *current=*head;
            ListElement_type *tmp;

            int i=0;
            while (current->next != NULL && i<position-1) {
                current = current->next;
                i++;
            }

            tmp=current->next;
            current->next=(ListElement_type *)malloc(sizeof(ListElement_type));
            current->next->data=number;
            current->next->previous=current;
            tmp->previous=current->next;
            current->next->next=tmp;

        }
    }


}





void pop_front(ListElement_type **head)
{

    if (*head!=NULL) {
        if((*head)->next==NULL) {
            *head=NULL;
        } else {
            ListElement_type *tmp;
            tmp=(*head)->next;
            free(*head);
            *head=tmp;
            (*head)->previous=NULL;
        }

    }

}

void pop_back(ListElement_type **head)
{

    if((*head)->next==NULL)
    {
        *head=NULL;
    }else
    {
        ListElement_type *current=*head;
        while (current->next->next!= NULL) {
            current = current->next;
        }
        free(current->next);
        current->next=NULL;
    }
}


void pop_by_index(ListElement_type **head, int position)
{
    if(position==0) pop_front(head);
    else
    {
        ListElement_type *current=*head;
        ListElement_type *tmp;

        int i=0;
        while (current->next != NULL && i<position-1) {
            current=current->next;
            i++;
        }

        tmp = current->next;
        current->next = tmp->next;
        current->next->previous=current;
        free(tmp);
    }


}



void show(ListElement_type *head)
{
    printf("\n");
    if(head==NULL) printf("List is empty");
    else
    {
        ListElement_type *current=head;
        do {
            printf("%i", current->data);
            printf("\n");
            current = current->next;
        }while (current != NULL);
    }
}

void show_reverse(ListElement_type *head)
{
    printf("\n");
    if(head==NULL) printf("List is empty");
    else
    {
        ListElement_type *current=head;
        while (current->next != NULL) {
            current = current->next; //idziemy na koniec listy
        }


        do {
            printf("%i", current->data);
            printf("\n");
            current = current->previous;
        }while(current!=NULL);

    }
}


int list_size(ListElement_type *head)
{
    int counter=0;
    if(head==NULL) return counter;
    else
    {
        ListElement_type *current=head;
        do {
            counter++;
            current = current->next;
        }while (current != NULL);
    }
    return counter;
}