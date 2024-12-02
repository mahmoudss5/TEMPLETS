#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
typedef struct { 
char tag; // d, v, or E 
int callerID, receiverID; 
int numPackets; 
int callerIDHidden, roaming; 
} Call; 
typedef struct Node { 
Call data; 
struct Node* next; 
} Node; 
Node* front = NULL;
Node* newNode(Call data) { 
Node* new_node = (Node*)malloc(sizeof(Node)); 
new_node->data = data; 
new_node->next = NULL; 
return new_node; 
} 
void insertCall(Call data) { 
Node* new_node = newNode(data); 
if (front == NULL) { 
front = new_node; 
return; 
} 
Node* current = front; 
Node* prev = NULL; 
if (data.tag == 'E') { 
while (current != NULL && current->data.tag == 'E') { 
prev = current; 
current = current->next; 
} 
new_node->next = current; 
if (prev == NULL) { 
front = new_node; 
        } else { 
            prev->next = new_node; 
        } 
        return; 
    } 
 
    if (data.tag == 'V') { 
        while (current != NULL && (current->data.tag == 'E' 
|| current->data.tag == 'V')) { 
            prev = current; 
            current = current->next; 
        } 
        new_node->next = current; 
        if (prev == NULL) { 
            front = new_node; 
        } else { 
            prev->next = new_node; 
        } 
return; 
} 
while (current != NULL) { 
prev = current; 
current = current->next; 
} 
prev->next = new_node; 
} 
void serveCall() { 
if (front == NULL) { 
printf("Queue is empty.\n"); 
return; 
} 
Node* temp = front; 
front = front->next; 
printf("Served call: %c %d %d\n", temp->data.tag, 
temp->data.callerID, temp->data.receiverID); 
free(temp); 
} 
void dismissLeastPriority() { 
if (front == NULL) { 
printf("Queue is empty.\n"); 
return; 
} 
Node* current = front; 
Node* prev = NULL; 
while (current != NULL && current->data.tag == 'D') { 
prev = current; 
current = current->next; 
printf("Dismissed data call: %c %d %d\n", current
>data.tag, current->data.callerID, current
>data.receiverID); 
free(current); 
} 
if (prev != NULL) { 
prev->next = current; 
} else { 
front = current; 
} 
} 
int main() { 
int choice; 
Call call; 
while (1) { 
        printf("\n1. Data Call coming\n"); 
        printf("2. Voice Call coming\n"); 
        printf("3. Emergency Call coming\n"); 
        printf("4. Serve a call\n"); 
        printf("5. Dismiss calls with least priority\n"); 
        printf("6. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter data call details (D, callerID, 
receiverID, numPackets): "); 
                scanf(" %c %d %d %d", &call.tag, &call.callerID, 
&call.receiverID, &call.numPackets); 
                insertCall(call); 
                break; 
            case 2: 
                printf("Enter voice call details (V, callerID, 
receiverID, callerIDHidden, roaming): "); 
                scanf(" %c %d %d %d %d", &call.tag, 
&call.callerID, &call.receiverID, &call.callerIDHidden, 
&call.roaming); 
                insertCall(call); 
                break; 
            case 3: 
                printf("Enter emergency call details (E, callerID, 
receiverID): "); 
                scanf(" %c %d %d", &call.tag, &call.callerID, 
&call.receiverID); 
                insertCall(call); 
                break; 
            case 4: 
                serveCall(); 
                break; 
            case 5: 
                dismissLeastPriority(); 
break; 
case 6: 
exit(0); 
default: 
printf("Invalid choice.\n"); 
} 
} 
return 0; 
} 
