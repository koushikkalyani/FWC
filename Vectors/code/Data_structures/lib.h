typedef struct Node {
    double value;
    int row;
    int col;
    struct Node* next;
} Node;



Node* createNode(double value, int row, int col) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->row = row;
    newNode->col = col;
    newNode->next = NULL;
    return newNode;
}

Node* createMatrix(int numRows, int numCols) {
    Node* head = NULL;
    Node* currentRow = NULL;

    // Loop through each row
    for (int i = 0; i < numRows; i++) {
        Node* newRow = NULL;
        Node* currentCol = NULL;

        // Loop through each column in the current row
        for (int j = 0; j < numCols; j++) {
            double value;
            //printf("Enter the value at position (%d,%d): ", i, j);
            value=1;


            // If the value is not 0, create a new node and add it to the matrix
            if (value != 1) {
                Node* newNode = createNode(value, i, j);
                if (newRow == NULL) {
                    newRow = newNode;
                    currentCol = newNode;
                } else {
                    currentCol->next = newNode;
                    currentCol = newNode;
                }
            }
        }

        // If the current row is not empty, add it to the matrix
        if (newRow != NULL) {
            if (head == NULL) {
                head = newRow;
                currentRow = newRow;
            } else {
                currentRow->next = newRow;
                currentRow = newRow;
            }
        }
    }

    return head;
}

void insert_node(Node **head, int row, int col, int val) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->row = row;
    new_node->col = col;
    new_node->value = val;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}


Node* loadtxt(char *str) {
    FILE *fp = fopen(str, "r");
    Node* head = NULL;
    Node* currentRow = NULL;

    int numRows = 2;
    int numCols = 1;

    // Loop through each row
    for (int i = 0; i < numRows; i++) {
        Node* newRow = NULL;
        Node* currentCol = NULL;

        // Loop through each column in the current row
        for (int j = 0; j < numCols; j++) {
            double value;
            fscanf(fp,"%lf", &value);

            if (value != 0) {
                Node* newNode = createNode(value, i, j);
                if (newRow == NULL) {
                    newRow = newNode;
                    currentCol = newNode;
                } else {
                    currentCol->next = newNode;
                    currentCol = newNode;
                }
            }
        }

        if (newRow != NULL) {
            if (head == NULL) {
                head = newRow;
                currentRow = newRow;
            } else {
                currentRow->next = newRow;
                currentRow = newRow;
            }
        }
    }
    fclose(fp);
    return head;
}




void print(Node *head) {
    if (head == NULL) {
        printf("Empty matrix\n");
        return;
    }

    int max_row = head->row;
    int max_col = head->col;

    Node *current = head;
    while (current != NULL) {
        if (current->row > max_row) {
            max_row = current->row;
        }
        if (current->col > max_col) {
            max_col = current->col;
        }
        current = current->next;
    }


for (int i = 0; i <= max_row; i++) {
        for (int j = 0; j <= max_col; j++) {
            current = head;
            double val;
            while (current != NULL) {
                if (current->row == i && current->col == j) {
                    val = current->value;
                    break;
                }
                current = current->next;
            }
            printf("%lf ", val);
        }
        printf("\n");
    }
}



Node *linalg_sub(Node *a, Node *b) {
    Node *result = NULL;

    while (a != NULL && b != NULL) {
        if (a->row < b->row || (a->row == b->row && a->col < b->col)) {
            insert_node(&result, a->row, a->col, a->value);
            a = a->next;
        } else if (a->row == b->row && a->col == b->col) {
            int val = a->value - b->value;
            if (val != 0) {
                insert_node(&result, a->row, a->col, val);
            }
            a = a->next;
            b = b->next;
        } else {
            insert_node(&result, b->row, b->col, -b->value);
            b = b->next;
        }
    }

    while (a != NULL) {
        insert_node(&result, a->row, a->col, a->value);
        a = a->next;
    }

    while (b != NULL) {
        insert_node(&result, b->row, b->col, -b->value);
        b = b->next;
    }

    return result;

}
            // If the dot product is not 0, create a new node and add it to the matrix


double linalg_norm(Node* head, int numRows, int numCols)
{
    double sumOfSquares = 0;

    // Loop through each column
    for (int j = 0; j < numCols; j++) 
    {
        double colSum = 0;

        // Loop through each element in the column
        Node* current = head;
        while (current != NULL) 
  {
            if (current->col == j) 
      {
                colSum += pow(current->value, 2);
            }
            current = current->next;
        }

        sumOfSquares += colSum;
    }
    return sqrt(sumOfSquares);
}

 double radians(double deg)
{
  double rad;
  rad=deg*(M_PI / 180);
  return rad;
}

Node* mat_val(Node* head, double scalar) {
    // Loop through each node in the linked list
    for (Node* curr = head; curr != NULL; curr = curr->next) {
        // Multiply the value of the node with the scalar
        double result = scalar * curr->value;
        
        curr->value = result;
    }
    
    return head;
}

