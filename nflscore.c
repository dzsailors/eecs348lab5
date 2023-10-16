#include <stdio.h>

int main()
{
    int score;
    while (1)
    {
        printf("Enter 0 or 1 to STOP\nEnter the NFL Score: ");
        scanf("%d", &score);
        printf("Possible Combinations of Scoring Plays: \n");
        if (score <= 1)
        {
            break;
        }
        for (int tdc = 0; tdc < (score / 8) + 1; tdc++)
        {
            for (int tdfg = 0; tdfg < (score / 7) + 1; tdfg++)
            {
                for (int td = 0; td < (score / 6) + 1; td++)
                {
                    for (int fg = 0; fg < (score / 3) + 1; fg++)
                    {
                        for (int s = 0; s < (score / 2) + 1; s++)
                        {
                            if ((8 * tdc) + (7 * tdfg) + (6 * td) + (3 * fg) + (2 * s) == score)
                            {
                                printf("%d TD + 2pt %d TD + 1pt %d TD %d FG %d Safety\n", tdc, tdfg, td, fg, s);
                            }
                        }
                    }
                }
            }
        }
    }
return 0;
}

