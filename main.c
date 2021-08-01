#include <stdio.h>
#include <string.h>
#include <windows.h>

void clearTextPointer(){
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;
    SetConsoleCursorInfo(hOut,&ConCurInf);
}


void printfFile(FILE *f,char *line, char *path, int *frameIndex){
	f=fopen(path,"r");
	if(f){
		(*frameIndex)++;
		while(!feof(f)){
            fgets(line,256,f);
            printf("%s",line);
            if(*frameIndex==1) Sleep(300);
        }
        
	}
}
int main(){
	int frameIndex=0;
	int framesNum=106;
	char fileName[100];
    char line[256];
	char buffer [33];
    FILE *f;
    clearTextPointer();
    printf("press any key to start!\n");
	getch();
	int i;
	for(i=0;i<=10;i++){
		printf("Loading...%d%%\n",i*10);
		Sleep(500);
	}
	system("CLS");
	clearTextPointer();
	for(i=0;i<framesNum;i++){
		strcpy(fileName,"./frogText/ASCII-frame_");
		itoa(i,buffer,10);
		strcat(fileName,buffer);
		strcat(fileName,".txt");
    	printfFile(f,line,fileName, &frameIndex);
//    	Sleep(10);
    	system("CLS");
    	if(i==framesNum-1) i=-1;
	}
    return 0;
}