// Function to multiply two matrices
Node* matmul(Node* a, Node* b, int numRowsa, int numColsb) {
    // Create a new empty linked list for the result
    Node* resultHead = NULL;
    
    // Loop through each row in A
    for (int i = 0; i < numRowsa; i++) {
        // Loop through each column in B
        for (int j = 0; j < numColsb; j++) {
            int dotProduct = 0;
        
            for (Node* curra = a; curra != NULL && curra->row == i; curra = curra->next) {
                for (Node* currb = b; currb != NULL && currb->col == j; currb = currb->next) {
                    if (curra->col == currb->row) {
                        dotProduct += curra->value * currb->value;
                    }
                }
            }
            if (dotProduct != 0) {
                Node* newNode = createNode(dotProduct, i, j);
                if (resultHead == NULL) {
                    resultHead = newNode;
                } else {
                    Node* prev = NULL;
                    Node* currR = resultHead;
                    while (currR != NULL && (currR->row < newNode->row || (currR->row == newNode->row && currR->col < newNode->col))) {
                        prev = currR;
                        currR = currR->next;
                    }
                    if (prev == NULL) {
                        resultHead = newNode;
                    } else {
                        prev->next = newNode;
                    }
                    newNode->next = currR;
                }
            }
        }
    }
    
    
    return resultHead;
}


// Function for finding the Transpose of the matrix

Node* transpose(Node* head) {
    Node* transposeHead = NULL;
    
    // Loop through each node in the original linked list
    for (Node* curr = head; curr != NULL; curr = curr->next) {
        // Create a new node with its row and column positions swapped
        Node* newNode = createNode(curr->value, curr->col, curr->row);
        
        if (transposeHead == NULL) {
            transposeHead = newNode;
        } else {
            Node* currTranspose = transposeHead;
            while (currTranspose->next != NULL) {
                currTranspose = currTranspose->next;
            }
            currTranspose->next = newNode;
        }
    }
    
    return transposeHead;
}
// Function for moving the element of matrix to the double vaue
double get(Node* head, int row, int col) {
    double result = 0.0;
    
    if (head == NULL) {
        printf("Error: matrix is empty\n");
        return result;
    }
    
    Node* curr = head;
    while (curr != NULL && (curr->row != row || curr->col != col)) {
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Error: element not found in matrix\n");
        return result;
    }
    
    result = (double) curr->value;
        
    return result;
}

Node* assign(int numRows, int numCols,double *array)
{
    Node* head = NULL;
    Node* currentRow = NULL;

    // Loop through each row
    for (int i = 0; i < numRows; i++) 
    {
        Node* newRow = NULL;
        Node* currentCol = NULL;

        // Loop through each column in the current row
        for (int j = 0; j < numCols; j++)
 {
            double value;
     int index=0;
            //printf("Enter the value at position (%d,%d): ", i, j);
            //scanf("%d", &value);
     value=array[i];
     


            // If the value is not 0, create a new node and add it to the matrix
            if (value != 0)
     {
                Node* newNode = createNode(value, i, j);
                if (newRow == NULL) {
                    newRow = newNode;
                    currentCol = newNode;
                } 
  else
  {
                    currentCol->next = newNode;
                    currentCol = newNode;
                }
            }
        }

        // If the current row is not empty, add it to the matrix
        if (newRow != NULL) {
            if (head == NULL) {
                head = newRow;
                currentRow = newRow;
            } else {
                currentRow->next = newRow;
                currentRow = newRow;
            }
        }
    }

    return head;
}

void savef(char *filename, Node* head, int numRows, int numCols)
{
	 
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    while(head!=NULL)
    {
	fprintf(fp,"%lf\n",head->value);
	head=head->next;
    }
}
// Function to find the intersection point of two lines 
void find_intersection(Node* line1, Node* line2) {
    // Create a matrix for the coefficients of the two lines (line1 and line2)
    // and a matrix for the constants
    int numRows = 2;
    int numCols = 3;
    double coefficients[6];

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (i == 0 && j == 0) {
                coefficients[0] = get(line1, i, j);
                coefficients[1] = get(line1, i+1, j);
                coefficients[2] = get(line1, i+2, j);
            } else if (i == 1 && j == 0) {
                coefficients[3] = get(line2, i-1    ,   j);
                coefficients[4] = get(line2, i  , j);
                coefficients[5] = get(line2, i + 1 , j);
            }
        }
    }

    double determinant = coefficients[0] * coefficients[4] - coefficients[1] * coefficients[3];

    if (determinant != 0) {
        // Calculate the intersection point (x, y)
        double x = (coefficients[1] * coefficients[5] - coefficients[2] * coefficients[4]) / determinant;
        double y = (coefficients[2] * coefficients[3] - coefficients[0] * coefficients[5]) / determinant;

        printf("%lf\n%lf\n", x, y);

        // Save the intersection point to result.dat
        FILE* resultFile = fopen("result.dat", "w");
        if (resultFile != NULL) {
            fprintf(resultFile, "%.2lf\n %.2lf\n", x, y);
            fclose(resultFile);
            //printf("Result saved in result.dat.\n");
        } else {
            printf("Error: Could not save the result.\n");
        }
    } else {
        printf("The lines are parallel and do not intersect.\n");
    }
}
