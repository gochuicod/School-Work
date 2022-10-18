typedef struct {
	float a;
		float b;
			float c;
} Quadratic;

void discriminant(Quadratic *q);
int isImaginary(Quadratic *q);
float firstRoot(Quadratic *q);
float secondRoot(Quadratic *q);
void display(Quadratic *q);
int getValue(Quadratic q, int x);
void menu();
void Exit();
const char *warning = "Enter a valid choice!";
