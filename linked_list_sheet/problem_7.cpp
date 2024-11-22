// انا مكروت السؤال ده
typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char street[50];
    char city[50];
    char zipCode[10];
} Address;

typedef struct {
    char name[50];
    Address address;
    char phoneNumber[15];
} Company;

typedef struct {
    char name[50];
    Address homeAddress;
    Date dateOfBirth;
    Company company;
} Employee;

typedef Employee type;

// تعريف العقدة
typedef struct nodet {
    type info;
    struct nodet *next;
} node;

typedef struct hea {
    int size;
    node *head;
} list;
