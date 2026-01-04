#include <stdio.h>

int main()
{
    int i, j;
    int T[7][7];

    printf("Fill the matrix 7*7 (1 = full, 0 = empty):\n");

    for (i = 0; i < 7; i++)
    {
        printf("Row %d: ",i+1); 
        // we ler the user enter by row to be clear and i+1 because if it showed the user ' row 0 :' it would look illogical;  //
        for (j = 0; j < 7; j++)
        {
            int temp;
            do {
                scanf("%d", &temp);
                if (temp == 0 || temp == 1) {
                    T[i][j] = temp;
                } else {
                    printf("Invalid! Enter 0 or 1 only: ");
                }
            } while (temp != 0 && temp != 1);
        }
    }
       printf(" your drawing \n ");
    
    printf("==================\n");
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            if(T[i][j] == 1) {
                printf("* ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("==================\n");
    // FEATURE EXTRACTION //

    // Density //
    int density = 0;
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            if (T[i][j] == 1)
                density++;
        }
    }

    // Top row //
    int top_row = 0;
    for (j = 0; j < 7; j++)
        top_row += T[0][j];
    int top_filled;
    if(top_row >= 4) {
        top_filled = 1;
    } else {
        top_filled = 0;
    }

    // Middle row //
    int middle_row = 0;
    for (j = 0; j < 7; j++)
        middle_row += T[3][j];
    int middle_filled;
    if(middle_row >= 4) {
        middle_filled = 1;
    } else {
        middle_filled = 0;
    }

    // Bottom row //
    int bottom_row = 0;
    for (j = 0; j < 7; j++)
        bottom_row += T[6][j];
    int bottom_filled;
    if(bottom_row >= 4) {
        bottom_filled = 1;
    } else {
        bottom_filled = 0;
    }

    // Left column //
    int left_col = 0;
    for (i = 0; i < 7; i++)
        left_col += T[i][0];
    int left_filled;
    if(left_col >= 4) {
        left_filled = 1;
    } else {
        left_filled = 0;
    }

    // Right column //
    int right_col = 0;
    for (i = 0; i < 7; i++)
        right_col += T[i][6];
    int right_filled;
    if(right_col >= 4) {
        right_filled = 1;
    } else {
        right_filled = 0;
    }

    // Center column for digit 1 //
    int center_col = 0;
    for (i = 0; i < 7; i++)
        center_col += T[i][3];
    int center_col_filled;
    if(center_col >= 4) {
        center_col_filled = 1;
    } else {
        center_col_filled = 0;
    }

    // Center cell  //
    int center_filled = T[3][3];

    // Main diagonal//
    int diagonal = 0;
    for (i = 0; i < 7; i++)
        diagonal += T[i][i];

    printf("Density: %d cells\n",density);
    
    if(top_filled == 1) {
        printf("Top row: FILLED (%d/7)\n",top_row);
    } else {
        printf("Top row: NOT FILLED (%d/7)\n",top_row);
    }
    
    if(middle_filled == 1) {
        printf("Middle row: FILLED (%d/7)\n", middle_row);
    } else {
        printf("Middle row: NOT FILLED (%d/7)\n", middle_row);
    }
    
    if(bottom_filled == 1) {
        printf("Bottom row: FILLED (%d/7)\n", bottom_row);
    } else {
        printf("Bottom row: NOT FILLED (%d/7)\n", bottom_row);
    }
    
    if(left_filled == 1) {
        printf("Left column: FILLED (%d/7)\n", left_col);
    } else {
        printf("Left column: NOT FILLED (%d/7)\n", left_col);
    }
    
    if(right_filled == 1) {
        printf("Right column: FILLED (%d/7)\n", right_col);
    } else {
        printf("Right column: NOT FILLED (%d/7)\n", right_col);
    }
    
    if(center_col_filled == 1) {
        printf("Center column: FILLED (%d/7)\n", center_col);
    } else {
        printf("Center column: NOT FILLED (%d/7)\n", center_col);
    }
    
    if(center_filled == 1) {
        printf("Center: FILLED\n");
    } else {
        printf("Center: EMPTY\n");
    }
    printf("Diagonal: %d/7 cells\n", diagonal);
    
    // number recognition //
    
  int digit = -1;

    if (density <= 10 &&
        center_col_filled &&
        !top_filled && !bottom_filled &&
        !left_filled && !right_filled)
        digit = 1;

    else if (top_filled &&
             !middle_filled &&
             !bottom_filled &&
             right_filled)
        digit = 7;

    else if (!top_filled &&
             middle_filled &&
             right_filled &&
             left_filled &&
             center_filled)
        digit = 4;

    else if (top_filled &&
             middle_filled &&
             bottom_filled &&
             right_filled &&
             !left_filled)
        digit = 3;

    else if (top_filled &&
             middle_filled &&
             bottom_filled &&
             left_filled &&
             !right_filled)
        digit = 5;

    else if (top_filled &&
             middle_filled &&
             bottom_filled &&
             diagonal >= 4 &&
             !left_filled &&
             !right_filled)
        digit = 2;

    else if (top_filled &&
             middle_filled &&
             bottom_filled &&
             left_filled &&
             !right_filled &&
             center_filled)
        digit = 6;

    else if (top_filled &&
             middle_filled &&
             right_filled &&
             !bottom_filled &&
             !left_filled)
        digit = 9;

    else if (top_filled &&
             bottom_filled &&
             left_filled &&
             right_filled &&
             !middle_filled &&
             !center_filled)
        digit = 0;

    else if (top_filled &&
             middle_filled &&
             bottom_filled &&
             left_filled &&
             right_filled &&
             center_filled)
        digit = 8;

    printf("-Density: %d cells\n", density);
    if(top_filled == 1) printf("-Top row: FILLED\n");
    if(middle_filled == 1) printf("-Middle row: FILLED\n");
    if(center_filled == 0) printf("-Center: EMPTY\n");
    if(center_col_filled == 1) printf("-Center column filled\n");

    if (digit != -1){
        printf("\nResult: Digit %d recognized!\n", digit);
        printf("Confidence: HIGH\n");
    }else{
        printf("\nDigit not recognized.\n");
        printf("Confidence: LOW - please Try again and draw clearer\n");
    }

    return 0;
}