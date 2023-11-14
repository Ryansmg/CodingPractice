#include <stdio.h>

int main()
{
    FILE *in;
    in = fopen("Bingo.in", "r");
    int card[5][5];
    int said[5][5] = {0};
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            fscanf(in, " %d", &(card[i][j]));
        }
    }
    int input = -1;
    int type;
    while(1)
    {
        fscanf(in, " %d", &input);
        if(input==0) {
            printf("No Bingo on this card");
            return 0;
        }
        else printf("%d\n", input);
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                if(card[i][j] == input) said[i][j] = 1;
            }
        }
        for(int i=0; i<5; i++)
        {
            int bingo = 1;
            //행
            for(int j=0; j<5; j++)
                if(!said[i][j]) {bingo = 0; break;}
            if(bingo)
            {
                printf("BINGO\n");
                for(int j=0; j<5; j++) printf("%d, %d, %d\n", i+1, j+1, card[i][j]);
                return 0;
            }

            //열
            bingo = 1;
            for(int j=0; j<5; j++)
                if(!said[j][i]) {bingo = 0; break;}
            if(bingo)
            {
                printf("BINGO\n");
                for(int j=0; j<5; j++) printf("%d, %d, %d\n", j+1, i+1, card[j][i]);
                return 0;
            }

            //모서리
            if(said[0][0] && said[4][0] && said[0][4] && said[4][4])
            {
                printf("BINGO\n");
                printf("0, 0, %d\n", card[0][0]);
                printf("4, 0, %d\n", card[4][0]);
                printf("0, 4, %d\n", card[0][4]);
                printf("4, 4, %d\n", card[4][4]);
            }

            //대각선 (\)
            bingo = 1;
            for(int j=0; j<5; j++)
            {
                if(!said[j][j]) {bingo = 0; break;}
            }
            if(bingo) 
            {
                printf("BINGO\n");
            for(int j=0; j<5; j++)
            {
                printf("%d, %d, %d\n", j+1, j+1, card[j][j]);
            }
                return 0;
            }

            //대각선 (/)
            bingo = 1;
            for(int j=0; j<5; j++)
            {
                if(!said[j][4-j]) {bingo = 0; break;}
            }
            if(bingo) 
            {
                printf("BINGO\n");
            for(int j=0; j<5; j++)
            {
                printf("%d, %d, %d\n", j+1, 5-j, card[j][4-j]);
            }
                return 0;
            }

        }
    }
}