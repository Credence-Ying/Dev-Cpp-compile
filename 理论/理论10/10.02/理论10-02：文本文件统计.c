#include<stdio.h>

int main()
{
	FILE *fin = fopen("input.txt","r");
	FILE *fout = fopen("output.txt","w");
	if (fin == NULL || fout == NULL)
	{
		printf("打开文件失败\n");
		return 1;
	}
	
	int characters = 0;
	int words = 0;
	int sentences = 0;
	int in_word = 0;
	int c;
	
	while ((c = fgetc(fin)) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\r' || c == '\t')
		{
			in_word = 0;
			continue;
		}
		
		characters++;
		
		if (!in_word) //从非单词进入单词
		{
			words++;
			in_word = 1;
		}
		
		if (c == '.' || c == '?' || c == '!') sentences++;
	}
	
	fprintf(fout,"Characters: %d\n", characters);
	fprintf(fout,"Words: %d\n", words);
	fprintf(fout,"Sentences: %d\n", sentences);
	
	fclose(fin);
	fclose(fout);
	return 0;
}
