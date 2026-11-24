#include<stdio.h>
#include<string.h>

int main()
{
	FILE *fin = fopen("input.txt","r");
	FILE *fout = fopen("output.txt","w");
	if (fin == NULL || fout == NULL)
	{
		printf("打开文件失败\n");
		return 1;
	}
	
	char line[2048];
	int no = 0;
	
	while (fgets(line, sizeof(line), fin) != NULL)
	{
		char tmp[2048];
		strcpy(tmp, line);
		tmp[strcspn(tmp, "\r\n")] = '\0';
		
		if (strcmp(tmp, "-END-") == 0) break;
		
		no++;
		fprintf(fout, "%03d %s", no, line);
		
		if (strchr(line, '\n') == NULL) fputc('\n', fout);
	}
	
	fclose(fin);
	fclose(fout);
	return 0;
}
