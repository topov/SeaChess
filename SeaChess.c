#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

int GetFontSize(HANDLE windowHandle, COORD *size)
    {
    CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };
 
    if (!GetCurrentConsoleFontEx(windowHandle, 0, &font))
        {
        return 0;
        }
 
    *size = font.dwFontSize;
 
    return 1;
    }
int SetFontSize(HANDLE windowHandle, COORD size)
    {
    CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };
 
    if (!GetCurrentConsoleFontEx(windowHandle, 0, &font))
        {
        return 0;
        }
 
    font.dwFontSize = size;
 
    if (!SetCurrentConsoleFontEx(windowHandle, 0, &font))
        {
        return 0;
        }
 
    return 1;
    }
int razmer(void)
    {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD size;
 
    if (GetFontSize(h, &size))
        {
        size.Y += (SHORT)(size.Y * .100);
        SetFontSize(h, size);
        } 
}

int game ()
{
	int m,n,row,box;
	int masa [3][3];
	char playerOne='-';
	char playerTwo='+';
	char playerNameOne[20];
	char playerNameTwo[20];
	FILE *fp;
	fp=fopen("result.txt","w+");
	row=0; box=0;
	system("COLOR F1");
	razmer();
	printf("Player One Name: ");
	scanf("%s",playerNameOne);
	printf("Player Two Name: ");
	scanf("%s",playerNameTwo);

	for(m=0;m<3;m++)
	{
		for(n=0;n<3;n++) masa[m][n]='O';
	}
	for(m=0;m<3;m++)
	{
		for(n=0;n<3;n++) printf ("%c",masa[m][n]); 
			
		printf ("\n");
	}
	printf ("\n");
	do
	{
	printf ("%s's Turn \n",playerNameOne);															 // PLAYER ONE  CODE !!!!!!!!!
	fflush(stdout);
	do 
	{
	printf("Please enter row and box: ");
	scanf("%d",&row);
	scanf("%d",&box);
	if(masa[row-1][box-1]!='O') printf ("TRY AGAIN ! \n");
	else masa[row-1][box-1]=playerOne;
	}
	while (masa[row-1][box-1]!=playerOne || row>3 || box>3);
	printf ("\n");
	for(m=0;m<3;m++)
	{
		for(n=0;n<3;n++) printf ("%c",masa[m][n]);
		printf ("\n");
	}
	printf ("\n");
	
	if ((masa[0][0]=='-')&&(masa[0][1]=='-')&&(masa[0][2]=='-')) {printf("%s WIN ! \n",playerNameOne);break;} else ;
	if ((masa[1][0]=='-')&&(masa[1][1]=='-')&&(masa[1][2]=='-')) {printf("%s WIN ! \n",playerNameOne);break;} else ;
	if ((masa[2][0]=='-')&&(masa[2][1]=='-')&&(masa[2][2]=='-')) {printf("%s WIN ! \n",playerNameOne);break;} else ;

	if ((masa[0][0]=='-')&&(masa[1][0]=='-')&&(masa[2][0]=='-')) {printf("%s WIN ! \n",playerNameOne);break;} else ;
	if ((masa[0][1]=='-')&&(masa[1][1]=='-')&&(masa[2][1]=='-')) {printf("%s WIN ! \n",playerNameOne);break;} else ;
	if ((masa[0][2]=='-')&&(masa[1][2]=='-')&&(masa[2][2]=='-')) {printf("%s WIN ! \n",playerNameOne);break;} else ;

	if ((masa[0][2]=='-')&&(masa[1][1]=='-')&&(masa[2][0]=='-')) {printf("%s WIN ! \n",playerNameOne);break;} else ;
	if ((masa[0][0]=='-')&&(masa[1][1]=='-')&&(masa[2][2]=='-')) {printf("%s WIN ! \n",playerNameOne);break;} else ;
	
	
	printf ("%s's Turn \n",playerNameTwo);															// PLAYER TWO CODE !!!!!!!!!
	fflush(stdout);
	do 
	{
	printf("Please enter row and box: ");
	scanf("%d",&row);
	scanf("%d",&box);
	if(masa[row-1][box-1]!='O') printf ("TRY AGAIN ! \n");
	else masa[row-1][box-1]=playerTwo;
	}
	while (masa[row-1][box-1]!=playerTwo || row>3 || box>3);
	printf ("\n");
	for(m=0;m<3;m++)
	{
		for(n=0;n<3;n++) printf ("%c",masa[m][n]);
		printf ("\n");
	}
	printf ("\n");
	
	if ((masa[0][0]=='+')&&(masa[0][1]=='+')&&(masa[0][2]=='+')) {printf("%s WIN ! \n",playerNameTwo);break;} else ;
	if ((masa[1][0]=='+')&&(masa[1][1]=='+')&&(masa[1][2]=='+')) {printf("%s WIN ! \n",playerNameTwo);break;} else ;
	if ((masa[2][0]=='+')&&(masa[2][1]=='+')&&(masa[2][2]=='+')) {printf("%s WIN ! \n",playerNameTwo);break;} else ;

	if ((masa[0][0]=='+')&&(masa[1][0]=='+')&&(masa[2][0]=='+')) {printf("%s WIN ! \n",playerNameTwo);break;} else ;
	if ((masa[0][1]=='+')&&(masa[1][1]=='+')&&(masa[2][1]=='+')) {printf("%s WIN ! \n",playerNameTwo);break;} else ;
	if ((masa[0][2]=='+')&&(masa[1][2]=='+')&&(masa[2][2]=='+')) {printf("%s WIN ! \n",playerNameTwo);break;} else ;

	if ((masa[0][2]=='+')&&(masa[1][1]=='+')&&(masa[2][0]=='+')) {printf("%s WIN ! \n",playerNameTwo);break;} else ;
	if ((masa[0][0]=='+')&&(masa[1][1]=='+')&&(masa[2][2]=='+')) {printf("%s WIN ! \n",playerNameTwo);break;} else ;
	}
	while (1);

	for(m=0;m<3;m++)
	{
		for(n=0;n<3;n++) fprintf (fp,"%c",masa[m][n]); 
			
		fprintf (fp,"\n");
	}
	fclose(fp);
	system ("pause");
}
int main()
{
	int choice;
	char str[999];
	FILE *rs;
	rs=fopen("result.txt","r");
	//Game Menu
	printf("SEA CHESS Game \n");
	printf("1.New Game \n");
	printf("2.Last Game\n");
	printf("3.EXIT\n");

	do
	{
		printf("Please select a choice:");
		scanf("%d", &choice);
		switch(choice)
		{
		case 1:
			{
				game();
				break;
			}
		case 2:
			{
				while (fscanf (rs, "%s", str) !=EOF) printf("%s \n",str);
				fclose (rs);
			}
		}
	}
	while (choice !=3); 

	system ("pause");
}

